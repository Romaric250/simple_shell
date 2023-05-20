#include "shell.h"

/**
 * _getenv - gets thee env
 * @env: environmrntal variable
 * Return: NULL.
 *
 */

void _getenv(char **env)
{
	size_t ev;

	ev = 0;
	
	while (env[ev])
	{
		write(STDOUT_FILENO, env[ev], _strlen(env[ev]));
		write(STDOUT_FILENO, "\n", 1);
		
		ev++;
	}
}

/**
 * exit_command - to colse the shell when the user tpyes exit
 * @arg: argument.
 * @lineptre: for inputing the string from user
 * @_exits: the exit
 * Return: Nothing
 **/
void exit_command(char **arg, char *lineptre, int _exits)
{
	int _status = 0;

	if (!arg[1])
	{
		free(lineptre);
		free(arg);
		exit(_exits);
	}
	_status = atoi(arg[1]);
	
	free(lineptre);
	free(arg);
	exit(_status);
}

