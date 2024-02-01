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
	while (n-- > 0)
	{
		*(char*)(dest + n) = *(char*)(src + n);
	}
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
void *(my_memmove)(void *dest, const void *src, size_t n)
{
	printf("oh hi");

	if ((dest > src && dest - src >= n-1)
		|| (src > dest && src - dest >= n-1))
	{
		// no overlap
		while (n-- > 0)
		{
			*(char*)(dest + n) = *(char*)(src + n);
		}
	}
	else
	{
		// overlap - use buffer
		char buf[n];
		int nn = n;
		while (nn-- > 0)
		{
			buf[nn] = *(char*)(src + nn);
		}
		while (n-- > 0)
		{
			*(char*)(dest + n) = buf[n];
		}
	}

	return dest;
}
