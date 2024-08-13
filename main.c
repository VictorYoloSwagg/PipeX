#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    char *path;
    path = findpath(argv[1], envp);
    printf("%s %d\n", path);
    return 0;
}