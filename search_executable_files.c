#include "shell.h"
/**
 * search_executable_files - function that take 2 inputs, just see below
 * It search the path of executable files
 *
 * @head: the head of the simply linked llist
 * @command: the command to search on the PATH
 *
 * Return: the path of the file
*/
char *search_executable_files(path_list *head, const char *command)
{
	char *pathname = NULL;

	while (head != NULL)
	{
		pathname = malloc(_strlen(head->directory) + _strlen(command) + 2);
		if (pathname == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}

		sprintf(pathname, "%s/%s", head->directory, command);
		if (access(pathname, X_OK) == 0)
		{
			return (pathname);
		}
		free(pathname);
		head = head->next;
	}
	return (NULL);
}
