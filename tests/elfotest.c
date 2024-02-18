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
        
      
	printf("0x%x\n", get_endianness(&eh));
	printf("0x%x\n", get_elf_version(&eh));
	printf("0x%x\n", get_osabi(&eh));
	printf("0x%x\n", get_osabi_version(&eh));
	printf("0x%x\n", get_elf_type(&eh));
	printf("0x%x\n", get_elf_machine(&eh));
	printf("0x%x\n", get_elf_entry(&eh));
	printf("0x%x\n", get_elf_phoffset(&eh));
	printf("0x%x\n", get_elf_shoffset(&eh));
    }
    return 0;
}
