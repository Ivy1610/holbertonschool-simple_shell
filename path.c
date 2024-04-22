#include "shell.h"
#include <string.h>
#include <unistd.h>

/** function to use pathKey
 *@env: array of pointers to string
 * environ: name of the environment variable
 **/

char *_getenv(char **env, const char *path)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], path, strlen(path)) == 0 && (env[i])[strlen(path)] == '=')
		{
			return (env[i] + strlen(path) + 1);
		}
		i++;
	}
	return (NULL);
}

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
	path = strtok(pathCopy, "=");

	while (path != NULL)
	{
		cmdValueSize = strlen(path) + strlen(getCmd) + 2;
		cmdValue = (char *)malloc(cmdValueSize);

		if (cmdValue == NULL)
		{
			fprintf(stderr, "unable to allocate buffer\n");
			exit(EXIT_FAILURE);
		}
		strcpy(cmdValue, path);
		strcat(cmdValue, "/");
		strcat(cmdValue, getCmd);

		if (access(cmdValue, X_OK) == 0)
		{
			free(pathCopy);
			return (cmdValue);
		}
		free(cmdValue);
		path = strtok(NULL, "=");
	}
	free(pathCopy);
	return (NULL);
}
