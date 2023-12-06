#include "shell.h"

/**
 * interactive - returns true when shell is interactive mode
 * @info: structure address
 * Olatunji and Goodnews
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the char is a delimeter
 * @c: character to check
 * @delim: delimeter str
 * Olatunji and Goodnews
 * Return: 1 if true, else 0
 */

int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 *_isalpha - check alphabetic char
 *@c: char to input
 * Olatunji and Goodnews
 *Return: 1 if c is alphabet, else 0
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 *_atoi - converts a str to int
 *@s: str to be converted
 * Olatunji and Goodnews
 *Return: 0 converted number otherwise
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
