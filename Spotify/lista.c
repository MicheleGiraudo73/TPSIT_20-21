#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

 /*
        Canzone *temp= playlist;
        while(fgets(linea,LUNG_P,fp)){
            temp->numero = atoi(strtok(linea,","));
            strcpy(temp->titolo,strtok(NULL,","));
            strcpy(temp->artista,strtok(NULL,","));
            temp->next = (Canzone*) malloc(sizeof(Canzone));
            temp = temp->next;
            k++;
            free(linea);
            linea = malloc(LUNG_P * sizeof(char));
        }
        free(temp);
    }
    */
    /*for(int j=0;j<k;j++){
            printf("%d %s %s \n",playlist->numero,playlist->titolo,playlist->artista);
            playlist=playlist->next;
        }*/


#define LUNG 60
#define LUNG_P 1000

typedef struct canzone{     //struttura canzone, suddivisoine file csv
    int numero;
    char titolo[LUNG];
    char artista[LUNG];
    struct canzone *next;
}Canzone;

void canzoniRandom(Canzone* ps,int n){
    srand(time(NULL));
    Canzone* temp;
    int* vetR;
    vetR = malloc(10 * sizeof(int));
    for(int k=0; k < 10; k++){
        *(vetR+k)=rand()%n;
        for(int j=0;j < k; j++){
            if(*(vetR+k) == *(vetR+j)){
                k--;
                break;
            }
        }
    }
    int k;
    for(int i=0; i<n;i++){
        temp = ps;
        k=0;
        while(k < *(vetR+i)+1){
            if(k+1==*(vetR+i)+1){
                printf("%d %s %s \n",temp->numero,temp->titolo,temp->artista);
            }
            temp = temp->next;
            k++;
        }
    }
}

void push(Canzone* p,int i,char* nome,char* autore){
    Canzone* temp;
    temp = p;
    if(i != 1){
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = malloc(sizeof(Canzone));
        temp->next->numero = i;
        strcpy(temp->next->titolo,nome);
        strcpy(temp->next->artista,autore);
        temp->next->next = NULL;
    }else{
        temp->numero=i;
        strcpy(temp->titolo,nome);
        strcpy(temp->artista,autore);
    }
} 


void main(){
    FILE *fp;
    Canzone *playlist;
    int k=0;

    int i;
    char* t=malloc(LUNG_P * sizeof(char));
    char* a=malloc(LUNG_P * sizeof(char));

    playlist = malloc(sizeof(Canzone));
    char *linea = malloc(LUNG_P * sizeof(char));
    fp=fopen("canz.csv","r");

    if(fp==NULL){
        printf("Il file non esiste");
    }else{    
        while(fgets(linea,LUNG_P,fp)){
            i = atoi(strtok(linea,","));
            strcpy(t,strtok(NULL,","));
            strcpy(a,strtok(NULL,"\n"));
            push(playlist,i,t,a);
            k++;
        }
        canzoniRandom(playlist,k);
    }
       
}
    
  