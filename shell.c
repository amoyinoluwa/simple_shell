#include "shell.h"

/**
 * exec - creates a child process in shell
 * @args: arguments
 * Return: -1 or nothing
 */

int exec(char **argv)
{
	pid_t child;
	int status;
	char **env = environ;

	if (_strcmp("exit", argv[0]) == 0)
		exit(-1);
	if (_strcmp("exit\n", argv[0]) == 0)
		exit(-1);
	child = fork();

	if (child == -1)
	{
		perror("Process failed");
		exit(-1);
	}
	if (child == 0)
	{
		execve(argv[0], argv, env);
		perror("Error");
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * free_mem - frees allocated buffer
 * @buf: buffer
 * Return: Nothing
 */

void free_mem(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
/**
 * main - main shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char **argv)
{
	size_t n;
	char **tokenize, *buffer;
	int size;

	(void) argv;
	tokenize = NULL;
	buffer = NULL;

	if (argc < 1)
		return (-1);
	
	n = 0;
	while (1)
	{
		free_mem(tokenize);
		free(buffer);
		printf("$: ");
		size = getline(&buffer, &n, stdin);
		if (_strcmp("exit\n", buffer) == 0)
			return (-1);
		if (size == -1)
			return (-1);
		if (buffer[size - 1] == '\n')
			buffer[size - 1] = '\0';
		tokenize = tokens(buffer);
		exec(tokenize);
	}
	return (0);
}
