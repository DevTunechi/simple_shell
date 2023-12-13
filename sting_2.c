#include "shell.h"

/**
 * _strlen - ret len of str
 * @s: str len to check
 * Olatunji and Goodnews
 * Return: int len of str
 */

int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}

/**
 * _strcmp - performs the lexicographic cmpre of2 str
 * @s1: first str
 * @s2: second str
 * Olatunji and Goodnews
 * Return: negative or positive
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - needle starts with haystack
 * @haystack: str to find
 * @needle: substr to search for
 * Olatunji and Goodnews
 * Return: add of next char or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - cats 2 strings
 * @dest: dest buff
 * @src: source buff
 * Olatunji and Goodnews
 * Return: pointer to dest buff
 */

char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
