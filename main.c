#include <stdio.h>
#include <stdlib.h>
#include "emulator.h"

int main (int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./8080 <filename>\n");
        exit(1);
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Error: couldn't open %s\n", argv[1]);
        exit(1);
    }

    // get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END); // move ptr to the end of file
    int fsize = ftell(f); // fsize stores how far f is from beginning
    fseek(f, 0L, SEEK_SET); // move f back to the beginning of the file

    unsigned char *buffer = malloc(fsize);
    fread(buffer, fsize, 1, f);
    fclose(f);

    for (int i = 0; i < fsize; i++) {
        printf("%#04X\n", buffer[i]);
    }
    
    int pc = 0;
    while (pc < fsize) {
        // pc += disassemble(buffer, pc);
        pc += 1;
    }

    return 0;
}
