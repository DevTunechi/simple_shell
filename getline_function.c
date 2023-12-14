#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * mygetline - custom finction to get and read input from stdin
 * @line_size: pointer to store the size
 * @newlinePos: a pointer to the location of  newline character
 * Return: on sucess, pointer to the allocated line
 *
 */

char *mygetline(size_t *line_size) {
    static char buffer[BUFFER_SIZE];
    static size_t index = 0;

    if (index >= BUFFER_SIZE) {
        index = 0;
    }

    ssize_t bytenum = read(STDIN_FILENO, buffer + index, BUFFER_SIZE - index);
    if (bytenum == -1 || bytenum == 0) {
        return NULL;
    }

    char *newlinePos = strchr(buffer + index, '\n');
    if (newlinePos != NULL) {
        *newlinePos = '\0';
        *line_size = newlinePos - (buffer + index);
        index = 0;
        return buffer;
    }

    index += bytenum;
    return NULL;
}

int main(void) {
    size_t line_size;

    while (1) {
        char *line = mygetline(&line_size);
        if (line == NULL) {
            break;
        }

        printf("Line: %s\n", line);
    }

    return 0;
}
