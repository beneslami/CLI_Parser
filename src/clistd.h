#ifndef CLISTD_H
#define CLISTD_H

#include "libcliid.h"

typedef struct leaf left_t;
typedef struct _param_t_ param_t;
typedef struct serialized_buffer ser_buff_t;
typedef enum{
  VALIDATION_FAILED = -1,
  VALIDATION_SUCCESS
}CLI_VAL_RC;

/* Default Validation handlers for Data types */
CLI_VAL_RC
int_validation_handler(leaf_t*, char*);
CLI_VAL_RC
string_validation_handler(leaf_t*, char*);
CLI_VAL_RC
ipv4_validation_handler(leaf_t*, char*);
CLI_VAL_RC
ipv6_validation_handler(leaf_t*, char*);
CLI_VAL_RC
float_validation_handler(leaf_t*, char*);
CLI_VAL_RC
boolean_validation_handler(leaf_t*, char*);

/* Default command handler */
int
config_console_name_handler(param_t*, ser_buff_t*, op_mode);
int
repeat_last_command(param_t*, ser_buff_t*, op_mode);
int
mode_enter_callback(param_t*, ser_buff_t*, op_mode);
int
display_sub_options_callback(param_t*, ser_buff_t*, op_mode);
int
display_cmd_expansion_callback(param_t*, ser_buff_t*, op_mode);
int
show_history_callback(param_t*, ser_buff_t*, op_mode);
int
clear_screen_handler(param_t*, ser_buff_t*, op_mode);
int
exit_cmd_handler(param_t*, ser_buff_t*, op_mode);
int
end_cmd_handler(param_t*, ser_buff_t*, op_mode);
int
config_mode_enter_handler(param_t*, ser_buff_t*, op_mode);
int
negate_callback(param_t*, ser_buff_t*, op_mode);
int
supprotsave_handler(param_t*, ser_buff_t*, op_mode);
int
show_registered_cmd_handler(param_t*, ser_buff_t*, op_mode);
int
show_cmd_tree(param_t*, ser_buff_t*, op_mode);
void
record_command(char*, char*, unsigned int);
int
show_extension_param_handler(param_t*, ser_buff_t*, op_mode);
#endif
