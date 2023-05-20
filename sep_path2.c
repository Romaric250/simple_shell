#include "shell.h"
/**
 * *_paths - this func sep pthe path into dif strings.
 * @arg: the input command from user.
 * @env: the env variable.
 * Return: pointer to the sep strings.
 **/

int _paths(char **arg, char **env)
{
	struct stat lineptre;

	char *path1 = NULL, *path2 = NULL;
	size_t v_path, _command;
	char *token = NULL;

	if(stat(*arg, &lineptre) == 0)
		return (-1);

	path1 = _path(env);

	if (!path1)
		return (-1);
	token = _strtok(path1, ":");
	_command = _strlen(*arg);

	while (token)
	{
		v_path = _strlen(token);
		path2 = malloc(sizeof(char) * (v_path + _command +2));

		if (!path2)
		{
			free(path1);
			return(-1);
		}
		path2 = _strcpy(path2, token);
		_strcat(path2, "/");
		_strcat(path2, *arg);

		if ( stat(path2, &lineptre) == 0)
		{
			*arg = path2;
			free(path1);
			return (0);
		}
		free(path2);
		token = _strtok(NULL,":");
	}
	free(path1);
	return (-1);
}

