#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void is_elf(unsigned char *e_magicN);
void elf_print_magic(unsigned char *e_magicN);
void elf_print_class(unsigned char *e_magicN);
void elf_print_data(unsigned char *e_magicN);
void elf_print_version(unsigned char *e_magicN);
void elf_print_ABI(unsigned char *e_magicN);
void elf_print_OSABI(unsigned char *e_magicN);
void elf_print_type(unsigned int elf_type, unsigned char *e_magicN);
void elf_print_entry(unsigned long int elf_entry, unsigned char *e_magicN);
void close_ELF(int elf);

/**
 * is_elf - Checks if a file is an ELF file.
 * @e_magicN: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void is_elf(unsigned char *e_magicN)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_magicN[i] != 127 &&
		    e_magicN[i] != 'E' &&
		    e_magicN[i] != 'L' &&
		    e_magicN[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * elf_print_magic - Prints the magic numbers of an ELF header.
 * @e_magicN: A pointer to an array containing the ELF magic numbers.
 * Description: the magic nos are separated by spaces.
 */
void elf_print_magic(unsigned char *e_magicN)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_magicN[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * elf_print_class - prints class of an ELF header.
 * @e_magicN: pointer to the array containing elf class.
 */
void elf_print_class(unsigned char *e_magicN)
{
	printf(" Class: ");

	switch (e_magicN[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_magicN[EI_CLASS]);
	}
}

/**
 * elf_print_data - Prints the data of an ELF header.
 * @e_magicN: A pointer to an array containing the ELF class.
 */
void elf_print_data(unsigned char *e_magicN)
{
	printf(" Data: ");

	switch (e_magicN[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_magicN[EI_CLASS]);
	}
}
/**
 * elf_print_version - prints version of  ELF header.
 * @e_magicN: pointer to array containing ELF version.
 */
void elf_print_version(unsigned char *e_magicN)
{
	 printf(" Version: %d",
			  e_magicN[EI_VERSION]);

	switch (e_magicN[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * elf_print_OSABI - prints the OS/ABI of an ELF header.
 * @e_magicN: A pointer to an array containing the ELF version.
 */
void elf_print_OSABI(unsigned char *e_magicN)
{
	printf(" OS/ABI: ");

	switch (e_magicN[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_magicN[EI_OSABI]);
	}
}

/**
 * elf_print_ABI - Prints the ABI version of an ELF header.
 * @e_magicN: pointer to array containing ELF ABI version.
 */
void elf_print_ABI(unsigned char *e_magicN)
{
	printf(" ABI Version: %d\n",
		e_magicN[EI_ABIVERSION]);
}

/**
 * elf_print_type - Prints the type of an ELF header.
 * @elf_type: stores the  ELF type.
 * @e_magicN: A pointer to an array containing the ELF class.
 */
void elf_print_type(unsigned int elf_type, unsigned char *e_magicN)
{
	if (e_magicN[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf(" Type: ");

	switch (elf_type)
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * elf_print_entry - Prints the entry point of an ELF header.
 * @elf_entry: The address of the ELF entry point.
 * @e_magicN: A pointer to an array containing the ELF class.
 */
void elf_print_entry(unsigned long int elf_entry, unsigned char *e_magicN)
{
	printf(" Entry point address: ");

	if (e_magicN[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (e_magicN[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_ELF - Closes ELF file.
 * @elf: file descriptor of ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_ELF(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - prints information stored in the
 * ELF header at the start of the  ELF.
 * @argc: The number of arguments entered.
 * @argv: array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If file is not an ELF File or
 * function fails - exit with code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int op, rd;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_ELF(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		close_ELF(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	is_elf(header->e_ident);
	printf("ELF Header:\n");
	elf_print_magic(header->e_ident);
	elf_print_class(header->e_ident);
	elf_print_data(header->e_ident);
	elf_print_version(header->e_ident);
	elf_print_OSABI(header->e_ident);
	elf_print_ABI(header->e_ident);
	elf_print_type(header->e_type, header->e_ident);
	elf_print_entry(header->e_entry, header->e_ident);

	free(header);
	close_ELF(op);
	return (0);
}

