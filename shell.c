#include "shell.h"

/**
 * exec - creates a child process in shell
 * @args: arguments
 * Return: -1 or nothing
 */

int exec(char *args)
{
	pid_t child;
	int status;

	child = fork();

	if (child == -1)
	{
		perror("Process failed");
		exit(-1);
	}
	if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Execution error");
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
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
	int status;
	char **tokens, *buffer;

	if (argc < 1)
		return (-1);

	n = 0;
	while (1)
	{
		printf("$: ");
		if (getline(&buffer, &n, stdin) == -1)
			return (-1);
		if (strcmp("exit", buffer) == 0)
		{
			free(buffer);
			return (-1);
		}
		tokens = tokens(buffer);
		exec(tokens);
	}
}
