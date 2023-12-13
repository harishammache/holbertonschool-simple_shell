#include "shell.h"
/**
 * execute_command - execute command no matter which one is
 *
 * @input: the cuser input on the terminal
 *
 * Return: nothing
*/
void execute_command(char *input)
{
	char *command_path, *args[2];
	path_list *directories;
	char *path;

	path = get_path();
	directories = create_path_list(path);

	command_path = search_executable_files(directories, input);
	if (command_path != NULL)
	{
		args[0] = command_path;
		args[1] = NULL;
		execv(command_path, args);
	}
	else
	{
		printf("Command not found: %s\n", input);
	}
}
