#include "shell.h"
/**
 * execute_command - execute each command write on the terminal
 *
 * @input: the user input on the terminal
 *
 * Return: nothing
*/
void execute_command(char **input)
{
	char *command_path;
	char *path = get_path();
	path_list *directories = create_path_list(path);

	command_path = search_executable_files(directories, input[0]);

	if (command_path != NULL)
	{
		execve(command_path, input, environ);
	}
	if (strncmp(input[0], "/bin/", 5) == 0)
	{
		execve(input[0], input, environ);
	}
	else
	{
		printf("Command not found: %s\n", *input);
	}
}
