#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message and exits the program.
 * @message: The error message to be printed.
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Invalid class\n");
		break;
	}
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
		break;
	}
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
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
		printf("Unknown type\n");
		break;
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on invalid usage or error.
 */
int main(int argc, char *argv[])
{
	const char *elf_filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		printf("Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	elf_filename = argv[1];
	 fd = open(elf_filename, O_RDONLY);

	if (fd == -1)
		print_error("Error opening file");

	bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read == -1)
		print_error("Error reading file");

	if (bytes_read < (ssize_t)sizeof(header))
		print_error("File is too small to be an ELF file");


	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("File is not an ELF file");
	}

	print_elf_header(&header);

	close(fd);

	return (0);
}
