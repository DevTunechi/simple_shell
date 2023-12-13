#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t _mygetline(char **line, size_t *len, int fd) {
    if (!line || !len) {
        return -1;
    }

    size_t bufsize = 1024;
    *line = (char *)malloc(bufsize);
    if (!*line) {
        return -1;
    }

    size_t i = 0;
    char c;

    while (1) {
        ssize_t read_size = read(fd, &c, 1);

        if (read_size == -1) {
            free(*line);
            *line = NULL;
            return -1;
        }

        if (read_size == 0 || c == '\n') {
            (*line)[i] = '\0';
            return i;
        }

        (*line)[i] = c;
        i++;

        if (i >= bufsize) {
            bufsize += 1024;
            char *temp = (char *)realloc(*line, bufsize);
            if (!temp) {
                free(*line);
                *line = NULL;
                return -1;
            }
            *line = temp;
        }
    }
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read_size;

    write(STDOUT_FILENO, "$: ", 3);

    read_size = _mygetline(&line, &len, STDIN_FILENO);
    if (read_size != -1) {
        write(STDOUT_FILENO, line, read_size);
    } else {
        perror("_mygetline");
        exit(EXIT_FAILURE);  
    }

    free(line);

    return 0;
}
