// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if (fd < 0){
	   errno = EBADF;
	   return -1;
        }
	if (offset < 0){
	   errno = EINVAL;
	   return -1;
	}
	if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END){
	   errno = EINVAL;
	   return -1;
	}
	off_t  result = syscall(__NR_lseek, fd, offset, whence);
	if (result == -1) {
	   errno = -result;
	   return -1;
	}
	return result;
	/*www.informit.com/articles/article.aspx*/
}
