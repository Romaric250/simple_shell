#include "shell.h"

/**
 * _atois - this func converts an str to an int.
 * @str: the str to convert
 * Return: the int val of str.
 **/

int _atois(const char *str)
{
	int s = 1;
	int res = 0, i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}

	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}
