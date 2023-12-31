#include "shell.h"

/**
 * is_cmd - to decide if file is executable command
 * @info: info struct
 * @path: path to file
 * Olatunji and Goodnews
 * Return: 1, 0 otherwise
 */

int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dup_chars - copies characters
 * @pathstr: the PATH string
 * @start: index
 * @stop: stopping index
 * Olatunji and Goodnews
 * Return: pointer to the new buf
 */

char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}

/**
 * find_path - cmd in the PATH string
 * @info: info struct
 * @pathstr: PATH string
 * Olatunji and Goodnews
 * @cmd: cmd to look for
 * Olatunji and Goodnews
 * Return: path of cmd or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
