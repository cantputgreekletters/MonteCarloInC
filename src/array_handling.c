#include <stdio.h>
#include "array_handling.h"
void ArrayfPrint(float * array, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%f",array[i]);
        if (i != size - 1)
        {
            printf(", ");
        }
        
    }
    puts("]");
}

double ArrayfSum(float * array, int size)
{
    double sum;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return(sum);
}

int ArrayfMaxidx(float * array, int size)
{
    int idx = 0;
    float max = array[idx];
    float current;
    for (int i = 1; i < size; i++)
    {
        current = array[i];
        if (max < current)
        {
            max = current;
            idx = i;
        }   
    }
    return idx;
}