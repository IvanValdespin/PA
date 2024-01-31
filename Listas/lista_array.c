#include "Lista_array.h"


void inicializa(lista *list){
    list->fin = 0;
}

int insertar( persona person, int position, lista *list){
    
    if (position >list->fin || position < 0){
        return OUT_OF_RANGE;
    }
    if (list->fin == LL){
        return FULL_LIST;
    }
    
    if(position == list->fin){
        list->person[position] = person;
        list->fin++;
    } else {
        int i;
        i = list->fin;
        while (i > position){
            list->person[i] = list->person[i-1];
        }
        list->person[position] = person;
        list->fin++;
    }
    return 1;

}


int localizar(persona person, lista *list){
    int i = 0;
    while (i < list->fin){
        if (person.clave == list->person[i].clave){
            break;
        }
        i++;
    }

    return (i == list->fin)?NOT_FOUND:i; //Elemento trivaluado
}
persona recuperar(int position, lista *list){
    if(position > list->fin || position < 0){
        persona tmp;
        tmp.clave = 0;
        tmp.nombre[0] = tmp.direccion[0] = '\0'; //Se regresa una cadena vacia
    }
    return list->person[position];
}
int suprimir(int position, lista *list){

}
int siguiente(int position, lista *list){
    if (position == list->fin) return OUT_OF_RANGE;
    return ++position;
}
int anterior(int position, lista *list){
    if(position == 0) return OUT_OF_RANGE;
    return --position;
}
int anular(lista *list){
    list->fin = 0;
}

int primer(lista *list){
    return 0;
}
void imprimir_lista(lista *list){
    int i = 0;
    while (i< list->fin){
        printf("%4u %s\t%s\n",list->person[i].clave,
        list->person[i].nombre, list->person[i].direccion);
        i++;
    }

}

void readcsv(char *buffer, int i,unsigned int *clave, char *nombre, char *direccion){
	
	char delimitador[] = ",";
    	if(i>0){
    		char *tok = strtok(buffer,delimitador);
    		sscanf(tok,"%d",clave);
    		tok = strtok(NULL,delimitador);
    		sscanf(tok,"%[^\n]",nombre);
    		tok = strtok(NULL, delimitador);
    		sscanf(tok,"%[^\n]",direccion);

    	}
}