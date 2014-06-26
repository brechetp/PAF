#include <x86intrin.h>
#include <stdio.h>

#define LCS _lrotl //left circular shift
#define u64 unsigned long long
#define f(x) ((LCS(x,1) & LCS(x,8)) ^ LCS(x,2))
#define R2(x,y,k1,k2) (y^=f(x), y^=k1, x^=f(y), x^=k2)


void Simon128Encrypt(u64 pt[], u64 ct[], u64 k[])
{
        u64 i;
        ct[0]=pt[0]; ct[1]=pt[1];
        printf("ct0 : %llx, ct1 : %llx, key : %llx \n", ct[0], ct[1], k);
        for(i=0; i<2; i+=2) {
        
                R2(ct[1], ct[0], k[i], k[i+1]);
                printf("ct0 : %llx, ct1 : %llx, key : %llx \n", ct[0], ct[1], k[i]);
        } 
}

