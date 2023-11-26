ELFO: A C-lang ELF Library Parser

![](assets/elfo.png)

An ELF parser library implemented in C.

## Contents

* [Features](#features)
* [Usage](#usage)
* [Integration](#integration)


## Features

- **Efficient Parsing:** Written in C for optimal performance and efficiency.
- **Versatility:** Supports parsing ELF files, including executables and shared libraries.
- **Accessible Information:** Extracts key information such as section headers, program headers, symbols, and more.
- **Integration-Friendly:** Easily integrate the library into your projects for seamless ELF file analysis using CMakeLists

## Usage

1. **Include the Library:**
```c
    #include "elfo.h"
    
    int fd = open("<bin.elf>", O_RDONLY);
    
    const Elf32_Ehdr eh;
    
    if (fd > 0)
    {
        read_elf_header(fd, &eh);
        
        if(is_elf(&eh))
        {
            assert(eh.e_entry == <0xaddr>);
            assert(is_elf_64(&eh) == true);
        }
        
        close(fd);
    }
    
    <...>

    Elf64_Ehdr eh_64;
    read_elf_header_64(fd, &eh_64);

    Elf64_Shdr *sh_64 = malloc(eh_64.e_shentsize * eh_64.e_shnum);

    read_section_header_table_64(fd, sh_64, eh_64);            

    free(sh_64);
```

## Integration

Add the following entry to your `CMakeLists.txt` file:

```
add_subdirectory(<clone_path_to_elfo> build/elfo)
```

Ensure you customize `<clone_path_to_elfo>` to the appropriate path in your project structure.


## Run Tests

To run the tests you need to enter the `build/tests` folder and then run it inside the `./elfotest` folder, you can choose to build or test it or not in CMakeLists by setting BUILD_TESTS