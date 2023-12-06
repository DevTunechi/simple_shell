#include "shell.h"

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Olatunji and Goodnews
 * Return: points to destination
 */

char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/**
 * _strdup - dups a str
 * @str: the str to duplicate
 * Olatunji and Goodnews
 * Return: pointer to duplicated str
 */

char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Goodnews and Olatunji
 * Return: Nothing
 */

void _puts(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Goodnews and Olatunji
 * Return: On success 1.
 * On error, -1 and errno is appropriately set
 */

int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
