// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	for(size_t i = 0; i < strlen(source); i++)
		destination[i] = source[i];
	destination[strlen(source)] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	for(size_t i = 0; i < len; i++) {
	   if (source[i] == '\0') {
		while(i < len){
		 destination[i] = '\0';
		 i++;
		}
		 break;
	 } else {
		destination[i] = source[i];
	}}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int length = strlen(destination);
	int total_length = strlen(destination) + strlen(source);
	for(int i = length; i < total_length; i++)
           for (size_t j = 0; j < strlen(source); j++)
		destination[i] = source[j];
	destination[total_length] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int total_length;
	size_t j = 0;
	if (len < strlen(source))
		 total_length = strlen(destination) + len;
	   else
		total_length = strlen(destination) + strlen(source);
	int dest_length = strlen(destination);
	int i = dest_length;
	while(source[j] != '\0' && j < len && i < total_length){
	     destination[i] = source[j];
	     i++;
	     j++;
		}
	destination[total_length] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0, result = 0;
	while(result == 0 && (str1[i] != '\0' || str2[i] != '\0')) {
	     if (str1[i] < str2[i]){
		 result = -1;
	     } else {
	     if (str1[i] > str2[i]) {
		 result = 1;
	     } else {
		i++;
	     }
	     }
	}
	return result;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int i = 0;
	while((str1[i] != '\0' || str2[i] != '\0') && len != 0){
	     if (str1[i] < str2[i]){
		len--;
		return -1;
            } else {
	    if (str1[i] > str2[i]){
		len--;
		return 1;
	    } else {
		 len--;
	         i++;;
	    }
	    }
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	while(str[i] != '\0'){
	     if (str[i] == c)
               	return (char *)&str[i];
	     else
		 i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int length = strlen(str);
	int i = length;
	while(length != 0){
	     if (str[i] == c) {
		return (char *)&str[i];
	     } else {
		  length--;
		  i--;
	     }
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *ptr;
	ptr = haystack;
	while (*ptr){
	      if (strncmp(ptr, needle, strlen(needle)) == 0)
	 	 return (char *)ptr;
	      ptr++;
	}
	return NULL;
	/*www.includehelp.com/c-programs/implement-own-strstr-function.aspx*/
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *ptr, *copy_ptr = NULL;
	ptr = haystack;
	int len_haystack = strlen(haystack);
	int len_needle = strlen(needle);
	if (len_needle ==  0)
	   return (char*)(haystack + len_haystack);
	if(len_haystack < len_needle)
	  return NULL;
	while (strstr(ptr, needle)  != NULL) {
		copy_ptr = (char *)ptr;
		ptr++;
	}
	return (char *) copy_ptr;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest_copy = (char*)destination;
	const char *source_copy = (const char*)source;
	for (size_t i = 0; i < num; i++) {
	    dest_copy[i] = source_copy[i];
	}
	return destination;
	/*www.geeksforgeeks.org/write-memcpy/*/
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char array[num];
	memcpy(array, source, num);
	memcpy(destination, array, num);
	return destination;
	/*https://aticleworld.com/memmove-function-implementation-in-c/*/
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *copy_ptr1 = (const char*)ptr1;
	const char *copy_ptr2 = (const char *)ptr2;
	for (size_t i = 0; i < num; i++){
	    if (copy_ptr1[i] > copy_ptr2[i])
		return 1;
	    else
		if (copy_ptr1[i] < copy_ptr2[i])
		   return -1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *copy = source;
	while(num > 0){
	     *copy = value;
	      copy++;
	      num--;
	}
	return copy;
}
