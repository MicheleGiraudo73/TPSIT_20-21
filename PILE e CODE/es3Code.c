#include <stdio.h>
#include <stdlib.h>

struct El{
    int val;
    struct El* next;
};

int is_empty(struct El *head){
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void enqueue(struct El** head, struct El** tail, struct El* element){
    
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;

    return;
}

struct El* dequeue(struct El** head, struct El** tail){
    
    struct El* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;

    return ret;
}

void push (struct El **head, struct El** tail, struct El *element){
    struct El* supportHead = NULL;
    struct El* supportTail = NULL;
    struct El* element2;

    while (!is_empty(*head)){
        element2 = dequeue(head,tail);
        enqueue(&supportHead, &supportTail, element2);
    }

    enqueue(head, tail, element);

    while (!is_empty(supportHead)){
        enqueue(head, tail, dequeue(&supportHead, &supportTail));
    }
}

struct El* pop(struct El **head){
    struct El* ret = *head;

    if (is_empty(*head))
    {
        return NULL;
    }else
    {
        *head = ret->next;
    }

    return ret;
}

void stampaCoda(struct El **head, struct El **tail){

    struct El* valore = (struct El*) malloc(sizeof(struct El));

    while (valore != NULL) {
        printf("%d\n",valore->val);
        valore = dequeue(head, tail);
    }
    free(valore);
}

void main(){
    struct El *head = NULL;
    struct El *tail = NULL;
    struct El* element = NULL;

    for (int i = 0; i < 10; i++)
    {
        element = (struct El*) malloc(sizeof(struct El));

        element->val = i;
        push(&head, &tail, element);
    }
    
    stampaCoda(&head, &tail);

}