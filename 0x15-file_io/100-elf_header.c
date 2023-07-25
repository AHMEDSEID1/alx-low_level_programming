#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header at the start
 * of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd, r;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Cannot open %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, &header, sizeof(header));
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error reading from file %s\n", argv[1]);
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "%s is not an ELF file\n", argv[1]);
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");

	int i;
for (i = 0; i < EI_NIDENT; i++)

	printf("%02x ", header.e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
			break;
	}
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
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
			printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
			break;
	}
	printf("  Version:                           ");
	switch (header.e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("0 (invalid)\n");
			break;
		case EV_CURRENT:
			printf("%d (current)\n", EV_CURRENT);
			break;
		default:
			printf("%d\n", header.e_ident[EI_VERSION]);
			break;
	}
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
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
    }
}
