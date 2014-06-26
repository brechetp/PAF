#ifndef UTILS_H_
#define UTILS_H_


unsigned int rotr(unsigned int value, int shift);

unsigned int rotl(unsigned int value, int shift);

void KeyExpansion (KEY_TYPE K[], KEY_TYPE L[]);

void Encryption (WORD_TYPE pt[], WORD_TYPE ct[], KEY_TYPE K[]);

#endif
