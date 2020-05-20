#ifndef CLICONST_H
#define CLICONST_H

#define CMD_NAME_SIZE           32
#define MAX_CMD_TREE_DEPTH      16
#define LEAF_VALUE_HOLDER_SIZE  64
#define LEAF_ID_SIZE            32
#define PARAM_HELP_STRING_SIZE  64
#define CONS_INPUT_BUFFER_SIZE  2048
#define TERMINAL_NAME_SIZE      CONS_INPUT_BUFFER_SIZE
#define TLV_MAX_BUFFER_SIZE     1024
#define POSSIBILITY_ARRAY_SIZE  10
#define DEFAULT_DEVICE_NAME     "env@benyamin"
#define MODE_CHARACTER          "/"
#define SUBOPTIONS_CHARACTER    "?"
#define CMD_EXPANSION_CHARACTER "."
#define MAX_OPTION_SIZE         16
#define CMD_HIST_RECORD_FILE    "CMD_HIST_RECORD_FILE.txt"
#define FILE_CMD_SIZE_MAX       (LEAF_VALUE_HOLDER_SIZE * MAX_CMD_TREE_DEPTH)
#define MODE_PARAM_INDEX        0
#define SUBOPTIONS_INDEX        1
#define CMD_EXPANSION_INDEX     2
#define CHILDREN_START_INDEX    3
#define CHILDREN_END_INDEX      (MAX_OPTION_SIZE -1)
#define MAX_SAVED_CMDS          30
#define NEGATE_CHARACTER        "no"
#define GOTO_TOP_STRING         "exitall"
#define GOTO_ONE_LVL_UP_STRING  "exit"
#define CLEAR_SCR_STRING        "clear"
#define DO                      "do"
#define SHOW_EXTENSION_PARAM            "SHOW_EXTENSIONS"
#define SHOW_EXTENSION_PARAM_BRIEF      "SHOW_BRIEF"
#define SHOW_EXTENSION_PARAM_DETAIL     "SHOW_DETAIL"
#define SHOW_EXTENSION_PARAM_EXTENSIVE  "SHOW_EXTENSIVE"
#define SHOW_HELP                   1
#define SHOW_HISTORY                2
#define SHOW_HISTORY_N              3
#define SHOW_REGISTERED_COMMANDS    4
#define CONFIG_SUPPORTSAVE_ENABLE   5
#define CONFIG_CONSOLEN_NAME_NAME   6
#define DEBUG_SHOW_CMDTREE          7

typedef enum{
    brief,
    detail,
    extensive,
    none
} show_ext_t;

typedef enum{
    COMPLETE,
    ERROR,
    INVALID_LEAF,
    USER_INVALID_LEAF,
    CMD_NOT_FOUND,
    INCOMPLETE_COMMAND,
    MULTIPLE_MATCHING_COMMANDS,
    UNKNOWN
} CMD_PARSE_STATUS;

#endif
