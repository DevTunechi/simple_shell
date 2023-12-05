#include "shell.h"

/**
 * _custom_erratoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 * Goodnews and Olatunji
 */

int _custom_erratoi(char *str)
{
int i = 0;
unsigned long int result = 0;

if (*str == '+')
str++;
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] >= '0' && str[i] <= '9')
{
result *= 10;
result += (str[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * custom_print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in the string, converted number otherwise
 * -1 on error
 * Goodnews and Olatunji
 */

void custom_print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * custom_print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 * Goodnews and Olatunji
 * Return: number of characters printed
 */

int custom_print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}

/**
 * custom_convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * Goodnews and Olatunji
 * Return: string
 */

char *custom_convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * custom_remove_comments - function replaces first instance of '#' with '\0'
 * @buffer: address of the string to modify
 * Goodnews and Olatunj
 * Return: Always 0;
 */

void custom_remove_comments(char *buffer)
{
int i;

for (i = 0; buffer[i] != '\0'; i++)
if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
{
buffer[i] = '\0';
break;
}
}