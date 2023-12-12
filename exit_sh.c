#include "shell.h"

/**
 * *_strncat - cats two str
 * @dest: first str
 * Olatunji and Goodnews
 * @src: second str
 * @n: total amount of bytes to be used
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;
	
	i = 0;
	j = 0;
	
	while (dest[i] != '\0')
		
		i++;
	
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 * *_strchr - locates a character in a str
 * @s: the str to be parsed
 * Olatunji and Goodnews
 * @c: char to look for
 * Return: pointer to the mem area s
 */

char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	}
	
	while (*s++ != '\0');
	
	return (NULL);
}
