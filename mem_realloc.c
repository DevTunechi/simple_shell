#include "shell.h"

/**
 * *_memset - fill mem wit const byte
 * @s: pointer to mem area
 * @b: byte to fill *s
 * @n: amount of byte to fill
 * Olatunji and Goodnews
 * Return: pointer to mem area
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - string of strings
 * @pp: string
 * Olatunji and Goodnews
 */

void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * _realloc - block of memory
 * @ptr: pointer to previous malloc
 * @old_size: byte size of previous mem block
 * @new_size: byte size
 * Olatunji and Goodnews
 * Return: pointer to old block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
