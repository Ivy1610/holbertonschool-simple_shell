#include "shell.h"
#include <stdio.h>

#define MAX_ARGS 10

/**
 * main - function main
 * Return: 0 if success
 */

int main(void)
{
	char *args[MAX_ARGS];
	int i;

	readCommand(args);

	for (i = 0; args[i] != NULL; i++)
		printf("%s\n", args[i]);
	return (0);
}
