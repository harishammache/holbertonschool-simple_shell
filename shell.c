#include "shell.h"
/**
 * main - function as a basic UNIX shell interpreter, parsing user input
 *		executing commands & managing built-in operations like 'exit' and 'env'
 *
 * Return: 0 if success , 1 if error
*/
int main(void)
{
	char *input = NULL, *path;
	int result;

	path = _getenv("PATH");
	if (path == NULL)
		return (-1);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		result = read_user_input(&input);
		if (result == 0)
		{
			printf("\n");
			free(input);
			return (0);
		}

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		if (strcmp(input, "env\n") == 0)
		{
			print_environnement();
			free(input);
			return (0);
		}

		if (handle_command(input) != 0)
		{
			fprintf(stderr, "Command execution failed: %s\n", input);
			free(input);
		}
	}
	if (input != NULL)
		free(input);

	return (0);
}
