#ifndef Mochila_h
#define Mochila_h
#define W 13.5
#define N 7
#define MAX_PACK_WEIGHT "Capacidad de la mochila:"
#define NUMBER_OF_ELEMENTS "No. de elementos introducidos:"
#define ELEMENTS_WEIGHT "Peso de elementos introducidos:"
#define TOTAL_WEIGHT "Peso máximo introducido:"

#include <stdio.h>



void maximizaMochila(float a[], int n, float max, float b[], int *k,
    float *temporal);

#endif