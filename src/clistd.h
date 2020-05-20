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

#endif
