#include "elfo_header.h"

#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/************************** ELF 32 *************************************************/
void read_elf_header(const int fd, const Elf32_Ehdr *elf_header)
{
    assert(lseek(fd, (off_t)0, SEEK_SET) == (off_t)0);
    assert(read(fd, (void *)elf_header, sizeof(Elf32_Ehdr)) == sizeof(Elf32_Ehdr));
}


const bool is_elf(const Elf32_Ehdr *eh)
{
	return (!strncmp((char *)eh->e_ident, "\177ELF", 4)) ? true : false;
}

const unsigned char get_endianness(const Elf32_Ehdr *eh){
	return eh->e_ident[EI_DATA];
}

const unsigned char get_elf_version(const Elf32_Ehdr *eh){
	return eh->e_ident[EI_VERSION];
}

const unsigned char get_osabi(const Elf32_Ehdr *eh){
	return eh->e_ident[EI_OSABI];
}

const unsigned char get_osabi_version(const Elf32_Ehdr *eh){
	return eh->e_ident[EI_ABIVERSION];
}

const ELF_Half get_elf_type(const Elf32_Ehdr *eh){
	return eh->e_type;
}

const ELF_Half get_elf_machine(const Elf32_Ehdr *eh){
	return eh->e_machine;
}

const Elf32_Addr get_elf_entry(const Elf32_Ehdr *eh){
	return eh->e_entry;
}

const Elf32_Off get_elf_phoffset(const Elf32_Ehdr *eh){
	return eh->e_phoff;
}

const Elf32_Off get_elf_shoffset(const Elf32_Ehdr *eh){
	return eh->e_shoff;
}
/*************************** ELF 64 *************************************************/
void read_elf_header_64(const int fd, const Elf64_Ehdr *elf_header)
{
    assert(lseek(fd, (off_t)0, SEEK_SET) == (off_t)0);
    assert(read(fd, (void *)elf_header, sizeof(Elf64_Ehdr)) == sizeof(Elf64_Ehdr));
}

const bool  is_elf_64(const Elf64_Ehdr *eh)
{
    return (eh->e_ident[EI_CLASS] == ELFCLASS64) ? true : false;
}

const unsigned char get_endianness64(const Elf64_Ehdr *eh){
	return eh->e_ident[EI_DATA];
}

const unsigned char get_elf_version64(const Elf64_Ehdr *eh){
	return eh->e_ident[EI_VERSION];
}

const unsigned char get_osabi64(const Elf64_Ehdr *eh){
	return eh->e_ident[EI_OSABI];
}

const unsigned char get_osabi_version64(const Elf64_Ehdr *eh){
	return eh->e_ident[EI_ABIVERSION];
}

const ELF_Half get_elf_type64(const Elf64_Ehdr *eh){
	return eh->e_type;
}

const ELF_Half get_elf_machine64(const Elf64_Ehdr *eh){
	return eh->e_machine;
}

const Elf64_Addr get_elf_entry64(const Elf64_Ehdr *eh){
	return eh->e_entry;
}

const Elf64_Off get_elf_phoffset64(const Elf64_Ehdr *eh){
	return eh->e_phoff;
}

const Elf64_Off get_elf_shoffset64(const Elf64_Ehdr *eh){
	return eh->e_shoff;
}
