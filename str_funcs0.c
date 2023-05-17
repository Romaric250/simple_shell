#include "shell.h"

size_t _strpn(const char *str1, const char *str2);
char *_strchr(const char *str, int chars);
size_t _strspn(const char *str1, const char *str2);


/**
 * _stchr - finds the first occurence of a partiular char in a string.
 * @str: string
 * @chars: character to locate.
 * Return:pointer to char. or NULL.
 **/

char *_strchr(const char *str, int chars)
{
	while(*str! = (char)chars)
	{
		if (!*str++)
			return (0);
	}
	return ((char *)str);
}

/**
 * _strspn - calculates the lengths of the max seg of the string.
 * @str: str to get lenth from.
 * @delim: indicate the char to separate the string into a segment when it is reach.
 * Return: length of the str when the delim point is reached.
 **/

ssize_t _strsnp(const char *str, const char *delim)
{
	size_t val = 0;

	while(*str && _strchr(delim, *str++))
		val++;
	return(val);
}

/**
 * _strtok - divides the string into different tokens.
 * @str: string to be divided.
 * @delim: char to splint the string when it is reached.
 * Return: the tokens.
 **/

char *_strtok(char *str, const char *delim)
{
	static char *s;

	if(str)
		s = str;
	else if (!s)
		return (0);
	str = s + _strspn(s, delim);
	s = str + _strpn(str, delim);
	if(s == str)
		return (s = 0);
	s = *s ? *s = 0,s + 1 : 0;
	return(str);
}

/**
 * _strpn - cal the length of the max seg of the string.
 * @str1: string to span through
 * @str2: STR TO COMPARE
 * Return: len  of seg
 **/

size_t _strpn(const char *str1, const char *str2)
{
	size_t val = 0;

	while (*str1)
	{
		if (_strchr(str2, *str1))
			return (val);
		str1++;
		val++;
	}
	return (val);
}

