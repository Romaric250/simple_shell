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
