#include "shell.h"

/**
 * generate_history_file_path - Generates the path to the history file.
 * @info: The parameter struct.
 * Authors: Goodnews & Olatunji
 * Returns: Allocated string containing the history file path.
 */

char *generate_history_file_path(info_t *info)
{
char *path, *home_directory;

home_directory = _getenv(info, "HOME=");
if (!home_directory)
return (NULL);

path = malloc(sizeof(char) * (_strlen(home_directory)
+ _strlen(HIST_FILE) + 2));
if (!path)
return (NULL);

path[0] = 0;
_strcpy(path, home_directory);
_strcat(path, "/");
_strcat(path, HIST_FILE);

return (path);
}

/**
 * write_history_to_file - Creates a file or appends an existing file
 * @info: The parameter struct.
 * Authors: Goodnews & Olatunji
 * Returns: 1 on success, else -1.
 */

int write_history_to_file(info_t *info)
{
ssize_t file_descriptor;
char *filename = generate_history_file_path(info);
list_t *history_node = NULL;

if (!filename)
return (-1);

file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);

if (file_descriptor == -1)
return (-1);

for (history_node = info->history; history_node; history_node
= history_node->next)
{
_putsfd(history_node->str, file_descriptor);
_putfd('\n', file_descriptor);
}

_putfd(BUF_FLUSH, file_descriptor);
close(file_descriptor);

return (1);
}

/**
 * read_history_from_file - Reads history from file and updates linked list.
 * @info: The parameter struct.
 * Authors: Goodnews & Olatunji
 * Returns: Histcount on success, 0 otherwise.
 */

int read_history_from_file(info_t *info)
{
int i, last = 0, line_count = 0;
ssize_t file_descriptor, read_length, file_size = 0;
struct stat file_stats;
char *buffer = NULL, *filename = generate_history_file_path(info);

if (!filename)
return (0);

file_descriptor = open(filename, O_RDONLY);
free(filename);

if (file_descriptor == -1)
return (0);

if (!fstat(file_descriptor, &file_stats))
file_size = file_stats.st_size;

if (file_size < 2)
return (0);

buffer = malloc(sizeof(char) * (file_size + 1));
if (!buffer)
return (0);

read_length = read(file_descriptor, buffer, file_size);
buffer[file_size] = 0;

if (read_length <= 0)
return (free(buffer), 0);

close(file_descriptor);

for (i = 0; i < file_size; i++)
if (buffer[i] == '\n')
{
buffer[i] = 0;
build_history_list(info, buffer + last, line_count++);
last = i + 1;
}

if (last != i)
build_history_list(info, buffer + last, line_count++);

free(buffer);
info->hist_count = line_count;

while (info->hist_count-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);

renumber_history(info);

return (info->hist_count);
}

/**
 * build_history_list - Adds an entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain
 * @buffer: Buffer containing the history entry.
 * @line_count: The history line count, hist_count.
 * Authors: Goodnews & Olatunji
 * Returns: Always 0.
 */

int build_history_list(info_t *info, char *buffer, int line_count)
{
list_t *node = NULL;

if (info->history)
node = info->history;

add_node_end(&node, buffer, line_count);

if (!info->history)
info->history = node;

return (0);
}

/**
 * renumber_history - Updates the numbering of the history linked list.
 * @info: Structure containing potential arguments. Used to maintain
 * Authors: Goodnews & Olatunji
 * Returns: The new hist_count.
 */

int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}

return (info->hist_count = i);
}
