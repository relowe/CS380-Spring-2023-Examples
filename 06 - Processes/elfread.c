#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "types.h"
#include "elf.h"

unsigned char *read_file(const char *filename) {
    struct stat st;
    unsigned char *data;
    int i;
    int fd;
    int sz;

    if(stat(filename, &st)) {
        return NULL;
    }

    // allocate space for the bytes in the file
    data = malloc(st.st_size);

    //read the contents of the file
    fd = open(filename, O_RDONLY); 
    sz = read(fd, data, st.st_size);
    close(fd);

    return data;
}


int main(int argc, char** argv) {
    unsigned char *data = read_file(argv[1]);
    struct elfhdr *elf = (struct elfhdr*) data;
    struct proghdr *phead;
    int i;

    // print the elf header
    printf("magic: 0x%x\n", elf->magic);
    printf("elf: ");
    for(i=0; i<12; i++) {
        printf("0x%x ", elf->elf[i]);
    }
    putchar('\n');
    printf("type: 0x%x\n", elf->type);
    printf("machine: 0x%x\n", elf->machine);
    printf("version: 0x%x\n", elf->version);
    printf("entry: 0x%x\n", elf->entry);
    printf("phoff: 0x%x\n", elf->phoff);
    printf("shoff: 0x%x\n", elf->shoff);
    printf("flags: 0x%x\n", elf->flags);
    printf("ehsize: 0x%x\n", elf->ehsize);
    printf("phentsize: 0x%x\n", elf->phentsize);
    printf("phnum: 0x%x\n", elf->phnum);
    printf("shentsize: 0x%x\n", elf->shentsize);
    printf("shnum: 0x%x\n", elf->shnum);
    printf("shstrndx: 0x%x\n", elf->shstrndx);

    //compute program header array
    phead = (struct proghdr*) (data + elf->phoff);
    
    //loop over the program headers
    for(i=0; i<elf->phnum; i++, phead++) {
        printf("\nProgram Header 0x%x\n", i);
        printf("type: 0x%x\n", phead->type);
        printf("flags: 0x%x\n", phead->flags);
        printf("off: 0x%x\n", phead->off);
        printf("vaddr: 0x%x\n", phead->vaddr);
        printf("paddr: 0x%x\n", phead->paddr);
        printf("filesz: 0x%x\n", phead->filesz);
        printf("memsz: 0x%x\n", phead->memsz);
        printf("align: 0x%x\n", phead->align);
    }
}
