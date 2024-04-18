#include "shell.h"

/**
 * readCommand - function to take user's input
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
	free(buff);
	return (size);
}
