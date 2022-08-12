#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_command - function thats reads input from the terminal
 *
 * Return: line read
 */
int read_command(void)
{

	void bg_job(char *cmdLine);

	char *cmd = NULL;
	size_t bufsize = 0;

	getline(&cmd, &bufsize, stdin);

	bg_job(cmd);

	if (strcmp(cmd, "exit\n") == 0)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
