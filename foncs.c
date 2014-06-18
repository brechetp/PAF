//#include <x86intrin.h>
#include <stdio.h>
#include "main.h"
#include "foncs.h"

void SpeckKeyExpansion(WORD_TYPE K[]){
        
        WORD_TYPE i;
        WORD_TYPE L[N_ROUNDS+M-2];
        
        //initialisation of L
        for(i=0; i < M-1; i++) 
                L[i] = K[i+1];
        
        
        
        
        //expansion loop
        for(i=0; i<N_ROUNDS-1; i++){

			    printf("%d eme itération : K[i] %lu RCS(L[i], ALPHA) %lu \n",i,sizeof(K[i]), sizeof((WORD_TYPE) RCS(L[i], ALPHA)));
				L[i+M-1]= (K[i]+ RCS(L[i], ALPHA)) ^ i;
                K[i+1] = ( LCS(K[i], BETA) ^ L[i+M-1]);
        
        }
        

}

void SpeckEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],WORD_TYPE K[]){

        WORD_TYPE i;
        //initalisation
	ct[0] = pt[0];
	ct[1] = pt[1];
	
	//N_ROUND of iteration of the round function on ct[1] and ct[0]
	for (i=0; i< N_ROUNDS ; i++){
		R(ct[1], ct[0], K[i]);
	}


}

void Speck128ExpandKeyAndEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],WORD_TYPE K[]){

	WORD_TYPE i;
	WORD_TYPE B=K[1],A=K[0];
        
	ct[0] = pt[0];
	ct[1] = pt[1];
        //Encryption and expansion in the case 128/128 and m=2
	for(i=0; i< N_ROUNDS; i++){
		R(ct[1],ct[0],A);
		R(B,A,i);
		// printf("ct0: %llx, ct1 : %llx, A : %llx, B : %llx \n", ct[0], ct[1], A, B);
	}
	
}

WORD_TYPE rotl(WORD_TYPE value, int shift){
	
	return (value << shift | value >> (sizeof(WORD_TYPE)*CHAR_SIZE-shift));

}

WORD_TYPE rotr(WORD_TYPE value, int shift){
	

	return (value >> shift | value << (sizeof(WORD_TYPE)*CHAR_SIZE-shift));

}




	
	

