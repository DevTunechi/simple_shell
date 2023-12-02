#include "shell.h"

/**
 * free_buffer - deallocates memory and sets the pointer to NULL
 * Goodnews & Olatunji
 * @buffer: address of the pointer to deallocate
 * Return: 1 if memory is deallocated, otherwise 0.
 */

int free_buffer(void **buffer)
{
if (buffer && *buffer)
{
free(*buffer);
*buffer = NULL;
return (1);
}
return (0);
}
