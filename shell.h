#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
int readCommand(char *args[]);
char *getPath(char **env);
int exeCmd(char *argsC[], char **argv, char **env);

#endif
