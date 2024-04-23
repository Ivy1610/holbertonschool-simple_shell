#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\n"

int main(void)
{
	char *buffer;
	size_t bufsize = BUFFER_SIZE;
	ssize_t characters;
	char *token;
	char *args[BUFFER_SIZE];
	pid_t pid;
	int status;
	int i;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("#cisfun$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline error");
				exit(EXIT_FAILURE);
			}
		}
		buffer[strcspn(buffer, "\n")] = 0;
		i = 0;
		token = strtok(buffer, TOKEN_DELIM);
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
	free(buffer);
	return EXIT_SUCCESS;
}
