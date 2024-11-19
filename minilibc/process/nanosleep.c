#include <internal/syscall.h>
#include <errno.h>
#include <time.h>


int nanosleep(const struct timespec *rqtp, struct timespec *rmtp){
    int result = syscall(__NR_nanosleep, rqtp, rmtp);
    if (result < 0){
       errno = -result;
       return -1;
    }
    return result;
}
