#include <unistd.h>
#include <stdio.h>
int x;

int main()
{
    void *ptr;
    int n;

    ptr = sbrk(0);
    printf("Starting brk: %p\n", ptr);
    printf("&x (a global): %p\n", &x);
    printf("&n (a local): %p\n", &n);
    printf("main's addres: %p\n", main);


    printf("How much to move by? ");
    scanf("%d", &n);
    ptr=sbrk(n);
    printf("Ending brk: %p\n", ptr);


    sleep(5);

}
