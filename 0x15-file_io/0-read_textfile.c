#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fh;
    int i, j;
    char *buffer;

    if (filename == NULL)
		return (0);

	fh = open(filename, O_RDONLY);

	if (fh == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
    if (!buffer)
        return (0);
    i = read(fh, buffer, letters);

	if (i == -1)
	{
		free(buffer);
		return (0);
	}
    buffer[i]='\0';
    close(fh);

    j = write(STDOUT_FILENO, buffer, i);

    if (j < 0)
	{
		free(buffer);
		return (0);
	}
	free(buffer);

	return (j);
}
