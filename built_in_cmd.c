#include "main.h"
#include <stdio.h>

/*Function declarations for builtin shell commands:*/
/*
struct builtin
{
	char *name;
	void (*func)(char **args);
};

struct builtin builtins[] = {
	{"help", help},
	{"exit", exit},
	{"cd", cd},
};

int num_builtins() {
	return sizeof(builtins) / sizeof(struct builtin);
} */
/*Builtin function implementations*/
/*
void cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error");
		}
	}
}

void help(char **args)
{
	char *help =
		"Kash - the Kinda Aimless Shell. "
		"The following commands are available:\n"
		"  cd       Change the working directory.\n"
		"  exit     Exit the shell.\n"
		"  help     Print this help text.\n";
	printf("%s", help);
}

void exit(char **args)
{
	exit (0);
} */

/*
 *   Function Declarations for builtin shell commands:
 *    */

/*
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
*/

/*
 *   List of builtin commands, followed by their corresponding functions.
 *    */
/*
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}
*/
/*
 *   Builtin function implementations.
 *   */
/*
int lsh_cd(char **args)
{
	if (args[1] == NULL) {
	fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	} 
	else 
	{
	if (chdir(args[1]) != 0) 
	{
		perror("lsh");
	}
	}
	return 1;
}

int lsh_help(char **args)
{
	int i;
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < num_builtins(); i++) 
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return 1;
}

int lsh_exit(char **args)
{
	  return 0;
}
*/
