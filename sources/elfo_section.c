#include "elfo_section.h"

#include <assert.h>
#include <aio.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void read_section_header_table(int fd, Elf64_Shdr *eh, Elf32_Ehdr sh_table)
{
	lseek(fd, (__off_t)sh_table.e_shoff, SEEK_SET);

	for (int i = 0; i < sh_table.e_shnum; i++)
	{
		read(fd, (void *)&eh[i], sh_table.e_shentsize);
	}
}

void read_section_header_table_64(int fd, Elf64_Shdr *eh, Elf64_Ehdr sh_table)
{
	lseek(fd, (__off_t)sh_table.e_shoff, SEEK_SET);

	for (int i = 0; i < sh_table.e_shnum; i++)
	{
		read(fd, (void *)&eh[i], sh_table.e_shentsize);
	}
}