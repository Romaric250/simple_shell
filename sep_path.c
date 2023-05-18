#include "shell.h"

/**
 * separatePath - separates the path variables into new strings.
 * @path: path variable to be separated.
 * Return: an array of separated path components.
 **/
char **separatePath(char *path)
{
	int set = 0;
	size_t i = 0;
	char **command = NULL;
	char *token = NULL;

	if (path == NULL)
	return (NULL);
	while (path[i] != '\0')
	{
		if (path[i] == ':')
			set++;
		i++;
	}

	if ((set + 1) == _strlen(path))
		return (NULL);
	command = malloc(sizeof(char *) * (set + 2));
	if (command == NULL)
		return (NULL);
	token = _strtok(path, ":");
	for (i = 0; token != NULL; i++)
	{
		command[i] = token;
	token = _strtok(NULL, ":");
	}
	command[i] = NULL;
	return (command);
}
/**
 * _path - gets the value of the PATH variable.
 * @env: environmental variables.
 * Return: the value of the PATH variable.
 */

char *_path(char **env)
{
	char *path = NULL;
	size_t i = 0;

	while (env[i] != NULL)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = _strdup(env[i] + 5);
			break;
		}
		i++;
	}
	return (path);
}

int main(void)
{
	char *path = _path(environ);
	char **path_components = separatePath(path);

	free(path);
	free(path_components);

	return (0);
}

