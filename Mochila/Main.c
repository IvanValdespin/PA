/*
    Se requiere generar un algoritmo que defina la carga máxima eficiente de elementos 
    dados y de pesos definidos que la mochila es capaz de cargar, sin sobrepasar su peso máximo.

    Los elementos deben de etar ordenados en orde descendente
*/

#include "Mochila.h"

/*
 argc = numero de argumentos
 argv = vector a cadena de caracteres que contiene los elementos ingresados
*/

int main(int argc, char const *argv[]) 
{
    int k = 0;
    float a[N] = {5.1,3.3, 2.9, 1.7, 1.2, 1.0, 0.5};
    float b[N];
    float temporal = 0.0;

    maximizaMochila(a,N, W, b, &k, &temporal);
    temporal = 0.0;

    printf("%s\t %3.2f\n",MAX_PACK_WEIGHT, W);
    printf("%s\t%d\n", k);
    
    for(int i=0;i<k;i++){
        printf("%3.2f ", b[i]);
        temporal += b[i];
    }

    printf("\n%s\t%3.2f\n", TOTAL_WEIGHT, temporal);

    return 0;
}