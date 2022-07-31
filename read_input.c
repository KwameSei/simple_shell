#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * read_input - Entry point
 * Return: number of characters from input
 */

int read_input(void)
{
	int nread;
	char *str;
	size_t buf;

	buf = 0;
	nread = 0;

	printf("$");
	nread = getline(&str, &buf, stdin);

	return (nread);
}
