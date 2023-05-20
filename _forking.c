#include "shell.h"

/**
 * _fork - forks the current process by creating a child.
 * @arg: get the comand
 * @name: name of program.
 * @env: the environmental variable
 * @lineptre: the user input
 * @id: id of the process
 * @count: adds a new test or process.
 * Return: 0
 **/


int _fork(char **arg, char **name, char **env, char *lineptre, int id, int count)
{
	int _status;
	char *_format = "%s: %d: %s: not found\n";
	pid_t = child_process;

	child_process = fork();

	if (child_process == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(sderr, _format, name[0], id, arg[0]);
			
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
		if (WIFEXITED(_status) && WEXITSTATUS(status) ! = 0)
			return (WEXITSTATUS(_status));
	}
	return (0);
}
