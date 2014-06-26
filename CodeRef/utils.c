#include "main.h"
#include <x86intrin.h>

unsigned int rotl(unsigned int value, int shift) {
    return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}
 
unsigned int rotr(unsigned int value, int shift) {
    return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}

void KeyExpansion (KEY_TYPE K[], KEY_TYPE L[]){
       
       KEY_TYPE i;
       
       for(i=0; i<N_ROUNDS-1; i++){
       		L[i+1] = (K[i] + RCS(L[i], ALPHA)) ^ i;
       		K[i+1] = LCS(K[i], BETA) ^ L[i+1];
       	
       } 

}

void Encryption (WORD_TYPE pt[], WORD_TYPE ct[], KEY_TYPE K[]){
	
	int i ;
	
	ct[0] = pt[0];
	ct[1] = pt[1];
	
	for(i=0; i<N_ROUNDS; i++){
	
		R(ct[1], ct[0], K[i]);
	
	
	}
	
	



}


