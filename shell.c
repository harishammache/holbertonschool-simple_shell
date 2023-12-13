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

	while (1)
	{
		/*fonction à part pour gérer interactif*/
		if (isatty(STDIN_FILENO)) /*verifie si shell fonctionne en mode interactif ou non , Affiche un prompt*/
		{
			printf("hsh $ ");
			read_byte = getline(&input, &length, stdin);
			if(read_byte == -1)
			{
				printf("\n");
				break;
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
	}
	return (0);
}
