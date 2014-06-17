
#include <x86intrin.h>
#include <stdio.h>
#include "main.h"
#include "foncs.h"

void SpeckKeyExpansion(KEY_TYPE K[]){
        
        KEY_TYPE i;
        KEY_TYPE L[N_ROUNDS+M-2];
        
        //initialisation of L
        for(i=0; i < M-1; i++) 
                L[i] = K[i+1];
        
        
        
        
        //expansion loop
        for(i=0; i<N_ROUNDS-1; i++){
                printf("%d eme itération : K[i] %u RCS(L[i], ALPHA) %u \n",i,sizeof(K[i]), sizeof((WORD_TYPE) RCS(L[i], ALPHA)));
                L[i+M-1]= (K[i]+(WORD_TYPE) RCS(L[i], ALPHA)) ^ i;
                K[i+1] = ((WORD_TYPE) LCS(K[i], BETA) ^ L[i+M-1]);
        
        }
        

}

void SpeckEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],KEY_TYPE K[]){

        WORD_TYPE i;
        //initalisation
	ct[0] = pt[0];
	ct[1] = pt[1];
	
	//N_ROUND of iteration of the round function on ct[1] and ct[0]
	for (i=0; i< N_ROUNDS ; i++){
		R(ct[1], ct[0], K[i]);
	}


}

void Speck128ExpandKeyAndEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],KEY_TYPE K[]){

	WORD_TYPE i;
	KEY_TYPE B=K[1],A=K[0];
        
	ct[0] = pt[0];
	ct[1] = pt[1];
        //Encryption and expansion in the case 128/128 and m=2
	for(i=0; i< N_ROUNDS; i++){
		R(ct[1],ct[0],A);
		R(B,A,i);
		// printf("ct0: %llx, ct1 : %llx, A : %llx, B : %llx \n", ct[0], ct[1], A, B);
	}
	
}


	
	
