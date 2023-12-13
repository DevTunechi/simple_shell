#include "shell.h"

/**
 * _myexit - function that exits shell
 * @info: Struct containing arguments
 * Return: exits with a given exit status
 * Olatunji and Goodnews
 */

int _myexit(info_t *info)
{
int exit_status = 0;

if (info->argv[1])
{
int exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
exit_status = (1);
}
else
{
info->err_num = exitcheck;
exit_status = (-2);
}
}
else
{
info->err_num = -1;
exit_status = (-2);
}
return (exit_status);
}

/**
 * _mycd - changescurrent directory of the process (cd)
 * @info: Structure containing potential arguments
 * Olatunji and Goodnews
 * Return: 0
 */

int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret =
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret =
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _myhelp - changes current directory of the process (cd)
 * @info: Structure containing potential arguments
 * Olatunji and Goodnews
 * Return: 0
 */

int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array);
return (0);
}
