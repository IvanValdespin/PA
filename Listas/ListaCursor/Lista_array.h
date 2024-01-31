#ifndef lista_array_h
#define lista_array_h

#include <stdio.h>
#include <string.h>

#define LENGHT_NAMES 150
#define LENGHT_DIRECCION 300
#define LL 1000

#define FULL_LIST -2
#define OUT_OF_RANGE -1
#define NOT_FOUND -3


//Definición de estructuras
typedef struct _persona
 {
    unsigned int clave;
    char nombre[LENGHT_NAMES];
    char direccion[LENGHT_DIRECCION];
} persona;

typedef struct _lista
 
{
    persona person[LL];
    int fin;
} lista;

//Instrucciones que puede realizar la lista
int insertar( persona person, int position, lista *list);
int localizar(persona person, lista *list);
persona recuperar(int position, lista *list);
int suprimir(int position, lista *list);
int siguiente(int position, lista *list);
int anterior(int position, lista *list);
int anular(lista *list);
int primer(lista *list);
void imprimir_lista(lista *list);

//API extendido

void inicializa(lista *list);
void readcsv(char *buffer, int i,unsigned int *clave, char *nombre, char *direccion);

#endif /*lista_array_h*/