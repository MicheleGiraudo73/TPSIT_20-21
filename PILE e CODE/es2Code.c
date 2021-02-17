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

void push(struct El **head, struct El *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct El* pop(struct El **head){
    struct El* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}
void stampaPila(struct El* l){
    while (!is_empty(l)){
        printf("%d",pop(&l)->val);
    } 
}

void stampaCoda(struct El **head, struct El **tail){

    struct El* valore = (struct El*) malloc(sizeof(struct El));
    valore = dequeue(head, tail);

    while (valore != NULL) {
        printf("%d\n",valore->val);
        valore = dequeue(head, tail);
    }
    free(valore);
}

void main(){
    struct El* tail = (struct El*) malloc(sizeof(struct El));    
    struct El* head = (struct El*) malloc(sizeof(struct El));
    struct El* stack = NULL;
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
    
    free(element);
    while(!is_empty(head)){
        
        element = dequeue(&head,&tail);
        push(&stack,element);
        
    }
    stampaPila(stack);
    printf("\n");
    free(element);
    while(!is_empty(stack)){
        
        element = pop(&stack);
        enqueue(&head,&tail,element);
        
    }
    stampaCoda(&head,&tail);
}