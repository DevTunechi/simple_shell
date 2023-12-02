#ifndef _SHELL_H_
#define _SHELL_H_

char *generate_history_file_path(info_t *info);
int write_history_to_file(info_t *info);
int read_history_from_file(info_t *info);
int build_history_list(info_t *info, char *buffer, int line_count);
int renumber_history(info_t *info);
char **get_environment(info_t *info);
int unset_environment_variable(info_t *info, char *var);
int set_environment_variable(info_t *info, char *var, char *value);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);
void ffree(char **pp);
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int is_command(info_t *info, char *path);
char *duplicate_chars(char *pathstr, int start, int stop);
char *find_cmd_path(info_t *info, char *pathstr, char *cmd);
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void initialize_data(Goodnews_info_t *data);
void configure_data(Goodnews_info_t *data, char **arguments_vector);
void release_data(Goodnews_info_t *data, int all);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused)) int sig_num);
char *copy_string(char *destination, char *source);
char *duplicate_string(const char *str);
void print_string(char *str);
int write_char(char character);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
int string_length(char *str);
int string_compare(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
int main(int ac, char **av);

#endif
