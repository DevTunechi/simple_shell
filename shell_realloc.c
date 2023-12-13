#include "shell.h"

/**
 * *_memset - fills the memory with constant byte
 * @s: pointer to memory area
 * @b: byte to fill *s with
 * @n: amount of bytes to be filled
 * Olatunji and Goodnews
 * Return:  a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: str of strings
 * Goodnews and Olatunji
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
 * _realloc - reallocate a block of memory
 * @ptr: pointer to previously allocated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of new block
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
