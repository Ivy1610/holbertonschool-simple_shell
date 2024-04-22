#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * main - function main
 * Return: 0 if success
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	char bytes_read;

	while (1)
	{
		write(STDOUT_FILENO, "CisNotFun$ ", 2);
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				break;
			}
		}

		int status = system(buffer);

		if (status == -1)
		{
			perror("system");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
