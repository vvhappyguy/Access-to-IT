#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define ELF_NIDENT	16


using namespace std;

// Эта структура описывает формат заголовока ELF файла
struct elf_hdr {
	std::uint8_t e_ident[ELF_NIDENT];
	std::uint16_t e_type;
	std::uint16_t e_machine;
	std::uint32_t e_version;
	std::uint64_t e_entry;
	std::uint64_t e_phoff;
	std::uint64_t e_shoff;
	std::uint32_t e_flags;
	std::uint16_t e_ehsize;
	std::uint16_t e_phentsize;
	std::uint16_t e_phnum;
	std::uint16_t e_shentsize;
	std::uint16_t e_shnum;
	std::uint16_t e_shstrndx;
} __attribute__((packed));


std::uintptr_t entry_point(const char *name)
{
    FILE* ptr;
 
    // Opening file in reading mode
    ptr = fopen(name, "rb");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    struct elf_hdr header;
    fread(&header, sizeof(struct elf_hdr),1, ptr);
    
    return header.e_entry;
 
}

int main() {
    cout << entry_point("a.out");
}