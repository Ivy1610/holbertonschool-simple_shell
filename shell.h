#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

char readCommand(char **argv, char **env);
char *getPath(char **env, const char *getCmd);
int exeCmd(char *args[], char **env);
char **splitLine(char *line);
char *_getenv(char **env, const char *path);

#endif
