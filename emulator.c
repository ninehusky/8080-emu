/*
 * =====================================================================================
 *
 *       Filename:  emulator.c
 *
 *    Description:  Emulates the 8080 :)
 *
 *        Version:  1.0
 *        Created:  12/21/2020 18:16:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

typedef struct ConditionCodes {
    uint8_t     z:1;
    uint8_t     s:1;
    uint8_t     p:1;
    uint8_t     cy:1;
    uint8_t     ac:1;
    uint8_t     pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t     a;
    uint8_t     b;
    uint8_t     c;
    uint8_t     d;
    uint8_t     e;
    uint8_t     h;
    uint8_t     l;
    uint16_t     sp;
    uint16_t     pc;
    uint8_t     *memory;
    struct      ConditionCodes  cc;
    uint8_t     int_enable;
} State8080;


/*  ARITHMETIC OPCODES  */

/*
 * Sets the flags of the condition codes of the 8080 when given a result.
 */
void setFlags(uint16_t result, State8080* state) {
    state->cc.z = ((result & 0xff) == 0);
    state->cc.s = ((result & 0x80) != 0);
    state->cc.cy = (result > 0xff);
    state->cc.p = (result % 2 == 0);
    state->a = result & 0xff;
}

/**
 * Adds the register A with the value in the given register, and stores the value in A.
 */
int add(uint8_t* reg, State8080* state) {
    uint16_t sum = (uint16_t)state->a + (uint16_t)*reg;
    setFlags(sum, state);
    return 1;
}

/*
 * The specified byte plus the content of the carry bit is added to the contents of the
 * accumulator.
 */
int adc(uint8_t* reg, State8080* state) {
    uint16_t sum = (uint16_t)state->a + (uint16_t)*reg + state->cc.cy;
    setFlags(sum, state);
    state->a = sum & 0xff;
    return 1;
}

int sub(uint8_t* reg, State8080* state) {
    uint16_t difference = (uint16_t)state->a - (uint16_t)*reg;
    setFlags(difference, state);
    state->a = sum & 0xff;
    return 1;
}


/*  MEMORY RELATED OPCODES   */
int mov(uint8_t* src, uint8_t* target) {
    *target = *src;
    return 1;
}
