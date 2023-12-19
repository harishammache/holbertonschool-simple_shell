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

	if (args == NULL)
	{
		return (-1);
	}

	process_id = fork();
	if (process_id == 0)
	{
		execute_command(args);
		exit(0);
	}
	else if (process_id > 0)
		wait(NULL);
	else
	{
		perror("error");
		return (1);
	}
	return (0);
}
