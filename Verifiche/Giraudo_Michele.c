//Verifica di Michele Giraudo 4^arob


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Carta{
    char seme;
    int val;
    struct Carta* next;
}Carta;

int is_empty(struct Carta *head){
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void push(struct Carta **head, struct Carta* element){
    if(&head == NULL){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct Carta* pop(struct Carta **head){
    struct Carta* ret = *head;
    if(&head == NULL){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}
void stampaLista(struct Carta* l){ 
    if(l!=NULL){ 
           
        printf("%c %d\n",l->seme,l->val);    
        l=l->next; 
        stampaLista(l); 
    }
    return;
}

int main(){
    int i=0;
    //i semi
    char s[4]={'C','P','D','F'};
    //le tre pile
    struct Carta* head = (struct Carta*) malloc(sizeof(struct Carta));
    struct Carta* Alice = (struct Carta*) malloc(sizeof(struct Carta));
    struct Carta* Bob = (struct Carta*) malloc(sizeof(struct Carta));
    struct Carta* element=NULL; 
    for(int k=0;k<4;k++){  //for che carica la pila delle carte
        for(int j=1;j<14;j++){
            element = (struct Carta*) malloc(sizeof(struct Carta));
            element->seme = s[k];
            element->val = j;
            push(&head,element);
        }
    }
    //stampaLista(head);
    //scorre la pila e con un numero random decido se dare la carta a alice o bob tramite un rand di un intero
    while(!is_empty(head)){
        
        i=1+rand()%100;
        if(i%2==0){
            push(&Alice,pop(&head));
        }else{
            push(&Bob,pop(&head));
        }
    }
    
    stampaLista(Alice);
    
    
    return 0;
}