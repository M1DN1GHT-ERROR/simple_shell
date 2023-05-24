#include "my_shell.h"
/**
 * my_getline -  GEts inputs
 * Return: The input.
 */

char *my_getline(void)
{
	char *str = NULL;
	size_t token = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&str, &token, stdin) == -1)
	{
		free(str);
		return (NULL);
	}

	return (str);
}
