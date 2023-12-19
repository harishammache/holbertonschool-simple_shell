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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&input, &length, stdin) < 0)
		{
			free_allocate_memory(NULL, input, NULL);
			printf("\n");
			return (1);
		}

		input[strcspn(input, "\n")] = 0;

		if (strlen(input) == 0)
			return (1);

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
		free(input);
		input = NULL;
	}
	return (0);
}
