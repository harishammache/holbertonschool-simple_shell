#include "shell.h"

#define MAX_TOKEN 1024
/**
 * parse_user_input - Parse user's input by
 *					reading the input and split it into token.
 *					The function will be use later to find
 *					the path of the command.
 *
 * @input: the user's input which is the string to split
 *
 * Return: the array that stored input token
 *
*/
char *parse_user_input(char *input)
{
	char *delimiter = " ";
	char *input_token;
	char **stored_token;
	int token_count = 0;

	stored_token = malloc(MAX_TOKEN * sizeof(char *));

	if (stored_token == NULL)
	{
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	input_token = strtok(input, delimiter);

	while (input_token != NULL && token_count < MAX_TOKEN - 1)
	{
		stored_token[token_count] = strdup(input_token);
		token_count++;
		input_token = strtok(NULL, delimiter);
	}
	stored_token[token_count] = NULL;
	return (*stored_token);
}
