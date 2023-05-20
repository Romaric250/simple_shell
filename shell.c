#include "shell.h"

/**
 * main - min function in the program.
 * @ac: count the number of arguments parsed.
 * @av: represent an arg.
 * @env: environmental variablee.
 * Return: 0.
 **/

int main(int ac, char **av, char **env)
{
	int value_path = 0;
	int exits = 0, i = 0;
	char *_command = NULL;
	char **comand_user = NULL;
	
	(void)ac;
	while (1)
	{
		_command = _get_command();

		if (_command)
		{
			value_path++;

			comand_user = _token(_command);

			if (!comand_user)
			{
				free(_command);
				continue;
			}

			if ((!_strcmp(comand_user[0], "exit")) && comand_user[1] == NULL)
				exit_command(comand_user, _command, exits);
			if (!_strcmp(comand_user[0], "env"))
			{
				_getenv(env);
			}

			else
			{
				/*the path function here*/
				i = _paths(&comand_user[0], env);
				exits = _fork(comand_user, av, env, _command, value_path, i);
				if (i == 0)
					free(comand_user[0]);
			}
			free(comand_user);
		}

		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);
			exit(exits);
		}
		free(_command);
	}
	return (exits);
}


