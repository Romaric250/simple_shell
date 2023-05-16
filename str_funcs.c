#include "shell.h"

/**
 * _strcmp - compares values of two different strings.
 *@str1: string 1
 *@str2: string 2
 *Return: 0
 */

int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - str2[i]);
	}
	return (0);
}

/**
 * _strlen - gets the length of a string str.
 * @str: string to get len from.
 * Return: len of str
 */
int _stlen(char *str)
{
	int len = 0;

	while (*(str +len) != '\0')
		len++;
	return (len);
}

/**
 * _strcat - concantenate or combines two diffeent strings.
 * @desk: cstring 1;
 * @src: string 2;
 * Return: desk
 */

char *_strcat(char *desk, char *src)
{
	int a = 0;
	int b = 0;
	
	while (desk[a] != '\0')
		a++;
	while (src[b] != '\0')
	{
		desk[a] = src[b];
		a++;
		b++;
	}
	desk[a] = '\0';
	return (desk);
}

/**
 * _strncmp - gets the dif between two strings.
 * @str1: string 1
 * @str2: string 2
 * Return: dif between str1 and str2.
 */

size_t _strncmp(char *str1, char *str2, size_t k)
{
	size_t i, j;
	for(j = 0; str1[j] != '\0' && j < k; j++)
	{
		i = str1[j] - str2[j];
		if (i != 0)
			return (i);
	}
	return (0)
}



/**
 * _strcpy - this function copies a string from a pointer into another srting
 * @desk: place to copy string to.
 * @src: place where the string is copied
 * Return: desk
 */

char *_strcpy(char *desk, char *src)
{
	int j = 0;
	
	while(*(src + j) != '\0')
	{
		*(desk + j) = *( scr + j);
		++j;
	}
	*(desk + j) = *(src - j);
	return(desk);
}

