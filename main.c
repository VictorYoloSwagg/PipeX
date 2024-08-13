#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    int i;

    i = 0;
    i += exec(argv[1], argv, envp);
    printf("%d \n %d\n",i , argc);
    return 0;
}