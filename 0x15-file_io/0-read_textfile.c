#include "main.h"
#include <stdlib.h>
/**
 * read_textfile- reads a text file and prints it to the POSIX standard output
 * @filename: file to be read
 * @letters: number of letters to be read
 * Return: b- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t filep;
	ssize_t b;
	ssize_t s;

	filep = open(filename, O_RDONLY);
	if (filep == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	s = read(filep, buffer, letters);
	b = write(STDOUT_FILENO, buffer, s);
	free(buffer);
	close(filep);
	return (b);
}
