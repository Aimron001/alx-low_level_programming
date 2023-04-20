#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


#define ERROR_CODE 98
/**
 * print_elf_header_info - prints ELF INFO
 * @elf_header: pointer to the header of elf
 * Return: 0
 */

void print_elf_header_info(Elf64_Ehdr *elf_header)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_header->e_ident[i]);
	}
	printf("\n");
	printf("Class: %s\n",
			elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data: %s\n",
			elf_header->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n",
			elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX - System V" : "UNIX - Other");
	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type: ");
	switch (elf_header->e_type)
	{
	case ET_NONE:
	printf("NONE (None)\n");
	break;
	case ET_REL:
	printf("REL (Relocatable file)\n");
	break;
	case ET_EXEC:
	printf("EXEC (Executable file)\n");
	break;
	case ET_DYN:
	printf("DYN (Shared object file)\n");
	break;
	case ET_CORE:
	printf("CORE (Core file)\n");
	break;
	default:
	printf("<unknown: %d>\n", elf_header->e_type);
	}
	printf(" Entry Point Address: 0x%lx\n", elf_header->e_entry);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: info form the header of ELF
 */

int main(int argc, char *argv[])
{
	Elf64_Ehdr elf_header;
	int fd;

	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	exit(ERROR_CODE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
	fprintf(stderr, "Error: Failed to open file %s\n", argv[1]);
	exit(ERROR_CODE);
	}

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
	fprintf(stderr, "Error: Failed to read ELF header from file %s\n", argv[1]);
	exit(ERROR_CODE);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: The file isn't an ELF file: %s\n", argv[1]);
		exit(ERROR_CODE);
	}

	print_elf_header_info(&elf_header);
	close(fd);

	return (0);
}
