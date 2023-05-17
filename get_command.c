#include "shell.h"

/**
 * _token - the function gets the string token.
 * @lineptre: the command to be entered by user.
 * Return: a pointer to the tokenised string.
 **/

char **_token(char *lineptre)
{
	int set = 0;
	size_t k = 0;
	char **_comand = NULL;
	char *token = NULL;


	if (lineptre == NULL)
		return (NULL);


	for (k = 0; lineptre[k]; k++)
	{
		if (lineptre[k] == ' ')
			set++;
	}
	if ((set + 1) == _strlen(lineptre))
		return (NULL);
	_comand = malloc(sizeof(char *) * (set + 2));
	if (_comand == NULL)
		return(NULL);
	token = _strtok(lineptre, " ");
	for (k = 0; token != NULL; k++)
	{
		_comand[k] = token;
		token = _strtok(NULL, " ");
	}
	_comand[k] = NULL;
	return (_comand);
}


/**
 * _get_command - display $ on the terminal and then the user can type cmds.
 * Return: the command the user entered.
 **/

char *_get_command(void)
{
	size_t user_input = 0;
	char *lineptre = NULL;
	
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "=>$: ", 2);
	if (getline(&lineptre, &user_input, stdin) == -1)
	{
		free(lineptre);
		return (NULL);
	}
	return (lineptre);
}

