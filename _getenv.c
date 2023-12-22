#include "shell.h"
/**
 * _getenv - function that finds a specific environment variable
 *
 * @name: pointer to the name of the env variable to find
 *
 * Return: the value of env variable or NUL if not found
*/
char *_getenv(const char *name)
{
	int index;
	size_t name_length;

	if (name == NULL)
	{
		return NULL;
	}

	name_length = strlen(name);
	for (index = 0; environ[index] != NULL; index++)
	{
		if (strncmp(name, environ[index], name_length) == 0 &&
			environ[index][name_length] == '=')
		{
			return environ[index] + name_length + 1;
		}
	}
	return NULL;
}
