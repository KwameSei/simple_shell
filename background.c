#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <errno.h>

#define DELIM "\n \t"
#define MAXARG 20
/*
void kash_exit(char **token) {
	    exit(0);
}
*/
// Change the working directory.
void kash_cd(char **token) 
{
	if (token[1] == NULL) 
	{
		fprintf(stderr, "kash: cd: missing argument\n");
	} 
	else 
	{
		if (chdir(token[1]) != 0)
	       	{
			perror("kash: cd");
		}
	}
}
/*
void kash_help(char **token) 
{
	char *helptext =
	"Kash - the Kinda Aimless Shell. "
	"The following commands are built in:\n"
	"cd Change the working directory.\n"
	"exit Exit the shell.\n"
	"help Print this help text.\n";
	        
	printf("%s", helptext);
}
*/
struct builtin
{
	    char *name;
	    void (*func)(char **token);
};

// Array of built in commands.
struct builtin builtins[] = 
{
/*	{"help", kash_help},
	{"exit", kash_exit}, */
	{"cd", kash_cd},	
};

// Returns the number of registered commands.
int kash_num_builtins() 
{
	return sizeof(builtins) / sizeof(struct builtin);
}

void bg_job(char *cmdline)
{
	char *token[MAXARG]; /*Creating argument array*/
	/*size_t bufsize = 0;*/
	/*char **args = NULL; */
	pid_t child_id; 
	int count = 0, bground = 0;

	token[count++] = strtok(cmdline, DELIM);
	while (count < MAXARG && (token[count++] = strtok(NULL, DELIM)) != NULL);

	/*
	token = strtok(cmdline, DELIM);
	while (token != NULL)
	{
		token[count] = strdup(token);
		token = strtok(NULL, DELIM);
	}
	count++;
*/
	for (int i = 0; i < kash_num_builtins(); i++) 
	{
		if (strcmp(token[0], builtins[i].name) == 0) 
			{
				builtins[i].func(token);
				return;
			}
	}

	child_id = fork();
	if (child_id == 0)	/*Child executes background job*/
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror("./shell");
			_exit(EXIT_FAILURE); 	/*execv failed*/
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
