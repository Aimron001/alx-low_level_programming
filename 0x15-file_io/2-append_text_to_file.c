#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to be edited
 * @text_content: text to be appended to end of the file.
 * Return: 1 on success
 * 	-1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o_file, w_file, size = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (size = 0; text_content[size];)
			size++;
	}
	o_file = open(filename, O_WRONLY | O_APPEND);
	w_file = write(o_file, text_content, size);
	if (o_file == -1 || w_file == -1)
		return (-1);
	close(o_file);
	return (1);
}
