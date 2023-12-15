#include "shell.h"
/**
 * main - function as a basic UNIX shell interpreter, parsing user input, executing commands
 *		And managing built-in operations like 'exit' and 'env'.
 *
 * Return: 0 if success , 1 if error
*/
int main(void)
{
	pid_t process_id;
	char *input = NULL, **env = environ, **args;
	size_t length = 0;
	ssize_t read_byte;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh $ ");

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

		args = parse_user_input(input);

		if (args == NULL)
			continue;

		process_id = fork();
		if (process_id == 0)
		{
			execute_command(args);
			/*printf("%d\n", process_id); affiche un 0 */
		}
		else if (process_id > 0)
			wait(NULL);
		else
		{
			perror("error");
			return (1);
		}
	}
	return (0);
}
