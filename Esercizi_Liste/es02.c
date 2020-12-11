#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

void push(struct El* l,int v){
    struct El* t;
    t = l;
    while(t->next!=NULL){
        t = t->next;
    }
    t->next = (struct El *)malloc(sizeof(struct El));
    t->next->valore=v;
    t->next->next=NULL;
}

void stampaLista(struct El* l){
    struct El* t;
    t = l;
    while(t!=NULL){
        printf("%d - %p \n", t->valore, t->next);
        t = t->next; 
    }
}

void stampaLista2(struct El* l){
    if(l!=NULL){
        printf("%d \n",l->valore);
        l=l->next;
        stampaLista(l);
    }
}

int main()
{
    int n;
    struct El *lista;
    lista = NULL; 

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) 
            {
                

                lista = (struct El *)malloc(sizeof(struct El));

                
            }else{  
                
                push(lista,n);
            }
            
        }
    } while (n >= 0);

   
    printf("numeri inseriti: ");
    stampaLista2(lista);
    printf("\n");
    return 0;
}