#include "shell.h"
#include <string.h>
#include <unistd.h>
/**
* getPath - function to get path from the environment
* @env: environment variable
* @getCmd: name of the command to find in the PAT
* Return: return path or NULL
**/

char *getPath(char **env, const char *getCmd)
{
	char *cmdValue, *path, *pathCopy = NULL;
	char *pathKey = _getenv(env, "PATH");
	size_t cmdValueSize = 0;

	while (pathKey == NULL)
	{
		fprintf(stderr, "Error: PATH env variable not found\n");
		return (NULL);
	}
	pathCopy = strdup(pathKey);
	if (!pathCopy)
	{
		fprintf(stderr, "unable to allocate buffer\n");
		exit(EXIT_FAILURE);
	}

	for (char *path = strtok(pathCopy, "/");
			path != NULL; path = strtok(NULL, "/"))
	{
		cmdValueSize = strlen(path) + strlen(getCmd) + 2;
		cmdValue = malloc(cmdValueSize);
		if (cmdValue == NULL)
		{
			fprintf(stderr, "unable to allocate buffer\n");
			exit(EXIT_FAILURE);
		}
		sprintf(cmdValue, "%s/%s", path, getCmd);

		if (access(cmdValue, X_OK) == 0)
		{
			free(pathCopy);
			return (cmdValue);
		}
		free(cmdValue);
	}
	free(pathCopy);
	return (NULL);
}
