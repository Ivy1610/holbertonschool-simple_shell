#include "shell.h"

/**
 * execute_command - function to execute user's command
 * @command: char�
 * Return: 0 on success, -1 on failure.
 */
void execute_command(char *command)
{
	char *args[BUFFER_SIZE];
	char *token;
	pid_t pid;
	int status;
	int i = 0;

	token = strtok(command, TOKEN_DELIM);
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, TOKEN_DELIM);
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
}
