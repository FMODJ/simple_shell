#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PRM "%"

int count_token(char *address, char *seperator);
char **tokenize(char *address);
int main(void);
#endif
