

#include "ListaLigada.h"
#include <stdlib.h>
#include <string.h>
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

void inicializa(lista *l){
    l->len=0;
    l->primer=NULL;
}

int inserta(persona x, int p, lista *l){

    if(p>l->len){
        return FUERA_RANGO;
    }
    if(p==0){
      elemento *t=l->primer;
      l->primer=(elemento *)malloc(sizeof(elemento));
      l->primer->p=x;
      l->primer->next=t;
      l->len++;
      return 0;

    }
    elemento *last=l->primer;
    elemento *iterador=last->next;
    int i;
    for (int i = 1; i < p; i++)
    {
        last=iterador;
        iterador=last->next;
    }
    last->next=(elemento *)malloc(sizeof(elemento));
    last->next->p=x;
    last->next->next=iterador;
    l->len++;
    return p;

}

void anula(lista *l){
    elemento *tmp1,*tmp2;
    tmp1=l->primer;
    while(tmp1!=NULL){
        tmp2=tmp1->next;
        free(tmp1);
        tmp1=tmp2;
    }
    l->len=0;
}

void suprime(int p, lista *l){
    elemento *last;
    elemento *actual;
    last= l->primer;
    actual=last->next;
    if(p==0){
        l->primer=last->next;
        free(last);
    }

    else{

        for (int i = 1; i < p; i++){
            actual=actual->next;    
            last=last->next;
        }

        last->next=actual->next;
        l->len --;
        free(actual);
    }
}

void purga (lista *l){

    elemento *it1= l->primer;
    elemento *it2= it1->next;

    int a=0;
    int cont=0;

    while(it1->next!=NULL){
    
        cont=a+1;

        while(cont<l->len){

            if(it1->p.clave==it2->p.clave){
                suprime(cont,l);}
            cont++;
            it2=it2->next;

        }
        it1=it1->next;
        it2=it1->next;
        a++;  
    }
}

void imprime_lista(lista *l){
    int i;
    elemento *imprime=l->primer;
    while(imprime!=NULL){
           printf("%d %s\t%s\n", imprime->p.clave,
                              imprime->p.nombre,
              imprime->p.direccion);
        
        imprime=imprime->next;  
    }
}

int tamano(lista *l){
    return l->len;
}
