#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - exits program with given exit_code and error message
 * @exit_code: exit code to use
 * @message: error message to print
 *
 * Return: void
 */
void error_exit(int exit_code, char *message)
{
        dprintf(STDERR_FILENO, "%s\n", message);
        exit(exit_code);
}

/**
 * main - entry point for the program
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, error code on failure
 */
int main(int argc, char **argv)
{
        int fd_from, fd_to, read_ret, write_ret;
        char buffer[BUFFER_SIZE];

        if (argc != 3)
                error_exit(97, "Usage: cp file_from file_to");

        fd_from = open(argv[1], O_RDONLY);
        if (fd_from == -1)
                error_exit(98, "Error: Can't read from file NAME_OF_THE_FILE");

        fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
        if (fd_to == -1)
                error_exit(99, "Error: Can't write to NAME_OF_THE_FILE");

        while ((read_ret = read(fd_from, buffer, BUFFER_SIZE)))
        {
                if (read_ret == -1)
                        error_exit(98, "Error: Can't read from file NAME_OF_THE_FILE");

                write_ret = write(fd_to, buffer, read_ret);
                if (write_ret == -1)
                        error_exit(99, "Error: Can't write to NAME_OF_THE_FILE");
        }

        if (close(fd_from) == -1)
                error_exit(100, "Error: Can't close fd FD_VALUE");

        if (close(fd_to) == -1)
                error_exit(100, "Error: Can't close fd FD_VALUE");

        return (0);
}
