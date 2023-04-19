#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file.
 * @text_content: string to be added at the end of the file.
 * Return: If filename is NULL - -1.
 *         If file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fo, fw, size = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (size = 0; text_content[size];)
			size++;
	}
	fo = open(filename, O_WRONLY | O_APPEND);
	fw = write(fo, text_content, size);

	if (fo == -1 || fw == -1)
		return (-1);
	close(fo);
	return (1);
}
