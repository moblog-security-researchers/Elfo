#pragma once

#include <elf.h>
#include <stdbool.h>
#include <stddef.h>

void read_elf_header(const int fd, const Elf32_Ehdr *elf_header);
void read_elf_header_64(const int fd, const Elf64_Ehdr *elf_header);
const bool is_elf_64(const Elf32_Ehdr *eh);
const bool is_elf(const Elf32_Ehdr *eh);
