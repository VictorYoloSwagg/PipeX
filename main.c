#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    char *path;
    path = findpath(envp);
    printf("%s \n", path);
    return 0;
}