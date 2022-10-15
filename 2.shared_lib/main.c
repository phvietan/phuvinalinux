#include <stdio.h>
#include "random.h"

int main() {
    int i = 0;
    char buf[10];

    if (my_random(buf, 10) == -1) {
        fprintf(stderr, "Error when generate random");
        return 1;
    }

    for (; i < 10; ++i)
        printf("%d,", buf[i]);
    return 0;
}
