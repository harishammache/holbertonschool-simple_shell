#include "shell.h"
/**
 * print_environnement - function that print the 'env' of the PATH
 *
 * Return: Nothing
*/
void print_environnement(void)
{
	char **env_variable = environ;

	while (*env_variable != NULL)
	{
		printf("%s\n", *env_variable);
		env_variable++;
	}
}
