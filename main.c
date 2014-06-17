/*
 * main.c
 *
 *  Created on: 16 juin 2014
 *      Author: Pierre
 */
 
#include <stdio.h>
#include "main.h"
#include "foncs.h"



int main (int argc,char *argv[]){
//64/128
/*Key:
1b1a1918 13121110 0b0a0908 03020100
Plaintext: 3b726574 7475432d
Ciphertext: 8c6fa548 454e028b*/

/*Speck 128/128
Key:
0f0e0d0c0b0a0908 0706050403020100
Plaintext: 6c61766975716520 7469206564616d20
Ciphertext: a65d985179783265 7860fedf5c570d18
*/
 
 
        printf("sizeof alpha %lu \n",sizeof(ALPHA));
        


        KEY_TYPE K[N_ROUNDS] ;
        WORD_TYPE pt[2]= /*{0x7469206564616d20,0x6c61766975716520};*/{0x7475432d, 0x3b726574};
        
        WORD_TYPE ct[2];
        WORD_TYPE solution[2] = {0x454e028b, 0x8c6fa548 };
 

        //K initialisation
        
        K[0] = /*0x0706050403020100; */0x03020100;
        K[1] = /*0x0f0e0d0c0b0a0908; */0x0b0a0908;
        K[2] = 0x13121110;
        K[3] = 0x1b1a1918;


     
        SpeckKeyExpansion(K);
        
        SpeckEncrypt(pt, ct, K);
        
        
        printf("Voici le texte chiffré %x et %x \n",ct[0],ct[1]);

        printf("Voici la bonne valeur %x et %x \n",solution[0],solution[1]);

	return 0;
}





