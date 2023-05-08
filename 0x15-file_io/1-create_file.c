#include "main.h"
/**
 * create_file - Creates a text file.
 * @filename: name of the file to be created.
 * @text_content: text to write to the file.
 * Return: -1 on fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n, size = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (size = 0; text_content[size];)
			size++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	n = write(fd, text_content, size);

	if (fd == -1 || n == -1)
		return (-1);

	close(fd);

	return (1);
}
