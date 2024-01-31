    
//
//Autor: Valdespin Garcia Ivan Giovanni
//	Lectura de un archivo CSV

#include <stdio.h>
#include <string.h>
#include "ListaLigada.h"


#define SB 600




int main(int argc, char **argv) {
    lista l;
    persona p;
    FILE *fp;
    int i;
    unsigned int clave;
    char buffer[SB];
	    
    fp=fopen(argv[1], "r");
    inicializa(&l);
    i=0;
    while ( fgets(buffer, SB, fp)!=NULL ) {
    	readcsv(buffer,i,&p.clave,p.nombre, p.direccion);
    	if (i>0){
    	inserta(p,(i-1), &l);}
    	i++; 
    }

    //Acciones de prueba 
    imprime_lista(&l);
    printf("\n");
    purga(&l);
    printf("\n");
    imprime_lista(&l);
    
    fclose(fp);
}
