#include "shell.h"

/**
 * **strtow - Separates a string into words. Repeated delimiters are ignored.
 * @str: The input string.
 * @d: The delimiter string.
 * Goodnews and Olatunji
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow(char *str, char *d)
{
int idx1, idx2, len1, len2, count = 0;
char **result;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (idx1 = 0; str[idx1] != '\0'; idx1++)
if (!is_delim(str[idx1], d) && (is_delim(str[idx1 + 1], d) || !str[idx1 + 1]))
count++;

if (count == 0)
return (NULL);
result = malloc((1 + count) *sizeof(char *));
if (!result)
return (NULL);
for (idx1 = 0, idx2 = 0; idx2 < count; idx2++)
{
while (is_delim(str[idx1], d))
idx1++;
len1 = 0;
while (!is_delim(str[idx1 + len1], d) && str[idx1 + len1])
len1++;
result[idx2] = malloc((len1 + 1) * sizeof(char));
if (!result[idx2])
{
for (len1 = 0; len1 < idx2; len1++)
free(result[len1]);
free(result);
return (NULL);
}
for (len2 = 0; len2 < len1; len2++)
result[idx2][len2] = str[idx1++];
result[idx2][len2] = 0;
}
result[idx2] = NULL;
return (result);
}

/**
 * **strtow2 - Splits a string into words.
 * @str: The input string.
 * @d: The delimiter.
 * Goodnews and Olatunji
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow2(char *str, char d)
{
int idx1, idx2, len1, len2, count = 0;
char **result;

if (str == NULL || str[0] == 0)
return (NULL);
for (idx1 = 0; str[idx1] != '\0'; idx1++)
if ((str[idx1] != d && str[idx1 + 1] == d) ||
(str[idx1] != d && !str[idx1 + 1]) || str[idx1 + 1] == d)
count++;
if (count == 0)
return (NULL);
result = malloc((1 + count) *sizeof(char *));
if (!result)
return (NULL);
for (idx1 = 0, idx2 = 0; idx2 < count; idx2++)
{
while (str[idx1] == d && str[idx1] != d)
idx1++;
len1 = 0;
while (str[idx1 + len1] != d && str[idx1 + len1] && str[idx1 + len1] != d)
len1++;
result[idx2] = malloc((len1 + 1) * sizeof(char));
if (!result[idx2])
{
for (len1 = 0; len1 < idx2; len1++)
free(result[len1]);
free(result);
return (NULL);
}
for (len2 = 0; len2 < len1; len2++)
result[idx2][len2] = str[idx1++];
result[idx2][len2] = 0;
}
result[idx2] = NULL;
return (result);
}
