#include "shell.h"

/**
 * _custom_myenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Goodnews and Olatunji
 * Return: Always 0
 */

int _custom_myenv(info_t *info)
{
_custom_print_list_str(info->env);
return (0);
}

/**
 * _custom_getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments.
 * @name: environment variable name
 * Goodnews and Olatunji
 * Return: the value
 */

char *_custom_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
p = _custom_starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
 * _custom_mysetenv - Initialize a new environment variable,
 * or modify an existing one
 * @info: Structure containing potential arguments.
 * Goodnews and Olatunji
 * Return: Always 0
 */

int _custom_mysetenv(info_t *info)
{
if (info->argc != 3)
{
_custom_eputs("Incorrect number of arguments\n");
return (1);
}
if (_custom_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _custom_myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * Goodnews and Olatunji
 * Return: Always 0
 */

int _custom_myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_custom_eputs("Too few arguments.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_custom_unsetenv(info, info->argv[i]);

return (0);
}

/**
 * _custom_populate_env_list - populates environment linked list
 * @info: Structure containing potential arguments.
 * Goodnews and Olatunji
 * Return: Always 0
 */

int _custom_populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
_custom_add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
