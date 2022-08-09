#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * program_loop - function that loops all the functions
 */
void program_loop(void)
{
	while (1)
	{
		prompt();
		read_command(/*par, env*/);
	}
}
