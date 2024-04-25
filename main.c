#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ARGS 10
#define UNUSED(x) (void)(x)
/**
 * print_env - imprime l'environement
 * @env: environnement variable
 */
void print_env(char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * main - main function
 * @argc: nombre d'arguments
 * @argv: chaine d'arguments
 * @env: liste d'environement variable
 * Return: EXIT_SUCCESS
 */

int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	int status;
	ssize_t bytes_read;
	size_t buffsize = 0;
	char **args;
	pid_t pid;

	UNUSED(argc);
	UNUSED(argv);

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			printf("CisNotFun;)$ ");
			fflush(stdout);
		}

		bytes_read = getline(&command, &buffsize, stdin);
		if (bytes_read == -1)
		{
			perror("getline failed");
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else if (command[bytes_read - 1] == '\n')
		{
			command[bytes_read - 1] = '\0';
		}
		if (strcmp(command, "exit") == 0)
		{
		       	_exit(0);
		}
		args = splitLine(command);
		if (args == NULL)
		{
			fprintf(stderr, "failed to split command\n");
			free(command);
			continue;
		}

		pid = fork();
		if (pid == -1) 
		{
			perror("Erreur fork");
			free(command);
			free(args);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			executCommand(args, env);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}

		free(command);
		free(args);
	}
	return (EXIT_SUCCESS);
}
