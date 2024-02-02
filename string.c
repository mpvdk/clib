#include "string.h"
#include <stdio.h>

/* function: memcpy
 * -----------------------------
 * Copy n bytes from src to dest.
 * Overlap is UB.
 *
 * param[out]	dest	pointer to start of destination block
 * param[in]	src		pointer to start of source memory block
 * param[in]	n		number of bytes to copy
 */
void *(memcpy)(void *dest, const void *src, size_t n)
{
	char* d = (char*)dest;
	char* s = (char*)src;
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return dest;
}

/* function: memmove
 * -----------------------------
 * Copy n bytes from src to dest.
 * Allows for overlap. Use buffer if overlap.
 *
 * param[out]	dest	pointer to start of destination block
 * param[in]	src		pointer to start of source memory block
 * param[in]	n		number of bytes to copy
 */
void *(my_memmove)(void *dest, const void *src, size_t n)
{
	char* d = (char*)dest;
	char* s = (char*)src;

	if ((dest > src && dest - src >= n-1)
		|| (src > dest && src - dest >= n-1))
	{
		// no overlap
		while (n-- > 0)
		{
			*d++ = *s++;
		}
	}
	else
	{
		// overlap - use buffer
		char buf[n];
		char* bufp = buf;
		int nn = n;
		while (nn-- > 0)
		{
			*bufp++ = *s++;
		}
		bufp = buf; // reset pointer to start of buffer
		while (n-- > 0)
		{
			*d++ = *bufp++;
		}
	}

	return dest;
}
