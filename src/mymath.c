#include "mymath.h"
#include <stdlib.h>
#include "array_handling.h"
float randf(int min, int max)
{
    return  min + (float)rand() / (float)RAND_MAX * (max - min);
}
float* runif(float min, float max, int n)
{
    float * array;
    array = (float *)malloc(sizeof(float) * n);
    if(array == NULL)
    {
        //Memory allocation failed
        exit(1);
    }
    for(int i = 0; i < n; i ++)
    {
        array[i] = randf(min, max);
    }
    return array;
}
float * fxRunif(float min, float max, unsigned int n, float(*F)(float))
{
    float * array;
    float * y;
    array = (float *)malloc(sizeof(float) * n);
    /*
    if(array == NULL)
    {
       exit(-1);
    }
    y = (float *)malloc(sizeof(float) * n);
    if(y == NULL)
    {
       exit(-1);
    }
    */
    y = runif(min, max, n);
    int max_y_idx = ArrayfMaxidx(y, n);
    float max_y = y[max_y_idx];
    free(y);
    y = runif(min, max_y, n);
    for (int i = 0; i < n; i++)
    {
        array[i] = (*F)(y[i]);
    }
    free(y);
    return(array);
}