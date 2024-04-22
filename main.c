#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/**
 * main - function main
 * Return: 0 if success
 */

int main(void)
{
	char *args[MAX_ARGS];
	char *env[] = {"PATH=/bin/ls, NULL"};


	while (1)
	{
		printf("CisNotFun;)$ ");
		fflush(stdout);

		if (readCommand(args, env) == -1)
		{
			break;
		}
		if (args[0] != NULL)
		{
			if (exeCmd(args, env) == -1)
			{
				fprintf(stderr, "Error: %s\n",args[0]);
			}
		}
	}
	return (0);
}
