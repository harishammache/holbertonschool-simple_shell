#include "shell.h"
/**
 * free_path_list - function that free the 'path_list' structure
 *
 * @head: pointer to the head of the path list
 *
 * Return: Nothing
 */
void free_path_list(path_list *head)
{
	while (head != NULL)
	{
		path_list *temporary = head;

		head = head->next;
		free(temporary->directory);
		free(temporary);
	}
}
