#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int fd;

    if (fd = open("/tmp/file.txt",
        O_CREAT | O_WRONLY | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
    ) == -1) {
        fprintf(stderr, "Unable to create /tmp/file.txt file");
        exit(1);
    }

    printf("fd ne = %d\n", fd);
    puts("\n");

    char buf[20] = "test ne huhu";
    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}
