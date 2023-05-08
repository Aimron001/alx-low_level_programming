#include "main.h"
#include <stdlib.h>
/**
 * read_textfile-  reads a file and prints it to the POSIX standard output
 * @filename: text file to be read
 * @letters: number of letters to be read and printed
 * Return: n -  actual number of letters it could read and print
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t n;
	ssize_t b;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	b = read(fd, buffer, letters);
	n = write(STDOUT_FILENO, buffer, b);

	free(buffer);
	close(fd);
	return (n);
}
