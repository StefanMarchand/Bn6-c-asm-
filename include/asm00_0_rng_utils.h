#ifndef ASM00_0_RNG_UTILS_H
#define ASM00_0_RNG_UTILS_H

int GetPositiveSignedRNG(void);
int GetPositiveSignedRNGSecondary(void);
int SWI_Div(int numerator, int denominator);

unsigned int sub_8000C5C(unsigned int value);
void ShuffleByteList_PrimaryRNG(unsigned char *list, int length, int unused1, int unused2);
void ShuffleByteList_SecondaryRNG(unsigned char *list, int length, int unused1, int unused2);
void ShuffleHwordList_PrimaryRNG(unsigned short *list, int length, int unused1, int unused2);
void ShuffleHwordList_SecondaryRNG(unsigned short *list, int length, int unused1, int unused2);
unsigned char unused_8000D4A(unsigned char *list, int length);
void unused_8000D5E(unsigned char *list, int length);

#endif
