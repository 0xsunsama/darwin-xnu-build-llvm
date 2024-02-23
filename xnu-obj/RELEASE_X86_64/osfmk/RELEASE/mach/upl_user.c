/*
 * IDENTIFICATION:
 * stub generated by bootstrap_cmds-129
 * OPTIONS: 
 *	KernelUser
 */
#define	__MIG_check__Reply__upl_subsystem__ 1

#include "upl.h"

/* TODO: #include <mach/mach.h> */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
extern void mach_msg_destroy(mach_msg_header_t *);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifndef	mig_internal
#define	mig_internal	static __inline__
#endif	/* mig_internal */

#ifndef	mig_external
#define mig_external
#endif	/* mig_external */

#if	!defined(__MigTypeCheck) && defined(TypeCheck)
#define	__MigTypeCheck		TypeCheck	/* Legacy setting */
#endif	/* !defined(__MigTypeCheck) */

#if	!defined(__MigKernelSpecificCode) && defined(_MIG_KERNEL_SPECIFIC_CODE_)
#define	__MigKernelSpecificCode	_MIG_KERNEL_SPECIFIC_CODE_	/* Legacy setting */
#endif	/* !defined(__MigKernelSpecificCode) */

#ifndef	LimitCheck
#define	LimitCheck 0
#endif	/* LimitCheck */

#ifndef	min
#define	min(a,b)  ( ((a) < (b))? (a): (b) )
#endif	/* min */

#if !defined(_WALIGN_)
#define _WALIGN_(x) (((x) + 3) & ~3)
#endif /* !defined(_WALIGN_) */

#if !defined(_WALIGNSZ_)
#define _WALIGNSZ_(x) _WALIGN_(sizeof(x))
#endif /* !defined(_WALIGNSZ_) */

#ifndef	UseStaticTemplates
#define	UseStaticTemplates	0
#endif	/* UseStaticTemplates */

#ifndef MIG_SERVER_ROUTINE
#define MIG_SERVER_ROUTINE
#endif

#ifndef	__MachMsgErrorWithTimeout
#define	__MachMsgErrorWithTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_DATA: \
	case MACH_SEND_INVALID_DEST: \
	case MACH_SEND_INVALID_HEADER: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
		break; \
	case MACH_SEND_TIMED_OUT: \
	case MACH_RCV_TIMED_OUT: \
	default: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithTimeout */

#ifndef	__MachMsgErrorWithoutTimeout
#define	__MachMsgErrorWithoutTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_DATA: \
	case MACH_SEND_INVALID_DEST: \
	case MACH_SEND_INVALID_HEADER: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithoutTimeout */

#ifndef	__DeclareSendRpc
#define	__DeclareSendRpc(_NUM_, _NAME_)
#endif	/* __DeclareSendRpc */

#ifndef	__BeforeSendRpc
#define	__BeforeSendRpc(_NUM_, _NAME_)
#endif	/* __BeforeSendRpc */

#ifndef	__AfterSendRpc
#define	__AfterSendRpc(_NUM_, _NAME_)
#endif	/* __AfterSendRpc */

#ifndef	__DeclareSendSimple
#define	__DeclareSendSimple(_NUM_, _NAME_)
#endif	/* __DeclareSendSimple */

#ifndef	__BeforeSendSimple
#define	__BeforeSendSimple(_NUM_, _NAME_)
#endif	/* __BeforeSendSimple */

#ifndef	__AfterSendSimple
#define	__AfterSendSimple(_NUM_, _NAME_)
#endif	/* __AfterSendSimple */

#define msgh_request_port	msgh_remote_port
#define msgh_reply_port		msgh_local_port



#if ( __MigTypeCheck )
#if __MIG_check__Reply__upl_subsystem__
#if !defined(__MIG_check__Reply__upl_abort_t__defined)
#define __MIG_check__Reply__upl_abort_t__defined

mig_internal kern_return_t __MIG_check__Reply__upl_abort_t(__Reply__upl_abort_t *Out0P)
{

	typedef __Reply__upl_abort_t __Reply __attribute__((unused));
	if (Out0P->Head.msgh_id != 2150) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (Out0P->Head.msgh_request_port != MACH_PORT_NULL) {
		return MIG_TYPE_ERROR;
	}
#endif	/* __MigTypeCheck */
	{
		return Out0P->RetCode;
	}
}
#endif /* !defined(__MIG_check__Reply__upl_abort_t__defined) */
#endif /* __MIG_check__Reply__upl_subsystem__ */
#endif /* ( __MigTypeCheck ) */


/* Routine upl_abort */
mig_external kern_return_t upl_abort
(
	upl_t upl_object,
	integer_t abort_cond
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		integer_t abort_cond;
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_msg_trailer_t trailer;
	} Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__upl_abort_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__upl_abort_t__defined */

	__DeclareSendRpc(2050, "upl_abort")

	InP->NDR = NDR_record;

	InP->abort_cond = abort_cond;

	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = upl_object;
	InP->Head.msgh_id = 2050;
	InP->Head.msgh_reserved = 0;

	__BeforeSendRpc(2050, "upl_abort")
#if	(__MigKernelSpecificCode) || (_MIG_KERNELSPECIFIC_CODE_)
	msg_result = mach_msg_rpc_from_kernel(&InP->Head, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendRpc(2050, "upl_abort")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
	}
	if (msg_result != MACH_MSG_SUCCESS) {
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__upl_abort_t__defined)
	check_result = __MIG_check__Reply__upl_abort_t((__Reply__upl_abort_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS) {
#if	__MigKernelSpecificCode
		mach_msg_destroy_from_kernel(&Out0P->Head);
#endif	/* __MigKernelSpecificCode */
		{ return check_result; }
	}
#endif	/* defined(__MIG_check__Reply__upl_abort_t__defined) */

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck )
#if __MIG_check__Reply__upl_subsystem__
#if !defined(__MIG_check__Reply__upl_abort_range_t__defined)
#define __MIG_check__Reply__upl_abort_range_t__defined

mig_internal kern_return_t __MIG_check__Reply__upl_abort_range_t(__Reply__upl_abort_range_t *Out0P)
{

	typedef __Reply__upl_abort_range_t __Reply __attribute__((unused));
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 2151) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (Out0P->Head.msgh_request_port != MACH_PORT_NULL) {
		return MIG_TYPE_ERROR;
	}
#endif	/* __MigTypeCheck */
	if (Out0P->RetCode != KERN_SUCCESS) {
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__upl_abort_range_t__defined) */
#endif /* __MIG_check__Reply__upl_subsystem__ */
#endif /* ( __MigTypeCheck ) */


/* Routine upl_abort_range */
mig_external kern_return_t upl_abort_range
(
	upl_t upl_object,
	upl_offset_t offset,
	upl_size_t size,
	integer_t abort_cond,
	boolean_t *empty
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		upl_offset_t offset;
		upl_size_t size;
		integer_t abort_cond;
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		boolean_t empty;
		mach_msg_trailer_t trailer;
	} Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		boolean_t empty;
	} __Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
		Reply Out;
	} Mess;

	Request *InP = &Mess.In;
	Reply *Out0P = &Mess.Out;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__upl_abort_range_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__upl_abort_range_t__defined */

	__DeclareSendRpc(2051, "upl_abort_range")

	InP->NDR = NDR_record;

	InP->offset = offset;

	InP->size = size;

	InP->abort_cond = abort_cond;

	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = upl_object;
	InP->Head.msgh_id = 2051;
	InP->Head.msgh_reserved = 0;

	__BeforeSendRpc(2051, "upl_abort_range")
#if	(__MigKernelSpecificCode) || (_MIG_KERNELSPECIFIC_CODE_)
	msg_result = mach_msg_rpc_from_kernel(&InP->Head, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendRpc(2051, "upl_abort_range")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
	}
	if (msg_result != MACH_MSG_SUCCESS) {
		{ return msg_result; }
	}


#if	defined(__MIG_check__Reply__upl_abort_range_t__defined)
	check_result = __MIG_check__Reply__upl_abort_range_t((__Reply__upl_abort_range_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS) {
#if	__MigKernelSpecificCode
		mach_msg_destroy_from_kernel(&Out0P->Head);
#endif	/* __MigKernelSpecificCode */
		{ return check_result; }
	}
#endif	/* defined(__MIG_check__Reply__upl_abort_range_t__defined) */

	*empty = Out0P->empty;

	return KERN_SUCCESS;
}

#if ( __MigTypeCheck )
#if __MIG_check__Reply__upl_subsystem__
#if !defined(__MIG_check__Reply__upl_commit_t__defined)
#define __MIG_check__Reply__upl_commit_t__defined

mig_internal kern_return_t __MIG_check__Reply__upl_commit_t(__Reply__upl_commit_t *Out0P)
{

	typedef __Reply__upl_commit_t __Reply __attribute__((unused));
	if (Out0P->Head.msgh_id != 2152) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    (Out0P->Head.msgh_size != (mach_msg_size_t)sizeof(__Reply)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (Out0P->Head.msgh_request_port != MACH_PORT_NULL) {
		return MIG_TYPE_ERROR;
	}
#endif	/* __MigTypeCheck */
	{
		kern_return_t ReturnValue;
		ReturnValue = Out0P->RetCode;
		return ReturnValue;
	}
}
#endif /* !defined(__MIG_check__Reply__upl_commit_t__defined) */
#endif /* __MIG_check__Reply__upl_subsystem__ */
#endif /* ( __MigTypeCheck ) */


/* Routine upl_commit */
mig_external kern_return_t upl_commit
(
	upl_t upl_object,
	upl_page_info_array_t page_list,
	mach_msg_type_number_t page_listCnt
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_msg_type_number_t page_listCnt;
		upl_page_info_t page_list[256];
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_msg_trailer_t trailer;
	} Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union upl_commitMessU {
		Request In;
		Reply Out;
	} *Mess = (union upl_commitMessU *) mig_user_allocate(sizeof(*Mess));

	Request *InP = &Mess->In;
	Reply *Out0P = &Mess->Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;

#ifdef	__MIG_check__Reply__upl_commit_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__upl_commit_t__defined */

	__DeclareSendRpc(2052, "upl_commit")

	InP->NDR = NDR_record;

	if (page_listCnt > 256) {
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->page_list, (const char *) page_list, 8 * page_listCnt);

	InP->page_listCnt = page_listCnt;

	msgh_size = (mach_msg_size_t)(sizeof(Request) - 2048) + ((8 * page_listCnt));
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = upl_object;
	InP->Head.msgh_id = 2052;
	InP->Head.msgh_reserved = 0;

	__BeforeSendRpc(2052, "upl_commit")
#if	(__MigKernelSpecificCode) || (_MIG_KERNELSPECIFIC_CODE_)
	msg_result = mach_msg_rpc_from_kernel(&InP->Head, msgh_size, (mach_msg_size_t)sizeof(Reply));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendRpc(2052, "upl_commit")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
	}
	if (msg_result != MACH_MSG_SUCCESS) {
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return msg_result; }
	}


#if	defined(__MIG_check__Reply__upl_commit_t__defined)
	check_result = __MIG_check__Reply__upl_commit_t((__Reply__upl_commit_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS) {
#if	__MigKernelSpecificCode
		mach_msg_destroy_from_kernel(&Out0P->Head);
#endif	/* __MigKernelSpecificCode */
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return check_result; }
	}
#endif	/* defined(__MIG_check__Reply__upl_commit_t__defined) */

	{ mig_user_deallocate((char *) Mess, sizeof(*Mess)); return KERN_SUCCESS; }
}

#if ( __MigTypeCheck )
#if __MIG_check__Reply__upl_subsystem__
#if !defined(__MIG_check__Reply__upl_commit_range_t__defined)
#define __MIG_check__Reply__upl_commit_range_t__defined

mig_internal kern_return_t __MIG_check__Reply__upl_commit_range_t(__Reply__upl_commit_range_t *Out0P)
{

	typedef __Reply__upl_commit_range_t __Reply __attribute__((unused));
#if	__MigTypeCheck
	unsigned int msgh_size;
#endif	/* __MigTypeCheck */
	if (Out0P->Head.msgh_id != 2153) {
	    if (Out0P->Head.msgh_id == MACH_NOTIFY_SEND_ONCE)
		{ return MIG_SERVER_DIED; }
	    else
		{ return MIG_REPLY_MISMATCH; }
	}

#if	__MigTypeCheck
	msgh_size = Out0P->Head.msgh_size;

	if ((Out0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) ||
	    ((msgh_size != (mach_msg_size_t)sizeof(__Reply)) &&
	     (msgh_size != (mach_msg_size_t)sizeof(mig_reply_error_t) ||
	      Out0P->RetCode == KERN_SUCCESS)))
		{ return MIG_TYPE_ERROR ; }
#endif	/* __MigTypeCheck */

#if	__MigTypeCheck
	if (Out0P->Head.msgh_request_port != MACH_PORT_NULL) {
		return MIG_TYPE_ERROR;
	}
#endif	/* __MigTypeCheck */
	if (Out0P->RetCode != KERN_SUCCESS) {
		return ((mig_reply_error_t *)Out0P)->RetCode;
	}

	return MACH_MSG_SUCCESS;
}
#endif /* !defined(__MIG_check__Reply__upl_commit_range_t__defined) */
#endif /* __MIG_check__Reply__upl_subsystem__ */
#endif /* ( __MigTypeCheck ) */


/* Routine upl_commit_range */
mig_external kern_return_t upl_commit_range
(
	upl_t upl_object,
	upl_offset_t offset,
	upl_size_t size,
	integer_t cntrl_flags,
	upl_page_info_array_t page_list,
	mach_msg_type_number_t page_listCnt,
	boolean_t *empty
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		upl_offset_t offset;
		upl_size_t size;
		integer_t cntrl_flags;
		mach_msg_type_number_t page_listCnt;
		upl_page_info_t page_list[256];
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		boolean_t empty;
		mach_msg_trailer_t trailer;
	} Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		boolean_t empty;
	} __Reply __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union upl_commit_rangeMessU {
		Request In;
		Reply Out;
	} *Mess = (union upl_commit_rangeMessU *) mig_user_allocate(sizeof(*Mess));

	Request *InP = &Mess->In;
	Reply *Out0P = &Mess->Out;

	mach_msg_return_t msg_result;
	unsigned int msgh_size;

#ifdef	__MIG_check__Reply__upl_commit_range_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__upl_commit_range_t__defined */

	__DeclareSendRpc(2053, "upl_commit_range")

	InP->NDR = NDR_record;

	InP->offset = offset;

	InP->size = size;

	InP->cntrl_flags = cntrl_flags;

	if (page_listCnt > 256) {
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return MIG_ARRAY_TOO_LARGE; }
	}
	(void)memcpy((char *) InP->page_list, (const char *) page_list, 8 * page_listCnt);

	InP->page_listCnt = page_listCnt;

	msgh_size = (mach_msg_size_t)(sizeof(Request) - 2048) + ((8 * page_listCnt));
	InP->Head.msgh_reply_port = mig_get_reply_port();
	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, MACH_MSG_TYPE_MAKE_SEND_ONCE);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = upl_object;
	InP->Head.msgh_id = 2053;
	InP->Head.msgh_reserved = 0;

	__BeforeSendRpc(2053, "upl_commit_range")
#if	(__MigKernelSpecificCode) || (_MIG_KERNELSPECIFIC_CODE_)
	msg_result = mach_msg_rpc_from_kernel(&InP->Head, msgh_size, (mach_msg_size_t)sizeof(Reply));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_RCV_MSG|MACH_MSG_OPTION_NONE, msgh_size, (mach_msg_size_t)sizeof(Reply), InP->Head.msgh_reply_port, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendRpc(2053, "upl_commit_range")
	if (msg_result != MACH_MSG_SUCCESS) {
		__MachMsgErrorWithoutTimeout(msg_result);
	}
	if (msg_result != MACH_MSG_SUCCESS) {
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return msg_result; }
	}


#if	defined(__MIG_check__Reply__upl_commit_range_t__defined)
	check_result = __MIG_check__Reply__upl_commit_range_t((__Reply__upl_commit_range_t *)Out0P);
	if (check_result != MACH_MSG_SUCCESS) {
#if	__MigKernelSpecificCode
		mach_msg_destroy_from_kernel(&Out0P->Head);
#endif	/* __MigKernelSpecificCode */
		{ mig_user_deallocate((char *) Mess, (mach_msg_size_t)sizeof(*Mess)); return check_result; }
	}
#endif	/* defined(__MIG_check__Reply__upl_commit_range_t__defined) */

	*empty = Out0P->empty;

	{ mig_user_deallocate((char *) Mess, sizeof(*Mess)); return KERN_SUCCESS; }
}
