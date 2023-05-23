#include "shell.h"
/**
 * _forks - the function creats a forking process
 *@arg: argument.
 *@av: program name.
 *@env: env variable
 *@lineptre: command entered by user in the terminal
 *@id: id of proces
 *@count: new task added.
 *Return: 0 success
 */

int _forks(char **arg, char **av,
		char **env, char *lineptre, int id, int count)
{
	int _status;
	pid_t child_process;
	char *_format = "%s: %d: %s: not found\n";

	child_process = fork();

	if (child_process == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, _format, av[0], id, arg[0]);
			if (!count)
				free(arg[0]);
			free(arg);
			free(lineptre);
			exit(errno);
		}
	}
	else
	{
		wait(&_status);

		if (WIFEXITED(_status) && WEXITSTATUS(_status) != 0)
			return (WEXITSTATUS(_status));
	}
	return (0);
}
