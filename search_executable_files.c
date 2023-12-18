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
	char *result;

	while (head != NULL)
	{
		result = NULL;
		pathname = malloc(strlen(head->directory) + strlen(command) + 2);
		if (pathname == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}

		sprintf(pathname, "%s/%s", head->directory, command);
		if (access(pathname, X_OK) == 0)
		{
			result = strdup(pathname);
			if (result == NULL)
			{
				perror("Memory allocation failed");
				free(pathname);
				return (NULL);
			}
			return (result);
		}
		free(pathname);
		head = head->next;
	}
	return (NULL);
}
