#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * exeCmd - function to execute user's command
 * @args: array of strings containing the command and its arguments
 * @env: array of strings representing the environment variables
 * Return: 0 on success, -1 on failure.
 */
int exeCmd(char *args[], char **env)
{
	pid_t pid = fork();
	char *newArgs[] = { "/bin/ls", "-l", NULL};
	char *path = getPath(env, args[0]);

	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		path = getPath(env, args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
		execve(path, newArgs, env);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
