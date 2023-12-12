#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * struct node - node of the path
 *
 * @directory: contains a directory
 * Each directory is a pointer to the first node of a linked list
 * @next: pointer to the next node
*/
typedef struct node
{
	char *directory;
	struct node *next;
} path_list;

int main(int argc, char **argv);
void *parse_user_input(char *input);
path_list *create_path_list (char *path);

#endif
