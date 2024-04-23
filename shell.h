#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\n"

void execute_command(char *command);

#endif /* SHELL_H */

