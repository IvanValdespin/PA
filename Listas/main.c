#include <stdio.h>
#include "Lista_array.h"

int main(int argc, char const *argv[])
{
    lista l;
    persona p;
    
    p.clave = 1;
    strcpy(p.nombre,"Ivan");
    strcpy(p.direccion,"Aqui");
    
    inicializa(&l);
    insertar(p,0,&l);

    p.clave = 2;
    strcpy(p.nombre,"Aaron");
    strcpy(p.direccion,"Alla");

    insertar(p,1,&l);

    imprimir_lista(&l);
    anular(&l);
    printf("Despues de anula \n");
    imprimir_lista(&l);

    return 0;
}
