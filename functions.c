#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string passed
 * Return: returns length of string passed
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strdup - return ptr to new str with copy of input
 * @str: input string
 * Return: copy of str
 */

char *_strdup(char *str)
{
	int i;
	int n = 0;
	char *copy = NULL;

	if (str == NULL)
		return (NULL);

	while (str[n] != '\0')
	{
		n++;
	}
	copy = malloc((n + 1) * sizeof(char));

	if (copy != NULL)
	{
		for (i = 0; i < n; i++)
		{
			copy[i] = str[i];
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);	
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: zero or non zero
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * tokens - converts str to tokens
 * @buffer: str buf
 * Return: Tokens
 */

char **tokens(char *buffer)
{
	char *token, *delim, **tokens;
	int counter, i, len;

	counter = 0;
	len = 0;
	i = 0;
	delim = " ";

	while (buffer[i] != '\0')
	{
		if (buffer[i] == ' ')
			len++;
		i++;
	}
	tokens = malloc((len + 1) * sizeof(char));
	if (tokens == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(1);
	}
	token = strtok(buffer, delim);
	while (token)
	{
		tokens[counter] = _strdup(token);
		token = strtok(NULL, delim);
		counter++;
	}
	tokens[counter] = token;
	return (tokens);
}
