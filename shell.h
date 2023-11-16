#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PRM "%"

extern char **environ;
int count_token(char *address, char *seperator);
char **tokenize(char *address);

#endif
