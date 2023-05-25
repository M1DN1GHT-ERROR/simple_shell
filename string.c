#include "my_shell.h"

/**
* print_promp - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void print_promp(void)
{
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
tool.acti = 1;
if (tool.acti)
write(STDERR_FILENO, "$emyy ", 2);
}

#include "my_shell.h"

/**
* _putchar - writes the character c to stdout
* @a: The character to print
*
* Return: On success 1.
* On error, -1 is returned and errno set appropriately
*/
int _putchar(char a)
{
return (write(1, &a, 1));
}

/**
* string_printer - prints a string
* @a: string to be printed
*
* Return: number of characters printed
*/
int string_printer(char *a)
{
int i = 0;

while (a[i] != '\0')
{
_putchar(a[i]);
i++;
}

return (i);
}

#include "my_shell.h"

/**
* env_printer - prints the environment string to stdout
*
* Return: 0
*/
void env_printer(void)
{
int g = 0;
char **ern = environ;

while (ern[g])
{
write(STDOUT_FILENO, (const void *)ern[g], strlen(ern[g]));
write(STDOUT_FILENO, "\n", 1);
g++;
}
}
