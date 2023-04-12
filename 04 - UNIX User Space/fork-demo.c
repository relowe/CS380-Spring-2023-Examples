#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = malloc(sizeof(int));

    if(fork()) {
        *ptr = 12;
        while(1) {
            printf("Parent ptr=%p, *ptr=%d\n", ptr, *ptr);
            sleep(1);
        }
    } else {
        *ptr = -12;
        while(1) {
            printf("Child ptr=%p, *ptr=%d\n", ptr, *ptr);
            sleep(1);
        }
    }
}
