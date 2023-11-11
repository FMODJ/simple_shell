#include "shell.h"

/**
 * Main - Entry point
 * count_token: To count amount of tokens available in a string
 * tmp: Store the main address to free it later
 * strtok: parse the string based on the seperator given
 * tokenize: tokenizes a string
 * malloc: allocate memory to store tokens
 * strdup; duplicates the string
 * Return: 0 when successful, -1 on error
 */

int count_token(char *address, char *seperator)
{
	int count = 0;
	char *tokens;
	char *tmp;


	tmp = address;
	if (address == NULL)
		return (0);
	tokens = strtok(address, seperator);
	while (tokens)
	{
		count++;
		tokens = strtok(NULL, seperator);
	}
	free(tmp);
	return (count);
}

char **tokenize(char *address)
{
	int count = 0;
	char *seperator = " \n\t";
	char **tokens;
	char *tmp;
	char *str, *token;
	int a = 0;
	char *dup;
	tokens = NULL;
		token = NULL;
		if (address == NULL)
			return (NULL);
		dup = strdup(address);
	count = count_token(dup, seperator);
	if (count == 0)
	{
		free(address);
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
	{
		free(address);
		return (NULL);
	}
	tmp = address;
		token = strtok(address, seperator);
	while (token != NULL)
	{
		str = strdup(token);
		tokens[a++] = str;
		token = strtok(NULL, seperator);
		}
	tokens[a]= NULL;
	free(tmp);
	return(tokens);
}
