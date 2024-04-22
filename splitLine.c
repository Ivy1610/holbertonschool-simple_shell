#include "shell.h"
#include <string.h>

#define MAX_TOKENS 64
#define MAX_LINE_SIZE 1024

/**
 * splitLine - function to split a line into tokens (words) base on spaces
 * @line: input string to be split
 * Return: Array of tohens (words) or NULL on failure
 */
char **splitLine(char *line)
{
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));
	char *token;
	int token_index = 0;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		if (token_index >= MAX_TOKENS - 1)
		{
			fprintf(stderr, "too many tokens (exceeds max)\n");
			free(tokens);
			return (NULL);
		}
		tokens[token_index] = token;
		token_index++;
		token = strtok(NULL, " \t\r\n\a");
	}
	return (tokens);
}
