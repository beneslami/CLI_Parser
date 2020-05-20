#ifndef SERIALIZE_H
#define SERIALIZE_H

typedef struct serialized_buffer{
  #define SERIALIZE_BUFFER_DEFAULT_SIZE 512
  void *b;
  int size;
  int next;
  int checkpoint;
}ser_buff_t;

#endit
