#include "shell.h"

/**
 * _path - this functions gets the var from PATH
 * @env: this is an environmental variable.
 * Return: the path value to be be tokenised later with input from user
 */

char *_path(char **env)
{
	char *paths = NULL;
	size_t k = 0;
	size_t j = 0;
	size_t i = 5;

	for (k = 0; _strncmp(env[k], "PATH=", 5); k++)
		;
	if (env[k] == NULL)
		return (NULL);
	for (i = 5; env[k][j]; j++, k++)
		;
	paths = malloc(sizeof(char) * (i + 1));

	if (paths == NULL)
		return (NULL);

	for (j = 5, i = 0; env[k][j]; j++, i++)
		paths[i] = env[k][j];


	paths[i] = '\0';

	return (paths);
}
