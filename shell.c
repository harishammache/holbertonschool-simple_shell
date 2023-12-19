#include "shell.h"
/**
 * main - function as a basic UNIX shell interpreter, parsing user input
 *		executing commands & managing built-in operations like 'exit' and 'env'
 *
 * Return: 0 if success , 1 if error
*/
int main(void)
{
	char *input = NULL, **env = environ;
	int result;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		result = read_user_input(&input);
		if (result == 0)
		{
			printf("\n");
			return (0);
		}

		if (strcmp(input, "exit") == 0)
			break;

		if (strcmp(input, "env\n") == 0)
		{
			for (; *env != NULL; env++)
			{
				char *env_1 = *env;

				printf("%s\n", env_1);
			}
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
