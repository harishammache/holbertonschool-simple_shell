#include "shell.h"
/**
 * handle_command - execute the provided command if all condition
 *
 * @command: the command to execute
 *
 * Return: 0 on success, 1 on error
*/
int handle_command(char *command)
{
	pid_t process_id;
	char **args = parse_user_input(command);
	path_list *directories = create_path_list(get_path());
	int status = 0;

	if (args == NULL || directories == NULL)
	{
		free_path_list(directories);
		free_tokens(args);
		return (1);
	}

	process_id = fork();
	if (process_id == 0)
	{
		execute_command(args);
		free_path_list(directories);
		free(args);
		exit(EXIT_SUCCESS);
	}
	else if (process_id > 0)
		wait(&status);
	else
	{
		perror("error");
		free_path_list(directories);
		free(args);
		status = 1;
	}
	free_path_list(directories);
	free_tokens(args);

	return (status);
}
