#include "my_string.h"
#include <stdio.h>

/* function: memchr
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param    searchable  pointer to start of string which to search
 * param    ch          charachter to look for
 * param    count       number of bytes to analyze
 *
 * return               pointer to first occurence of char in string, 
 *                      or NULL pointer if character is not found. 
 */
void* (my_memchr)(const void* searchable, int ch, size_t count)
{
  // Cast to int for comparison to c
  const char* sc = (const char*)searchable;

  for (size_t i = 0; i < count; i++)
    if (sc[i] == (char)ch)
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
 * param    str   pointer to the start of the string to search
 * param    ch    character to look for
 *
 * return         pointer to the position if found, NULL otherwise
 */
char* my_strchr(const char* str, int ch)
{
  while(*str != '\0')
  {
    if (*str == ch)
      return (char*)str;
    str++;
  }

  if (*str == '\0' && ch == '\0')
    return (char*)str;

  return NULL;
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
char* my_strcpy(char* dest, const char* src)
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
size_t my_strlen(const char* str)
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
 * param    lhs     pointer to start of string to compare to rhs
 * param    rhs     pointer to start of string compare to lhs
 *
 * return           negative int if the first differing byte in lhs is < corresponding byte in rhs
 *                  0 if lhs and rhs are equal
 *                  positive int if the first differing byte in lhs is > corresponding byte in rhs
 */
int my_strcmp(const char* lhs, const char* rhs)
{
  while (*lhs && *rhs && (*lhs == *rhs))
  {
    lhs++;
    rhs++;
  }
  return *lhs - *rhs;
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
 * param    lhs     pointer to start of string to compare to rhs
 * param    rhs     pointer to start of string compare to lhs
 * param    count   max number of bytes to compare
 *
 * return           negative int if the first differing byte in lhs is < corresponding byte in rhs
 *                  0 if lhs and rhs are equal
 *                  positive int if the first differing byte in lhs is > corresponding byte in rhs
 */
int my_strncmp(const char* lhs, const char* rhs, size_t count)
{
  if (count < 1) return 0;

  while (*lhs && *rhs && count && (*lhs == *rhs))
  {
    lhs++;
    rhs++;
    count--;
  }

  if (count == 0) return 0;
  return *lhs - *rhs;
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
char* my_strncpy(char* dest, const char* src, size_t count)
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

/* function: strrchr
 * -----------------------------
 * Search for last occurence of character in string
 *
 * param    str     pointer to the start of the string to search
 * param    ch      character to look for
 *
 * return           pointer to the position if found, NULL otherwise
 */
char* (my_strrchr)(const char* str, int ch)
{
  const char* saved = str;
  while(*++str != '\0');
  while(str != saved - 1) {
    if (*str == ch)
      return (char*)str;
    str--;
  } 

  return NULL;
}

/* function: strspn
 * -----------------------------
 * Search for last occurence of character in string
 *
 * param    lhs     pointer to start of string to be scanned
 * param    ch      pointer to start of string containing chars to be matched
 *
 * return           length of portion of [lhs] containing only characters that
 *                  appear in rhs.
 */
size_t my_strspn(const char* lhs, const char* rhs)
{
  const char* p; 
  const char* q;
  size_t cnt = 0;

  for (p = lhs; *p != '\0'; ++p) {
    for (q = rhs; *q != '\0'; ++q) {
      if (*p == *q) break; // Found a matching character in rhs.
    }
    if (*q == '\0') break; // No matching character found; end of segment.
    cnt++; // Increment count for each character in lhs found in rhs.
  }
  return cnt;
}
