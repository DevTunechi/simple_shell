#include "shell.h"

/**
 * _custom_strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num: the amount of characters to be copied
 * Return: the concatenated string
 * Goodnews and Olatunji
 */

char *_custom_strncpy(char *destination, char *source, int num)
{
char *s = destination;
int i, j;

i = 0;
while (source[i] != '\0' && i < num - 1)
{
destination[i] = source[i];
i++;
}
if (i < num)
{
j = i;
while (j < num)
{
destination[j] = '\0';
j++;
}
}
return (s);
}

/**
 *  _custom_strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @num: the amount of bytes to be maximally used
 * Return: the concatenated string
 * Goodnews and Olatunji
 */

char *_custom_strncat(char *destination, char *source, int num)
{
char *s = destination;
int i, j;

i = 0;
j = 0;
while (destination[i] != '\0')
i++;
while (source[j] != '\0' && j < num)
{
destination[i] = source[j];
i++;
j++;
}
if (j < num)
destination[i] = '\0';
return (s);
}

/**
 * _custom_strchr - locates a character in a string
 * @str: the string to be parsed
 * @character: the character to look for
 * Return: (str) a pointer to the memory area str
 * Goodness and Olatunji
 */

char *_custom_strchr(char *str, char character)
{
do {
if (*str == character)
return (str);
} while (*str++ != '\0');
{
return (NULL);
}
}
