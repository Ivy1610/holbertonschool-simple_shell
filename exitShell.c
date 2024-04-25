#include "shell.h"

/**
 * _exit - function for quit shell
 * @status: getout status
 */
void _exit(int status)
{
    printf("exit\n");
    exit(status);
    
}

