#include <fcntl.h>
#include <unistd.h> 

int main()
{
    char name[20];
    int n;

    write(1, "What is your name? ", 19);
    n = read(0, name, 20);

    close(1);
    open("output.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644);
    
    /* trim our input */
    if(name[n-1] == '\n') n--;

    write(1, "Hello, ", 7);
    write(1, name, n);
    write(1, ", how are you?", 14);

    close(1);
}
