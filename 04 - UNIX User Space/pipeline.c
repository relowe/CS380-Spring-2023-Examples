/*
 * Establish the pipeline ls /etc | more
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    char *const ls_args[] = { "ls",
                                "/etc",
                                NULL
                              };
    char *const more_args[] = { "more",
                                NULL
                              };
    int p[2];

    /* create a pipe */
    if(pipe(p)!=0) {
        fprintf(stderr, "Could not create pipe\n");
        return -1;
    }

    /* run fork */
    pid = fork();
    if(pid == 0) {
        /* this child is going to become ls */
        close(1);  /* close stdout */
        dup(p[1]); /* redirect through the pipe */
        close(p[1]); /* close both pipe ends */
        close(p[0]);
        execvp(ls_args[0], ls_args);
        return -2;
    } 

    pid = fork(); 
    if(pid == 0) {
        /* this child is going to become more */
        close(0);  /* close stdin */
        dup(p[0]); /* redirect through the pipe */
        close(p[1]); /* close both pipe ends */
        close(p[0]);
        execvp(more_args[0], more_args);
        return -2;
    } 

    wait(NULL);
    wait(NULL);
    printf("All done!\n");
}
