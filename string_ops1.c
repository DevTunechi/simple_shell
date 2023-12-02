#include "shell.h"

/**
 * string_length - returns the length of a string
 * @str: the string whose length to check
 * Goodnews and Olatunji
 * Return: integer length of string
 */

int string_length(char *str)
{
int len = 0;
if (!str)
return (0);
while (*str++)
len++;
return (len);
}

/**
 * string_compare - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 * Goodnews and Olatunji
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int string_compare(char *s1, char *s2)
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
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Goodnews and Olatunji
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * string_concatenate - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Goodnews and Olatunji
 * Return: pointer to destination buffer
 */

char *string_concatenate(char *dest, char *src)
{
char *result = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (result);
}
