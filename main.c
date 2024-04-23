#include "shell.h"

/**
 * main - main function
 * Return: void
 */

int main(void)
{
	char *buffer;
	size_t bufsize = BUFFER_SIZE;
	ssize_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("#cisfun$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline error");
				exit(EXIT_FAILURE);
			}
		}
		buffer[strcspn(buffer, "\n")] = 0;
		execute_command(buffer);
	}
	free(buffer);
	return (EXIT_SUCCESS);
}
