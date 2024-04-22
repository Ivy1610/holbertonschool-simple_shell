#include "shell.h"

/**
 * tokenize - function to help tokenize users input
 * @ArgC: storage for tokens
 * @command: command received from the user
 * Return: number of tokens
 */

int tokenize(char *command, char *ArgsC[])
{
	char *delimit = " ", *token;
	int count = 0;

	token = strtok(command, delimit);

	while(token)
	{
		ArgsC[count++] = token;
		token = strtok(NULL, delimit);
	}
	return (count);
}
