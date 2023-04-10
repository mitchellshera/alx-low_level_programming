#include"main.h"

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
	if (filename == NULL)
		return (0);

	int file_handle = open(filename, O_RDONLY);

	if (file_handle == -1)
		return (0);

	char *buffer = malloc(sizeof(char) * letters);
	ssize_t bytes_read = read(file_handle, buffer, letters);

	if (bytes_read == -1)
	{
		free(buffer);
		close(file_handle);
		return (0);
	}

	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(file_handle);

	if (bytes_written != bytes_read)
		return (0);

	return (bytes_read);
}
