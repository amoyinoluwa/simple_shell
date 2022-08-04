#include "shell.h"

int exec(char *args)
{
}

int main(int argc, char **argv)
{
	pid_t child;
	size_t n;
	int status;
	char **env, *buffer;

	if (argc < 1)
		return (-1);

	env = environ;
	n = 0;
	while (1)
	{
		printf("$: ");
		getline(&buffer, &n, stdin);
	}
	child = fork();

	if (child == -1)
	{
		perror("Process failed");
		return (-1);
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
