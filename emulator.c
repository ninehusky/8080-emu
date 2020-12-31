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
#include <stdio.h> // for printf
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

/*  HELPER FUNCTIONS  */
// Note: these functions are mostly related to the flags.
// It looks like the flags are set differently depending on the operation.
// Instead of altering the flags in the operations, consider having
// different setFlags() functions.
// TODO: Check to see how different flags are set.
// According to the manual, "Addition, subtraction, rotate, and logical operations
// follow different rules for setting and resetting the carry bit.

/*
 * Returns the result of a parity calculation given a result.
 */
int parity(uint16_t result) {
    int parityResult = 1;
    while (result > 0) {
        int currentBit = result & 0x1;
        if (currentBit) {
            parityResult = !parityResult;
        }
        result /= 10;
    }
    return parityResult;
}

/*
 * Sets the zero, sign, and parity bits given some result.
 */
void setZSPFlags(uint16_t result, State8080* state) {
    // zero bit is set when the result is zero
    state->cc.z = ((result & 0xff) == 0x0);
    // the sign bit is on when the seventh bit is 1
    state->cc.s = ((result & 0x80) == 0x80);
    // the parity bit is on when the number of '1' bits in a byte is even
    state->cc.p = parity(result & 0xff);
}

/*
 * Sets the condition bits after an addition operation.
 */
void setFlagsAdd(State8080* state, uint16_t result) {
    setZSPFlags(result, state);
    state->cc.cy = result > 0xff;
}

/*
 * Sets the condition bits after a subtraction operation.
 */
void setFlagsSub(State8080* state, uint16_t result) {
    setFlagsAdd(state, result);
    // if the carry bit is set when adding the 2's complement, reset it.
    // set the carry bit if the opposite occurs
    state->cc.cy = !state->cc.cy;
}

/*
 * TODO: check this out. it looks like the different rotation instructions
 * affect the carry bit differently.
 */

/*
 * Sets the condition bits after a logical operation, e.g. ANA
 */
void setFlagsLogical(State8080* state, uint16_t result) {
    setZSPFlags(result, state);
    // The carry bit is reset to zero.
    state->cc.cy = 0;
}

/*  CARRY BIT INSTRUCTIONS  */
/*
 * CMC
 * Flips the carry bit.
 */
void complementCarry(State8080* state) {
    state->cc.cy = !state->cc.cy;
}

/*
 * STC
 * The Carry bit is set to one.
 */
void setCarry(State8080* state) {
    state->cc.cy = 1;
}

/*
 * INR
 * The specified register or memory byte is incremented by one.
 */
void incrementRegisterOrMemory(State8080* state, uint8_t* byte) {
    uint16_t result = (uint16_t)byte + 0x1;
    setFlagsAdd(state, result); // TODO: call the add method instead
}

/*
 * DCR
 * The specified register or memory byte is decremented by one.
 */
void decrementRegisterOrMemory(State8080* state, uint8_t* byte) {
    uint16_t result = (uint16_t)byte - 0x1;
    setFlagsSub(state, result);
}

/*
 * CMA
 * Each bit of the contents of the accumulator is complemented, producing the
 * one's complement.
 */
void complementAccumulator(uint8_t* accumulator) {
    *accumulator ^= *accumulator;
}

/*
 * DAA
 * Decimal adjust accumulator - unneeded by Space Invaders.
 */
void decimalAdjustAccumulator() {
    printf("Opcode implementation unneeded by Space Invaders\n");
}

/*
 * MOV
 * One byte of data is moved from the register specified by src (the source register) to the
 * register specified by dst (the destination register). The data replaces the contents
 * of the destination register; the source remains unchanged.
 * Flags affected: none
 */
void movInstruction(uint8_t* src, uint8_t* dst) {
    uint8_t temp = *src;
    *src = *dst;
    *dst = temp;
}

/*
 * STAX
 * The contents of the accumulator are stored in the memory location addressed by the given pair of
 * registers. These are registers B and C, or registers D and E.
 * Flags affected: none
 */
void storeAccumulator(State8080* state, uint8_t* reg1, uint8_t* reg2) {
    uint8_t accumulatorValue = state->a;
    uint16_t address = ((*reg1 << 8) | *reg2);
    // mem[address] = accumulatorValue;
}


/*
 * LDAX
 * The contents of the memory location addressed by registers B and C, or by registers D and E,
 * replace the contents of the accumulator.
 */
void loadAccumulator(State8080* state, uint8_t* reg1, uint8_t* reg2) {
    uint16_t address = ((*reg1 << 8) | *reg2);
    // state->a = mem[address];
}


