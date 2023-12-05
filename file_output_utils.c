#include "shell.h"

/**
*_custom_eputs - prints an input string
*@str: the string to be printed
*Goodnews and Olatunji
*/

void _custom_eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_custom_eputchar(str[i]);
i++;
}
}

/**
*_custom_eputchar - writes the character c to stderr
*@c: The character to print
*Return: On success 1.
*On error, -1 is returned, and errno is set appropriately.
*Goodnews and Olatunji
*/

int _custom_eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
*_custom_putfd - writes the character c to given fd
*@c: The character to print
*@fd: The filedescriptor to write to
*Return: On success 1.
*On error, -1 is returned, and errno is set appropriately.
*Goodnews and Olatunji
*/

int _custom_putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
*_custom_putsfd - prints an input string
*@str: the string to be printed
*@fd: the filedescriptor to write to
*Return: the number of chars put
*Goodnews and Olatunji
*/

int _custom_putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
while (*str)
{
i += _custom_putfd(*str++, fd);
}
return (i);
}
