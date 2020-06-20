#ifndef SERIALIZE_H
#define SERIALIZE_H

typedef struct serialized_buffer{
  #define SERIALIZE_BUFFER_DEFAULT_SIZE 512
  void *b;
  int size;
  int next;
  int checkpoint;
}ser_buff_t;

/* init functions*/
void
init_serialized_buffer(ser_buff_t**);
void
init_serialized_buffer_of_defined_size(ser_buff_t**, int);

/* Serialize functions*/
void
serialize_uint8 (ser_buff_t*, char);
void
serialize_int8 (ser_buff_t*, char);
void
serialize_int32 (ser_buff_t*, int);
void
serialize_uint32(ser_buff_t*, unsigned int);
void
serialize_float (ser_buff_t*, float);
void
serialize_double(ser_buff_t*, double);
void
serialize_string(ser_buff_t*, char*, int);
char
is_serialized_buffer_empty(ser_buff_t*);
/* get functions*/
int
get_serialize_buffer_size(ser_buff_t*);
int
get_serialize_buffer_current_ptr_offset(ser_buff_t*);
char*
get_serialize_buffer_current_ptr(ser_buff_t*);
void
serialize_buffer_skip(ser_buff_t*, int);
void
copy_in_serialized_buffer_by_offset(ser_buff_t*, int, char*, int);

/* De-Serialize function */

void
de_serialize_string(char*, ser_buff_t*, int);

/* free Resourse*/
void free_serialize_buffer(ser_buff_t*);

/*reset function*/
void
truncate_serialize_buffer(ser_buff_t**);
void
reset_serialize_buffer(ser_buff_t*);
void
restore_checkpoint_serialize_buffer(ser_buff_t*);
int
get_serialize_buffer_checkpoint_offset(ser_buff_t*);
void
mark_checkpoint_serialize_buffer(ser_buff_t*);
/* Details*/
void
print_buffer_details(ser_buff_t*, const char*, int);
#define deserialize_primitive(ser_buff, dest, type)				\
do{										\
	ser_buff_t *_b = (ser_buff_t *)(ser_buff);				\
	memcpy((char *)&dest, (char *)(_b->b) + _b->next, sizeof(type));	\
	_b->next += sizeof(type);						\
}while(0);

#if 0
#define deserialize_string(ser_buff, dest, size)				\
do{										\
	ser_buff_t *_b = (ser_buff_t *)(ser_buff);				\
	memcpy((char *)dest, (char *)(_b->b) + _b->next, size);			\
	_b->next += size;							\
}while(0);
#endif

#define serialize_primitive(ser_buff, dest, type)				\
do{                                                                             \
	if (ser_buff == NULL) assert(0);					\
	ser_buff_t *buff = (ser_buff_t *)(ser_buff);				\
	int available_size = buff->size - buff->next;				\
	char isResize = 0;							\
	while(available_size < sizeof(type)){					\
        	buff->size = buff->size * 2;					\
	        available_size = buff->size - buff->next;			\
        	isResize = 1;							\
    	}									\
        if(isResize == 0){							\
        memcpy((char *)buff->b + buff->next, &data, sizeof(type));		\
        buff->next += sizeof(type);						\
        return;									\
    }										\
    buff->b = realloc(buff->b, buff->size);					\
    memcpy((char *)buff->b + buff->next, &data, sizeof(type));			\
    buff->next += sizeof(type);							\
}while(0);

#endif
