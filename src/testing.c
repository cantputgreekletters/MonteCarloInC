#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"
#include "array_handling.h"
void randfTest(unsigned int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Random number in [2,5) = %f\n",randf(2,5));
    }
    puts("Finished");
}
void runifTest(int min, int max, unsigned int n)
{
    float * array = runif(min, max, n);
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%f, ",array[i]);
    }
    printf("]\n");
    free(array);
}

float __f(float x)
{
    return x + 2;
}
int __n__ = 0;
float __sim()
{
    __n__ ++;
    return(__f(__n__));
}
void ReplicateTest(unsigned int n)
{
    float * array = Replicatef(&__sim, n);
    ArrayfPrint(array, n);
}

void MCTest()
{
    double result = MC_Simulationf(&__sim, 1000);
    printf("result = %lf\n",result);
}

int main(void)
{
    MCTest();
    return(0);
}