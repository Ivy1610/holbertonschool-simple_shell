#include "shell.h"

/**
 * executCommand - function to execute user's command
 * @args: arguments d'une commande
 * @env: variable d'environement
 * Return: 0 on success, -1 on failure.
 */
int executCommand(char *args[], char **env)
{
	char *path;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
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

		if (execve(path, args, env) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
