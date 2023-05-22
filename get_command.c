#include "shell.h"
/**
 * _getspath - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_getspath(char **env)
{
	size_t ex = 0, ar = 0, count = 5;
	char *path = NULL;

	for (ex = 0; _strncmp(env[ex], "PATH=", 5); ex++)
		;
	if (env[ex] == NULL)
		return (NULL);

	for (count = 5; env[ex][ar]; ar++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (ar = 5, count = 0; env[ex][ar]; ar++, count++)
		path[count] = env[ex][ar];

	path[count] = '\0';
	return (path);
}

/**
 * _getuser_command - get command from user.
 * Return: line of str entered by user.
 */

char *_getuser_command(void)
{
	char *lineptre = NULL;
	size_t _user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$: ", 3);

	if (getline(&lineptre, &_user, stdin) == -1)
	{
		free(lineptre);
		return (NULL);
	}

	return (lineptre);
}
