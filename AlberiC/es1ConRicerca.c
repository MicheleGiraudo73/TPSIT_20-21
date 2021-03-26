#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//es che stampa le key degli alberi
//struttura del nodo
struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int key;
};
//funzione che inserisce i nodi nell'albero
void insert(struct tree_node** tree, struct tree_node* new){
    if(*tree==NULL){
        *tree = new;
        (*tree)->left=NULL;
        (*tree)->right=NULL;
    }else{
        if(new->key < (*tree)->key)
            insert(&(*tree)->left,new);
        else if(new->key > (*tree)->key){
            insert(&(*tree)->right,new);
        }else{
            printf("Chiave duplicata!\n");
        }
    }
}
//funzione che stampa l'albero, in questo caso stampa solo la key
void in_order_view(struct tree_node *tree){
    if(tree != NULL){
        in_order_view(tree->left);
        printf("Key: %d",tree->key);
        in_order_view(tree->right);

    }
}
//funzione che trova la chiave
struct tree_node *find_by_key(struct tree_node *tree, int key){
    if (tree == NULL){
        return NULL;
    }
    else if (key < tree->key){
        return find_by_key(tree->left, key);
    }
    else if (key > tree->key){
        return find_by_key(tree->right, key);
    }else{
        return tree;
    }
}
//funzione che fa il nodo
struct tree_node *nodo(int k){
    struct tree_node *n = (struct tree_node*)malloc(sizeof(struct tree_node));
    n->key = k;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    //struttura albero
    struct tree_node *tree;
    struct tree_node *a; //struttura d'appoggio per fare le foglie
    //chiave 
    int k;
    char n;

    printf("Inserire la chiave root: ");
    fflush(stdin);
    scanf("%d",&k);

    tree = nodo(k);
    k=0;
    //do while che inserisce chiavi
    do{
        printf("inserire chiave nodo: ");
        fflush(stdin);
        scanf("%d",&k);
        a = nodo(k);
        insert(&tree,a);
        printf("ancora? ");
        fflush(stdin);
        scanf("%c",&n);
    }while(n!= 'n');
    //cerco la key
    printf("\n Inserire la chiave del nodo da cercare: ");
    fflush(stdin);
    scanf("%d", &k);
    a = find_by_key(tree, k);
    printf("\n trovato: %d\n", a->key);

    in_order_view(tree);

    //stampa l'albero
    in_order_view(tree);
    return 0;
}
