#include "elfo.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd = open("./bin/elf32test", O_RDONLY);

    if (fd > 0)
    {
        Elf32_Ehdr eh;
        read_elf_header(fd, &eh);
        
        bool is_64;

        assert(is_elf(&eh) == true);
	//assert(eh.e_entry == 0x1960);
	//assert(is_64 = is_elf_64(&eh) == true);

	printf("%s\n", get_endianness(&eh));
        if (is_64)
        {
            Elf64_Ehdr eh_64;
            read_elf_header_64(fd, &eh_64);

            Elf64_Shdr *sh_64 = malloc(eh_64.e_shentsize * eh_64.e_shnum);

            read_section_header_table_64(fd, sh_64, eh_64);            

            free(sh_64);
        }

        close(fd);
    }

    return 0;
}
