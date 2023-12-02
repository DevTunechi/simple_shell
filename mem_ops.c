#include "shell.h"

/**
* _memset - Fills a block of memory with a specified byte.
* @s: Pointer to the memory area to be filled.
* @b: The byte to fill the memory area with.
* @n: Number of bytes to be filled.
* Goodnews & Olatunji
* Return: A pointer to the filled memory area (s).
*/

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
* ffree - Frees a dynamically-allocated array of strings.
* @pp: The array of strings to be freed.
* Goodnews & Olatunji
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
* _realloc - Reallocates a memory block with a new size.
* @ptr: Pointer to the previous dynamically-allocated block.
* @old_size: Size (in bytes) of the previous block.
* @new_size: Size (in bytes) of the new block.
* Goodnews & Olatunji
* Return: A pointer to the newly allocated memory block.
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
