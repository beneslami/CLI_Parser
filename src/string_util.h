#ifndef STRING_UTIL_H
#define STRING_UTIL_H

char** tokenizer(char*, const char, size_t*);
void
string_space_trim(char*);
void
print_tokens(unsigned int);
void
init_token_array();
void
re_init_tokens(int);
void
tokenize(char*, unsigned int, unsigned int);
void
untokenize(unsigned int);
char *
get_token(unsigned int );

#endif
