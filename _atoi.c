#include "shell.h"

/**
 * _num_id - find index where a digit is first found in string
 * @s: string to search
 * Return: integer index where digit is first found
 */

int _num_id(char *s)
{
	int j;
	int len = _strlen(s);

	for (j = 0; j < len; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
			return (j);
	}
	return (-1); /* return -1 if no digits found */
}

/**
 * find_sign - determine if integer is negative
 * @s: integer
 * Return: integer 1 or -1
 */
int find_sign(char *s)
{
	int negatives = 0, j = 0, sign = 1;
	int num_id = _num_id(s);

	while (j < num_id)
	{
		if (s[j++] == '-')
			negatives++;
	}

	if (negatives % 2 != 0)
		sign = -1;

	return (sign);
}

/**
 * _atoi - convert string to int
 * @s: string to convert
 * Return: integer
 */

int _atoi(char *s)
{
	int start_id = _num_id(s);
	int sign;
	int digits = 0;
	int t = 1, j;
	unsigned int num = 0;

	if (start_id < 0) /* if no digits found, exit program */
		return (0);

	sign = find_sign(s);

	while ((s[start_id] >= '0' && s[start_id] <= '9')
	       && (start_id < _strlen(s))) /* count digits to print */
	{
		digits += 1;
		start_id++;
	}

	j = 1;
	while (j < digits) /* find powers of ten to multiply places */
	{
		t *= 10;
		j++;
	}

	for (j = _num_id(s); j < (_num_id(s) + digits); j++) /* calculate num */
	{
		num += (s[j] - '0') * t;
		t /= 10;
	}

	return (num * sign);
}
