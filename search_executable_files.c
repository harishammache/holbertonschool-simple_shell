#include "shell.h"

/**
 * search_executable_files - function that take 2 inputs, just see below
 * It search the path of executable files
 *
 * @head: the head of the simply linked llist
 * @command: the command to search on the PATH
 *
 * Return: NULL if any executable file match with 'command'
*/
char *search_executable_files(path_list *head, const char *command)
{
	char *pathname;
	char *result = NULL;

	if (head == NULL || head->directory == NULL)
	{
		fprintf(stderr, "Invalid path\n");
		return (NULL);
	}

	while (head != NULL)
	{
		pathname = malloc(strlen(head->directory) + strlen(command) + 2);
		if (pathname == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}

		sprintf(pathname, "%s/%s", head->directory, command);
		if (command[0] == '/' || command[0] == '.')
		{
			if (access(command, X_OK) == 0)
			{
				result = strdup(command);
				if (result == NULL)
				{
					perror("Memory allocation failed");
					free(pathname);
					return (NULL);
				}
				free(pathname);
				return (result);
			}
		}
		else
		{
			if (access(pathname, X_OK) == 0)
			{
				result = strdup(pathname);
				if (result == NULL)
				{
					perror("Memory allocation failed");
					free(pathname);
					return (NULL);
				}
				free(pathname);
				return (result);
			}
		}
		free(pathname);
		head = head->next;
	}
	/*free(result);*/
	return (NULL);
}
