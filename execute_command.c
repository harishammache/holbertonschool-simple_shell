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
	char *command_path, *path = get_path();
	path_list *directories = create_path_list(path);

	if (input == NULL || *input == NULL)
	{
		free(input);
		free(path);
		free_path_list(directories);
		return;
	}

	if (directories == NULL || path == NULL)
	{
		free_path_list(directories);
		free(path);
		return;
	}
	command_path = search_executable_files(directories, input[0]);

	if (command_path != NULL)
		execve(command_path, input, environ);

	else if (strncmp(input[0], "/bin/", 5) == 0)
		execve(input[0], input, environ);

	else
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, *input);

	free(*input);
	free_path_list(directories);
	free(path);
}
