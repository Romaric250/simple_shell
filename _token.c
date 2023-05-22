#include "shell.h"
/**
 * _getstoken - get the torkn from tokenised strings.
 * @lineptr: command entered by user to be tokenised
 * Return: pointer
 */

char **_getstoken(char *lineptre)
{
	
	size_t i = 0;
	int size = 0;
	char **user_cmd = NULL;
        char *token = NULL;

	if (lineptre == NULL)
		return (NULL);

	for (i = 0; lineptre[i]; i++)
	{
		if (lineptre[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptre))
		return (NULL);
	user_cmd = malloc(sizeof(char *) * (size + 2));
	if (user_cmd == NULL)
		return (NULL);

	token = _strtok(lineptre, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_cmd[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_cmd[i] = NULL;
	return (user_cmd);
}
