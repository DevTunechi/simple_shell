#include "shell.h"

/**
 * bfree - free pointer and NULLs the add
 * @ptr: add of pointer to be freed
 * Olatunji and Goodnews
 * Return: 1, otherwise 0.
 */

int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
