#include "my_shell.h"

/**
 * execut_exter_cmd - Executes an external command
 * @cmd: The command name
 * @args: An array of command arguments
 * @path_var: The value of the PATH environment variable
 * credit to imane lagsoun
 * @argv: The program name and command line arguments
 */

void execut_exter_cmd(__attribute__((unused)) char *cmd, char **args,
		char *path_var, __attribute__((unused)) char **argv)
{
    /* Check the command path */
    char command_path[BUFFER_SIZE];
    int status;
    pid_t pid;

    if (!check_cmd_path(args[0], command_path, path_var))
    {
        my_putstring("sh: 1: ");
        my_putstring(args[0]);
        my_putstring(": not found\n");
        return;
    }

    /* Fork a child process to execute the command */
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }
    else if (pid == 0)
    {
        /* Child process */
        /* Execute the command */
        execve(command_path, args, environ);
        /* If execve returns, an error occurred */
        my_putstring("sh: 1: ");
        my_putstring(args[0]);
        my_putstring(": not found\n");
        exit(127);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
