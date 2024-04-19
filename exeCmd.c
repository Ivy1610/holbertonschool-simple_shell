#include "shell.h"

/**
 * exeCmd - function to execute user's command
 * @argsC: array of commands from the users
 * @argv: argument
 * Return: 0 if success
 */

int exeCmd(char *args[], char **argv, char **env)
{
	pid_t pid;
	int exe, status;

	pid = fork();
	char *path = getPath(env);
	printf("%s", path);
	if (pid == -1)
	{
		perror("Create process failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		exe = execve(argsC[0], argsC[0], argsC, NULL);
	if (exe == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else wait(&status);

	return (0);
}
