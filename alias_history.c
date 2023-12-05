#include "shell.h"

/**
 * _custom_myhistory-displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 * @info:Structure with potential args. Used to maintain function prototype.
 * Goodnews and Olatunji
 * Return:Always 0
 */

int _custom_myhistory(info_t *info)
{
_print_list(info->history);
return (0);
}

/**
 * _custom_unset_alias - sets alias to string
 * @info:parameter struct
 * @str:string alias
 * Return:Always 0 on success, 1 on error
 * Goodnews and Olatunji
 */

int _custom_unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _custom_strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = _custom_delete_node_at_index(&(info->alias),
get_node_index(info->alias,
node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * _custom_set_alias-sets alias to string
 * @info:parameter struct
 * @str:string alias
 * Return:Always 0 on success, 1 on error
 * Goodnews and Olatunji
 */

int _custom_set_alias(info_t *info, char *str)
{
char *p;

p = _custom_strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (_custom_unset_alias(info, str));

_custom_unset_alias(info, str);
return (_custom_add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _custom_print_alias-prints an alias string
 * @node:alias node
 * Return:Always 0 on success, 1 on error
 * Goodnews and Olatunji
 */

int _custom_print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _custom_strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_custom_puts(p + 1);
_custom_puts("'\n");
return (0);
}
return (1);
}

/**
 * _custom_myalias-mimics the alias builtin (man alias)
 * @info:Structure with potential args. Used to maintain function prototype.
 * Return:Always 0
 * Goodnews and Olatunji
 */

int _custom_myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
_custom_print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _custom_strchr(info->argv[i], '=');
if (p)
_custom_set_alias(info, info->argv[i]);
else
_custom_print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
