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
	pid_t pid;
	int status;
	char *path;
	

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		path = getPath(env, args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "PATH environment variable not found\n");
			exit(EXIT_FAILURE);
		}
		if (execve(path, args, env) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
