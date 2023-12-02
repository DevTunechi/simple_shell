#include "custom_shell.h"

/**
 * initialize_data - sets up the Goodnews_info_t struct
 * @data: struct address
 * Goodnews&Olatunji
 */

void initialize_data(Goodnews_info_t *data)
{
data->argument = NULL;
data->arguments = NULL;
data->executable_path = NULL;
data->argument_count = 0;
}

/**
 * configure_data - configures the Goodnews_info_t struct
 * @data: struct address
 * @arguments_vector: argument vector
 * Goodnews&Olatunji
 */

void configure_data(Goodnews_info_t *data, char **arguments_vector)
{
int i = 0;
data->filename = arguments_vector[0];
if (data->argument)
{
data->arguments = custom_strtow(data->argument, " \t");
if (!data->arguments)
{
data->arguments = malloc(sizeof(char *) * 2);
if (data->arguments)
{
data->arguments[0] = custom_strdup(data->argument);
data->arguments[1] = NULL;
}
}
for (i = 0; data->arguments && data->arguments[i]; i++)
;
data->argument_count = i;
replace_custom_alias(data);
replace_custom_variables(data);
}
}

/**
 * release_data - frees Goodnews_info_t struct fields
 * @data: struct address
 * @all: true if freeing all fields
 * Goodnews&Olatunji
 */

void release_data(Goodnews_info_t *data, int all)
{
custom_free(data->arguments);
data->arguments = NULL;
data->executable_path = NULL;
if (all)
{
if (!data->command_buffer)
free(data->argument);
if (data->environment_variables)
custom_free_list(&(data->environment_variables));
if (data->history_data)
custom_free_list(&(data->history_data));
if (data->custom_alias)
custom_free_list(&(data->custom_alias));
custom_free(data->environment);
data->environment = NULL;
custom_block_free((void **)data->command_buffer);
if (data->read_file_descriptor > 2)
close(data->read_file_descriptor);
custom_putchar(BUFFER_FLUSH);
}
}
