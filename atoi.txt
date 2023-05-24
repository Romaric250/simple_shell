#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	int result = 0;
	int i = 0;

	while (info->readfd <= 2 && isatty(STDIN_FILENO) && i == 0)
	{
		result = 1;
		i++;
	}
	return (result);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	int result = 0;

	while (*delim != '\0')
	{
		if (*delim == c)
		{
			result = 1;
			break;
		}
		delim++;
	}
	return (result);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	int result = 0;

	while (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			&& result == 0)
	{
		result = 1;
		break;
	}
	return (result);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(const char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}

		i++;
	}

	return (sign * result);
}

