/*
 * Copyright 2015      Intel, Inc. All rights reserved
 */

#ifndef PMIX_RENAME_H
#define PMIX_RENAME_H

#include "pmix_config.h"


BEGIN_C_DECLS


/* Only enact these defines if we're actually renaming the symbols
   (i.e., avoid trying to have no-op defines if we're *not*
   renaming).

   Note that we don't symbol shift if we aren't in embedded mode
   as that wouldn't make any sense. If we are in embedded mode,
   then we aren't building the PMI-1/2 APIs as that also doesn't
   make any sense
*/

#if PMIX_SYM_TRANSFORM

/* Use a preprocessor two-step in order to get the prefixing right.
   Make 2 macros: PMIX_NAME and PMIX_NAME_CAPS for renaming
   things. */

#define PMIX_MUNGE_NAME(a, b) PMIX_MUNGE_NAME2(a, b)
#define PMIX_MUNGE_NAME2(a, b) a ## b
#define PMIX_NAME(name) PMIX_MUNGE_NAME(PMIX_SYM_PREFIX, pmix_ ## name)
#define PMIX_NAME_CAPS(name) PMIX_MUNGE_NAME(PMIX_SYM_PREFIX_CAPS, PMIx_ ## name)

/* Now define all the "real" names to be the prefixed names.  This
   allows us to use the real names throughout the code base (i.e.,
   "pmix_<foo>"); the preprocessor will adjust to have the prefixed
   name under the covers. */

/* PMIx APIs */
#define PMIx_Abort                              PMIX_NAME_CAPS(Abort)
#define PMIx_Commit                             PMIX_NAME_CAPS(Commit)
#define PMIx_Connect                            PMIX_NAME_CAPS(Connect)
#define PMIx_Connect_nb                         PMIX_NAME_CAPS(Connect_nb)
#define PMIx_Deregister_errhandler              PMIX_NAME_CAPS(Deregister_errhandler)
#define PMIx_Disconnect                         PMIX_NAME_CAPS(Disconnect)
#define PMIx_Disconnect_nb                      PMIX_NAME_CAPS(Disconnect_nb)
#define PMIx_Error_string                       PMIX_NAME_CAPS(Error_string)
#define PMIx_Fence                              PMIX_NAME_CAPS(Fence)
#define PMIx_Fence_nb                           PMIX_NAME_CAPS(Fence_nb)
#define PMIx_Finalize                           PMIX_NAME_CAPS(Finalize)
#define PMIx_Get                                PMIX_NAME_CAPS(Get)
#define PMIx_Get_nb                             PMIX_NAME_CAPS(Get_nb)
#define PMIx_Get_version                        PMIX_NAME_CAPS(Get_version)
#define PMIx_Init                               PMIX_NAME_CAPS(Init)
#define PMIx_Initialized                        PMIX_NAME_CAPS(Initialized)
#define PMIx_Lookup                             PMIX_NAME_CAPS(Lookup)
#define PMIx_Lookup_nb                          PMIX_NAME_CAPS(Lookup_nb)
#define PMIx_Publish                            PMIX_NAME_CAPS(Publish)
#define PMIx_Publish_nb                         PMIX_NAME_CAPS(Publish_nb)
#define PMIx_Put                                PMIX_NAME_CAPS(Put)
#define PMIx_Register_errhandler                PMIX_NAME_CAPS(Register_errhandler)
#define PMIx_Resolve_nodes                      PMIX_NAME_CAPS(Resolve_nodes)
#define PMIx_Resolve_peers                      PMIX_NAME_CAPS(Resolve_peers)
#define PMIx_Spawn                              PMIX_NAME_CAPS(Spawn)
#define PMIx_Spawn_nb                           PMIX_NAME_CAPS(Spawn_nb)
#define PMIx_Unpublish                          PMIX_NAME_CAPS(Unpublish)
#define PMIx_Unpublish_nb                       PMIX_NAME_CAPS(Unpublish_nb)


/* internal client functions */
#define pmix_client_process_nspace_blob         PMIX_NAME(client_process_nspace_blob)


/* src/util directory */
#define pmix_argv_append                        PMIX_NAME(argv_append)
#define pmix_argv_append_nosize                 PMIX_NAME(argv_append_nosize)
#define pmix_argv_append_unique_nosize          PMIX_NAME(argv_append_unique_nosize)
#define pmix_argv_copy                          PMIX_NAME(argv_copy)
#define pmix_argv_count                         PMIX_NAME(argv_count)
#define pmix_argv_delete                        PMIX_NAME(argv_delete)
#define pmix_argv_free                          PMIX_NAME(argv_free)
#define pmix_argv_insert                        PMIX_NAME(argv_insert)
#define pmix_argv_insert_element                PMIX_NAME(argv_insert_element)
#define pmix_argv_join                          PMIX_NAME(argv_join)
#define pmix_argv_join_range                    PMIX_NAME(argv_join_range)
#define pmix_argv_len                           PMIX_NAME(argv_len)
#define pmix_argv_prepend_nosize                PMIX_NAME(argv_prepend_nosize)
#define pmix_argv_split                         PMIX_NAME(argv_split)
#define pmix_argv_split_with_empty              PMIX_NAME(argv_split_with_empty)
#define pmix_asprintf                           PMIX_NAME(asprintf)
#define pmix_basename                           PMIX_NAME(basename)
#define pmix_bcopy_csum_partial                 PMIX_NAME(bcopy_csum_partial)
#define pmix_bcopy_uicrc_partial                PMIX_NAME(bcopy_uicrc_partial)
#define pmix_bcopy_uicsum_partial               PMIX_NAME(bcopy_uicsum_partial)
#define pmix_csum_partial                       PMIX_NAME(csum_partial)
#define pmix_dirname                            PMIX_NAME(dirname)
#define pmix_environ_merge                      PMIX_NAME(environ_merge)
#define pmix_errhandler_invoke                  PMIX_NAME(errhandler_invoke)
#define pmix_fd_read                            PMIX_NAME(fd_read)
#define pmix_fd_set_cloexec                     PMIX_NAME(fd_set_cloexec)
#define pmix_fd_write                           PMIX_NAME(fd_write)
#define pmix_home_directory                     PMIX_NAME(home_directory)
#define pmix_initialize_crc_table               PMIX_NAME(initialize_crc_table)
#define pmix_os_path                            PMIX_NAME(os_path)
#define pmix_output                             PMIX_NAME(output)
#define pmix_output_close                       PMIX_NAME(output_close)
#define pmix_output_finalize                    PMIX_NAME(output_finalize)
#define pmix_output_get_verbosity               PMIX_NAME(output_get_verbosity)
#define pmix_output_init                        PMIX_NAME(output_init)
#define pmix_output_open                        PMIX_NAME(output_open)
#define pmix_output_reopen                      PMIX_NAME(output_reopen)
#define pmix_output_reopen_all                  PMIX_NAME(output_reopen_all)
#define pmix_output_set_output_file_info        PMIX_NAME(output_set_output_file_info)
#define pmix_output_set_verbosity               PMIX_NAME(output_set_verbosity)
#define pmix_output_string                      PMIX_NAME(output_string)
#define pmix_output_switch                      PMIX_NAME(output_switch)
#define pmix_output_verbose                     PMIX_NAME(output_verbose)
#define pmix_output_vstring                     PMIX_NAME(output_vstring)
#define pmix_output_vverbose                    PMIX_NAME(output_vverbose)
#define pmix_setenv                             PMIX_NAME(setenv)
#define pmix_snprintf                           PMIX_NAME(snprintf)
#define pmix_start_progress_thread              PMIX_NAME(start_progress_thread)
#define pmix_stop_progress_thread               PMIX_NAME(stop_progress_thread)
#define pmix_tmp_directory                      PMIX_NAME(tmp_directory)
#define pmix_uicrc_partial                      PMIX_NAME(uicrc_partial)
#define pmix_uicsum_partial                     PMIX_NAME(uicsum_partial)
#define pmix_unsetenv                           PMIX_NAME(unsetenv)
#define pmix_vasprintf                          PMIX_NAME(vasprintf)
#define pmix_vsnprintf                          PMIX_NAME(vsnprintf)


/* buffer operations */
#define pmix_bfrop_buffer_extend                PMIX_NAME(bfrop_buffer_extend)
#define pmix_bfrop_close                        PMIX_NAME(bfrop_close)
#define pmix_bfrop_copy                         PMIX_NAME(bfrop_copy)
#define pmix_bfrop_copy_app                     PMIX_NAME(bfrop_copy_app)
#define pmix_bfrop_copy_array                   PMIX_NAME(bfrop_copy_array)
#define pmix_bfrop_copy_bo                      PMIX_NAME(bfrop_copy_bo)
#define pmix_bfrop_copy_buf                     PMIX_NAME(bfrop_copy_buf)
#define pmix_bfrop_copy_info                    PMIX_NAME(bfrop_copy_info)
#define pmix_bfrop_copy_kval                    PMIX_NAME(bfrop_copy_kval)
#define pmix_bfrop_copy_modex                   PMIX_NAME(bfrop_copy_modex)
#define pmix_bfrop_copy_payload                 PMIX_NAME(bfrop_copy_payload)
#define pmix_bfrop_copy_pdata                   PMIX_NAME(bfrop_copy_pdata)
#define pmix_bfrop_copy_persist                 PMIX_NAME(bfrop_copy_persist)
#define pmix_bfrop_copy_proc                    PMIX_NAME(bfrop_copy_proc)
#define pmix_bfrop_copy_string                  PMIX_NAME(bfrop_copy_string)
#define pmix_bfrop_copy_value                   PMIX_NAME(bfrop_copy_value)
#define pmix_bfrop_get_data_type                PMIX_NAME(bfrop_get_data_type)
#define pmix_bfrop_open                         PMIX_NAME(bfrop_open)
#define pmix_bfrop_pack                         PMIX_NAME(bfrop_pack)
#define pmix_bfrop_pack_app                     PMIX_NAME(bfrop_pack_app)
#define pmix_bfrop_pack_array                   PMIX_NAME(bfrop_pack_array)
#define pmix_bfrop_pack_bo                      PMIX_NAME(bfrop_pack_bo)
#define pmix_bfrop_pack_buf                     PMIX_NAME(bfrop_pack_buf)
#define pmix_bfrop_pack_buffer                  PMIX_NAME(bfrop_pack_buffer)
#define pmix_bfrop_pack_byte                    PMIX_NAME(bfrop_pack_byte)
#define pmix_bfrop_pack_datatype                PMIX_NAME(bfrop_pack_datatype)
#define pmix_bfrop_pack_double                  PMIX_NAME(bfrop_pack_double)
#define pmix_bfrop_pack_float                   PMIX_NAME(bfrop_pack_float)
#define pmix_bfrop_pack_info                    PMIX_NAME(bfrop_pack_info)
#define pmix_bfrop_pack_int                     PMIX_NAME(bfrop_pack_int)
#define pmix_bfrop_pack_int16                   PMIX_NAME(bfrop_pack_int16)
#define pmix_bfrop_pack_int32                   PMIX_NAME(bfrop_pack_int32)
#define pmix_bfrop_pack_int64                   PMIX_NAME(bfrop_pack_int64)
#define pmix_bfrop_pack_kval                    PMIX_NAME(bfrop_pack_kval)
#define pmix_bfrop_pack_modex                   PMIX_NAME(bfrop_pack_modex)
#define pmix_bfrop_pack_pdata                   PMIX_NAME(bfrop_pack_pdata)
#define pmix_bfrop_pack_persist                 PMIX_NAME(bfrop_pack_persist)
#define pmix_bfrop_pack_pid                     PMIX_NAME(bfrop_pack_pid)
#define pmix_bfrop_pack_proc                    PMIX_NAME(bfrop_pack_proc)
#define pmix_bfrop_pack_sizet                   PMIX_NAME(bfrop_pack_sizet)
#define pmix_bfrop_pack_string                  PMIX_NAME(bfrop_pack_string)
#define pmix_bfrop_pack_time                    PMIX_NAME(bfrop_pack_time)
#define pmix_bfrop_pack_timeval                 PMIX_NAME(bfrop_pack_timeval)
#define pmix_bfrop_pack_value                   PMIX_NAME(bfrop_pack_value)
#define pmix_bfrop_print                        PMIX_NAME(bfrop_print)
#define pmix_bfrop_print_app                    PMIX_NAME(bfrop_print_app)
#define pmix_bfrop_print_array                  PMIX_NAME(bfrop_print_array)
#define pmix_bfrop_print_bo                     PMIX_NAME(bfrop_print_bo)
#define pmix_bfrop_print_buf                    PMIX_NAME(bfrop_print_buf)
#define pmix_bfrop_print_byte                   PMIX_NAME(bfrop_print_byte)
#define pmix_bfrop_print_double                 PMIX_NAME(bfrop_print_double)
#define pmix_bfrop_print_float                  PMIX_NAME(bfrop_print_float)
#define pmix_bfrop_print_info                   PMIX_NAME(bfrop_print_info)
#define pmix_bfrop_print_int                    PMIX_NAME(bfrop_print_int)
#define pmix_bfrop_print_int16                  PMIX_NAME(bfrop_print_int16)
#define pmix_bfrop_print_int32                  PMIX_NAME(bfrop_print_int32)
#define pmix_bfrop_print_int64                  PMIX_NAME(bfrop_print_int64)
#define pmix_bfrop_print_int8                   PMIX_NAME(bfrop_print_int8)
#define pmix_bfrop_print_kval                   PMIX_NAME(bfrop_print_kval)
#define pmix_bfrop_print_modex                  PMIX_NAME(bfrop_print_modex)
#define pmix_bfrop_print_pdata                  PMIX_NAME(bfrop_print_pdata)
#define pmix_bfrop_print_persist                PMIX_NAME(bfrop_print_persist)
#define pmix_bfrop_print_pid                    PMIX_NAME(bfrop_print_pid)
#define pmix_bfrop_print_proc                   PMIX_NAME(bfrop_print_proc)
#define pmix_bfrop_print_size                   PMIX_NAME(bfrop_print_size)
#define pmix_bfrop_print_string                 PMIX_NAME(bfrop_print_string)
#define pmix_bfrop_print_time                   PMIX_NAME(bfrop_print_time)
#define pmix_bfrop_print_timeval                PMIX_NAME(bfrop_print_timeval)
#define pmix_bfrop_print_uint                   PMIX_NAME(bfrop_print_uint)
#define pmix_bfrop_print_uint16                 PMIX_NAME(bfrop_print_uint16)
#define pmix_bfrop_print_uint32                 PMIX_NAME(bfrop_print_uint32)
#define pmix_bfrop_print_uint64                 PMIX_NAME(bfrop_print_uint64)
#define pmix_bfrop_print_uint8                  PMIX_NAME(bfrop_print_uint8)
#define pmix_bfrop_print_value                  PMIX_NAME(bfrop_print_value)
#define pmix_bfrop_std_copy                     PMIX_NAME(bfrop_std_copy)
#define pmix_bfrop_store_data_type              PMIX_NAME(bfrop_store_data_type)
#define pmix_bfrop_too_small                    PMIX_NAME(bfrop_too_small)
#define pmix_bfrop_unpack                       PMIX_NAME(bfrop_unpack)
#define pmix_bfrop_unpack_app                   PMIX_NAME(bfrop_unpack_app)
#define pmix_bfrop_unpack_array                 PMIX_NAME(bfrop_unpack_array)
#define pmix_bfrop_unpack_bo                    PMIX_NAME(bfrop_unpack_bo)
#define pmix_bfrop_unpack_buf                   PMIX_NAME(bfrop_unpack_buf)
#define pmix_bfrop_unpack_buffer                PMIX_NAME(bfrop_unpack_buffer)
#define pmix_bfrop_unpack_byte                  PMIX_NAME(bfrop_unpack_byte)
#define pmix_bfrop_unpack_datatype              PMIX_NAME(bfrop_unpack_datatype)
#define pmix_bfrop_unpack_double                PMIX_NAME(bfrop_unpack_double)
#define pmix_bfrop_unpack_float                 PMIX_NAME(bfrop_unpack_float)
#define pmix_bfrop_unpack_info                  PMIX_NAME(bfrop_unpack_info)
#define pmix_bfrop_unpack_int                   PMIX_NAME(bfrop_unpack_int)
#define pmix_bfrop_unpack_int16                 PMIX_NAME(bfrop_unpack_int16)
#define pmix_bfrop_unpack_int32                 PMIX_NAME(bfrop_unpack_int32)
#define pmix_bfrop_unpack_int64                 PMIX_NAME(bfrop_unpack_int64)
#define pmix_bfrop_unpack_kval                  PMIX_NAME(bfrop_unpack_kval)
#define pmix_bfrop_unpack_modex                 PMIX_NAME(bfrop_unpack_modex)
#define pmix_bfrop_unpack_pdata                 PMIX_NAME(bfrop_unpack_pdata)
#define pmix_bfrop_unpack_persist               PMIX_NAME(bfrop_unpack_persist)
#define pmix_bfrop_unpack_pid                   PMIX_NAME(bfrop_unpack_pid)
#define pmix_bfrop_unpack_proc                  PMIX_NAME(bfrop_unpack_proc)
#define pmix_bfrop_unpack_sizet                 PMIX_NAME(bfrop_unpack_sizet)
#define pmix_bfrop_unpack_string                PMIX_NAME(bfrop_unpack_string)
#define pmix_bfrop_unpack_time                  PMIX_NAME(bfrop_unpack_time)
#define pmix_bfrop_unpack_timeval               PMIX_NAME(bfrop_unpack_timeval)
#define pmix_bfrop_unpack_value                 PMIX_NAME(bfrop_unpack_value)
#define pmix_value_load                         PMIX_NAME(value_load)
#define pmix_value_unload                       PMIX_NAME(value_unload)
#define pmix_value_xfer                         PMIX_NAME(value_xfer)


/* class system */
#define pmix_class_finalize                     PMIX_NAME(class_finalize)
#define pmix_class_initialize                   PMIX_NAME(class_initialize)
#define pmix_hash_fetch                         PMIX_NAME(hash_fetch)
#define pmix_hash_remove_data                   PMIX_NAME(hash_remove_data)
#define pmix_hash_store                         PMIX_NAME(hash_store)
#define pmix_hash_table_get_first_key_uint32    PMIX_NAME(hash_table_get_first_key_uint32)
#define pmix_hash_table_get_first_key_uint64    PMIX_NAME(hash_table_get_first_key_uint64)
#define pmix_hash_table_get_next_key_uint32     PMIX_NAME(hash_table_get_next_key_uint32)
#define pmix_hash_table_get_next_key_uint64     PMIX_NAME(hash_table_get_next_key_uint64)
#define pmix_hash_table_get_value_ptr           PMIX_NAME(hash_table_get_value_ptr)
#define pmix_hash_table_get_value_uint32        PMIX_NAME(hash_table_get_value_uint32)
#define pmix_hash_table_get_value_uint64        PMIX_NAME(hash_table_get_value_uint64)
#define pmix_hash_table_init                    PMIX_NAME(hash_table_init)
#define pmix_hash_table_remove_all              PMIX_NAME(hash_table_remove_all)
#define pmix_hash_table_remove_value_ptr        PMIX_NAME(hash_table_remove_value_ptr)
#define pmix_hash_table_remove_value_uint32     PMIX_NAME(hash_table_remove_value_uint32)
#define pmix_hash_table_remove_value_uint64     PMIX_NAME(hash_table_remove_value_uint64)
#define pmix_hash_table_set_value_ptr           PMIX_NAME(hash_table_set_value_ptr)
#define pmix_hash_table_set_value_uint32        PMIX_NAME(hash_table_set_value_uint32)
#define pmix_hash_table_set_value_uint64        PMIX_NAME(hash_table_set_value_uint64)
#define pmix_list_insert                        PMIX_NAME(list_insert)
#define pmix_list_join                          PMIX_NAME(list_join)
#define pmix_list_sort                          PMIX_NAME(list_sort)
#define pmix_list_splice                        PMIX_NAME(list_splice)
#define pmix_pointer_array_add                  PMIX_NAME(pointer_array_add)
#define pmix_pointer_array_init                 PMIX_NAME(pointer_array_init)
#define pmix_pointer_array_set_item             PMIX_NAME(pointer_array_set_item)
#define pmix_pointer_array_set_size             PMIX_NAME(pointer_array_set_size)
#define pmix_pointer_array_test_and_set_item    PMIX_NAME(pointer_array_test_and_set_item)


/* security system */
#define pmix_sec_finalize                       PMIX_NAME(sec_finalize)
#define pmix_sec_init                           PMIX_NAME(sec_init)


/* usock messaging system */
#define pmix_usock_finalize                     PMIX_NAME(usock_finalize)
#define pmix_usock_init                         PMIX_NAME(usock_init)
#define pmix_usock_process_msg                  PMIX_NAME(usock_process_msg)
#define pmix_usock_recv_blocking                PMIX_NAME(usock_recv_blocking)
#define pmix_usock_recv_handler                 PMIX_NAME(usock_recv_handler)
#define pmix_usock_send_blocking                PMIX_NAME(usock_send_blocking)
#define pmix_usock_send_handler                 PMIX_NAME(usock_send_handler)
#define pmix_usock_send_recv                    PMIX_NAME(usock_send_recv)
#define pmix_usock_set_blocking                 PMIX_NAME(usock_set_blocking)
#define pmix_usock_set_nonblocking              PMIX_NAME(usock_set_nonblocking)


#endif /* PMIX_SYM_TRANSFORM */

END_C_DECLS

#endif /* PMIX_RENAME_H */
