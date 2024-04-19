#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

/**
 * readCommand - function to take user's input
 * Return: size (numbers if characters that users input)
 */

int readCommand(char **argv, char **env)
{
	size_t n = 0;
	char *buff = NULL;
	int size;

	printf("$ ");
	size = getline(&buff,  &n, stdin);
	/*the condition (stdin != NULL) is unnecessary cuz stdin is always valid (stdin is a predefined file pointer)*/
	if (size == -1)
	{
		if (buff == NULL)
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
		else
		{
		perror("input error");
		}
	}
	else
	/*tokenize the input string so that we canseparate the command and its arguments and store it in the args array.*/
	{
		char *token = strtok(buff, " /n");
		int i = 0;
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " /n");
		}
		args[i] = NULL; /* to mark the end of the args*/
		exeCmd(argC, argv, env);
	}
	free(buff);
	return (size);
}
