SOURCE_DIR=/Users/sunsama/Documents/workspace/research/ios/darwin-xnu-build-llvm/xnu
export CONFIG_DEFINES = -DINET -DMACH -DVLAN -DBOND -DIF_FAKE -DIF_REDIRECT -DAH_ALL_CRYPTO -DPF -DPFLOG -DDUMMYNET -DTRAFFIC_MGT -DMULTICAST -DIFNET_INPUT_SANITY_CHK -DMULTIPATH -DMPTCP -DSYSV_SEM -DSYSV_MSG -DSYSV_SHM -DPSYNCH -DFLOW_DIVERT -DNECP -DCONTENT_FILTER -DREMOTE_VIF -DSKYWALK -DCONFIG_NEXUS_USER_PIPE -DCONFIG_NEXUS_KERNEL_PIPE -DCONFIG_NEXUS_MONITOR -DCONFIG_NEXUS_FLOWSWITCH -DCONFIG_NEXUS_NETIF -DCONFIG_MBUF_MCACHE -DSOCKETS -DSENDFILE -DNETWORKING -DCONFIG_FSE -DCONFIG_IMAGEBOOT -DCONFIG_MBUF_JUMBO -DCONFIG_IMAGEBOOT_CHUNKLIST -DFIFO -DFDESC -DDEVFS -DNULLFS -DBINDFS -DFS_COMPRESSION -DCONFIG_DEV_KMEM -DQUOTA -DNAMEDSTREAMS -DCONFIG_APPLEDOUBLE -DCONFIG_VOLFS -DCONFIG_IMGSRC_ACCESS -DCONFIG_TRIGGERS -DCONFIG_EXT_RESOLVER -DCONFIG_SEARCHFS -DCONFIG_MNT_SUID -DCONFIG_MNT_ROOTSNAP -DCONFIG_ROSV_STARTUP -DCONFIG_FIRMLINKS -DCONFIG_MOUNT_VM -DCONFIG_MOUNT_PREBOOTRECOVERY -DCONFIG_DATALESS_FILES -DCONFIG_BASESYSTEMROOT -DCONFIG_UNION_MOUNTS -DCONFIG_FILE_LEASES -DNFSSERVER -DCONFIG_NETBOOT -DIPSEC -DIPSEC_ESP -DCRYPTO -DCRYPTO_SHA2 -DENCRYPTED_SWAP -DCONFIG_IMG4 -DZLIB -DIF_BRIDGE -DCONFIG_KN_HASHSIZE="64" -DCONFIG_VNODES="263168" -DCONFIG_NC_HASH="4096" -DCONFIG_VFS_NAMES="4096" -DCONFIG_MAX_CLUSTERS="8" -DCONFIG_MIN_NBUF="256" -DCONFIG_MIN_NIOBUF="128" -DCONFIG_NMBCLUSTERS="((1024 * 512) / MCLBYTES)" -DCONFIG_TCBHASHSIZE="4096" -DCONFIG_AIO_MAX="90" -DCONFIG_AIO_PROCESS_MAX="16" -DCONFIG_AIO_THREAD_COUNT="4" -DCONFIG_MAXVIFS="32" -DCONFIG_MFCTBLSIZ="256" -DCONFIG_MSG_BSIZE_REL="131072" -DCONFIG_MSG_BSIZE_DEV="131072" -DCONFIG_MSG_BSIZE="CONFIG_MSG_BSIZE_REL" -DCONFIG_IPC_TABLE_ENTRIES_SIZE_MAX="7340032" -DCONFIG_IPC_TABLE_REQUEST_SIZE_MAX="2097152" -DCONFIG_IPC_KERNEL_MAP_SIZE="64" -DCONFIG_VSPRINTF -DCONFIG_DYNAMIC_CODE_SIGNING -DCONFIG_CODE_DECRYPTION -DCONFIG_PROTECT -DCONFIG_KEYPAGE_WP -DCONFIG_MEMORYSTATUS -DCONFIG_DEFERRED_RECLAIM -DCONFIG_PHYS_WRITE_ACCT -DVM_PRESSURE_EVENTS -DCONFIG_LEDGER_INTERVAL_MAX -DCONFIG_IOSCHED -DIMPORTANCE_INHERITANCE -DCONFIG_TELEMETRY -DCONFIG_PROC_UUID_POLICY -DCONFIG_COREDUMP -DCONFIG_PV_TICKET -DHIBERNATION -DIOKITCPP -DIOKITSTATS -DCONFIG_SLEEP -DCONFIG_MAX_THREADS="500" -DLIBKERNCPP -DCONFIG_BLOCKS -DCONFIG_KEC_FIPS -DCONFIG_KEXT_BASEMENT -DCONFIG_PERSONAS -DCONFIG_MACF -DCONFIG_MACF_SOCKET_SUBSET -DCONFIG_AUDIT -DCONFIG_ARCADE -DCONFIG_SETUID -DCONFIG_KAS_INFO -DCONFIG_ZLEAKS -DCONFIG_VOUCHER_DEPRECATED -DKPERF -DKPC -DPGO -DMACH_BSD -DIOKIT -DCONFIG_THREAD_MAX="2560" -DCONFIG_TASK_MAX="1024" -DCONFIG_ZONE_MAP_MIN="120586240" -DCONFIG_SCHED_TRADITIONAL -DCONFIG_SCHED_MULTIQ -DCONFIG_SCHED_TIMESHARE_CORE -DCONFIG_SCHED_SFI -DCONFIG_PROB_GZALLOC -DMACH_KDP -DCONFIG_SERIAL_KDP -DCONFIG_KDP_INTERACTIVE_DEBUGGING -DCONFIG_KDP_COREDUMP_ENCRYPTION -DCONFIG_TASKWATCH -DCONFIG_USER_NOTIFICATION -DCONFIG_ATM -DCONFIG_COALITIONS -DCONFIG_SYSDIAGNOSE -DCONFIG_CSR -DSERIAL_CONSOLE -DVIDEO_CONSOLE -DCONFIG_REQUIRES_U32_MUNGING -DCOPYOUT_SHIM -DCONFIG_MACH_BRIDGE_SEND_TIME -DCONFIG_SERVICE_PORT_INFO -DCONFIG_DELAY_IDLE_SLEEP -DCONFIG_PROC_UDATA_STORAGE -DPAL_I386 -DCONFIG_MCA -DCONFIG_VMX -DCONFIG_MTRR -DCONFIG_MACF_LAZY_VNODE_LABELS -DHYPERVISOR -DCONFIG_MACH_APPROXIMATE_TIME
OSFMK_MACHINE=x86_64
#
# Mach Operating System
# Copyright (c) 1986 Carnegie-Mellon University
# All rights reserved.  The CMU software License Agreement specifies
# the terms and conditions for use and redistribution.
#

export MakeInc_cmd=${SRCROOT}/makedefs/MakeInc.cmd
export MakeInc_def=${SRCROOT}/makedefs/MakeInc.def
export MakeInc_rule=${SRCROOT}/makedefs/MakeInc.rule
export MakeInc_dir=${SRCROOT}/makedefs/MakeInc.dir

include $(MakeInc_cmd)
include $(MakeInc_def)

#
# CFLAGS
#
CFLAGS+= -include meta_features.h -DLIBSA_KERNEL_PRIVATE
SFLAGS+= -include meta_features.h

#
# Directories for mig generated files
#
COMP_SUBDIRS =

#
#  Make sure we don't remove this by accident if interrupted at the wrong
#  time.
#
.PRECIOUS: Makefile

#
#  Theses macros are filled in by the config program depending on the
#  current configuration.  The MACHDEP macro is replaced by the
#  contents of the machine dependent makefile template and the others
#  are replaced by the corresponding symbol definitions for the
#  configuration.
#

OBJS=bootstrap.cpo 

LIBOBJS=

CFILES=
COBJS=

CXXFILES=\
	$(SOURCE_DIR)/libsa/bootstrap.cpp 
CXXOBJS=bootstrap.cpo 

SFILES=
SOBJS=

######################################################################
#BEGIN	Machine dependent Makefile fragment for x86_64
######################################################################


# Bootstrap __KLD files must be Mach-O for "setsegname"
$(foreach file,$(OBJS),$(eval $(file)_CFLAGS_ADD += $(CFLAGS_NOLTO_FLAG)))

######################################################################
#END	Machine dependent Makefile fragment for x86_64
######################################################################

# Rebuild if per-file overrides change
${OBJS}: $(firstword $(MAKEFILE_LIST))

# Rebuild if global compile flags change
$(COBJS): .CFLAGS
.CFLAGS: ALWAYS
	$(_v)$(REPLACECONTENTS) $@ $(KCC) $(CFLAGS) $(INCFLAGS)
$(CXXOBJS): .CXXFLAGS
.CXXFLAGS: ALWAYS
	$(_v)$(REPLACECONTENTS) $@ $(KC++) $(CXXFLAGS) $(INCFLAGS)
$(SOBJS): .SFLAGS
.SFLAGS: ALWAYS
	$(_v)$(REPLACECONTENTS) $@ $(S_KCC) $(SFLAGS) $(INCFLAGS)

KLD_FILES = $(OBJS)

$(COMPONENT).filelist: $(OBJS)
	$(_v)for kld_file in ${KLD_FILES}; do      \
		$(SEG_HACK) -s __TEXT -n __KLD -o $${kld_file}__ $${kld_file} || exit 1; \
		mv $${kld_file}__ $${kld_file} || exit 1; \
		$(SEG_HACK) -i __KLD -n __KLDDATA -o $${kld_file}__ $${kld_file} || exit 1; \
		mv $${kld_file}__ $${kld_file} || exit 1; \
	done
	@$(LOG_LDFILELIST) "$(COMPONENT)"
	$(_v)for obj in ${OBJS}; do	\
		 $(ECHO) $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done > $(COMPONENT).filelist

$(COMPONENT).libfilelist: $(LIBOBJS)
	@$(LOG_LDFILELIST) "lib$(COMPONENT)"
	$(_v)for obj in ${LIBOBJS}; do	\
		 $(ECHO) $(TARGET)/$(CURRENT_KERNEL_CONFIG)/$${obj}; \
	done > $(COMPONENT).libfilelist


ifeq ($(RC_ProjectName),xnu_libraries)
do_all: $(COMPONENT).libfilelist
else
do_all: $(COMPONENT).filelist
endif

do_build_all:: do_all

-include bootstrap.cpd
bootstrap.cpo: $(SOURCE_DIR)/libsa/bootstrap.cpp
	${P_RULE_0}
	${P_RULE_1A} $(SOURCE_DIR)/libsa/${P_RULE_1B}
	${P_RULE_2}
	${P_RULE_3}
	$(if ${P_RULE_4A},${P_RULE_4A}$(SOURCE_DIR)/libsa/${P_RULE_4B})

include $(MakeInc_rule)
include $(MakeInc_dir)

# the KLD segment is mapped read-only on arm, so if we include llvm profiling
# here it will segfault the kernel.  (see arm_vm_init.c) We don't currently have
# a way of retrieving these counters from KLD anyway, so there's no harm in just
# disabling them.
CXXFLAGS_GEN:=$(filter-out -fprofile-instr-generate,$(CXXFLAGS_GEN))
CFLAGS_GEN:=$(filter-out -fprofile-instr-generate,$(CFLAGS_GEN))
