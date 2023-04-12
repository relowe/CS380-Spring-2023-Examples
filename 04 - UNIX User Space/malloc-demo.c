#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int *ptr;
    int n;

    n = atoi(argv[1]);

    for(int i=0; i<n; i++) {
    ptr = malloc(sizeof(int));
    free(ptr);
    }

}
