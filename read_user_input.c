#include "shell.h"
/**
 * read_user_input - function that handle the user input by reading it
 *
 * @input: the user input
 *
 * Return: 2 if success, 1 if success but user input is empty, 0 if it's failed
*/
int read_user_input(char **input)
{
	size_t length = 0;
	ssize_t read_byte;

	read_byte = getline(input, &length, stdin);
	if (read_byte < 0)
	{
		if (*input != NULL)
		{
			free(*input);
		}
		return (0);
	}

	(*input)[strcspn(*input, "\n")] = 0;

	if (strlen(*input) == 0)
	{
		if (*input != NULL)
		{
			free(*input);
		}
		return (1);
	}

	return (2);
}

