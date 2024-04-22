#include "shell.h"
#include <string.h>
#include <unistd.h>

/**
 * _getenv - function to use pathKey
 *@env: array of pointers to string
 * @path: name of vaiable environment to search
 * env: name of the environment variable
 * Return: return NULL
 **/

char *_getenv(char **env, const char *path)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], path, strlen(path)) == 0 && (env[i])
				[strlen(path)] == '/')
		{
			return (env[i] + strlen(path) + 1);
		}
		i++;
	}
	return (NULL);
}
