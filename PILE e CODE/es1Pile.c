#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int n;
    struct nodo* next;    
}Nodo;

void push(Nodo **head, Nodo *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

int main(){
    Nodo* head;
    Nodo* element;
    char numeri[200];

    printf("inserisci numeri interi, max 200: ");
    scanf("%s", numeri);

    for(int k=0; k < strlen(numeri); k++){
        element = (Nodo*) malloc(sizeof(Nodo));
        element->n = numeri[k] - 48;
        push(&head, element);
    }
    Nodo* appoggio;
    appoggio = pop(head);
    while(appoggio != NULL){
        printf("%d",appoggio->n);
        free(appoggio);
    }

    return 0;
}