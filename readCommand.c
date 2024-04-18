#include "shell.h"

/**
 * readCommand - function to take users input
 * Return: size (numbers if characters that users input)
 */

int readCommand(void)
{
	size_t n = 0;
	char *buff = NULL;
	int size;

	printf("$ ");
	size = getline(&buff,  &n, stdin);
	if (size == -1)
	{
		if (stdin != NULL)
		{
			free(buff);
			exit(0);
		}
		else
		{
		perror("input error");
		free(buff);
		}
	}
	free(buff);
	return (size);
}
