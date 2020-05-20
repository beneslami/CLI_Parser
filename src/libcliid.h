#ifndef LIBCLIID_H
#define LIBCLIID_H

typedef enum{
  CONFIG_DISABLE,
  CONFIG_ENABLE,
  OPERATIONAL,
  MODE_UNKNOWN
}op_mode;        /* Used for identifying the mode of the command */

typedef enum{
  INT,
  FLOAT,
  STRING,
  BOOLEAN,
  IPV4,
  IPV6,
  MPLS,
  INVALID,
  LEAF_MAX
}leaf_type_t;

#endif
