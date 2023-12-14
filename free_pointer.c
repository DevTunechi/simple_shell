#include "shell.h"

/**
 * bfree - a pointer, NULLs the add
 * @ptr: add f pointer to free
 * Olatunji Oluwadare and Goodnews Akpan
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
