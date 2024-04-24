#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\a\n"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


char readCommand(char **argv, char **env);
char *getPath(char **env, const char *getCmd);
int executCommand(char *args[], char **env);
char **splitLine(char *line);
char *getEnv(char **env, const char *varName);
void print_env(char **env);



#endif /* SHELL_H */

