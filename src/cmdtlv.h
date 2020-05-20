#ifndef CMDTLV_H
#define CMDTLV_H

#include "cmd_hier.h"
#include "libcliid.h"
#include "serialize.h"

typedef struct tlv_struct{
  leaf_type_t leaf_type;
  char leaf_id[LEAF_ID_SIZE];
  char value[LEAF_VALUE_HOLDER_SIZE];
}tlv_struct_t;

#endif
