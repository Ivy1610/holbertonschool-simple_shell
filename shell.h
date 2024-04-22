#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

char readCommand(char **argv, char **env);
char *getPath(char **env, const char *getCmd);
char exeCmd(char *args[], char **env);

#endif
