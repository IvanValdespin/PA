/*
    Se requiere generar un algoritmo que defina la carga máxima eficiente de elementos 
    dados y de pesos definidos que la mochila es capaz de cargar, sin sobrepasar su peso máximo.

    Los elementos deben de etar ordenados en orde descendente
*/


//Sección de encabezados
#include "Mochila.h"

#define W 8.6 //Peso de la mochila
#define N 7 //Número de objetos


void maximizaMochila(float a[], int n, float max, float b[], int *k,
    float *temporal){
    *temporal = 0.0;

    for (int i=0; i<n; i++){
        if((*temporal + a[i]) <= max){
            *temporal += a[i];
            b[*k] = a[i];
            (*k)++;
        }
    }

}

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

    printf("Peso Maximo %3.2f\n",W);

    
    printf("%3.2f\t%d\n", temporal, k);

    temporal = 0.0;

    for(int i=0;i<k;i++){
        printf("%3.2f ", b[i]);
        temporal += b[i];
    }
    printf("\n%3.2f\n", temporal);

    return 0;
}
