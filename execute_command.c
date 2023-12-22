#include "shell.h"
/**
 * execute_command - execute each command write on the terminal
 *
 * @input: the user input on the terminal
 * @program_name: the name of the program to passed on argument
 *
 * Return: nothing
*/
void execute_command(char **input, char *program_name)
{
	char *command_path, *path = get_path(), *actual_command;
	path_list *directories = create_path_list(path);

	if (input == NULL || *input == NULL ||
		directories == NULL || path == NULL)
	{
		free_path_list(directories);
		free(path);
		free_tokens(input);
		return;
	}

	command_path = search_executable_files(directories, input[0]);

	if (command_path != NULL)
	{
		execve(command_path, input, environ);
		free(command_path);
	}

	else if (strncmp(input[0], "/bin/", 5) == 0)
	{
		actual_command = input[0] + 5;
		if (access(actual_command, X_OK) == 0)
		{
			execve(input[0], input, environ);
		}
		else
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, actual_command);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, *input);
	}

	free_path_list(directories);
	free(path);
}
