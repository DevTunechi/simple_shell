#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* print 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - linked list
 * @num: number field
 * @str: string
 * @next: pointing to the next node
 */

typedef struct liststr
{
int num;
char *str;
struct liststr *next;
}
list_t;


/**
 * struct passinfo - encapsulates pseudo-arguments for passing to a fnctn
 * providing a standardized prototype for function pointer structures
 * @arg: a string created from getline containing arguments
 * @argv: an array of strings derived from arg
 * @path: a string representing the current command's path
 * @argc: the count of arguments
 * @line_count: the count of lines processed
 * @err_num: the error code for exit() operations
 * @linecount_flag: flag indicating whether to count this line of input
 * @fname: the filename of the program
 * @env: a local copy of the linked list environment
 * @environ: a customized and modified copy of the environment from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: flag indicating if the environment was changed
 * @status: the return status of the last executed command
 * @cmd_buf: address of the pointer to cmd_buf, set if chaining
 * @cmd_buf_type: CMD_type indicating ||, &&, or ;
 * @readfd: the file descriptor from which to read line input
 * @histcount: the count of history line numbers
 */

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
}
info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, \
0, 0, NULL, 0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */

typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;


/* Goodnews */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);


/* Olatunji */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);


/* Goodnews */
int loophsh(char **);


/* Olatunji */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);


/* Goodnews */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);


/* Goodnews */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


/* Olatunji */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


/* Goodnews */
char **strtow(char *, char *);
char **strtow2(char *, char);


/* Olatunji */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


/* Olatunji */
int bfree(void **);


/* Goodnews */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


/* Olatunji */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);


/* Goodnews */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);


/* Goodnews */
int _myhistory(info_t *);
int _myalias(info_t *);
int unset_alias(info_t *info, char *str);
int _myhistory(info_t *info);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);



/* Olatunji */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);


/* Goodnews */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);


/* Olatunji */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);


/* Goodnews */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


/* Goodnews */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);


/* Olatunji */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);


/* Olatunji */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);


/* Goodnews */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* setenv and unsetenv */
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);

#endif
