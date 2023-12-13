#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

/**
 * struct path_node - node of the path
 *
 * @directory: contains a directory
 * Each directory is a pointer to the first node of a linked list
 * @next: pointer to the next node
*/
typedef struct path_node
{
	char *directory;
	struct path_node *next;
} path_list;

extern char **environ;

char *get_path();
int main(void);
char **parse_user_input(char *input);
path_list *create_path_list (char *path);
char *search_executable_files(path_list *head, const char *user_input);
int implement_builtin_command(char **command);
void execute_command(char *input);

#endif
