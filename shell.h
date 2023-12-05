#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* command_processing.c */
int determine_chain(char *command);
int verify_chain(int status, char *chain_delimiter);
char *substitute_alias(char *command);
char *substitute_vars(char *command);
char *substitute_string(char *str, char *old, char *new);
char **str_to_words(char *str);
int count_words(char *str);
void free_words(char **words);
int is_delim(char c, char *delims);

/* string_operations.c */
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

/* shell_execution.c */
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);

/* memory_operations.c */
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string_operations1.c */
char *copy_string(char *destination, char *source);

/* path_operations.c */
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);


/* free_buffer.c */
int free_buffer(void **buffer);

/* main.c */
int main(int ac, char **av);

/* list_operations.c */


size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);

/* linked_list_operations.c */
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/* history_operations.c */
char *generate_history_file_path(info_t *info);
int write_history_to_file(info_t *info);
int read_history_from_file(info_t *info);
int build_history_list(info_t *info, char *buffer, int line_count);
int renumber_history(info_t *info);
int _putchar(char c);

/* shell_getline.c */
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused)) int sig_num);

/* shell_get_info.c */
void initialize_data(Goodnews_info_t *data);
void configure_data(Goodnews_info_t *data, char **arguments_vector);
void release_data(Goodnews_info_t *data, int all);

/* get_shell_env.c */
char **get_environment(info_t *info);
int unset_environment_variable(info_t *info, char *var);
int set_environment_variable(info_t *info, char *var, char *value);

/* string_functions.c */
char *_custom_strncpy(char *destination, char *source, int num);
char *_custom_strncat(char *destination, char *source, int num);
char *_custom_strchr(char *str, char character);

/* handle_error.c */
int _custom_erratoi(char *str);
void custom_print_error(info_t *info, char *estr);
int custom_print_d(int input, int fd);
char *custom_convert_number(long int num, int base, int flags);
void custom_remove_comments(char *buffer);

#endif /* SHELL_H */
