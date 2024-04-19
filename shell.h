#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int readCommand(char *args[]);
char *getPath(char **env);
int exeCmd(char *args[], char **argv, char **env);

#endif
