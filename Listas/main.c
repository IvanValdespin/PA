/*Se agregan usuarios contenidos en un archivo csv
a una lista. Los usuarios reciben los atributos de clave, nombre y dirección*/

#include "Lista_array.h"

#define SB 600

int main(int argc, char const *argv[])
{
    lista l;
    persona p;
    FILE *fp;
    char buffer[SB];
    int counter = 0;

    inicializa(&l);
    fp = fopen(argv[1], "r"); //Recibir el archivo
          //Donde guardar, tamaño maximo, que leer
    while(fgets(buffer, SB, fp) != NULL){ //fgets regresa NULL cuando ya no pueda leer nada
        readcsv(buffer,counter,&p.clave,p.nombre, p.direccion);
        //No se agregan "&" en nombre y dirección devido a que un arreglo de caracteres ya es una referencia a dirección de memoria
        if(counter > 0){
            printf("%ls",&p.clave);    
            insertar(p,counter-1, &l);
        }
        counter++;
        
    }
    fclose(fp); //Cerrar archivo
    imprimir_lista(&l);
    printf("\n");


    return 0;
}
