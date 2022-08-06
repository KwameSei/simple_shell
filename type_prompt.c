#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * type_prompt - function that types prompt and reads input
 *
 * Return: input read
 */

#define PRMTSIZ 255

int type_prompt()
{
	for (;;)
	{
	char input[PRMTSIZ + 1] = { 0X0 };
	char *ptr = input;

	// prompt
	printf("%s", getuid() == 0 ? "$" : "#cisfun$");
	fgets(ptr, PRMTSIZ, stdin);
	}
}

