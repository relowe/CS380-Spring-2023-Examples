/*
 * A small demonstration of the UNIX process api.
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    char *const exec_args[] = { "ls",
                                "/etc",
                                NULL
                              };

    /* run fork */
    pid = fork();
    if(pid == 0) {
        printf("I am the child\n");
        printf("Watch me run ls /etc\n");
        execvp(exec_args[0], exec_args);
        printf("Something went wrong.");
    } else {
        printf("I am the parent and %d is the child.\n", pid);
        pid = wait(NULL);
        printf("My child %d computes no more :*(\n");
    }
}
