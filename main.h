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
#define WORD_SIZE 32
#define KEY_SIZE 128
#define M (KEY_SIZE/WORD_SIZE)
#define N_ROUNDS 27
#define ALPHA (WORD_SIZE == 16) ? 7 : 8
#define BETA (WORD_SIZE == 16) ? 2 : 3
//functions
#define WORD_TYPE unsigned int // put the most adapted type for the current wordsize
#define KEY_TYPE unsigned int
#define LCS rotl // left circular shift
#define RCS rotr // right circular shift
#define R(x,y,k) (x= (WORD_TYPE) RCS(x,ALPHA), x+=y, x^=k, y= (WORD_TYPE) LCS(y,BETA), y^=x)




#endif /* MAIN_H_ */
