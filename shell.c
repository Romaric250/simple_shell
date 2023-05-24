#include "shell.h"
/**
 * executes_command - this func exec the command from user.
 * @env: env variable.
 * @av: argument from user.
 * @path: command path.
 * Return: exits.
 **/
int executes_command(char **env, char **av, int path)
{
	char *_command = NULL;
	char **user_command = NULL;
	int exits = 0;
	int k = 0;

	_command = _getuser_command();
	if (_command)
	{
		path++;
		user_command = _getstoken(_command);
		if (!user_command)

		{
			free(_command);
			return (exits);
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
	return (exits);
}



/**
 * main - main function of the shell project.
 * @ac: argument counter.
 * @av: arguments to be parsed.
 * @env: env variable
 * Return: exits..
 */
int main(int ac, char **av, char **env)
{

	int path = 0;
	int exits = 0;
	(void)ac;

	while (1)
	{
	exits = executes_command(env, av, path);
	}
	return (exits);
}
