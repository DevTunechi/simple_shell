#include "shell.h"

char *strncpy(char *dest, const char *src, size_t n)
{
	size_t b;

	for (b = 0; b < n && src[b] != '\0'; b++)
	{
		dest[b] = src[b];
	}

	while (b < n)
	{
		dest[b] = '\0';
		b++;
	}
	return (dest);
}

char *_strncat(char *dest' const char *src, size_t n)
{
	size_t dest_length = 0;
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	size_t b;
	for (b = 0; b < n && src[b] != '\0'; b++)
	{
		dest[dest_length + b] = src[b];
	}
	dest[dest_length + b] = '\0';
	return (dest);
}

char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return (char *)s;
		}
		s++;
	}
	return (NULL);
}
