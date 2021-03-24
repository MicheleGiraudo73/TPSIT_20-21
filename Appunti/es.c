#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

void stampaLista(Nodo* lista){
    //funzione ricorsiva
    if(lista == NULL ){
        printf("\n");
    }else{
        printf("%d\n",lista->valore);
        stampaLista(lista->next);
    }
}

int lunghezzaLista_iterativa(Nodo* lista){
    int cnt=0;
    while (lista != NULL){
        lista = lista->next;
        cnt++;
    }
    
}

int lunghezzaLista_ricorsiva(Nodo* lista){
    if(lista == NULL){
        return 0;
    }else{
        return 1 + lunghezzaLista_ricorsiva(lista->next); //1 + 1 + 1 + 0
    }
}

void deAlloca(Nodo* lista){
    if(lista!=NULL){
        deAlloca(lista->next);
        free(lista);
    }
}

int main(){

}
