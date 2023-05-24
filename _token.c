#include "shell.h"

/**
 * _getstoken - get the token from tokenized strings.
 * @lineptre: command entered by the user to be tokenized
 * Return: pointer to an array of tokens
 *
 * Description: This function takes a command entered by the user and tokenizes
 * it based on spaces, newlines, tabs, and carriage returns.
 * It returns an array of pointers to the tokens.
 */

char **_getstoken(char *lineptre)
{
	size_t j = 0;
	int size = 0;
	char **user_cmd = NULL;
	char *token = NULL;

	if (lineptre == NULL)
		return (NULL);

	for (j = 0; lineptre[j]; j++)
	{
		if (lineptre[j] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptre))
		return (NULL);
	user_cmd = malloc(sizeof(char *) * (size + 2));
	if (user_cmd == NULL)
		return (NULL);

	token = _strtok(lineptre, " \n\t\r");
	for (j = 0; token != NULL; j++)
	{
		user_cmd[j] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_cmd[j] = NULL;
	return (user_cmd);
}
