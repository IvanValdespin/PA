//
//  lista_array.h
//

#ifndef lista_Ligada_h
#define lista_Ligada_h
#define LISTA_LLENA -2 
#define FUERA_RANGO -1 


#include <stdio.h>

#define LN 150
#define LD 300

typedef struct _persona{
    unsigned int clave;
    char nombre[LN];
    char direccion[LD];
}persona;

typedef struct _elemento{

    persona p;
    struct _elemento *next;
} elemento;

typedef struct _lista{
elemento *primer;
int len;

}lista;


void readcsv(char *buffer, int i,unsigned int *clave, char *nombre, char *direccion); //Leer archivo csv
void inicializa(lista *l); //Inicializar una lista ligada
int inserta(persona x, int p, lista *l); //Insertar elemento en lista ligada
void suprime(int p, lista *l); // Eliminar un elemento de la lista ligada
void anula(lista *l); // Anular lista ligada
void imprime_lista(lista *l); // Imprimir elementos de la lista ligada
void purga (lista *l); // Eliminar elementos repetidos dentro de la lista ligada


#endif

