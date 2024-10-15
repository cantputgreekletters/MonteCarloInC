#if !defined(__SIMULATION_H__)
#define __SIMULATION_H__
#include <stdlib.h>
float * Replicatef(float(*FUN)(), unsigned int n);
double MC_Simulationf(float(*Sim)(), unsigned int n);
double MC_Integralf(int min, int max, float(*FUN)(float), unsigned int n);
#endif // __SIMULATION_H__
