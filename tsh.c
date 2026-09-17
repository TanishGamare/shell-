#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // String to hold input buffer 
    char buf[1024];

    //Prompt
    printf("$ ");

    // Get input from keyboard 
    fgets(buf, 1024, stdin);

    // Run the command
    system(buf);
}
