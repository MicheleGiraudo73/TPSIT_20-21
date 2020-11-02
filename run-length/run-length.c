/*
Author: Michele Giraudo
Es: run-lenght
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 100

void encoding(char s[]){  
    int n;
    n=strlen(s);
    for(int k=0;k<n;k++){   //ciclo che scorre i caratteri
        int cnt=1;          //variabile per sapere quanti caratteri inizializzata a 1
        while(s[k]==s[k+1]){ //while che controlla se la cella della stringa corrente e quella successiva sono uguali, se si si incrementa il contattore delle lettere e si incrementa il cnt per saltare al carattere successivo
            cnt++;
            k++;
        }
        printf("%d%c",cnt,s[k]);  //stampa del numero dei caratteri e il carattere
    }
}

void decoding(char s[]){ //funzione di decoding
    int n;
    for(int k=0;s[k] != '\0' ;k++){ //for che cicla fino alla fine della stringa
        if(s[k]>='0'&& s[k]<='9'){ //if che controlla se il carattere è compreso tra 0 e 9 (contati come caratteri)
            for(int j=1;j<s[k]-48;j++){ //for che stampa il carattere in base al numero preso 
                printf("%c",s[k+1]);
            }
        }else{
            printf("%c",s[k]);    //se c'è solo un carattere stampa quel carattere
        }
    }
}

void main(){
    int n;
    char s[LUNG];
    printf("inserire 1 per fare encoding o 2 per fare decoding: \n");
    scanf("%d",&n);
    printf("inserire la stringa: \n");
    if(n==1){
        scanf("%s",s);
        encoding(s);
    }else{
        scanf("%s",s);
        decoding(s);
    }
}
