#include "simulation.h"
#include "array_handling.h"
#include "mymath.h"
// stdlib

float * Replicatef(float(*FUN)(), unsigned int n)
{
    float * array;
    array = (float * )malloc(sizeof(float) * n);
    for(int i = 0; i < n; i ++)
    {
        array[i] = (*FUN)();
    }
    return(array);
}

double MC_Simulationf(float(*Sim)(), unsigned int n)
{
    float * data;
    double sum;
    double result;
    data = Replicatef(Sim, n);
    sum = ArrayfSum(data, n);
    result = sum / n;
    return(result);
}

double MC_Integralf(int min, int max, float(*FUN)(float), unsigned int n)
{
    float *x = runif(min, max, n);
    float * fx = fxRunif(min, max, n, FUN);
    float max_y = fx[ArrayfMaxidx(fx, n)];
    float * y = runif(min, max_y, n);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        counter += y[i] <= fx[i];
    }
    return counter * (max - min) * (max_y - min) / n;
}