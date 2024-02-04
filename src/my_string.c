#include "my_string.h"
#include <stdio.h>

/* function: memchr
 * -----------------------------
 * Search string for first occurence of a character.
 *
 * param[in]	searchable	pointer to start of string which to search
 * param[in]	ch			charachter to look for
 * param[in]	count		number of bytes to analyze
 *
 * return					pointer to first occurence of char in string, 
 *							or NULL pointer if character is not found. 
 */
void* (my_memchr)(const void* searchable, int c, size_t count)
{
	const char* sc = (const char*)searchable;
	for (size_t i = 0; i < count; i++)
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
 * param[in]	count	number of bytes to compare
 *
 * return				-1 if the first differing byte in lhs is < corresponding byte in rhs
 *						0 if all [count] bytes in lhs and rhs are equal
 *						1 if the first differing byte in lhs is > corresponding byte in rhs
 */
int (my_memcmp)(const void* lhs, const void* rhs, size_t count)
{
	for (size_t i = 0; i < count; i++)
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
 * param[in]	count	number of bytes to copy
 *
 * return		dest	pointer to start of destination block
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
 * param[out]	dest	pointer to start of destination block
 * param[in]	src		pointer to start of source memory block
 * param[in]	count	number of bytes to copy
 *
 * return		dest	pointer to start of destination block
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
 * param[out]	dest	pointer to start of destination block
 * param[in]	ch		value to set bytes to
 * param[in]	count	number of bytes to set to [ch]
 *
 * return		dest	pointer to start of destination block
 */
void* (my_memset)(void* dest, int ch, size_t count)
{
	// easy exits
	if (dest == NULL || count < 1) return dest;
	char* d = (char*)dest;

	for(size_t i = 0; i < count; i++)
	{
		*d++ = ch;
	}

	return dest;
}

/* function: strcat
 * -----------------------------
 * Append copy of src to dest
 *
 * param[out]	dest	pointer to start of dest string
 * param[in]	src		pointer to start of string to be appended to dest
 *
 * return		dest	pointer to start of destination block
 */
char* my_strcat(char* dest, const char* src)
{
	// if src is NULL do nothing
	if (src == NULL) return dest;

	char* start_pos = (char*)my_memchr(dest, '\0', 99999); // WHAT VAL TO USE FOR COUNT ARG?
	
	while(*src != '\0')
	{
		*start_pos++ = *src++;
	}

	return dest;
}
