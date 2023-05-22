#include "shell.h"
/**
 * exit_cmd - the func closes the shell when exit is typed.
 * @arg: argument.
 * @lineptr: standar input string
 * @_exit: exiting value
 * Return: kind of nothing.
 */
void exit_cmd(char **arg, char *lineptre, int _exit)
{
	int _status = 0;

	if (!arg[1])
	{
		free(lineptre);
		free(arg);
		exit(_exit);
	}
	_status = atoi(arg[1]);

	free(lineptre);
	free(arg);
	exit(_status);
}

/**
 *_getenv - gets the env variable.
 *@env: env variable
 *Return: 0
 */

void _getenv(char **env)
{
	size_t env_v = 0;

	while (env[env_v])
	{
		write(STDOUT_FILENO, env[env_v], _strlen(env[env_v]));
		write(STDOUT_FILENO, "\n", 1);
		env_v++;
	}
}
