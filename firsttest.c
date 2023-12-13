#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
int main()
{
	char *line = NULL;
	
	size_t len = 0;
	
	ssize_t read;
	
	write(STDOUT_FILENO, "$: ", 3);
	
	read = getline(&line, &len, stdin);
	if (read != -1)
	{
		write(STDOUT_FILENO, line, read);
	}
	else
	{
		perror("getline");
	}
	free(line);
	
	return 0;
}
