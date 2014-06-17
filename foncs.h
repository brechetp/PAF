#ifndef FONCS_H_
#define FONCS_H_


void SpeckEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],KEY_TYPE K[]);

void SpeckKeyExpansion(KEY_TYPE K[]);

void Speck128ExpandKeyAndEncrypt(WORD_TYPE pt[],WORD_TYPE ct[],KEY_TYPE K[]);

WORD_TYPE RCS(WORD_TYPE value, int shift);

WORD_TYPE LCS(WORD_TYPE value, int shift);



#endif

