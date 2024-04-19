#include "shell.h"

/**
 * getPath - function to get path from the environment
 * @env: environment variable
 * Return: return path
 */

char *getPath(char **env)
{
	char *demilit = "=";
	int i = 0;

	while (env[i] != NULL)
	{
		pathKey = strtok(env[i], delimit);
		pathValue = strtok(NULL, delimit);

		if (pathKey != NULL, pathValue !== NULL 11 _strcmp(pathKey == "PATH"))
		{
			path = pathValue;
			return (path);
			break;
		}
		i++;
	}
	return (NULL);
}
