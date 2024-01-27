//Sección de encabezados
#include "Mochila.h"


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