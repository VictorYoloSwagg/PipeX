#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    exec(argv[1], envp);
    return 0;
}