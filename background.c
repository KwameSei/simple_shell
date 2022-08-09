#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/**
 * bg_job - function that tokenises and executes the commands and arguments
 * @cmdline: pointer to the input to be tokenised
 */
#define DELIM "\n \t"
#define MAXARG 20

void bg_job(char *cmdline)
{
	char *token[MAXARG]; /*Creating argument array*/
	pid_t child_id;
	int count = 0, bground = 0;

	token[count++] = strtok(cmdline, DELIM);
	while (count < MAXARG && (token[count++] = strtok(NULL, DELIM)) != NULL);

	child_id = fork();
	if (child_id == 0)	/*Child executes background job*/
	{
		if (execv(token[0], token) < 0)
		{
			printf("./shell: No such file or directory\n");
			_exit(EXIT_FAILURE);/*execv failed*/
		}
	}

	if (child_id < 0)
	{
		fprintf(stderr, "duplicate process failed\n");
		perror("background process failed");
	}

	if (!bground)
	{
		int status;

		if (waitpid(child_id, &status, 0) < 0)
			perror("waitfg: waitpid error");
	}
	else
		printf("%d %s", child_id, cmdline);

}
