#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

/**
 * readCommand - function to take user's input
 * @argv: array of strings to arguments
 * @env: array of string representing the environment variable
 * Return: 0
 */

char readCommand(char **argv, char **env)
{
	size_t n = 0;
	ssize_t bytes_read;
	char *buff = NULL;
	char *token;
	int argCount = 0;

	bytes_read = getline(&buff, &n, stdin);

	if (bytes_read == -1)
	{
		perror("getline failed");
		free(buff);
		return (-1);
	}

	if (buff[bytes_read - 1] == '\n')
	{
		buff[bytes_read - 1] = '\0';
	}

	token = strtok(buff, " \n");

	while (token != NULL && argCount < MAX_ARGS - 1)
	{
		argv[argCount++] = token;
		token = strtok(NULL, " ");
	}
	argv[argCount] = NULL;
	if (argv[0] != NULL)
	{
		executCommand(argv, env);
	}
	free(buff);
	free(token);
	return (0);
}
