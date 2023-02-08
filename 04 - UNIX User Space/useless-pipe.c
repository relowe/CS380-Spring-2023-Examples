#include <unistd.h>

int main()
{
    int p[2];
    char buf[100];
    int n;

    if(pipe(p)!=0) {
        write(2, "Pipe Failed\n", 12);
    }

    write(p[1], "Hello, Pipe\n", 12);
    n = read(p[0], buf, 100);
    write(1, buf, n);

}
