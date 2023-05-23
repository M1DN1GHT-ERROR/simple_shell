#include "my_shell.h"

/**
 * handle_sigint - Signal handler for SIGINT
 * credit to lagsoun emyy
 * @signum: The signal number
 */

void handle_sigint(__attribute__((unused))int signum)
{
	my_putstring("\n");
	should_exit = 1; /*Set the flag to exit the shell*/
	exit(EXIT_SUCCESS);
}
