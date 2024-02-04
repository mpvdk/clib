#ifndef MY_STRING_H
#define MY_STRING_H

/* __need_size_t tells stddef.h to define size_t only */
#define __need_size_t
#include <stddef.h>

void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *lhs, const void *rhs, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);

void *my_memset(void *, int c, size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);
char *my_strchr(const char *, int c);
char *my_strrchr(const char *, int c);
int my_strcmp(const char *, const char *);
int my_strncmp(const char *, const char *, size_t n);
int my_strcoll(const char *, const char *);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strerror(int);
size_t my_strlen(const char *);
size_t my_strspn(const char *, const char *accept);
size_t my_strcspn(const char *, const char *reject);
char *my_strpbrk(const char *, const char *accept);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *, const char * delim);
size_t my_strxfrm(char *dest, const char *src, size_t n);

#endif /* MY_STRING_H */
