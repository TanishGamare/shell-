#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // String to hold input buffer 
    char buf[1024];

    //Prompt
    printf("$ ");

    // Get input from keyboard 
    fgets(buf, 1024, stdin);

    // Run the command using system shell ><
    //system(buf);

    // Fork and exec 
    pid_t pid = fork();

    if(pid > 0)
    {
        // we are the parent 
        wait(NULL);
    }
    else 
    {
        // we are the child 
        execlp(buf, buf, NULL);
        
        // something went wrong with exec 
        fprintf(stderr, "coul not exec %s\n", buf);
    }
}
