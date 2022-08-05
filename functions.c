#include "shell.h"

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
