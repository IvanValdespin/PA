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

//Arg1: Archivo de datos

int main(int argc, char const *argv[]) 
{
    int weight, vector_lenght;
    int k = 0;
    float *a;
    float *b;

    //float a[N] = {5.1,3.3, 2.9, 1.7, 1.2, 1.0, 0.5};
    //float b[N];

    float temporal = 0.0;
    FILE *file_pointer;


    //Leer los datos ingresados
    file_pointer = fopen(argv[1],"r");
    //Leer archivo por fila
    fscanf(file_pointer, "%f", &weight); //Leer el primer elemento del archivo
    fscanf(file_pointer, "%d", &vector_lenght); //Leer tamaño del vector

    //Asignar memoria a los dos vectores
    a = (float*)malloc(vector_lenght * sizeof(float)); 
    b = (float*)malloc(vector_lenght * sizeof(float));


    for(i=0; i<vector_lenght;i++){
        fscanf(file_pointer, "%f", &a[i]);
        printf("%f\t", a[i]);
    }


    free(a);
    free(b);
    fclose(file_pointer);


    maximizaMochila(a,vector_lenght, weight, b, &k, &temporal);
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