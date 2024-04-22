#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

/**
 * readCommand - function to take user's input
 * @argv: array of strings to arguments
 * @env: array of string representing the environment variable
 * Return: size (numbers if characters that users input)
 */

char readCommand(char **argv, char **env)
{
	size_t n = 0;
	char *buff = NULL;
	int size;
	char *token;
	int argCount = 0;

	size = getline(&buff, &n, stdin);

	if (size == -1)
	{
		perror("getline failed");
		free(buff);
		exit(EXIT_FAILURE);
	}


	if (buff[size - 1] == '\n')
	{
		buff[size - 1] = '\0';
	}

	token = strtok(buff, " /n");

	while (token != NULL && argCount < MAX_ARGS - 1)
	{
		argv[argCount++] = token;
		token = strtok(NULL, " /n");
	}
	argv[argCount] = NULL; 

	if (argv[0] != NULL)
	{
		exeCmd(argv, env);
	}
	free(buff);
	return (size);
}
