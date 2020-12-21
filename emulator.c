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
        case 0x10:
            printf("NOP");
            break;
        case 0x11:
            printf("LXI    D, %02x%02x", opcode[2], opcode[1]);
            opbytes = 3;
            break;
        case 0x12:
            printf("STAX   D");
            break;
        case 0x13:
            printf("INX    D");
            break;
        case 0x14:
            printf("INR    D");
            break;
        case 0x15:
            printf("DCR    D");
            break;
        case 0x16:
            printf("MVI    D, %02x", opcode[1]);
            opbytes = 2;
            break;
        case 0x17:
            printf("RAL");
            break;
        case 0x18:
            printf("NOP");
            break;
        case 0x19:
            printf("DAD    D");
            break;
        case 0x1A:
            printf("LDAX   D");
            break;
        case 0x1B:
            printf("DCX    D");
            break;
        case 0x1C:
            printf("INR    E");
            break;
        case 0x1D:
            printf("DCR    E");
            break;
        case 0x1E:
            printf("MVI    E, %02x", opcode[1]);
            opbytes = 2;
            break;
        case 0x1F:
            printf("RAR");
            break;
        case 0x20:
            printf("NOP");
            break;
        case 0x21:
            printf("LXI    H, %02x%02x", opcode[2], opcode[1]);
            opbytes = 3;
            break;
        case 0x22:
            printf("STAX   D");
            break;
        case 0x23:
            printf("INX    D");
            break;
        case 0x24:
            printf("INR    D");
            break;
        case 0x25:
            printf("DCR    D");
            break;
        case 0x26:
            printf("MVI    D, %02x", opcode[1]);
            opbytes = 2;
            break;
        case 0x27:
            printf("RAL");
            break;
        case 0x28:
            printf("NOP");
            break;
        case 0x29:
            printf("DAD   D");
            break;
        case 0x2A:
            printf("LDAX  D");
            break;
        case 0x2B:
            printf("DCX   D");
            break;
        case 0x2C:
            printf("INR   E");
            break;
        case 0x2D:
            printf("DCR   E");
            break;
        case 0x2E:
            printf("MVI   E, %02x", opcode[1]);
            opbytes = 2;
            break;
        case 0x2F:
            printf("RAR");
            break;
        default:
            printf("Error: opcode %04x not implemented.", *opcode);
            break;
    }
    printf("\n");
    return opbytes;
}
