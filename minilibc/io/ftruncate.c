// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int ret = syscall(__NR_ftruncate, fd, length);
	/*if (fd < 0 || length < 0){
	   errno = -result;
	   return -1;
	}*/
        if (ret < 0){
	   errno = -ret;
           return -1;
	}
	return ret;
}
