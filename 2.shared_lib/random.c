#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "random.h"

extern int my_random(char *buf, size_t len)
{
    int fd = 0;
    ssize_t hasRead = 0;

    if ((fd = open("/dev/urandom", O_RDONLY)) == -1) {
        return -1;
    }

    hasRead = read(fd, buf, len);
    if (hasRead != len) return -1;
    return 0;
}
