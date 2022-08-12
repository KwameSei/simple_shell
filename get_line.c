#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int read_command(void)
{

<<<<<<< HEAD:get_line.c
	void bg_job(char *cmdLine);

=======
/*	char cmd[MAX_LINE];	*/
	void bg_job(char *cmdline);
	
>>>>>>> ffebb02e9e90f3cf5c9cbda853b1f6f16104e2a6:line_into_args.c
	char *cmd = NULL;
	size_t bufsize = 0;

	getline(&cmd, &bufsize, stdin);
<<<<<<< HEAD:get_line.c

=======
	/*
	fgets(cmd, MAX_LINE, stdin);
	if (feof (stdin))
		exit(0);
*/
>>>>>>> ffebb02e9e90f3cf5c9cbda853b1f6f16104e2a6:line_into_args.c
	bg_job(cmd);


	if (strcmp(cmd, "exit\n") == 0)
<<<<<<< HEAD:get_line.c
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
=======
		return EXIT_SUCCESS;

	return EXIT_FAILURE;
>>>>>>> ffebb02e9e90f3cf5c9cbda853b1f6f16104e2a6:line_into_args.c
}
