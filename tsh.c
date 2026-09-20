#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // String to hold input buffer 
    char buf[1024];

    //Prompt
    printf("$ ");

    // Get input from keyboard 
    fgets(buf, 1024, stdin);

    // Trim newline
    char *nl = strchr(buf, '\n');
    if (nl) *nl = '\0';

    // Split buf into args
    char *args[50];
    int nargs = 0;
    args[nargs] = strtok(buf, " "); 
    while (args[nargs] != NULL)
    {
        args[++nargs] = strtok(NULL, " ");
    }
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
        execvp(args[0], args);
        
        // something went wrong with exec 
        fprintf(stderr, "coul not exec %s\n", buf);
    }
}
