#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>

float f(float x)
{
    return x * x + 1;
}
int main(void)
{
    float result = MC_Integralf(0,2,&f,1000);
    printf("Result = %f\n",result);
    return(0);
}