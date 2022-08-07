#include <stdio.h>
#include "main.h"

/**
 * *token_str - function that breaks the input into commands and srguments
 *
 * Return: pointer to the next occurence
 */
int main(int argc,char **argv)
{
	char *ptr = ("l am a man");

	char *str = strtok(ptr, " ");
	while (str != NULL)
	{
		printf("%s\n", str);
		str = strtok(NULL, " ");
	}

	return (0);
}

