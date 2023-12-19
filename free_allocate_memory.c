#include "shell.h"
/**
 * free_allocate_memory - function that free the allocate memory
 *
 * @command: pointer of an array which stored the command
 * @input: the user input
 * @size: stored the size of user input
 *
 * Return: nothing
*/
void free_allocate_memory(char **command, char *input, int *size)
{
	if (command != NULL)
	{
		free(command);
	}
	if (input != NULL)
	{
		free(input);
	}
	if (size != NULL)
	{
		free(size);
	}
}
