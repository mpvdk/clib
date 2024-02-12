#ifndef MY_STRING_H
#define MY_STRING_H


#define __need_size_t // tell stddef to define size_t only
#include <stddef.h>

// ISO C
void*  my_memchr(const void* haystack, int needle, size_t count);
int    my_memcmp(const void* lhs, const void* rhs, size_t count);
void*  my_memcpy(void* dest, const void* src, size_t count);
void*  my_memmove(void* dest, const void* src, size_t count);
void*  my_memset(void* dest, int ch, size_t count);
char*  my_strcat(char* dest, const char* append);
char*  my_strchr(const char* haystack, int needle);
int    my_strcoll(const char* str1, const char* str2);
char*  my_strcpy(char* dest, const char* src);
size_t my_strlen(const char* str);
int    my_strcmp(const char* str1, const char* str2);
size_t my_strcspn(const char* str1, const char* str2);
char*  my_strncat(char* dest, const char* append, size_t count);
int    my_strncmp(const char* str1, const char* str2, size_t count);
char*  my_strncpy(char* dest, const char* src, size_t count);
char*  my_strpbrk(const char* str1, const char* str2);
char*  my_strrchr(const char* haystack, int needle);
size_t my_strspn(const char* str1, const char* str2);
char*  my_strstr(const char* haystack, const char* needle);
char*  my_strtok(char* str, const char* delim);
size_t my_strxfrm(char* dest, const char* src, size_t max);

// EXTENSIONS
void*  my_memccpy(void* dest, const void* src, int ch, size_t count);
char*  my_strdup(const char* src);
size_t my_strlcat(char* dest, const char* append, size_t buf_size);

size_t my_strlcpy(char* dest, const char* src, size_t buf_size);
char*  my_strtok_r(char* str, const char* delim, char** saveptr);

// WON'T IMPLEMENT
//
// int    my_strcat_s(char* dest, size_t max, const char* append);  too many non-standard considerations
// int    my_strcpy_s(char* dest, size_t count, const char* src);   too many non-standard considerations 
// char*  my_strerror(int num);                                     tedious (mapping lots of nrs to str)
// int    my_strerror_r(int, char *, size_t);                       idem
// char*  my_strerror_r(int, char *, size_t);                       idem
// char*  my_strsignal(int sig);                                    idem

#endif /* MY_STRING_H */
