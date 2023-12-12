#include "shell.h"

/**
* _putfd - writes the char c to given fd
* @c: char to print
* @fd: filedescriptor to write to
* Olatunji and Goodnews
* Return: 1, on failure -1 and errno will set approrpiately */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];
	
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	
	if (c != BUF_FLUSH)
		buf[i++] = c;
	
	return (1);
}

/**
 * _putsfd - prints input str
 * @str: str to print
 * @fd: file descriptor to write to
 * Olatunji and Goodnews
 * Return: num of chars to put
 */
 
 int _putsfd(char *str, int fd)
 {
	 int i = 0;
	 
	 if (!str)
		 
		 return (0);
	 while (*str)
	 {
		 i += _putfd(*str++, fd);
	 }
	 
	 return (i);
 }
