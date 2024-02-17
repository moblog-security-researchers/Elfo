#include "elfo_header.h"

#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void read_elf_header(const int fd, const Elf32_Ehdr *elf_header)
{
    assert(lseek(fd, (off_t)0, SEEK_SET) == (off_t)0);
    assert(read(fd, (void *)elf_header, sizeof(Elf32_Ehdr)) == sizeof(Elf32_Ehdr));
}

void read_elf_header_64(const int fd, const Elf64_Ehdr *elf_header)
{
    assert(lseek(fd, (off_t)0, SEEK_SET) == (off_t)0);
    assert(read(fd, (void *)elf_header, sizeof(Elf64_Ehdr)) == sizeof(Elf64_Ehdr));
}

const bool  is_elf_64(const Elf32_Ehdr *eh)
{
    return (eh->e_ident[EI_CLASS] == ELFCLASS64) ? true : false;
}

const bool is_elf(const Elf32_Ehdr *eh)
{
	return (!strncmp((char *)eh->e_ident, "\177ELF", 4)) ? true : false;
}

const char* get_endianness(const Elf32_Ehdr *eh){
	switch(eh->e_ident[EI_DATA]){
		case ELFDATA2LSB:
			return "Little Endian";
		case ELFDATA2MSB:
			return "Big Endian";
		default:
			return "Data encoding unknown!";
	}
}
