#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * start_program - function that creates child process
 *@args: arguments passed
 *Return: 1
 */
int start_program(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		int val = execve(args[0], args, NULL);

		if (val == -1)
			perror("Error starting");
	}
	else if (pid < 0)
	{
	/*	Error forking child process	*/
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
