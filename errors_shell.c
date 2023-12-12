#include "shell.h"

/**
 * _eputs - prints input str
 * @str: str to be printed
 * Olatunji and Goodnews
 * Return: Absolutely nothing
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
 * _eputchar - writes the character c to stderr
 * @c: character to print
 * Olatunji and Goodnews
 * Return: 1, on failure -1 and errno will set approrpiately
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

