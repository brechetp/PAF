#ifndef FONCS_H_
#define FONCS_H_


void SpeckEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],WORD_TYPE K[]);

void SpeckKeyExpansion(WORD_TYPE K[]);

void Speck128ExpandKeyAndEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],WORD_TYPE K[]);

WORD_TYPE rotr(WORD_TYPE value, int shift);

WORD_TYPE rotl(WORD_TYPE value, int shift);

WORD_TYPE RCS(WORD_TYPE value, int shift);

WORD_TYPE LCS(WORD_TYPE value, int shift);



#endif

