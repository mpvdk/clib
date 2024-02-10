#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>

/* function: memchr
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param    haystack  pointer to start of string which to search
 * param    needle    charachter to look for
 * param    count     number of bytes to analyze
 *
 * return             pointer to first occurence of char in string, 
 *                    or NULL pointer if character is not found. 
 */
void* (my_memchr)(const void* haystack, int needle, size_t count)
{
  // Cast to int for comparison to c
  const char* sc = (const char*)haystack;

  for (size_t i = 0; i < count; i++)
    if (sc[i] == (char)needle)
      return (void*)(sc + i);

  return NULL;
}

/* function: memcmp
 * -----------------------------
 * Compare two blocks of memory
 *
 * param    lhs     pointer to start of block of memory to compare to rhs
 * param    rhs     pointer to start of block of memory to compare to lhs
 * param    count   number of bytes to compare
 *
 * return           -1 if the first differing byte in lhs is < corresponding byte in rhs
 *                  0 if all [count] bytes in lhs and rhs are equal
 *                  1 if the first differing byte in lhs is > corresponding byte in rhs
 */
int (my_memcmp)(const void* lhs, const void* rhs, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    if (*((const char*)lhs + i) == *((const char*)rhs + i))
      continue;   // equal byte; continue to next
    if (*((const char*)lhs + i) > *((const char*)rhs + i))
      return 1;   // lhs > rhs
    if (*((const char*)lhs + i) < *((const char*)rhs + i))
      return -1;  // rhs < lhs
  }
  return 0;       // all bytes equal
}

/* function: memcpy
 * -----------------------------
 * Copy n bytes from src to dest.
 * Overlap is UB.
 *
 * param    dest    pointer to start of destination block
 * param    src     pointer to start of source memory block
 * param    count   number of bytes to copy
 *
 * return   dest    pointer to start of destination block
 */
void* (my_memcpy)(void* dest, const void* src, size_t count)
{
  char* d = (char*)dest;
  char* s = (char*)src;

  while (count-- > 0)
    *d++ = *s++;

  return dest;
}

/* function: memmove
 * -----------------------------
 * Copy n bytes from src to dest.
 * Allows for overlap.
 *
 * param    dest    pointer to start of destination block
 * param    src     pointer to start of source memory block
 * param    count   number of bytes to copy
 *
 * return   dest    pointer to start of destination block
 */
void* (my_memmove)(void* dest, const void* src, size_t count)
{
  if (dest == src) return dest;
  if (count <= 0) return dest;

  char* d = (char*)dest;
  char* s = (char*)src;

  if (dest > src && dest - src < count)
  {
    // Overlap. Dest is past src:
    // ...src...
    //       ...dest...
    // start copying from end to prevent overwriting 
    // source bytes before they're copied to dest.
    for(int i = (int)count - 1; i >= 0; i--)
      d[i] = s[i];
  }
  else
  {
    // Either there is no overlap, or src is past dest. 
    // In both cases, overlap is no concern. 
    while (count-- > 0)
      *d++ = *s++;
  }

  return dest;
}

/* function: memset
 * -----------------------------
 * Set bytes to value
 *
 * param    dest    pointer to start of destination block
 * param    ch      value to set bytes to
 * param    count   number of bytes to set to [ch]
 *
 * return   dest    pointer to start of destination block
 */
void* (my_memset)(void* dest, int ch, size_t count)
{
  if (dest == NULL) return dest;
  if (count < 1) return dest;

  char* d = (char*)dest;
  for(size_t i = 0; i < count; i++)
    *d++ = ch;

  return dest;
}

/* function: strcat
 * -----------------------------
 * Append copy of append to dest
 *
 * param    dest    pointer to start of dest string
 * param    append  pointer to start of string to be appended to dest
 *
 * return   dest    pointer to start of destination block
 */
char* (my_strcat)(char* dest, const char* append)
{
  if (append == NULL) return dest;

  char* ret = dest;

  while(*dest != '\0')
    dest++;

  while((*dest++ = *append++));

  return ret;
}

/* function: strchr
 * -----------------------------
 * Search for first occurence of character in string
 *
 * param    haystack  pointer to the start of the string to search
 * param    needle    character to look for
 *
 * return             pointer to the position if found, NULL otherwise
 */
char* (my_strchr)(const char* haystack, int needle)
{
  while(*haystack != '\0')
  {
    if (*haystack == needle)
      return (char*)haystack;
    haystack++;
  }

  if (*haystack == '\0' && needle == '\0')
    return (char*)haystack;

  return NULL;
}

/* function: strcoll
 * -----------------------------
 * Compare two strings, assuming both are null-terminated. 
 *
 * param    str1     pointer to start of string to compare to str2
 * param    str2     pointer to start of string compare to str1
 *
 * return           negative int if the first differing byte in str1 is < corresponding byte in str2
 *                  0 if str1 and str2 are equal
 *                  positive int if the first differing byte in str1 is > corresponding byte in str2
 */
int (my_strcoll)(const char* str1, const char* str2)
{
  // not dealing with locales
  return my_strcmp(str1, str2);
}

/* function: strcpy
 * -----------------------------
 * Copy [src] string to [dest] block, including null-terminator
 *
 * param    dest    pointer to start of destination block
 * param    src     ppointer to start of string to copy
 *
 * return   dest    pointer to start of destionation block
 */
char* (my_strcpy)(char* dest, const char* src)
{
  size_t str_len = 0;
  const char* saved_src = src;

  while (*src++)
    str_len++;
  str_len++; // add null-terminator

  my_memcpy(dest, saved_src, str_len);

  return dest;
}

/* function: strlen
 * -----------------------------
 * Get length of [str], not counting null-terminator
 *
 * param    str   pointer to start of string to count
 *
 * return         number of characters in [str]
 */
size_t (my_strlen)(const char* str)
{
  size_t str_len = 0;

  while (*str++)
    str_len++;

  return str_len;
}

/* function: strcmp
 * -----------------------------
 * Compare two strings, assuming both are null-terminated
 *
 * param    str1     pointer to start of string to compare to str2
 * param    str2     pointer to start of string compare to str1
 *
 * return           negative int if the first differing byte in str1 is < corresponding byte in str2
 *                  0 if str1 and str2 are equal
 *                  positive int if the first differing byte in str1 is > corresponding byte in str2
 */
int (my_strcmp)(const char* str1, const char* str2)
{
  while (*str1 && *str2 && (*str1 == *str2))
  {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

/* function: strncat
 * -----------------------------
 * Append copy of [append] to [dest], max [count] bytes.
 * Always appends \0 to end of result.
 *
 * param    dest    pointer to start of dest string
 * param    append  pointer to start of string to be appended to dest
 * param    count   max bytes to append
 *
 * return   dest    pointer to start of destination block
 */
char* (my_strncat)(char* dest, const char* append, size_t count)
{
  if (append == NULL) return dest;
  if (count < 1) return dest;

  char* ret = dest;

  while(*dest != '\0')
    dest++;

  while(count-- > 0 && (*dest++ = *append++) != '\0')
    if (count == 0 && *dest != '\0')
      *++dest = '\0';

  return ret;
}

/* function: strncmp
 * -----------------------------
 * Compare two strings, assuming both are null-terminated, for a max of [count] bytes
 *
 * param    str1     pointer to start of string to compare to str2
 * param    str2     pointer to start of string compare to str1
 * param    count   max number of bytes to compare
 *
 * return           negative int if the first differing byte in str1 is < corresponding byte in str2
 *                  0 if str1 and str2 are equal
 *                  positive int if the first differing byte in str1 is > corresponding byte in str2
 */
int (my_strncmp)(const char* str1, const char* str2, size_t count)
{
  if (count < 1) return 0;

  while (*str1 && *str2 && count && (*str1 == *str2))
  {
    str1++;
    str2++;
    count--;
  }

  if (count == 0) return 0;
  return *str1 - *str2;
}

/* function: strcspn
 * -----------------------------
 * Find the index of the first occurence of a character in [str1]
 * that belongs to the set of characters specified by [str2]
 *
 * param    str1    pointer to start of string to be scanned
 * param    str2    pointer to start of string containing chars to be matched
 *
 * return           Index of first character found in [str1] that occurs in [str2].
 *                  In other words: length of the part of [str1] that consists
 *                  entirely of characters that do not occur in [str2].
 */
size_t (my_strcspn)(const char* str1, const char* str2)
{
  const char* p;
  const char* q;
  size_t count = 0;

  for (p = str1; *p != '\0'; p++)
  {
    for (q = str2; *q != '\0'; q++)
    {
      if (*p == *q) return count;
    }
    count++;
  }
  return count;
}

/* function: strncpy
 * -----------------------------
 * Copy [src] string to [dest] with max of [count] bytes.
 * No null-terminating character is added implicitly. 
 * Padd with 0 if [count] > length of [src].
 *
 * param    dest    pointer to start of dest block
 * param    src     pointer to start of source string
 * param    count   max bytes to copy
 *
 * return   dest    pointer to start of destination block
 */
char* (my_strncpy)(char* dest, const char* src, size_t count)
{
  size_t src_len = 0;
  const char* src_counter = src;
  while (*src_counter++)
    src_len++;
  
  if (count > src_len)
  {
    my_memcpy(dest, src, src_len);
    my_memset(dest + src_len, 0, count - src_len); // pad with zeroes
  }
  else 
  {
    my_memcpy(dest, src, count);
  }

  return dest;
}

/* function: strpbrk
 * -----------------------------
 * Find the first character in [str1] that matches any character in [str2]
 *
 * param    str1    pointer to start of string to be scanned
 * param    str2    pointer to start of string containing characters to be matched
 *
 * return   str1    pointer to char in str1
 */
char* (my_strpbrk)(const char* str1, const char* str2)
{
  const char* p;
  while (*str1 != '\0')
  {
    for (p = str2; *p != '\0'; p++)
    {
      if (*p == *str1) return (char*)str1;
    }
    str1++;
  }
  return NULL;
}

/* function: strrchr
 * -----------------------------
 * Search for last occurence of character in string
 *
 * param    haystack  pointer to the start of the string to search
 * param    needle    character to look for
 *
 * return             pointer to the position if found, NULL otherwise
 */
char* (my_strrchr)(const char* haystack, int needle)
{
  const char* saved = haystack;
  while(*++haystack != '\0');
  while(haystack != saved - 1) {
    if (*haystack == needle)
      return (char*)haystack;
    haystack--;
  } 

  return NULL;
}

/* function: strspn
 * -----------------------------
 * Count length of initial portion of str1 containing 
 * only characters that occur in str2.
 *
 * param    str1     pointer to start of string to be scanned
 * param    str2     pointer to start of string containing chars to be matched
 *
 * return           length of portion of [str1] containing only characters that
 *                  appear in str2.
 */
size_t (my_strspn)(const char* str1, const char* str2)
{
  const char* p; 
  const char* q;
  size_t count = 0;

  for (p = str1; *p != '\0'; p++) 
  {
    for (q = str2; *q != '\0'; q++) 
    {
      if (*p == *q) break;
    }
    if (*q == '\0') break;
    count++;
  }
  return count;
}

/* function: strstr
 * -----------------------------
 * Find first occurence of substring [needle] in [haystack].
 *
 * param    haystack  pointer to start of string to be scanned
 * param    needle    pointer to start of substring to be matched
 *
 * return   haystack  pointer to the first occurence in [haystack] of the entire sequence 
 *                    of characters specified in [needle], or NULL if not found.
 */
char* (my_strstr)(const char* haystack, const char* needle)
{
  if (haystack == NULL) return NULL;
  if (needle == NULL) return (char*)haystack;
  if (*needle == '\0') return (char*)haystack;

  char* saved_needle = (char*)needle;
  
  for (; *haystack != 0; haystack++)
  { 
    // try to match first char
    if (*haystack != *needle) continue; // no match

    // first char of needle matched. Try to match rest. 
    char* substr = (char*)haystack;
    while (1)
    {
      if (*needle == '\0') return (char*)haystack;
      if (*substr == '\0') break;
      if (*needle++ != *substr++) break;
    }
    if (*needle == '\0') return (char*)haystack; // full needle found
    needle = saved_needle;
  }
  return NULL;
}

/* function: strtok
 * -----------------------------
 * Break [str] into a series of tokens using delimiter [delim]
 *
 * param    str     pointer to start of string to be scanned
 * param    delim   pointer to start of substring to be matched
 *
 * return           pointer to the first token found in the string. 
 *                  NULL if no matches left. 
 */
char* (my_strtok)(char* str, const char* delim)
{
  static char* save;

  if (str == NULL) str = save;   // continue from location saved by prev invocation
  if (str == NULL) return NULL;  // invalid use
  if (*str == '\0') return NULL; // no (more) tokens to be found

  // Skip any tokens at start of string
  while (*str != '\0')
  {
    int delim_matched = 0;
    for (const char* d = delim; *d != '\0'; d++)
    {
      if (*str == *d)
      {
        str++;
        delim_matched = 1;
        break;
      }
    }
    if (!delim_matched) break; // all delims at start of string skipped
  }
  if (*str == '\0') return NULL; // end of string reached

  // find first matching delim, turn it into '\0'
  char* return_address = str;
  while (1)
  {
    int delim_matched = 0;
    for (const char* d = delim; *d != '\0'; d++)
    {
      if (*str != *d)
      {
        continue;
      }
      delim_matched = 1;
      *str = '\0';
      save = ++str;
      break;
    }
    if (delim_matched) break;
    str++;
  }

  return return_address;
}

/* function: strxfrm
 * -----------------------------
 * Transform [src] according to locale into [dest] for max of [max] characters
 *
 * param    dest    pointer to start of destination block
 * param    src     pointer to start of source string
 * param    max     max number of bytes to copy
 *
 * return           length of transformed string
 */
size_t my_strxfrm(char* dest, const char* src, size_t max)
{
  // not dealing with locales - just copy. 
  my_strncpy(dest, src, max);
  return my_strlen(src);
}

/* function: memccpy
 * -----------------------------
 * Copy [count] bytes from [src] to [dest], stopping when [ch] is found.
 * Overlap is UB.
 *
 * param    dest    pointer to start of destination block
 * param    src     pointer to start of source memory block
 * param    ch      character to stop at when matched
 * param    count   number of bytes to copy
 *
 * return   dest    pointer to start of destination block
 */
void* (my_memccpy)(void* dest, const void* src, int ch, size_t count)
{
  char* d = (char*)dest;
  char* s = (char*)src;

  while (count-- > 0)
  {
    if (*s == ch)
    {
      *d = *s;
      break;
    }
    else
    {
      *d++ = *s++;
    }
  }

  if (*s == ch) return d;
  return NULL;
}

/* function: strdup
 * -----------------------------
 * Copy [src] string into a heap-allocated destination string
 *
 * param    src   pointer to start of null-terminated source string
 *
 * return         pointer to start of destination block on heap
 */
char* (my_strdup)(const char* src)
{
  if (src == NULL) return NULL;

  char* copy;
  size_t len = my_strlen(src) + 1;
  
  if (!(copy = malloc(len))) return NULL;
  my_memcpy(copy, src, len);
  return copy;
}

