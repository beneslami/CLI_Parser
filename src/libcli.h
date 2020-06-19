#ifndef LIBCLI_H
#define LIBCLI_H

#include "libcliid.h"
#include "cmd_hier.h"

void
init_libcli();

void
set_device_name(const char *);

/*import functions. These functions to be used to get access to
 * library global variables - the zero level command hooks */

param_t *
libcli_get_show_hook(void);
param_t *
libcli_get_debug_hook(void);
param_t *
libcli_get_debug_show_hook(void);
param_t *
libcli_get_config_hook(void);
param_t *
libcli_get_clear_hook(void);
param_t *
libcli_get_run_hook(void);
void
enable_show_extension_param_brief(param_t*);
void
set_param_cmd_code(param_t*, int);
/*See the definition of this fn to know about arguments*/
void
init_param(param_t*, param_type_t, char*, cmd_callback, user_validation_callback, leaf_type_t, char*, char*);
void
libcli_register_param(param_t*, param_t*);
void
libcli_register_display_callback(param_t*, display_possible_values_callback);
show_ext_t
get_show_extension_type(ser_buff_t*);
/*After this call, libcli_register_param MUST not be invoked on param*/
void
support_cmd_negation(param_t*);
void
dump_cmd_tree();
void
start_shell(void);
#define HIDE_PARAM(param_ptr)   ((param_ptr)->ishidden = 1)
#define IS_PARAM_HIDDEN(param_ptr)  ((param_ptr)->ishidden == 1)

#endif
