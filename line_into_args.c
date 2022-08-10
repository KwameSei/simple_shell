#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

/**
 * read_command - function thats reads input from the terminal
 *
 * Return: line read
 */
int read_command(void)
{

	char cmd[MAX_LINE];

	void bg_job(char *cmdline);

	fgets(cmd, MAX_LINE, stdin);

	/*Handling the "end of file" condition (Ctrl+D)*/
	if (feof(stdin))
	{
		printf("\n");
		exit(0);
	}
	/*Handling the background job or process*/
	bg_job(cmd);


	if (strcmp(cmd, "exit\n") == 0)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
