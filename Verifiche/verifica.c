/*
Author: Michele Giraudo
Verifica TPSIT
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 100
#define SIZE 1000

typedef struct drone{
    int tempo;
    float lat;
    float longitudine;
}Drone;

typedef struct anomalie{
    int tempo;
    char errore[LUNG];
}Anomalie;

//questa funzione tramite due for va ad individuare i campi tempo uguali delle due strutture
void latLongAno(Drone *d, Anomalie *a,int k,int i){
    //scorro la prima struttura e poi la seconda se individuo due campi tempo uguali stampo
    for(int j=1; j<i; j++){
        for(int l=1; l < k; l++){
            if((a+j)->tempo == (d+l)->tempo){
                printf("%d %.3f %.3f %s \n",(d+l)->tempo,(d+l)->lat,(d+l)->longitudine,(a+j)->errore); //stampo il tempo lat e lon e l'errore quando c'è stata un'anaomalia
            }
        }

    }
}


void main(){
    FILE *fV;  //puntatore al file Volo_drone
    FILE *fVA; //puntatore al file Anomalie;
    Drone *voli;  //vettore di strutture
    Anomalie *anomalia; //vettore di strutture
    char *linea; //buffer per contenere la prima riga dei file
    char voloDrone[]="Volo_drone.csv";
    char anoDrone[]="Anomalie_drone.csv";
    linea = malloc(SIZE * sizeof(char)); //allocazione dinamica a linea
    int k=0,i=0;
    fV = fopen(voloDrone,"r");
    fVA = fopen(anoDrone,"r");
    if(fV == NULL && fVA == NULL){  //controllo se i file esistono
        printf("non esistono");
    }else{
        
        while(fgets(linea,SIZE,fV)){  //conteggio righe primo file
            k++;
        }
        
        fclose(fV);
        voli = malloc(k * sizeof(Drone)); //allocazione dinamica per il primo vettore di strutture
        
        while(fgets(linea,SIZE,fVA)){  //conteggio righe secondo file
            i++;
        }
        fclose(fVA);
        anomalia = malloc(i * sizeof(Anomalie)); //allocazione dinamica per il secondo vettore di strutture
        fV = fopen(voloDrone,"r");
        fVA = fopen(anoDrone,"r");
        i=0;
        k=0;
        //caricamento delle due strutture utilizzando strtok 
        while(fgets(linea,SIZE,fV)){
            (voli+k)->tempo = atoi(strtok(linea,","));
            (voli+k)->lat = atof(strtok(NULL,",")); //metto NULL in modo da spezzettare il la riga presa da fgets
            (voli+k)->longitudine = atof(strtok(NULL,"\n"));
            k++;
            
        }
        while(fgets(linea,SIZE,fVA)){
            (anomalia+i)->tempo = atoi(strtok(linea,","));
            strcpy((anomalia+i)->errore, strtok(NULL,"\n"));
            i++;
        }
        latLongAno(voli,anomalia,k,i);
    }
}