#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char **tokenize_input(char *input);
void execute_command(char **args);
int should_exit(char *input);

char **tokenize_input(char *input) {
    const char *delimiters = " \t\n";
    char **tokens = NULL;
    int token_count = 0;

    char *token = strtok(input, delimiters);
    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        tokens[token_count] = strdup(token);
        token_count++;

        token = strtok(NULL, delimiters);
    }

    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }
}

int should_exit(char *input) {
    return strcmp(input, "exit\n") == 0;
}

int main() {
    char *input = NULL;
    size_t input_size = 0;

    while (1) {
        printf("$:");

        if (getline(&input, &input_size, stdin) == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Check if the user wants to exit
        if (should_exit(input)) {
            break;
        }

        char **args = tokenize_input(input);

        if (args[0] != NULL) {
            execute_command(args);
        }

        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);
    }

    free(input);

    return 0;
}

