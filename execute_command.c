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
	char *path = get_path(), *command_path;
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
		struct stat file_stat;

		if (stat(input[0], &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
		{
			execve(input[0], input, environ);
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found or not executable\n",
			program_name, input[0]);
		}
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, input[0]);
	}

	free_path_list(directories);
	free(path);
}
