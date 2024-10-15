#if !defined(__ARRAY_HANDLING_H__)
#define __ARRAY_HANDLING_H__
void ArrayfPrint(float * array, int size);
double ArrayfSum(float * array, int size);
int ArrayfMaxidx(float * array, int size);
float * fxRunif(float min, float max, unsigned int n, float(*F)(float));
#endif // __ARRAY_HANDLING_H__
