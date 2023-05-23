#include "shell.h"
/**
 * main - main function of the shell project.
 * @ac argument counter.
 * @av: arguments to be parsed.
 * @env: env variable
 * Return: exits..
 */
int main(int ac, char **av, char **env)
{
	char *_command = NULL;
       char **user_command = NULL;
	int path = 0;
        int exits = 0;
       int k = 0;
	(void)ac;

	while (1)
	{
		_command = _getuser_command();
		if (_command)
		{
			path++;
			user_command = _getstoken(_command);
			if (!user_command)
			{
				free(_command);
				continue;
			}
			if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
				exit_cmd(user_command, _command, exits);
			if (!_strcmp(user_command[0], "env"))
				_getenv(env);
			else
			{
				k = sep_path(&user_command[0], env);
				exits = _forks(user_command, av, env, _command, path, k);
				if (k == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exits);
		}
		free(_command);
	}
	return (exits);
}
