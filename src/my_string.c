#include "my_string.h"
#include <stdio.h>

/* function: memchr
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param[in]	s	pointer to start of string which to search
 * param[in]	c	charachter to look for
 * param[in]	n	number of bytes to analyze
 *
 * return			pointer to first occurence of char in string, 
 *					or NULL pointer if character is not found. 
 */
void* (my_memchr)(const void *s, int c, size_t n)
{
	const char *sc = (const char *)s;
	for (size_t i = 0; i < n; i++)
	{
		if (sc[i] == (char)c)
			return (void*)(sc + i);
	}
	return NULL;
}

/* function: memcmp
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param[in]	lhs		pointer to start of block of memory to compare to rhs
 * param[in]	rhs		pointer to start of block of memory to compare to lhs
 * param[in]	n		number of bytes to compare
 *
 * return				-1 if the first differing byte in lhs is < corresponding byte in rhs
 *						0 if all n bytes in lhs and rhs are equal
 *						1 if the first differing byte in lhs is > corresponding byte in rhs
 */
int (my_memcmp)(const void *lhs, const void *rhs, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (*((const char*)lhs + i) == *((const char*)rhs + i))
			continue;
		if (*((const char*)lhs + i) > *((const char*)rhs + i))
			return 1;
		if (*((const char*)lhs + i) < *((const char*)rhs + i))
			return -1;
	}
	return 0;
}

/* function: memcpy
 * -----------------------------
 * Copy n bytes from src to dest.
 * Overlap is UB.
 *
 * param[out]	dest	pointer to start of destination block
 * param[in]	src		pointer to start of source memory block
 * param[in]	n		number of bytes to copy
 *
 * return		dest	pointer to start of destination block
 */
void* (my_memcpy)(void *dest, const void *src, size_t n)
{
	char* d = (char*)dest;
	char* s = (char*)src;
	while (n-- > 0)
		*d++ = *s++;
	return dest;
}

/* function: memmove
 * -----------------------------
 * Copy n bytes from src to dest.
 * Allows for overlap.
 *
 * param[out]	dest	pointer to start of destination block
 * param[in]	src		pointer to start of source memory block
 * param[in]	n		number of bytes to copy
 *
 * return		dest	pointer to start of destination block
 */
void* (my_memmove)(void *dest, const void *src, size_t n)
{
	if (dest == src) return dest;
	if (n <= 0) return dest;

	char* d = (char*)dest;
	char* s = (char*)src;

	if (dest > src && dest - src < n)
	{
		// Overlap. Dest is past src:
		// ...src...
		//       ...dest...
		// start copying from end to prevent overwriting 
		// source bytes before they're copied to dest.
		for(int i = (int)n - 1; i >= 0; i--)
			d[i] = s[i];
	}
	else
	{
		// Either there is no overlap, or src is past dest. 
		// In both cases, overlap is no concern. 
		while (n-- > 0)
			*d++ = *s++;
	}

	return dest;
}

