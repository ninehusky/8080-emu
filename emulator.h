/*
 * =====================================================================================
 *
 *       Filename:  emulator.h
 *
 *    Description:  Header file for emulator.c
 *
 *        Version:  1.0
 *        Created:  12/20/2020 02:39:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef EMULATORS_H_INCLUDED
#define EMULATORS_H_INCLUDED
int disassemble(unsigned char* codebuffer, int pc);
#endif
