#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char **tokenize_input(char *input);
void execute_command(char **args);

char **tokenize_input(char *input) 
{
	const char *delimiters = " \t\n";
	char **tokens = NULL;
	int token_count = 0;
	
	char *token = strtok(input, delimiters);
	
	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
		tokens[token_count] = strdup(token);
		token_count++;
		
		token = strtok(NULL, delimiters);
	}
	
	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	tokens[token_count] = NULL;
	
	return tokens;
}
 void execute_command(char **args)
{
	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		/* Print the prompt */
		printf("($) ");

		/* Read what the user typed */

		if (getline(&input, &input_size, stdin) == -1)
		{
			perror("getline");

			exit(EXIT_FAILURE);
		}

		/* Break down what the user typed into words */

		char **args = tokenize_input(input);

		/* Check if there's something to do */

		if (args[0] != NULL)
		{
			/* Do what the user asked for */

			execute_command(args);
		}

		/* Clean up the memory */

		for (int i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}

		free(args);
	}

	/* Free the memory used for input */

	free(input);
	return (0);
}

