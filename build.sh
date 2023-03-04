#!/usr/bin/env bash

# CREDIT: https://github.com/pwn0rz/xnu-build

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

# Help
if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: build.sh [-h] [--clean]

This script builds the macOS 13.0 XNU kernel

Where:
    -h       show this help text
    --kc     Create Kext Collection (via kmutil create)
    --clean  cleans build and fakeroot directories
'
    exit
fi

# Colors
export ESC_SEQ="\x1b["
export COL_RESET=$ESC_SEQ"39;49;00m"
export COL_RED=$ESC_SEQ"31;01m"
export COL_GREEN=$ESC_SEQ"32;01m"
export COL_YELLOW=$ESC_SEQ"33;01m"
export COL_BLUE=$ESC_SEQ"34;01m"
export COL_MAGENTA=$ESC_SEQ"35;01m"
export COL_CYAN=$ESC_SEQ"36;01m"

function running() {
    echo -e "$COL_MAGENTA ⇒ $COL_RESET"$1
}

function info() {
    echo -e "$COL_BLUE[info]$COL_RESET" $1
}

: ${KERNEL_CONFIG:=RELEASE}
: ${ARCH_CONFIG:=ARM64}
: ${MACHINE_CONFIG:=VMAPPLE}
: ${JSONDB:=0}

WORK_DIR="$PWD"
BUILD_DIR=${WORK_DIR}/build
FAKEROOT_DIR=${WORK_DIR}/fakeroot
DSTROOT=${FAKEROOT_DIR}

RELEASE_URL='https://raw.githubusercontent.com/apple-oss-distributions/distribution-macOS/macos-131/release.json'

KDKROOT='/Library/Developer/KDKs/KDK_13.1_22C65.kdk'
KERNEL_FRAMEWORK_ROOT='/System/Library/Frameworks/Kernel.framework/Versions/A'

venv() {
    if [ ! -d "${WORK_DIR}/venv" ]; then
        running "Creating virtual environment"
        python3 -m venv ${WORK_DIR}/venv
    fi
    info "Activating virtual environment"
    source ${WORK_DIR}/venv/bin/activate
}

patches() {
    running "Patching xnu files"
    # xnu headers patch
    sed -i '' 's|^AVAILABILITY_PL="${SDKROOT}/${DRIVERKITROOT}|AVAILABILITY_PL="${FAKEROOT_DIR}|g' ${WORK_DIR}/bsd/sys/make_symbol_aliasing.sh
    # libsyscall patch
    sed -i '' 's|^#include.*BSD.xcconfig.*||g' ${WORK_DIR}/libsyscall/Libsyscall.xcconfig
    # xnu build patch
    sed -i '' 's|^LDFLAGS_KERNEL_SDK	= -L$(SDKROOT).*|LDFLAGS_KERNEL_SDK	= -L$(FAKEROOT_DIR)/usr/local/lib/kernel -lfirehose_kernel|g' ${WORK_DIR}/makedefs/MakeInc.def
    sed -i '' 's|^INCFLAGS_SDK	= -I$(SDKROOT)|INCFLAGS_SDK	= -I$(FAKEROOT_DIR)|g' ${WORK_DIR}/makedefs/MakeInc.def
    git apply .github/patches/machine_routines.patch || true
}

build_dtrace() {
    if [ ! -f "${FAKEROOT_DIR}/usr/local/bin/ctfmerge" ]; then
        running "📦 Building dtrace"
        if [ ! -d "${WORK_DIR}/dtrace" ]; then
            DTRACE_VERSION=$(curl -s $RELEASE_URL | jq -r '.projects[] | select(.project=="dtrace") | .tag')
            git clone --branch ${DTRACE_VERSION} https://github.com/apple-oss-distributions/dtrace.git ${WORK_DIR}/dtrace
        fi
        SRCROOT=${WORK_DIR}/dtrace
        OBJROOT=${BUILD_DIR}/dtrace.obj
        SYMROOT=${BUILD_DIR}/dtrace.sym
        cd ${SRCROOT}
        xcodebuild install -sdk macosx -target ctfconvert -target ctfdump -target ctfmerge ARCHS="arm64" CODE_SIGN_IDENTITY="-" OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT}
        cd ${WORK_DIR}
    fi
}

build_availabilityversions() {
    if [ ! -f "${FAKEROOT_DIR}/${KERNEL_FRAMEWORK_ROOT}/Headers/AvailabilityVersions.h" ]; then
        running "📦 Building AvailabilityVersions"
        if [ ! -d "${WORK_DIR}/AvailabilityVersions" ]; then
            AVAILABILITYVERSIONS_VERSION=$(curl -s $RELEASE_URL | jq -r '.projects[] | select(.project=="AvailabilityVersions") | .tag')
            git clone --branch ${AVAILABILITYVERSIONS_VERSION} https://github.com/apple-oss-distributions/AvailabilityVersions.git ${WORK_DIR}/AvailabilityVersions
        fi
        SRCROOT=${WORK_DIR}/AvailabilityVersions
        OBJROOT=${BUILD_DIR}/
        SYMROOT=${BUILD_DIR}/
        cd ${SRCROOT}
        make install -j8 OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT}
        cd ${WORK_DIR}
    fi
}

xnu_headers() {
    if [ ! -d "${FAKEROOT_DIR}/${KERNEL_FRAMEWORK_ROOT}/PrivateHeaders" ]; then
        running "Installing xnu headers TARGET_CONFIGS=\"$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG\""
        SRCROOT=${WORK_DIR}
        OBJROOT=${BUILD_DIR}/xnu-hdrs.obj
        SYMROOT=${BUILD_DIR}/xnu-hdrs.sym
        cd ${SRCROOT}
        make installhdrs SDKROOT=macosx TARGET_CONFIGS="$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG" OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR}
        cd ${WORK_DIR}
    fi
}

libsystem_headers() {
    if [ ! -d "${FAKEROOT_DIR}/System/Library/Frameworks/System.framework" ]; then
        running "Installing Libsystem headers"
        if [ ! -d "${WORK_DIR}/Libsystem" ]; then
            LIBSYSTEM_VERSION=$(curl -s $RELEASE_URL | jq -r '.projects[] | select(.project=="Libsystem") | .tag')
            git clone --branch ${LIBSYSTEM_VERSION} https://github.com/apple-oss-distributions/Libsystem.git ${WORK_DIR}/Libsystem
        fi
        sed -i '' 's|^#include.*BSD.xcconfig.*||g' ${WORK_DIR}/Libsystem/Libsystem.xcconfig
        SRCROOT=${WORK_DIR}/Libsystem
        OBJROOT=${BUILD_DIR}/Libsystem.obj
        SYMROOT=${BUILD_DIR}/Libsystem.sym
        cd ${SRCROOT}
        xcodebuild installhdrs -sdk macosx ARCHS="arm64 arm64e" VALID_ARCHS="arm64 arm64e" OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR}
        cd ${WORK_DIR}
    fi
}

libsyscall_headers() {
    if [ ! -f "${FAKEROOT_DIR}/usr/include/os/proc.h" ]; then
        running "Installing libsyscall headers"
        SRCROOT=${WORK_DIR}/libsyscall
        OBJROOT=${BUILD_DIR}/libsyscall.obj
        SYMROOT=${BUILD_DIR}/libsyscall.sym
        cd ${SRCROOT}
        xcodebuild installhdrs -sdk macosx TARGET_CONFIGS="$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG" ARCHS="arm64 arm64e" VALID_ARCHS="arm64 arm64e" OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR}
        cd ${WORK_DIR}
    fi
}

build_libplatform() {
    if [ ! -f "${FAKEROOT_DIR}/usr/local/include/_simple.h" ]; then
        running "📦 Building libplatform"
        if [ ! -d "${WORK_DIR}/libplatform" ]; then
            LIBPLATFORM_VERSION=$(curl -s $RELEASE_URL | jq -r '.projects[] | select(.project=="libplatform") | .tag')
            git clone --branch ${LIBPLATFORM_VERSION} https://github.com/apple-oss-distributions/libplatform.git ${WORK_DIR}/libplatform
        fi
        SRCROOT=${WORK_DIR}/libplatform
        cd ${SRCROOT}
        ditto ${SRCROOT}/include ${DSTROOT}/usr/local/include
        ditto ${SRCROOT}/private ${DSTROOT}/usr/local/include
        cd ${WORK_DIR}
    fi
}

build_libdispatch() {
    if [ ! -f "${FAKEROOT_DIR}/usr/local/lib/kernel/libfirehose_kernel.a" ]; then
        running "📦 Building libdispatch"
        if [ ! -d "${WORK_DIR}/libdispatch" ]; then
            LIBDISPATCH_VERSION=$(curl -s $RELEASE_URL | jq -r '.projects[] | select(.project=="libdispatch") | .tag')
            git clone --branch ${LIBDISPATCH_VERSION} https://github.com/apple-oss-distributions/libdispatch.git ${WORK_DIR}/libdispatch
        fi
        SRCROOT=${WORK_DIR}/libdispatch
        OBJROOT=${BUILD_DIR}/libfirehose_kernel.obj
        SYMROOT=${BUILD_DIR}/libfirehose_kernel.sym
        # libfirehose_kernel patch
        sed -i '' 's|$(SDKROOT)/System/Library/Frameworks/Kernel.framework/PrivateHeaders|$(FAKEROOT_DIR)/System/Library/Frameworks/Kernel.framework/PrivateHeaders|g' ${SRCROOT}/xcodeconfig/libfirehose_kernel.xcconfig
        sed -i '' 's|$(SDKROOT)/usr/local/include|$(FAKEROOT_DIR)/usr/local/include|g' ${SRCROOT}/xcodeconfig/libfirehose_kernel.xcconfig
        cd ${SRCROOT}
        xcodebuild install -target libfirehose_kernel -sdk macosx ARCHS="arm64e" VALID_ARCHS="arm64e" OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR}
        cd ${WORK_DIR}
        mv ${FAKEROOT_DIR}/usr/local/lib/kernel/liblibfirehose_kernel.a ${FAKEROOT_DIR}/usr/local/lib/kernel/libfirehose_kernel.a
    fi
}

build_xnu() {
    if [ "$JSONDB" -ne "0" ]; then
        running "📦 Building XNU kernel with JSON compilation database"
        if [ ! -d "${KDKROOT}" ]; then
            error "KDKROOT not found: ${KDKROOT} - please install from the Developer Portal"
            exit 1
        fi        
        SRCROOT=${WORK_DIR}
        OBJROOT=${BUILD_DIR}/xnu-compiledb.obj
        SYMROOT=${BUILD_DIR}/xnu-compiledb.sym
        rm -rf ${OBJROOT}
        rm -rf ${SYMROOT}
        cd ${SRCROOT}
        make SDKROOT=macosx TARGET_CONFIGS="$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG" LOGCOLORS=y BUILD_WERROR=0 BUILD_LTO=0 BUILD_JSON_COMPILATION_DATABASE=1 SRCROOT=${SRCROOT} OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR} KDKROOT=${KDKROOT} || true
        JSON_COMPILE_DB=$(find ${OBJROOT} -name compile_commands.json)
        info "JSON compilation database: ${JSON_COMPILE_DB}"
        cp -f ${JSON_COMPILE_DB} ${SRCROOT}
    else
        running "📦 Building XNU kernel TARGET_CONFIGS=\"$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG\""
        if [ ! -d "${KDKROOT}" ]; then
            error "KDKROOT not found: ${KDKROOT} - please install from the Developer Portal"
            exit 1
        fi
        SRCROOT=${WORK_DIR}
        OBJROOT=${BUILD_DIR}/xnu.obj
        SYMROOT=${BUILD_DIR}/xnu.sym
        cd ${SRCROOT}
        make install -j8 SDKROOT=macosx TARGET_CONFIGS="$KERNEL_CONFIG $ARCH_CONFIG $MACHINE_CONFIG" CONCISE=0 LOGCOLORS=y BUILD_WERROR=0 BUILD_LTO=0 SRCROOT=${SRCROOT} OBJROOT=${OBJROOT} SYMROOT=${SYMROOT} DSTROOT=${DSTROOT} FAKEROOT_DIR=${FAKEROOT_DIR} KDKROOT=${KDKROOT}
        cd ${WORK_DIR}
    fi
}

install_ipsw() {
    if ! [ -x "$(command -v ipsw)" ]; then
        running "Installing `ipsw`..."
        brew install blacktop/tap/ipsw
    fi
}

build_kc() {
    if [ -f "${BUILD_DIR}/xnu.obj/kernel.${KERNEL_CONFIG,,}.${MACHINE_CONFIG,,}" ]; then
        running "📦 Building kext collection for kernel.${KERNEL_CONFIG,,}.${MACHINE_CONFIG,,}"
        kmutil create -M -v -V release -a arm64e -n boot \
            -B ${BUILD_DIR}/oss-xnu.kc \
            -k ${BUILD_DIR}/xnu.obj/kernel.${KERNEL_CONFIG,,}.${MACHINE_CONFIG,,} \
            --kdk ${KDKROOT} \
            --elide-identifier com.apple.driver.SEPHibernation \
            --elide-identifier com.apple.iokit.IOSkywalkFamily \
            -r ${KDKROOT}/System/Library/Extensions \
            -r /System/Library/Extensions \
            -r /System/Library/DriverExtensions \
            -x $(ipsw kernel kmutil inspect -x --filter 'com.apple.iokit.IOSkywalkFamily|com.apple.driver.SEPHibernation') # this will skip IOSkywalkFamily and SEPHibernation (and other kexts with them as dependencies)
            # -x $(kmutil inspect -V release --no-header | grep apple | grep -v "SEPHiber\|IOSkywalkFamily" | awk '{print " -b "$1; }')
    fi
}

main() {
    if [[ "${1-}" =~ ^-*c(lean)?$ ]]; then
        running "Cleaning build directories and extra repos..."
        read -p "Are you sure? " -n 1 -r
        echo    # (optional) move to a new line
        if [[ $REPLY =~ ^[Yy]$ ]]; then
            info "deleting ${BUILD_DIR}"
            rm -rf ${BUILD_DIR}
            info "deleting ${FAKEROOT_DIR}"
            rm -rf ${FAKEROOT_DIR}
            info "deleting ${WORK_DIR}/dtrace"
            rm -rf ${WORK_DIR}/dtrace
            info "deleting ${WORK_DIR}/AvailabilityVersions"
            rm -rf ${WORK_DIR}/AvailabilityVersions
            info "deleting ${WORK_DIR}/Libsystem"
            rm -rf ${WORK_DIR}/Libsystem
            info "deleting ${WORK_DIR}/libplatform"
            rm -rf ${WORK_DIR}/libplatform
            info "deleting ${WORK_DIR}/libdispatch"
            rm -rf ${WORK_DIR}/libdispatch
        fi
    fi
    venv
    patches
    build_dtrace
    build_availabilityversions
    xnu_headers
    libsystem_headers
    libsyscall_headers
    build_libplatform
    build_libdispatch
    build_xnu
    if [[ "${1-}" =~ ^-*k(c)?$ ]]; then    
        install_ipsw
        build_kc
    fi
    echo "  🎉 XNU Build Done!"
}

main "$@"