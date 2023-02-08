#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    close(1);
    open("hello.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644);
    printf("Hello, world\n");
}
