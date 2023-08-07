#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/* A macro to define the ELF data types depending on the architecture */
#if defined(__LP64__)
#define ElfW(type) Elf64_ ## type
#else
#define ElfW(type) Elf32_ ## type
#endif

/* A function to print the magic number in hexadecimal format */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
}
	printf("\n");
}

/* A function to print the class of the file (32-bit or 64-bit) */
void print_class(unsigned char e_class)
{
	printf("  Class:                             ");
	switch (e_class)
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASSNONE:
			printf("Invalid class\n");
			break;
		default:
			printf("Unknown class\n");
			break;
	}
}

/* A function to print the data encoding of the file */
void print_data(unsigned char e_data)
{
	printf("  Data:                              ");
	switch (e_data)
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		case ELFDATANONE:
			printf("Invalid data encoding\n");
			break;
		default:

			printf("Unknown data encoding\n");
			break;
	}
}

/* A function to print the version of the file */
void print_version(unsigned char e_version)
{
	printf("  Version:                           ");
	switch (e_version)
	{
		case EV_CURRENT:
			printf("%d (current)\n", e_version);
			break;
		case EV_NONE:
			printf("%d\n", e_version);
			break;
		default:
			printf("%d\n", e_version);
			break;
	}
}

/* A function to print the OS/ABI of the file*/
void print_osabi(unsigned char e_osabi)
{
	printf("  OS/ABI:                            ");
	switch (e_osabi)
	{
		case ELFOSABI_SYSV:
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
			printf("<unknown: %x>\n", e_osabi);
			break;
	}
}

/* A function to print the ABI version of the file*/
void print_abiversion(unsigned char e_abiversion)
{

	printf("ABI Version:                       %d\n", e_abiversion);
}

