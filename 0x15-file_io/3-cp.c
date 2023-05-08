#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buff(char *filename);
void close_file(int fd);
/**
 * create_buff - creates memory space of 1024 bytes
 * @filename: name of the file to be edited
 * Return: allocated buffer.
 */
char *create_buff(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (buf);
}

/**
 * close_file - Closes files.
 * @fd: file descriptors for files to be closed.
 */
void close_file(int fd)
{
	int c_fd;

	c_fd = close(fd);

	if (c_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main -  copies the content of a file to another file
 * @argc: The number of arguments typed in the terminal
 * @argv: An array of the arguments.
 * Return: 0 on success.
 * Description: if the number of argument is not the correct one, exit code 97
 * if file_from does not exist, or if you can not read it, exit with code 98
 * if you can not create or if write to file_to fails, exit with code 99
 * if you can not close a file descriptor , exit with code 100
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, r_file, w_file;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = create_buff(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	r_file = read(file_from, buf, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || r_file == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		w_file = write(file_to, buf, r_file);
		if (file_to == -1 || w_file == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		r_file = read(file_from, buf, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r_file > 0);
	free(buf);
	close_file(file_from);
	close_file(file_to);
	return (0);
}

