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

	if (strcmp("exit", argv[0]) == 0)
		exit(EXIT_SUCCESS);

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

	buffer = NULL;
	(void) argv;

	if (argc < 1)
		return (-1);

	n = 0;
	while (1)
	{
		printf("$: ");
		size = getline(&buffer, &n, stdin);
		if (strcmp("exit\n", buffer) == 0)
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
