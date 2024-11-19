#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
#include <internal/essentials.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

struct timespec {
     long tv_sec;
     long tv_nsec;
};

/*void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
long exit(long exit_code);*/
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
int sleep(unsigned int sec);

#ifdef __cplusplus
}
#endif

#endif
