#include "shell.h"

/**
 * main - The main function
 * @argc: argument counter
 * @argv: the argument vector
 *@env: environment variable
 * Return: 0 on success, -1 if it fails
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *buffer;
	char *new_buf;
	size_t size;
	ssize_t read_value;
	char **tokens, *sep;
	int index = 0;

	sep = "\n\t ";
	environ = dynamic_env(env);

	do {
		if (isatty(STDIN_FILENO))
			prompt_user();

		buffer = NULL;
	tokens = NULL;
	read_value = get_line(&buffer, &size, STDIN_FILENO);
	if (read_value == 1)
	{
		free(buffer);
	continue;
	}

	if (read_value == -1)
	{
		free(buffer);
		free_mem(environ);
		exit(EXIT_SUCCESS);
	}

	new_buf = process_buf(buffer);
	tokens = tokenize(new_buf, sep);

	if (tokens == NULL)
		continue;

	process_command(tokens, env, &status, argv[0];
			free_mem(tokens);
	} while (TRUE);

	free_mem(environ);
	return (status);
}

/**
*handle_sp_char - handles the character processes with special tokens
*@tokens: the tokens to be evaluated
*Return: the pointer to the special character
*/

char *handle_sp_char(char **tokens)
{
char *special_chars = ";||&&";
	char *sp_char;

	int f = 0;

	do {
		sp_char = strstr(special_chars, tokens[f]);
		if (sp_char)
			return (sp_char);
		f++;
	} while (tokens[f]);

	return (NULL);
}

/**
*process_command - processes command lines
*@tokens: tokens
*@env: environment
*@status: the status code
*@argv: arguments variables
*Return: 0 at the end of the loop
*/
int process_command(char **tokens, char **env, int *status, char *argv)

{
char *sp_chars = ";||&&", *checked_char, **new_tk, **tk = tokens;
int num = 0, f, prev;

	checked_char = handle_sp_char(tokens);
	if (!checked_char)
		path_handler(tokens, env, status, argv);
	else
	{
		for (num = 0; tk[num]; num++)
	{
		prev = num;
		while (tk[num] && !strstr(sp_chars, tk[num]))
		num++;

	new_tk = malloc(sizeof(char *) * ((num - prev) + 1));
	for (f = 0; f < (count - prev); f++)
		new_tk[f] = strdup(tk[prev + f]);

	new_tk[f] = NULL;
	checked_char = tk[count];
		path_handler(new_tk, env, status, argv);

		if (checked_char != NULL)
		{
			if (strcmp(checked_char, "||") == 0)
		{
			if (*status == 0)
				return (flusher(new_tk));
		}
			else if (strcmp(checked_char, "&&") == 0)
		{
			if (*status != 0)
			return (flusher(new_tk));
		}
		}
	else
		return (flusher(new_tk));

	free_mem(new_tk);
	}
	}

	return (0);
}

/**
  *flusher - flushes memory
  *@tokens: the tokens
  *Return: 1 on success
  */
int flusher(char **tokens)
{
	free_mem(tokens);
	return (1);
}
