#include "shell.h"

/**
 * copy_string - copies a string
 * @destination: the destination
 * @source: the source
 * Goodnews and Olatunji
 * Return: pointer to destination
 */

char *copy_string(char *destination, char *source)
{
int index = 0;

if (destination == source || source == 0)
return (destination);
while (source[index])
{
destination[index] = source[index];
index++;
}
destination[index] = 0;
return (destination);
}

/**
 * duplicate_string - duplicates a string
 * @str: the string to duplicate
 * Goodnews and Olatunji
 * Return: pointer to the duplicated string
 */

char *duplicate_string(const char *str)
{
int length = 0;
char *result;

if (str == NULL)
return (NULL);
while (*str++)
length++;
result = malloc(sizeof(char) * (length + 1));
if (!result)
return (NULL);
for (length++; length--;)
result[length] = *--str;
return (result);
}

/**
 * print_string - prints an input string
 * @str: the string to be printed
 * Goodnews and Olatunji
 * Return: Nothing
 */

void print_string(char *str)
{
int index = 0;

if (!str)
return;
while (str[index] != '\0')
{
write_char(str[index]);
index++;
}
}

/**
 * write_char - writes the character c to stdout
 * @character: The character to print
 * Goodnews and Olatunji
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int write_char(char character)
{
static int buffer_index;
static char buffer[WRITE_BUF_SIZE];

if (character == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
{
write(1, buffer, buffer_index);
buffer_index = 0;
}
if (character != BUF_FLUSH)
buffer[buffer_index++] = character;
return (1);
}
