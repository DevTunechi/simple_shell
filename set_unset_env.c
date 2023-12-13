#include "shell.h"

/**
 * _mysetenv - set environment variable
 * @info: Struct containing arguments
 * Olatunji and Goodnews
 * Return: 0 on success, -1 on failure
 */

int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
print_error(info, "Usage: setenv VARIABLE VALUE\n");
return (-1);
}

if (setenv(info->argv[1], info->argv[2], 1) == -1)
{
perror("setenv");
return (-1);
}
return (0);
}

/**
 * _myunsetenv - unset environment variable
 * @info: Struct containing arguments
 * Olatunji and Goodnews
 * Return: 0 on success, -1 on failure
 */

int _myunsetenv(info_t *info)
{
if (info->argc != 2)
{
print_error(info, "Usage: unsetenv VARIABLE\n");
return (-1);
}

if (unsetenv(info->argv[1]) == -1)
{
perror("unsetenv");
return (-1);
}

return (0);
}
