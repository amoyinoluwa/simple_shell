#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string.h>

extern char **environ;

char *_strdup(char *str);
char **tokens(char *buffer);
int exec(char **argv);
int _strcmp(char *s1, char *s2);

#endif
