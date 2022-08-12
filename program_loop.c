#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void program_loop(void)
{
/*	char **arguments = NULL; */

	while (1)
	{
		prompt();
	
/*		arguments = line_into_args(lineread); */
	/*	execute(arguments);	*/ 	
		read_command(/*par, env*/);
		/* start_program();*/
		/*free(lineread);*/
	/*	free(arguments); */
	}
}
