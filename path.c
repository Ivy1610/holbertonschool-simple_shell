#include "shell.h"
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
/**
 * getEnv - cherche l'environement du path
 * @env: environnement variable
 * @varName: nom de  l'environement variable
 * Return: NULL
 */
char *getEnv(char **env, const char *varName)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], varName, strlen(varName)) == 0)
		{
			return (env[i] + strlen(varName));
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
 */
char *getPath(char **env, const char *getCmd)
{
	char *fullPath, *pathCopy = NULL;
	char *pathEnv = NULL;
	char *token;
	size_t sizePath;

	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			pathEnv = *env + 5;
			break;
		}
		env++;
	}
	if (!pathEnv)
	{
		fprintf(stderr, "Error: PATH env variable not found\n");
		return (NULL);
	}
	pathCopy = strdup(pathEnv);
	if (!pathCopy)
	{
		perror("Memory allocation erreur");
		exit(EXIT_FAILURE);
	}
	token = strtok(pathCopy, ":");
	while (token)
	{
		sizePath = strlen(token) + strlen(getCmd) + 2;
		fullPath = (char *)malloc(sizePath);
		if (!fullPath)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		sprintf(fullPath, "%s/%s", token, getCmd);

		if (access(fullPath, X_OK) == 0)
		{
			return (fullPath);
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}
