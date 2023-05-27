#include "shell.h"

/**
* get_environ - returns the string array copy of our environ
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}

/**
* _setenv - Initialize a new environment variable,
*             or modify an existing one
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
* @var: the string env var property
* @value: the string env var value
* Return: Always 0
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buffer = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

buffer = malloc(_strlen(var) + _strlen(value) + 2);
if (!buffer)
return (1);
_strcpy(buffer, var);
_strcat(buffer, "=");
_strcat(buffer, value);
node = info->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buffer, 0);
free(buffer);
info->env_changed = 1;
return (0);
}
