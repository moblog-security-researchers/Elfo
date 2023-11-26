#pragma once

#include <elf.h>

void read_section_header_table(int fd, Elf64_Shdr *eh, Elf32_Ehdr sh_table);
void read_section_header_table_64(int fd, Elf64_Shdr *eh, Elf64_Ehdr sh_table);