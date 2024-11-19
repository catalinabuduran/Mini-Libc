#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int sleep(unsigned int sec) {
	struct timespec req, rem;
	req.tv_sec =  sec;
	req.tv_nsec = 0;
	while(nanosleep(&req, &rem) == -1) {
	     if (rem.tv_sec == 0 && rem.tv_nsec == 0) {
		return 0;
	     }
             req = rem;
	}
	return 0;
}
