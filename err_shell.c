#include "shell.h"

/**
 * _eputs - prints input str
 * @str: string to print
 * Olatunji and Goodnews
 * Return: Nothing
 */

void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - char c to stderr
 * @c: character to print
 * Olatunji and Goodnews
 * Return: 1
  */

int _eputchar(char c)
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
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: fd to write to
 * Olatunji and Goodnews
 * Return: 1
 */

int _putfd(char c, int fd)
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
 *_putsfd - prints input str
 * @str: str to print
 * @fd: fd to write to
 * Olatunji and Goodnews
 * Return: num of chars to put
 */

int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
