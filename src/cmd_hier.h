#ifndef CMD_HIER_H
#define CMD_HIER_H

#include "clistd.h"
#include "cliconst.h"
#include "libcliid.h"
#include <string.h>

typedef struct serialized_buffer ser_buff_t;
typedef int (*cmd_callback)(param_t*, ser_buff_t*, op_mode);
typedef int (*user_validatoin_callback)(char*);
typedef void (*display_possible_values_callback)(param_t*, ser_buff_t*);
typedef struct _param_t_ param_t;
typedef struct cmd{
  char cmd_name[CMD_NAME_SIZE];
}cmd_t;
typedef struct leaf{
  leaf_type_t leaf_type;
  char value_holder[LEAF_VALUE_HOLDER_SIZE];
  user_validation_callback user_validation_cb_fn;
  char leaf_id[LEAF_ID_SIZE];
}leaf_t;
typedef CLI_VAL_RC (*leaf_type_handler)(leaf_t*, char*);
typedef enum{
  CMD,
  LEAF,
  NO_CMD
}param_type_t;
typedef union _param_t{
  cmd_t *cmd;
  leaf_t *leaf;
}_param_t;
struct _param_t_{
  param_type_t param_type;
  _param_t cmd_type;
  cmd_callback callback;
  char ishidden;
  char help[PARAM_HELP_STRING_SIZE];
  param_t *options[MAX_OPTION_SIZE];
  param_t *parent;
  display_possible_values_callback disp_callback;
  int CMDMODE;
};
char*
get_str_leaf_type(leaf_type_t);
#endif
