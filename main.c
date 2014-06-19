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


        WORD_TYPE K[N_ROUNDS] ;
        WORD_TYPE pt[2]= /*{0x7469206564616d20,0x6c61766975716520};*/{0x7475432d, 0x3b726574};
        
        WORD_TYPE ct[2];
        WORD_TYPE solution[2] = {0x454e028b, 0x8c6fa548};
 

        //K initialisation
        
        K[0] = /*0x0706050403020100; */0x03020100;
        K[1] = /*0x0f0e0d0c0b0a0908; */ 0x0b0a0908;
        K[2] = 0x13121110 ;
        K[3] = 0x1b1a1918;


     
        SpeckKeyExpansion(K);
        
        SpeckEncrypt(pt, ct, K);
        
        
        printf("Voici le texte chiffré %x et %x \n",ct[0],ct[1]);

        printf("Voici la bonne valeur %x et %x \n",solution[0],solution[1]);

	return 0;
}

/*Speck 32/64
Key: 1918 1110 0908 0100 Plaintext: 6574 694c Ciphertext: a868 42f2

Speck 48/72
Key: 121110 0a0908 020100 Plaintext: 20796c 6c6172 Ciphertext: c049a5 385adc

Speck 48/96
Key: 1a1918 121110 0a0908 020100 Plaintext: 6d2073 696874
Ciphertext: 735e10 b6445d

Speck 64/96
Key: 13121110 0b0a0908 03020100 Plaintext: 74614620 736e6165 Ciphertext: 9f7952ec 4175946c

Speck 64/128
Key: 1b1a1918 13121110 0b0a0908 03020100 Plaintext: 3b726574 7475432d
Ciphertext: 8c6fa548 454e028b

Speck 96/96
Key: 0d0c0b0a0908 050403020100 Plaintext: 65776f68202c 656761737520 Ciphertext: 9e4d09ab7178 62bdde8f79aa

Speck 96/144
Key: 151413121110 0d0c0b0a0908 050403020100 Plaintext: 656d6974206e 69202c726576
Ciphertext: 2bf31072228a 7ae440252ee6

Speck 128/128
Key: 0f0e0d0c0b0a0908 0706050403020100 Plaintext: 6c61766975716520 7469206564616d20 Ciphertext: a65d985179783265 7860fedf5c570d18

Speck 128/192
Key: 1716151413121110 0f0e0d0c0b0a0908 0706050403020100 Plaintext: 7261482066656968 43206f7420746e65
Ciphertext: 1be4cf3a13135566 f9bc185de03c1886

Speck 128/256
Key: 1f1e1d1c1b1a1918 1716151413121110 0f0e0d0c0b0a0908 0706050403020100 Plaintext: 65736f6874206e49 202e72656e6f6f70
Ciphertext: 4109010405c0f53e 4eeeb48d9c188f43

*/





