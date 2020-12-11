#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; //metto NULL a lista in modo che punti al nulla

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) //controllo che la lista punti a NULL e non abbia valori
            {
                //alloco dinamicamente lista e poi lo assegno a l

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }else{  
                // se la lista non punta a NULL ovvero punta a qualcosa alloco a next per un nuovo valore e punto alla cella dopo
                l->next = (struct El *)malloc(sizeof(struct El));
                l = l->next;
            }
            l->valore = n;  //assegno al nuovo l il valore inserito da tastiera
            l->next = NULL; //porto il puntatore di l a NULL
        }
    } while (n >= 0);

    l = lista; //porto la struct l all'inzio della lista
    printf("numeri inseriti: ");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //vado all'elemento successivo
    }
    printf("\n");
    return 0;
}
