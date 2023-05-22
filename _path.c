#include "shell.h"

/**
 * _pathcommand - gets the var from PATH
 * @env: env variable.
 * Return: the path value used for tok()
 */

char *_pathcommand(char **env)
{
	char *_path = NULL;
	size_t k = 0;
	size_t j = 0;
	size_t i = 5;
	

	for (k = 0; _strncmp(env[k], "PATH=", 5); k++)
		;
	if (env[k] == NULL)
		return (NULL);
	for (i = 5; env[k][j]; j++, k++)
		;
	_path = malloc(sizeof(char) * (i + 1));

	if (_path == NULL)
	{
	
		return (NULL);
	}
	for (j = 5, i = 0; env[k][j]; j++, i++)
		_path[i] = env[k][j];


	_path[i] = '\0';

	return (_path);
}
