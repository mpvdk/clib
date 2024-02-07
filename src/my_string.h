#ifndef MY_STRING_H
#define MY_STRING_H

/* __need_size_t tells stddef.h to define size_t only */
#define __need_size_t
#include <stddef.h>

void* my_memchr(const void* searchable, int ch, size_t count);
int my_memcmp(const void* lhs, const void* rhs, size_t count);
void* my_memcpy(void* dest, const void* src, size_t count);
void* my_memmove(void* dest, const void* src, size_t count);
void* my_memset(void* dest, int ch, size_t count);
char* my_strcat(char* dest, const char* append);
char* my_strchr(const char* str, int ch);
int my_strcmp(const char* lhs, const char* rhs);
char* my_strrchr(const char* str, int ch);
char *my_strncat(char* dest, const char* append, size_t count);

int my_strncmp(const char*, const char*, size_t count);
int my_strcoll(const char*, const char*);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char *dest, const char *src, size_t n);
char* my_strerror(int);
size_t my_strlen(const char*);
size_t my_strspn(const char*, const char *accept);
size_t my_strcspn(const char*, const char *reject);
char* my_strpbrk(const char*, const char *accept);
char* my_strstr(const char* haystack, const char *needle);
char* my_strtok(char*, const char* delim);
size_t my_strxfrm(char* dest, const char* src, size_t n);

#endif /* MY_STRING_H */
