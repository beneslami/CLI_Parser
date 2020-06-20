# CLI_Parser

I have been curious about how Cisco CLI works. Finally, thanks to Coronavirus, I found a time to dig into the question and try to understand what is going on inside Cisco user interface. You definitely have seen what Cisco CLI looks like.

![picture](data/cli.png)

Commands in CLI are implemented as n-aryl Tree. It means every node can have n number of children. So, commands are organized as hierarchy. For example, suppose a command like below:

```
show list [INPUT1] person [INPUT2]
show list all
```

![picture](data/cmd_graph.png)

Each node in the tree is called **param**. Params at the first level of the overall command tree is called **hooks**. Params are categorized into two groups:

1. **command params**: constant keywords in the graph (like show, list, all, person)

2. **leaf params**: denotes to user input in the graph (like INPUT1, INPUT2).

There are also incomplete commands when the user traverse each path of the tree. For example,
``show list ``
is incomplete and the program should recognize between complete and incomplete commands. In addition, a node cannot have two or more than two leaf params as its children. Generally, the CLI parser should have following responsibilities:

* Validate command syntax

* Validate leaf values are compatible with leaf expectatoin

* Send command to backend/application along with the leaf values for command processing.

* Provide handy and easy method to developer to modify/extend or add more commands

* provide shortcuts to user to speed up the work.

### implementation

The main building block of such program is elaborated as below:

* To define a hook, there is a data structure called **param_t** provided in libcli.h.

* To assign a procedure to a defined hook, a function called **init_param** is used. If the param is command node, there is no function to be called, and if the param is leaf node, a pre-defined function is called.

* After finalizing above steps, the param should be attached to the command tree.

* The library should extract leaf params' values in a command and send it to application process. The values and their metadata should be organized as TLV. Then, there should be a function to parse TLV.

---

Whenever you want to use this library, add the following lines to your code:
```
#include "src/cmdtlv.h"
#include "src/libcli.h"
```

At the beginning of main function, call ```init_libcli();```. This function initializes the library to be used by your application. At the end of main function, add following functions:
```
support_cmd_negation(config); //this adds 'no' support config commands.
start_shell();  //This finally starts the shell interface. Any code after this function call is dead code.
```

After **init_libcli()**, call the below APIs to import hooks from the library:
```
param_t *show   = libcli_get_show_hook();
param_t *debug  = libcli_get_debug_hook();
param_t *config = libcli_get_config_hook();
param_t *clear  = libcli_get_clear_hook();
param_t *run    = libcli_get_run_hook();
```

The constructor function is **init_param**. The arguments to this init_param is explained below. Each argument to the constructor is passed in the context whether the param is CMD or LEAF param.
```
void
init_param(param_t *param,                               /* pointer to param_t variable*/
        param_type_t param_type,                         /* CMD if it is a CMD param , LEAF if it is a leaf param*/
        char *cmd_name,                                        /* <command name> for cmd param | always NULL for LEAF param*/
        cmd_callback callback,                              /* Callback field, applicable to both CMD and LEAF param. NULL for incomplete commands */
        user_validation_callback user_validation_cb_fn,  /* always NULL for CMD param | Can be NULL Or valid function pointer for LEAF param */
        leaf_type_t leaf_type,                                 /* always INVALID for CMD param | leaf type (discuss shortly)*/
        char *leaf_id,                                             /* always NULL for CMD param , some <STRING> for LEAF param*/
        char *help) ;                                             /* Help String */
```

**cmd_callback callback**: This field is a pointer to applicable specific function which you want to invoke when user type out the command on shell up to this param and hit enter. If this field is left blank, the command exactly up to this param is said to be incomplete command. Also, function prototype MUST be like below:
```
int <function_name> (param_t *param, ser_buff_t *tlv_buf, op_mode enable_or_disable);
```
This function must always return 0.

**user_validation_callback user_validation_cb_fn**: This field is a pointer to application specific function which you want to invoke in order to validate the value passed by the user for this param. This field is meaningful only for LEAF param. The function prototype MUST be like below:
```
int <function_name> (char *value);
```
The value of the leaf param as typed out by the user on shell is passed as argument to this function as string. You can write your own logic how to validate this value further. This function must return either VALIDATION_SUCCESS or VALIDATION_FAILED as return value.

in main.c file, you must see **node_loopback_callback_handler()** which is invoked when we execute corresponding command. That command has two leaves in it: <node_name> and <loopback_address>. You should be able to fetch the values of these two leaves in application code along with command code.

How to run?
Simply run **make** in main folder of the project. Then run **./exe**. 
