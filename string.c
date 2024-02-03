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
 */
void *(memmove)(void *dest, const void *src, size_t n)
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
		// start copying from end. 
		for(size_t i = n - 1; i >= 0; i--)
			d[i] = s[i];
	}
	else
	{
		// Either there is no overlap, or src is past dest. 
		// In both cases, overlap is no concern. 
		// Same as memcpy.
		while (n-- > 0)
			*d++ = *s++;
	}

	return dest;
}
