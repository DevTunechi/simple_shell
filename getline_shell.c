#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 * Olatunji and Goodnews
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;

if (!*len)
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
r = getline(buf, &len_p, stdin);
r = _getline(info, buf, &len_p);
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);

{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 * Olatunji and Goodnews
 * Return: bytes read
 */

ssize_t get_input(info_t *info)
{
static char *buf;
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = i;
p = buf + i;

check_chain(info, buf, &j, i, len);
while (j < len)
{
if (is_chain(info, buf, &j))
break;
j++;
}

i = j + 1;
if (i >= len)
{
i = len = 0;
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buf;
return (r);
}

/**
 * read_buf - buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 * Olatunji and Goodnews
 * Return: r
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}
