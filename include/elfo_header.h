#pragma once

#include <elf.h>
#include <stdbool.h>
#include <stddef.h>

#define ELF_Half uint16_t
#define ELF_Word uint32_t

/**************** ELF 32 *************************************/

void read_elf_header(const int fd, const Elf32_Ehdr *elf_header);
const bool is_elf(const Elf32_Ehdr *eh);
const unsigned char get_endianness(const Elf32_Ehdr *eh);
const unsigned char get_elf_version(const Elf32_Ehdr *eh);
const unsigned char get_osabi(const Elf32_Ehdr *eh);
const unsigned char get_osabi_version(const Elf32_Ehdr *eh);
const ELF_Half get_elf_type(const Elf32_Ehdr *eh);
const ELF_Half get_elf_machine(const Elf32_Ehdr *eh);
const Elf32_Addr get_elf_entry(const Elf32_Ehdr *eh);
const Elf32_Off get_elf_phoffset(const Elf32_Ehdr *eh);
const Elf32_Off get_elf_shoffset(const Elf32_Ehdr *eh);
/**************** ELF 64 *************************************/

void read_elf_header_64(const int fd, const Elf64_Ehdr *elf_header);
const bool is_elf_64(const Elf64_Ehdr *eh);
const unsigned char get_endianness64(const Elf64_Ehdr *eh);
const unsigned char get_elf_version64(const Elf64_Ehdr *eh);
const unsigned char get_osabi64(const Elf64_Ehdr *eh);
const unsigned char get_osabi_version64(const Elf64_Ehdr *eh);
const ELF_Half get_elf_type64(const Elf64_Ehdr *eh);
const ELF_Half get_elf_machine64(const Elf64_Ehdr *eh);
const Elf64_Addr get_elf_entry64(const Elf64_Ehdr *eh);
const Elf64_Off get_elf_phoffset64(const Elf64_Ehdr *eh);
const Elf64_Off get_elf_shoffset64(const Elf64_Ehdr *eh);
