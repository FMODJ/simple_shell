#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ

int main(void);
{
	char *lineptr = NULL;
	size_t n;
	ssize_t get_line_val;
	char *token;
		char *command_args[1024];

	do {
		printf("(shell)% ");
		get_line_val = getline(&lineptr, &n, stdin);

		if (get_line_val == EOF || get_line_val == -1)
		{
		free(lineptr);
		exit(0);
		}


	int fm = 0;
		token = strtok(lineptr, " \n\t");

	while (token != NULL && fm < 1024
	{
		command_args[i] = strdup(token);
		token = strtok(NULL, " \n\t");
		fm += 1;
	}
		command_args[fm] = NULL;

	char cmd[1024];

	strcpy(cmd, command_args[0]);
	strcat(cmd, "/bin");

	execve(cmd, command_args, environs);
	} while (1);

	free(lineptr);
	return (0);
}
