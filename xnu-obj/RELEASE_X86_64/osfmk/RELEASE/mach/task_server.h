#ifndef	_task_server_
#define	_task_server_

/* Module task */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>
	
/* BEGIN MIG_STRNCPY_ZEROFILL CODE */

#if defined(__has_include)
#if __has_include(<mach/mig_strncpy_zerofill_support.h>)
#ifndef USING_MIG_STRNCPY_ZEROFILL
#define USING_MIG_STRNCPY_ZEROFILL
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS_CSTRING_ATTR
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS_CSTRING_COUNTEDBY_ATTR(C) __unsafe_indexable
#endif
	extern int mig_strncpy_zerofill(char * dest, const char * src, int len) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif /* __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__ */
#endif /* __has_include(<mach/mig_strncpy_zerofill_support.h>) */
#endif /* __has_include */
	
/* END MIG_STRNCPY_ZEROFILL CODE */


#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            * name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	task_MSG_COUNT
#define	task_MSG_COUNT	65
#endif	/* task_MSG_COUNT */

#include <Availability.h>
#include <mach/std_types.h>
#include <mach/mig.h>
#include <ipc/ipc_voucher.h>
#include <kern/ipc_kobject.h>
#include <kern/ipc_tt.h>
#include <kern/ipc_host.h>
#include <kern/ledger.h>
#include <kern/processor.h>
#include <kern/sync_sema.h>
#include <ipc/ipc_eventlink.h>
#include <vm/memory_object.h>
#include <vm/vm_map.h>
#include <kern/arcade.h>
#include <kern/ipc_mig.h>
#include <kern/task_ident.h>
#include <kern/kern_cdata.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <mach_debug/mach_debug_types.h>

#ifdef __BeforeMigServerHeader
__BeforeMigServerHeader
#endif /* __BeforeMigServerHeader */

#ifndef MIG_SERVER_ROUTINE
#define MIG_SERVER_ROUTINE
#endif


/* Routine task_terminate */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_terminate
(
	task_t target_task
);

/* Routine task_threads_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_threads_from_user
(
	mach_port_t port,
	thread_act_array_t *act_list,
	mach_msg_type_number_t *act_listCnt
);

/* Routine mach_ports_register */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t mach_ports_register
(
	task_t target_task,
	mach_port_array_t init_port_set,
	mach_msg_type_number_t init_port_setCnt
);

/* Routine mach_ports_lookup */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t mach_ports_lookup
(
	task_t target_task,
	mach_port_array_t *init_port_set,
	mach_msg_type_number_t *init_port_setCnt
);

/* Routine task_info_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_info_from_user
(
	mach_port_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_out,
	mach_msg_type_number_t *task_info_outCnt
);

/* Routine task_set_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_info
(
	task_t target_task,
	task_flavor_t flavor,
	task_info_t task_info_in,
	mach_msg_type_number_t task_info_inCnt
);

/* Routine task_suspend */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_suspend
(
	task_read_t target_task
);

/* Routine task_resume */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_resume
(
	task_read_t target_task
);

/* Routine task_get_special_port_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_special_port_from_user
(
	mach_port_t port,
	int which_port,
	mach_port_t *special_port
);

/* Routine task_set_special_port_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_special_port_from_user
(
	task_t task,
	int which_port,
	mach_port_t special_port
);

/* Routine thread_create_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t thread_create_from_user
(
	task_t parent_task,
	thread_act_t *child_act
);

/* Routine thread_create_running_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t thread_create_running_from_user
(
	task_t parent_task,
	thread_state_flavor_t flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt,
	thread_act_t *child_act
);

/* Routine task_set_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor
);

/* Routine task_get_exception_ports_from_user */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_exception_ports_from_user
(
	mach_port_t port,
	exception_mask_t exception_mask,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlers,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine task_swap_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_swap_exception_ports
(
	task_t task,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlers,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine semaphore_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t semaphore_create
(
	task_t task,
	semaphore_t *semaphore,
	int policy,
	int value
);

/* Routine semaphore_destroy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t semaphore_destroy
(
	task_t task,
	semaphore_t semaphore
);

/* Routine task_policy_set */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_policy_set
(
	task_policy_set_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t policy_infoCnt
);

/* Routine task_policy_get */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_policy_get
(
	task_policy_get_t task,
	task_policy_flavor_t flavor,
	task_policy_t policy_info,
	mach_msg_type_number_t *policy_infoCnt,
	boolean_t *get_default
);

/* Routine task_get_state */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_state
(
	task_read_t task,
	thread_state_flavor_t flavor,
	thread_state_t old_state,
	mach_msg_type_number_t *old_stateCnt
);

/* Routine task_set_state */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_state
(
	task_t task,
	thread_state_flavor_t flavor,
	thread_state_t new_state,
	mach_msg_type_number_t new_stateCnt
);

/* Routine task_set_phys_footprint_limit */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_phys_footprint_limit
(
	task_t task,
	int new_limit,
	int *old_limit
);

/* Routine task_suspend2_mig */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_suspend2_mig
(
	task_read_t target_task,
	task_suspension_token_t *suspend_token
);

/* Routine task_resume2_mig */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_resume2_mig
(
	task_suspension_token_t suspend_token
);

/* Routine task_purgable_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_purgable_info
(
	task_inspect_t task,
	task_purgable_info_t *stats
);

/* Routine task_get_mach_voucher */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_mach_voucher
(
	task_read_t task,
	mach_voucher_selector_t which,
	ipc_voucher_t *voucher
);

/* Routine task_set_mach_voucher */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_mach_voucher
(
	task_t task,
	ipc_voucher_t voucher
);

/* Routine task_swap_mach_voucher */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_swap_mach_voucher
(
	task_t task,
	ipc_voucher_t new_voucher,
	ipc_voucher_t *old_voucher
);

/* Routine task_generate_corpse */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_generate_corpse
(
	task_read_t task,
	mach_port_t *corpse_task_port
);

/* Routine task_map_corpse_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_map_corpse_info
(
	task_t task,
	task_read_t corspe_task,
	vm_address_t *kcd_addr_begin,
	uint32_t *kcd_size
);

/* Routine task_register_dyld_image_infos */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_register_dyld_image_infos
(
	task_t task,
	dyld_kernel_image_info_array_t dyld_images,
	mach_msg_type_number_t dyld_imagesCnt
);

/* Routine task_unregister_dyld_image_infos */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_unregister_dyld_image_infos
(
	task_t task,
	dyld_kernel_image_info_array_t dyld_images,
	mach_msg_type_number_t dyld_imagesCnt
);

/* Routine task_get_dyld_image_infos */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_dyld_image_infos
(
	task_read_t task,
	dyld_kernel_image_info_array_t *dyld_images,
	mach_msg_type_number_t *dyld_imagesCnt
);

/* Routine task_register_dyld_shared_cache_image_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_register_dyld_shared_cache_image_info
(
	task_t task,
	dyld_kernel_image_info_t dyld_cache_image,
	boolean_t no_cache,
	boolean_t private_cache
);

/* Routine task_register_dyld_set_dyld_state */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_register_dyld_set_dyld_state
(
	task_t task,
	uint8_t dyld_state
);

/* Routine task_register_dyld_get_process_state */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_register_dyld_get_process_state
(
	task_t task,
	dyld_kernel_process_info_t *dyld_process_state
);

/* Routine task_map_corpse_info_64 */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_map_corpse_info_64
(
	task_t task,
	task_read_t corspe_task,
	mach_vm_address_t *kcd_addr_begin,
	mach_vm_size_t *kcd_size
);

/* Routine task_inspect */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_inspect
(
	task_inspect_t task,
	task_inspect_flavor_t flavor,
	task_inspect_info_t info_out,
	mach_msg_type_number_t *info_outCnt
);

/* Routine task_get_exc_guard_behavior */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_exc_guard_behavior
(
	task_inspect_t task,
	task_exc_guard_behavior_t *behavior
);

/* Routine task_set_exc_guard_behavior */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_exc_guard_behavior
(
	task_t task,
	task_exc_guard_behavior_t behavior
);

/* Routine mach_task_is_self */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t mach_task_is_self
(
	task_name_t task,
	boolean_t *is_self
);

/* Routine task_dyld_process_info_notify_register */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_dyld_process_info_notify_register
(
	task_read_t target_task,
	mach_port_t notify
);

/* Routine task_create_identity_token */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_create_identity_token
(
	task_t task,
	task_id_token_t *token
);

/* Routine task_identity_token_get_task_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_identity_token_get_task_port
(
	task_id_token_t token,
	task_flavor_t flavor,
	mach_port_t *task_port
);

/* Routine task_dyld_process_info_notify_deregister */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_dyld_process_info_notify_deregister
(
	task_read_t target_task,
	mach_port_name_t notify
);

/* Routine task_get_exception_ports_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_get_exception_ports_info
(
	mach_port_t port,
	exception_mask_t exception_mask,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_info_array_t old_handlers_info,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine task_test_sync_upcall */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_test_sync_upcall
(
	task_t task,
	mach_port_t port
);

/* Routine task_set_corpse_forking_behavior */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_set_corpse_forking_behavior
(
	task_t task,
	task_corpse_forking_behavior_t behavior
);

/* Routine task_test_async_upcall_propagation */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_test_async_upcall_propagation
(
	task_t task,
	mach_port_t port,
	int qos,
	int iotier
);

/* Routine task_map_kcdata_object_64 */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t task_map_kcdata_object_64
(
	task_t task,
	kcdata_object_t kcdata_object,
	mach_vm_address_t *kcd_addr_begin,
	mach_vm_size_t *kcd_size
);

#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
boolean_t task_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
mig_routine_t task_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
extern const struct task_subsystem {
	mig_server_routine_t	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/* Array of routine descriptors */
		routine[65];
} task_subsystem;

/* typedefs for all requests */

#ifndef __Request__task_subsystem__defined
#define __Request__task_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_terminate_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_threads_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t init_port_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t init_port_setCnt;
	} __Request__mach_ports_register_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__mach_ports_lookup_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_outCnt;
	} __Request__task_info_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
		mach_msg_type_number_t task_info_inCnt;
		integer_t task_info_in[90];
	} __Request__task_set_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_suspend_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_resume_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int which_port;
	} __Request__task_get_special_port_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t special_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int which_port;
	} __Request__task_set_special_port_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__thread_create_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t new_stateCnt;
		natural_t new_state[1296];
	} __Request__thread_create_running_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__task_set_exception_ports_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
	} __Request__task_get_exception_ports_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__task_swap_exception_ports_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int policy;
		int value;
	} __Request__semaphore_create_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t semaphore;
		/* end of the kernel processed data */
	} __Request__semaphore_destroy_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		integer_t policy_info[16];
	} __Request__task_policy_set_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_policy_flavor_t flavor;
		mach_msg_type_number_t policy_infoCnt;
		boolean_t get_default;
	} __Request__task_policy_get_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t old_stateCnt;
	} __Request__task_get_state_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		thread_state_flavor_t flavor;
		mach_msg_type_number_t new_stateCnt;
		natural_t new_state[1296];
	} __Request__task_set_state_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int new_limit;
	} __Request__task_set_phys_footprint_limit_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_suspend2_mig_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_resume2_mig_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_purgable_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_voucher_selector_t which;
	} __Request__task_get_mach_voucher_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t voucher;
		/* end of the kernel processed data */
	} __Request__task_set_mach_voucher_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_voucher;
		mach_msg_port_descriptor_t old_voucher;
		/* end of the kernel processed data */
	} __Request__task_swap_mach_voucher_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_generate_corpse_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t corspe_task;
		/* end of the kernel processed data */
	} __Request__task_map_corpse_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t dyld_images;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dyld_imagesCnt;
	} __Request__task_register_dyld_image_infos_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t dyld_images;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dyld_imagesCnt;
	} __Request__task_unregister_dyld_image_infos_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_get_dyld_image_infos_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		dyld_kernel_image_info_t dyld_cache_image;
		boolean_t no_cache;
		boolean_t private_cache;
	} __Request__task_register_dyld_shared_cache_image_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		uint8_t dyld_state;
		char dyld_statePad[3];
	} __Request__task_register_dyld_set_dyld_state_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_register_dyld_get_process_state_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t corspe_task;
		/* end of the kernel processed data */
	} __Request__task_map_corpse_info_64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_inspect_flavor_t flavor;
		mach_msg_type_number_t info_outCnt;
	} __Request__task_inspect_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_get_exc_guard_behavior_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_exc_guard_behavior_t behavior;
	} __Request__task_set_exc_guard_behavior_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__mach_task_is_self_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t notify;
		/* end of the kernel processed data */
	} __Request__task_dyld_process_info_notify_register_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__task_create_identity_token_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_flavor_t flavor;
	} __Request__task_identity_token_get_task_port_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		mach_port_name_t notify;
	} __Request__task_dyld_process_info_notify_deregister_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
	} __Request__task_get_exception_ports_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t port;
		/* end of the kernel processed data */
	} __Request__task_test_sync_upcall_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		task_corpse_forking_behavior_t behavior;
	} __Request__task_set_corpse_forking_behavior_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int qos;
		int iotier;
	} __Request__task_test_async_upcall_propagation_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t kcdata_object;
		/* end of the kernel processed data */
	} __Request__task_map_kcdata_object_64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Request__task_subsystem__defined */


/* union of all requests */

#ifndef __RequestUnion__task_subsystem__defined
#define __RequestUnion__task_subsystem__defined
union __RequestUnion__task_subsystem {
	__Request__task_terminate_t Request_task_terminate;
	__Request__task_threads_from_user_t Request_task_threads_from_user;
	__Request__mach_ports_register_t Request_mach_ports_register;
	__Request__mach_ports_lookup_t Request_mach_ports_lookup;
	__Request__task_info_from_user_t Request_task_info_from_user;
	__Request__task_set_info_t Request_task_set_info;
	__Request__task_suspend_t Request_task_suspend;
	__Request__task_resume_t Request_task_resume;
	__Request__task_get_special_port_from_user_t Request_task_get_special_port_from_user;
	__Request__task_set_special_port_from_user_t Request_task_set_special_port_from_user;
	__Request__thread_create_from_user_t Request_thread_create_from_user;
	__Request__thread_create_running_from_user_t Request_thread_create_running_from_user;
	__Request__task_set_exception_ports_t Request_task_set_exception_ports;
	__Request__task_get_exception_ports_from_user_t Request_task_get_exception_ports_from_user;
	__Request__task_swap_exception_ports_t Request_task_swap_exception_ports;
	__Request__semaphore_create_t Request_semaphore_create;
	__Request__semaphore_destroy_t Request_semaphore_destroy;
	__Request__task_policy_set_t Request_task_policy_set;
	__Request__task_policy_get_t Request_task_policy_get;
	__Request__task_get_state_t Request_task_get_state;
	__Request__task_set_state_t Request_task_set_state;
	__Request__task_set_phys_footprint_limit_t Request_task_set_phys_footprint_limit;
	__Request__task_suspend2_mig_t Request_task_suspend2_mig;
	__Request__task_resume2_mig_t Request_task_resume2_mig;
	__Request__task_purgable_info_t Request_task_purgable_info;
	__Request__task_get_mach_voucher_t Request_task_get_mach_voucher;
	__Request__task_set_mach_voucher_t Request_task_set_mach_voucher;
	__Request__task_swap_mach_voucher_t Request_task_swap_mach_voucher;
	__Request__task_generate_corpse_t Request_task_generate_corpse;
	__Request__task_map_corpse_info_t Request_task_map_corpse_info;
	__Request__task_register_dyld_image_infos_t Request_task_register_dyld_image_infos;
	__Request__task_unregister_dyld_image_infos_t Request_task_unregister_dyld_image_infos;
	__Request__task_get_dyld_image_infos_t Request_task_get_dyld_image_infos;
	__Request__task_register_dyld_shared_cache_image_info_t Request_task_register_dyld_shared_cache_image_info;
	__Request__task_register_dyld_set_dyld_state_t Request_task_register_dyld_set_dyld_state;
	__Request__task_register_dyld_get_process_state_t Request_task_register_dyld_get_process_state;
	__Request__task_map_corpse_info_64_t Request_task_map_corpse_info_64;
	__Request__task_inspect_t Request_task_inspect;
	__Request__task_get_exc_guard_behavior_t Request_task_get_exc_guard_behavior;
	__Request__task_set_exc_guard_behavior_t Request_task_set_exc_guard_behavior;
	__Request__mach_task_is_self_t Request_mach_task_is_self;
	__Request__task_dyld_process_info_notify_register_t Request_task_dyld_process_info_notify_register;
	__Request__task_create_identity_token_t Request_task_create_identity_token;
	__Request__task_identity_token_get_task_port_t Request_task_identity_token_get_task_port;
	__Request__task_dyld_process_info_notify_deregister_t Request_task_dyld_process_info_notify_deregister;
	__Request__task_get_exception_ports_info_t Request_task_get_exception_ports_info;
	__Request__task_test_sync_upcall_t Request_task_test_sync_upcall;
	__Request__task_set_corpse_forking_behavior_t Request_task_set_corpse_forking_behavior;
	__Request__task_test_async_upcall_propagation_t Request_task_test_async_upcall_propagation;
	__Request__task_map_kcdata_object_64_t Request_task_map_kcdata_object_64;
};
#endif /* __RequestUnion__task_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__task_subsystem__defined
#define __Reply__task_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__task_terminate_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t act_list;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t act_listCnt;
	} __Reply__task_threads_from_user_t __attribute__((unused));
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
	} __Reply__mach_ports_register_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t init_port_set;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t init_port_setCnt;
	} __Reply__mach_ports_lookup_t __attribute__((unused));
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
		mach_msg_type_number_t task_info_outCnt;
		integer_t task_info_out[90];
	} __Reply__task_info_from_user_t __attribute__((unused));
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
	} __Reply__task_set_info_t __attribute__((unused));
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
	} __Reply__task_suspend_t __attribute__((unused));
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
	} __Reply__task_resume_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t special_port;
		/* end of the kernel processed data */
	} __Reply__task_get_special_port_from_user_t __attribute__((unused));
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
	} __Reply__task_set_special_port_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t child_act;
		/* end of the kernel processed data */
	} __Reply__thread_create_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t child_act;
		/* end of the kernel processed data */
	} __Reply__thread_create_running_from_user_t __attribute__((unused));
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
	} __Reply__task_set_exception_ports_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t old_handlers[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__task_get_exception_ports_from_user_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t old_handlers[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__task_swap_exception_ports_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t semaphore;
		/* end of the kernel processed data */
	} __Reply__semaphore_create_t __attribute__((unused));
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
	} __Reply__semaphore_destroy_t __attribute__((unused));
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
	} __Reply__task_policy_set_t __attribute__((unused));
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
		mach_msg_type_number_t policy_infoCnt;
		integer_t policy_info[16];
		boolean_t get_default;
	} __Reply__task_policy_get_t __attribute__((unused));
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
		mach_msg_type_number_t old_stateCnt;
		natural_t old_state[1296];
	} __Reply__task_get_state_t __attribute__((unused));
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
	} __Reply__task_set_state_t __attribute__((unused));
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
		int old_limit;
	} __Reply__task_set_phys_footprint_limit_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t suspend_token;
		/* end of the kernel processed data */
	} __Reply__task_suspend2_mig_t __attribute__((unused));
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
	} __Reply__task_resume2_mig_t __attribute__((unused));
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
		task_purgable_info_t stats;
	} __Reply__task_purgable_info_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t voucher;
		/* end of the kernel processed data */
	} __Reply__task_get_mach_voucher_t __attribute__((unused));
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
	} __Reply__task_set_mach_voucher_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t old_voucher;
		/* end of the kernel processed data */
	} __Reply__task_swap_mach_voucher_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t corpse_task_port;
		/* end of the kernel processed data */
	} __Reply__task_generate_corpse_t __attribute__((unused));
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
		vm_address_t kcd_addr_begin;
		uint32_t kcd_size;
	} __Reply__task_map_corpse_info_t __attribute__((unused));
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
	} __Reply__task_register_dyld_image_infos_t __attribute__((unused));
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
	} __Reply__task_unregister_dyld_image_infos_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t dyld_images;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dyld_imagesCnt;
	} __Reply__task_get_dyld_image_infos_t __attribute__((unused));
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
	} __Reply__task_register_dyld_shared_cache_image_info_t __attribute__((unused));
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
	} __Reply__task_register_dyld_set_dyld_state_t __attribute__((unused));
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
		dyld_kernel_process_info_t dyld_process_state;
	} __Reply__task_register_dyld_get_process_state_t __attribute__((unused));
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
		mach_vm_address_t kcd_addr_begin;
		mach_vm_size_t kcd_size;
	} __Reply__task_map_corpse_info_64_t __attribute__((unused));
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
		mach_msg_type_number_t info_outCnt;
		integer_t info_out[4];
	} __Reply__task_inspect_t __attribute__((unused));
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
		task_exc_guard_behavior_t behavior;
	} __Reply__task_get_exc_guard_behavior_t __attribute__((unused));
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
	} __Reply__task_set_exc_guard_behavior_t __attribute__((unused));
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
		boolean_t is_self;
	} __Reply__mach_task_is_self_t __attribute__((unused));
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
	} __Reply__task_dyld_process_info_notify_register_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t token;
		/* end of the kernel processed data */
	} __Reply__task_create_identity_token_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task_port;
		/* end of the kernel processed data */
	} __Reply__task_identity_token_get_task_port_t __attribute__((unused));
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
	} __Reply__task_dyld_process_info_notify_deregister_t __attribute__((unused));
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
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_handler_info_t old_handlers_info[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__task_get_exception_ports_info_t __attribute__((unused));
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
	} __Reply__task_test_sync_upcall_t __attribute__((unused));
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
	} __Reply__task_set_corpse_forking_behavior_t __attribute__((unused));
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
	} __Reply__task_test_async_upcall_propagation_t __attribute__((unused));
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
		mach_vm_address_t kcd_addr_begin;
		mach_vm_size_t kcd_size;
	} __Reply__task_map_kcdata_object_64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Reply__task_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__task_subsystem__defined
#define __ReplyUnion__task_subsystem__defined
union __ReplyUnion__task_subsystem {
	__Reply__task_terminate_t Reply_task_terminate;
	__Reply__task_threads_from_user_t Reply_task_threads_from_user;
	__Reply__mach_ports_register_t Reply_mach_ports_register;
	__Reply__mach_ports_lookup_t Reply_mach_ports_lookup;
	__Reply__task_info_from_user_t Reply_task_info_from_user;
	__Reply__task_set_info_t Reply_task_set_info;
	__Reply__task_suspend_t Reply_task_suspend;
	__Reply__task_resume_t Reply_task_resume;
	__Reply__task_get_special_port_from_user_t Reply_task_get_special_port_from_user;
	__Reply__task_set_special_port_from_user_t Reply_task_set_special_port_from_user;
	__Reply__thread_create_from_user_t Reply_thread_create_from_user;
	__Reply__thread_create_running_from_user_t Reply_thread_create_running_from_user;
	__Reply__task_set_exception_ports_t Reply_task_set_exception_ports;
	__Reply__task_get_exception_ports_from_user_t Reply_task_get_exception_ports_from_user;
	__Reply__task_swap_exception_ports_t Reply_task_swap_exception_ports;
	__Reply__semaphore_create_t Reply_semaphore_create;
	__Reply__semaphore_destroy_t Reply_semaphore_destroy;
	__Reply__task_policy_set_t Reply_task_policy_set;
	__Reply__task_policy_get_t Reply_task_policy_get;
	__Reply__task_get_state_t Reply_task_get_state;
	__Reply__task_set_state_t Reply_task_set_state;
	__Reply__task_set_phys_footprint_limit_t Reply_task_set_phys_footprint_limit;
	__Reply__task_suspend2_mig_t Reply_task_suspend2_mig;
	__Reply__task_resume2_mig_t Reply_task_resume2_mig;
	__Reply__task_purgable_info_t Reply_task_purgable_info;
	__Reply__task_get_mach_voucher_t Reply_task_get_mach_voucher;
	__Reply__task_set_mach_voucher_t Reply_task_set_mach_voucher;
	__Reply__task_swap_mach_voucher_t Reply_task_swap_mach_voucher;
	__Reply__task_generate_corpse_t Reply_task_generate_corpse;
	__Reply__task_map_corpse_info_t Reply_task_map_corpse_info;
	__Reply__task_register_dyld_image_infos_t Reply_task_register_dyld_image_infos;
	__Reply__task_unregister_dyld_image_infos_t Reply_task_unregister_dyld_image_infos;
	__Reply__task_get_dyld_image_infos_t Reply_task_get_dyld_image_infos;
	__Reply__task_register_dyld_shared_cache_image_info_t Reply_task_register_dyld_shared_cache_image_info;
	__Reply__task_register_dyld_set_dyld_state_t Reply_task_register_dyld_set_dyld_state;
	__Reply__task_register_dyld_get_process_state_t Reply_task_register_dyld_get_process_state;
	__Reply__task_map_corpse_info_64_t Reply_task_map_corpse_info_64;
	__Reply__task_inspect_t Reply_task_inspect;
	__Reply__task_get_exc_guard_behavior_t Reply_task_get_exc_guard_behavior;
	__Reply__task_set_exc_guard_behavior_t Reply_task_set_exc_guard_behavior;
	__Reply__mach_task_is_self_t Reply_mach_task_is_self;
	__Reply__task_dyld_process_info_notify_register_t Reply_task_dyld_process_info_notify_register;
	__Reply__task_create_identity_token_t Reply_task_create_identity_token;
	__Reply__task_identity_token_get_task_port_t Reply_task_identity_token_get_task_port;
	__Reply__task_dyld_process_info_notify_deregister_t Reply_task_dyld_process_info_notify_deregister;
	__Reply__task_get_exception_ports_info_t Reply_task_get_exception_ports_info;
	__Reply__task_test_sync_upcall_t Reply_task_test_sync_upcall;
	__Reply__task_set_corpse_forking_behavior_t Reply_task_set_corpse_forking_behavior;
	__Reply__task_test_async_upcall_propagation_t Reply_task_test_async_upcall_propagation;
	__Reply__task_map_kcdata_object_64_t Reply_task_map_kcdata_object_64;
};
#endif /* __ReplyUnion__task_subsystem__defined */

#ifndef subsystem_to_name_map_task
#define subsystem_to_name_map_task \
    { "task_terminate", 3401 },\
    { "task_threads_from_user", 3402 },\
    { "mach_ports_register", 3403 },\
    { "mach_ports_lookup", 3404 },\
    { "task_info_from_user", 3405 },\
    { "task_set_info", 3406 },\
    { "task_suspend", 3407 },\
    { "task_resume", 3408 },\
    { "task_get_special_port_from_user", 3409 },\
    { "task_set_special_port_from_user", 3410 },\
    { "thread_create_from_user", 3411 },\
    { "thread_create_running_from_user", 3412 },\
    { "task_set_exception_ports", 3413 },\
    { "task_get_exception_ports_from_user", 3414 },\
    { "task_swap_exception_ports", 3415 },\
    { "semaphore_create", 3418 },\
    { "semaphore_destroy", 3419 },\
    { "task_policy_set", 3420 },\
    { "task_policy_get", 3421 },\
    { "task_get_state", 3433 },\
    { "task_set_state", 3434 },\
    { "task_set_phys_footprint_limit", 3435 },\
    { "task_suspend2_mig", 3436 },\
    { "task_resume2_mig", 3437 },\
    { "task_purgable_info", 3438 },\
    { "task_get_mach_voucher", 3439 },\
    { "task_set_mach_voucher", 3440 },\
    { "task_swap_mach_voucher", 3441 },\
    { "task_generate_corpse", 3442 },\
    { "task_map_corpse_info", 3443 },\
    { "task_register_dyld_image_infos", 3444 },\
    { "task_unregister_dyld_image_infos", 3445 },\
    { "task_get_dyld_image_infos", 3446 },\
    { "task_register_dyld_shared_cache_image_info", 3447 },\
    { "task_register_dyld_set_dyld_state", 3448 },\
    { "task_register_dyld_get_process_state", 3449 },\
    { "task_map_corpse_info_64", 3450 },\
    { "task_inspect", 3451 },\
    { "task_get_exc_guard_behavior", 3452 },\
    { "task_set_exc_guard_behavior", 3453 },\
    { "mach_task_is_self", 3455 },\
    { "task_dyld_process_info_notify_register", 3456 },\
    { "task_create_identity_token", 3457 },\
    { "task_identity_token_get_task_port", 3458 },\
    { "task_dyld_process_info_notify_deregister", 3459 },\
    { "task_get_exception_ports_info", 3460 },\
    { "task_test_sync_upcall", 3461 },\
    { "task_set_corpse_forking_behavior", 3462 },\
    { "task_test_async_upcall_propagation", 3463 },\
    { "task_map_kcdata_object_64", 3464 }
#endif

#ifdef __AfterMigServerHeader
__AfterMigServerHeader
#endif /* __AfterMigServerHeader */

#endif	 /* _task_server_ */
