#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 30
#define LUNG_F 200

typedef struct canzone{
    int n;  //numero della canzone
    char canzone[LUNG]; //nome della canzone
    char autore[LUNG];  //nome dell'autore 
}Canzone;

//funzione che randomizza le canzoni
void canzoniRandom(Canzone* ps,int n){
    srand(time(NULL));
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
    for(int j=0;j<n;j++){  //stampo le canzoni randomizzate
        printf("%d- %s -%s\n",(ps+(*(vetR+j)))->n,(ps+(*(vetR+j)))->canzone,(ps+(*(vetR+j)))->autore);
    }
}

int nLinee(FILE *fp,char* linea){
    int k;
    while (fgets(linea,LUNG_F,fp)){
        k++;
    }
    fclose(fp);
    return k;
}

void main(){
    Canzone* playlist;  //vettore di strutture
    FILE *fp;
    char *linea;
    linea = malloc(LUNG_F * sizeof(char));
    char nomeFileIn[]="canzoni.csv"; 
    int k=0;
    fp=fopen(nomeFileIn,"r");
    if(fp == NULL){
        printf("non esiste il file\n");
    }else{
        k=nLinee(fp,linea);
        fp=fopen(nomeFileIn,"r");
        playlist = malloc(k * sizeof(Canzone));
        k=0;
        //carico la struttura utilizzando fgets ovvero leggere una riga e poi spezzettarla per i vari campi
        while(fgets(linea,LUNG_F,fp)){
            (playlist+k)->n = atoi(strtok(linea,","));
            strcpy((playlist+k)->canzone,strtok(NULL,","));
            strcpy((playlist+k)->autore,strtok(NULL,"\n"));
            k++;
        }
        canzoniRandom(playlist,k);  
    }
}
