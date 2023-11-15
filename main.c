#include "shell.h" 

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *prompt_m = "% ";
	char *address;
	size_t size;
	ssize_t read_value;
	char **tokens;
	int index = 0
		;
	while (1)
	{
		address = NULL;
		tokens = NULL;
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt_m, strlen(prompt_m));
		read_value = getline(&address, &size, stdin);
		if (read_value == 1)
		{
			free(address);
			continue;
		}
		if (read_value == -1)
		{
			free(address);
			exit(EXIT_SUCCESS);
		}
		tokens = tokenize(address);
		if (tokens == NULL)
			continue;
		while (tokens[index] != NULL)
		{
			printf("%s\n", tokens[index]);
			index++;
		}
	}
	return (0);
}
