#include "SHELL.H"
/**
 * main - UNIX command line interpreter
 * @argv: Number of arguments passed to the program
 * @argc: Array of strings representing the arguments
 *
 * Return: 0 if success
*/
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	int process_id;
	char *input = NULL;
	size_t length = 0;
	ssize_t read_byte;
	char **env = environ;
	char *path;

	while (1)
	{
		if (isatty(STDIN_FILENO))/*verifie si shell fonctionne en mode interactif ou non , Affiche un prompt*/
		{
			printf("\xf0\x9f\x98\x84\xf0\x9f\x8c\x9f Shell by SH \xf0\x9f\x8c\x9f\xf0\x9f\x98\x84 $ ");
			read_byte = getline(&input, &length, stdin);
			if(read_byte == -1)
			{
				printf("\n");
				break;
			}
		}
		if (strcmp(input, "exit\n") == 0)
		{
			break;
		}
		if (strcmp(input, "env\n") == 0)
		{
			for(; *env != NULL; env++)
			{
				char *env_1 = *env;
				printf("%s\n", env_1);
			}
		}
		process_id = fork();
		if (process_id == 0)
        {
            exit(EXIT_FAILURE);
        }
		else if (process_id > 0)
		{
			printf("%d\n", process_id);
		}
		else
		{
			perror("error");
		}
		path = get_path();
		create_path_list(path);
	}
	return (0);
}
