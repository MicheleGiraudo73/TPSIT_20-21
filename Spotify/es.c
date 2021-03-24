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

#define LUNG 30
#define LUNG_P 1000

typedef struct canzone{     //struttura canzone, suddivisoine file csv
    int numero;
    char titolo[LUNG];
    char artista[LUNG];
    struct canzone *next;
}Canzone;



void push(Canzone* p, int i,char* titolo,char* autore){
    Canzone *temp;
    temp = p;
    if(i!=1){    
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = (Canzone*) malloc(sizeof(Canzone));
        temp->next->numero= i;
        strcpy(temp->next->titolo, titolo);
        strcpy(temp->next->artista, autore);
        temp->next->next=NULL;
    }else{
        temp->numero=i;
        strcpy(temp->titolo,titolo);
        strcpy(temp->artista,autore);
    }
    
}

void main(){
    FILE *fp;
    Canzone *playlist;
    int k=0;
    int i;
    char* tit= malloc(LUNG_P * sizeof(char));
    char* aut= malloc(LUNG_P * sizeof(char));
    playlist = (Canzone*) malloc(sizeof(Canzone));
    if((fp=fopen("canzoni.csv","r"))==NULL){
        printf("Il file non esiste");
    }else{    
        char *linea = malloc(LUNG_P * sizeof(char));
        while (fgets(linea,LUNG_P,fp)){
            i=atoi(strtok(linea,","));
            strcpy(tit,strtok(NULL,","));
            strcpy(aut,strtok(NULL,"\n"));
            push(playlist,i,tit,aut); 
            k++;
        }
    }
    
}