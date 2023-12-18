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
	size_t length = 0;
	ssize_t read_byte;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read_byte = getline(&input, &length, stdin);
		if (read_byte == -1)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = 0;

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
		}
	}
	return (0);
}
