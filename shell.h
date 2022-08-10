#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

char *_strdup(char *str);
char **tokens(char *buffer);
int _strcmp(char *s1, char *s2);
void print_env(void);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *append_path(char *path, char *command);
char *find_path(void);
int exec(char **argv);

#endif
