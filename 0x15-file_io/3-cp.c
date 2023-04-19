#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *createBuffer(char *file);
void closeFile(int fd);
/**
 * createBuffer -  creates a memory space of 1024 bytes.
 * @file: name of the file buffer is holding chars for.
 * Return: currently allocated buffer.
 */
char *createBuffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * closeFile - Closes the files.
 * @fd: file to be closed.
 */
void closeFile(int fd)
{
	int fc;

	fc = close(fd);
	if (fc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: no. of arguments entered.
 * @argv: An array of the arguments.
 * Return: 0 on success.
 * Description: If argument count is incorrect - exit with code 97.
 * If file_from does not  exist or cant be read - exit with code 98.
 * If file_to cant be created or edited - exit with  code 99.
 * If file_to or file_from cannot be closed - exit with code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, fr, fw;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = createBuffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	fr = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || fr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		fw = write(file_to, buffer, fr);
		if (file_to == -1 || fw == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		fr = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (fr > 0);
	free(buffer);
	closeFile(file_from);
	closeFile(file_to);
	return (0);
}
