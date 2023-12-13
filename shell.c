#include "shell.h"
/**
 * main - UNIX command line interpreter
 * @argv: Number of arguments passed to the program
 * @argc: Array of strings representing the arguments
 *
 * Return: 0 if success , 1 if error
*/
int main(void)
{
	pid_t process_id;
	char *input = NULL;
	size_t length = 0;
	ssize_t read_byte;
	char **env = environ;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("hsh $ ");
		}
		read_byte = getline(&input, &length, stdin);
		if(read_byte == -1)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit\n") == 0)
			break;
		if (strcmp(input, "env\n") == 0)
		{
			for(; *env != NULL; env++)
			{
				char *env_1 = *env;
				printf("%s\n", env_1);
			}
		}

		args = parse_user_input(input);
		if (args == NULL)
			continue;

		process_id = fork();
		/*in child process*/
		if (process_id == 0)
		{

			execute_command(input);
				printf("%d\n", process_id);
		}
		/*in parent process*/
		else if (process_id > 0)
		{
			wait(NULL);
		}
		/* if fork failes*/
		else
		{
			perror("error");
			return (1);
		}
	}
	return (0);
}
