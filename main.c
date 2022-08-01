#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * main - main function
 *
 * Return: 0 (Success)
 */
int main(void)
{
	/*Two arrays to hold commands: and one array to hold parameters*/
	char cmd[100], command[100], *parameters[20];
	char *envp[] = { (char *) "PATH=/bin", 0 };

	while (1)
	{
		/*Display prompt*/
		type_prompt();

		/*read input*/
		read_command (command, parameters);

		if (fork () != 0)
			wait (NULL);

		else
		{
			strcpy (cmd, "/bin/");
			strcat (cmd, command);
			execve (cmd, parameters, envp);
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}


