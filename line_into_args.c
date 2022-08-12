#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

int read_command(void)
{

/*	char cmd[MAX_LINE];	*/
	void bg_job(char *cmdline);
	
	char *cmd = NULL;
	size_t bufsize = 0;

	getline(&cmd, &bufsize, stdin);
	/*
	fgets(cmd, MAX_LINE, stdin);
	if (feof (stdin))
		exit(0);
*/
	bg_job(cmd);


	if (strcmp(cmd, "exit\n") == 0)
		return EXIT_SUCCESS;

	return EXIT_FAILURE;
}
