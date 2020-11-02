#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 30
#define DIM 10
#define LUNG_F 200

typedef struct canzone{
    int n;  //numero della canzone
    char canzone[LUNG]; //nome della canzone
    char autore[LUNG];  //nome dell'autore 
}Canzone;

//funzione che randomizza le canzoni
void canzoniRandom(Canzone ps[],int n){
    srand(time(NULL));
    int vetR[DIM];
    for(int k=0;k<n;k++){
        vetR[k]=rand()%n;
        for(int j=0;j<k;j++) {
       		if(vetR[k]==vetR[j]) { //if che controlla che se ci sono dei valori uguali e se sono uguali si decrementa 
            	   k--;
            	   break;
            }
        }
    }
    for(int k=0;k<n;k++){  //stampo le canzoni randomizzate
        printf("%d-%s -%s\n",ps[vetR[k]].n,ps[vetR[k]].canzone,ps[vetR[k]].autore);
    }
}

void main(){
    Canzone playlist[DIM];  //vettore di strutture
    FILE *fp;
    char nomeFileIn[]="canzoni.csv"; 
    char linea[LUNG_F];
    int k=0;
    fp=fopen(nomeFileIn,"r");
    if(fp == NULL){
        printf("non esiste il file\n");
    }else{
        //carico la struttura utilizzando fgets ovvero leggere una riga e poi spezzettarla per i vari campi
        while(fgets(linea,LUNG_F,fp)){
            playlist[k].n=atoi(strtok(linea,","));
            strcpy(playlist[k].canzone,strtok(NULL,","));
            strcpy(playlist[k].autore,strtok(NULL,"\n"));
            k++;
        }
        canzoniRandom(playlist,k);  
    }
}