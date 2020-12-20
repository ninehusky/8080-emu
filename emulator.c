#include <stdio.h>
int disassemble(unsigned char* codebuffer, int pc) {
    unsigned char *opcode = &codebuffer[pc];
    int opbytes = 1;
    printf("%04x ", pc);
    switch(*opcode) {
        case 0x00:
            printf("NOP");
            break;
        case 0x01:
            printf("LXI    B, %02X%02X", opcode[2], opcode[1]);
            opbytes = 3;
            break;
        case 0x02:
            printf("STAX   B");
            break;
        case 0x03:
            printf("INX    B");
            break;
        case 0x04:
            printf("INR    B");
            break;
        case 0x05:
            printf("DCR    B");
            break;
        case 0x06:
            printf("MVI    B, %02X", opcode[1]);
            opbytes = 2;
            break;
        case 0x07:
            printf("RLC");
            break;
        case 0x08:
            printf("NOP");
            break;
        case 0x09:
            printf("DAD    B");
            break;
        case 0x0A:
            printf("LDAX   B");           
            break;
        case 0x0B:
            printf("DCX    B");
            break;
        case 0x0C:
            printf("INR    C");
            break;
        case 0x0D:
            printf("DCR    C");
            break;
        case 0x0E:
            printf("MVI    C, %02x", opcode[1]);
            opbytes = 2;
            break;
        case 0x0F:
            printf("RRC");
            break;
        default:
            printf("Error: opcode %04X not implemented.", *opcode);
            break;
    }
    printf("\n");
    return opbytes;
}
