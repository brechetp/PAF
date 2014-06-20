/*
 * main.h
 *
 *  Created on: 16 juin 2014
 *      Author: Pierre
 */


#ifndef MAIN_H_
#define MAIN_H_

// utils

// constante

#define WORD_SIZE 48
#define KEY_SIZE 96
#define M (KEY_SIZE/WORD_SIZE)
#define N_ROUNDS 28
#define CHAR_SIZE 8
#define ALPHA (WORD_SIZE == 16) ? 7 : 8
#define BETA (WORD_SIZE == 16) ? 2 : 3
//function

#define WORD_TYPE uint48_t // put the most adapted type for the current wordsize
#define u_int8_t unsigned short
#define u_int16_t unsigned short
#define uint24_t unsigned int
#define uint32_t unsigned int
#define uint48_t unsigned long
#define uint64_t unsigned long


#define MAX (WORD_SIZE == 48) ? 0xffffffffffff : 0xffffff


#define LCS rotl // left circular shift
#define RCS rotr // right circular shift
#define R(x,y,k) (x=  RCS(x,ALPHA), x= modulosum(x,y), x^=k, y=  LCS(y,BETA), y^=x)

	
#endif /* MAIN_H_ */
	
