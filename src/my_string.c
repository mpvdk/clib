#include "my_string.h"
#include <stdio.h>

/* function: memchr
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param  searchable  pointer to start of string which to search
 * param  ch          charachter to look for
 * param  count       number of bytes to analyze
 *
 * return                 pointer to first occurence of char in string, 
 *                        or NULL pointer if character is not found. 
 */
void* (my_memchr)(const void* searchable, int ch, size_t count)
{
  // Cast to int for comparison to c
  const int* sc = (const int*)searchable;

  for (size_t i = 0; i < count; i++)
    if (sc[i] == ch)
      return (void*)(sc + i);

  return NULL;
}

/* function: memcmp
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param  lhs     pointer to start of block of memory to compare to rhs
 * param  rhs     pointer to start of block of memory to compare to lhs
 * param  count   number of bytes to compare
 *
 * return             -1 if the first differing byte in lhs is < corresponding byte in rhs
 *                    0 if all [count] bytes in lhs and rhs are equal
 *                    1 if the first differing byte in lhs is > corresponding byte in rhs
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
 * param  dest    pointer to start of destination block
 * param  src     pointer to start of source memory block
 * param  count   number of bytes to copy
 *
 * return     dest    pointer to start of destination block
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
 * param  dest    pointer to start of destination block
 * param  src     pointer to start of source memory block
 * param  count   number of bytes to copy
 *
 * return     dest    pointer to start of destination block
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
 * param  dest    pointer to start of destination block
 * param  ch      value to set bytes to
 * param  count   number of bytes to set to [ch]
 *
 * return     dest    pointer to start of destination block
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
 * param  dest    pointer to start of dest string
 * param  append  pointer to start of string to be appended to dest
 *
 * return dest    pointer to start of destination block
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
 * param  str     pointer to the start of the string to search
 * param  ch      character to look for
 *
 * return         pointer to the position if found, NULL otherwise
 */
char* my_strchr(const char* str, int ch)
{
  while(*str != '\0')
    if (*str == ch)
      return (char*)str;
    str++;

  return NULL;
}

/* function: strrchr
 * -----------------------------
 * Search for last occurence of character in string
 *
 * param  str     pointer to the start of the string to search
 * param  ch      character to look for
 *
 * return         pointer to the position if found, NULL otherwise
 */
char* my_strrchr(const char* str, int ch)
{
  while(*str++);
  while(*str != '\0')
    if (*str == ch)
      return (char*)str;
    str--;

  return NULL;
}

/* function: strncat
 * -----------------------------
 * Append copy of [append] to dest, max [count] bytes.
 * Always appends \0 to end of result.
 *
 * param  dest    pointer to start of dest string
 * param  append  pointer to start of string to be appended to dest
 * param  count   max bytes to append
 *
 * return dest    pointer to start of destination block
 */
char *(my_strncat)(char* dest, const char* append, size_t count)
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
