#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



struct El{
    int val;
    struct El* next;
};

int is_empty(struct El* head){
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(struct El **head, struct El **tail, struct El *element){

    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;    
}
struct El * dequeue(struct El **head, struct El **tail){
    struct El *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail = NULL;
    }
    return ret;
}

void main(){
    struct El* tail = (struct El*) malloc(sizeof(struct El));    
    struct El* head = (struct El*) malloc(sizeof(struct El));
    head = NULL;
    tail = NULL;
    struct El* element;
    char risposta;
    do{
        element = (struct El*) malloc(sizeof(struct El));
        printf("inserisci un numero: ");
        fflush(stdin);
        scanf("%d",&element->val);
        enqueue(&head,&tail,element);
        printf("vuoi ancora inserire y/n:");
        fflush(stdin);
        scanf("%c",&risposta);
    }while(risposta == 'y' || risposta=='Y');

    while (element!=NULL)
    {
        element = dequeue(&head,&tail);
        printf("%d",element->val);
        free(element);
    }
         
}