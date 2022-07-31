#include "main.h"
#include <string.h>

/**
 * str_token - Tokenizes the string input
 *
 * Return: pointer to the next token
 */

char *str_token()
{
	char *token = NULL;
	char delim[] = "\n";
	char **tokens = NULL;
	int i = 0;

	token = strtok(nread, delim);

	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}

	return (token);

}
