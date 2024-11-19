// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

struct mem_list *freelist = NULL;

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
	void *ptr = malloc(total_size);
	if (!ptr)
	   return NULL;
	return memset(ptr, 0, total_size);
	/*https://locklessinc.com/articles/calloc/*/
}

void free(void *ptr)
{
        /* TODO: Implement free(). */
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0)
	   return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (ptr == NULL)
	   return malloc(nmemb * size);
	size_t total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
	   return NULL;
	void *ptr2 = realloc(ptr, total_size);
	if (ptr2 == NULL)
	   return NULL;
	return ptr2;
}
