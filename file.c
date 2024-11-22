#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>

bool controllo(int lunghnav, char v[][10][3], int k, int j, int rotazione){
    for(int i = 0; i > lunghnav; i++){
        return !(v[k-1+(1-rotazione)*i][j-1 + rotazione*i][1] == 'x');
    }
    return true;
}

void inserimento(int lunghnav, char v[][10][3]){
    //variabili
    
    int k = 1;          //riga, memoria di k (usata nel printf della griglia per rimuovere l'elemento alla precedente posizione)
    int j = 1;          //colonna, memoria di j
    int rotazione = 1;        //rotazione nave. 1 = orizzontale, 0 = verticale
    int inizio = 1;
    int rotazione1=1, k1=1, j1=1;     //memoria di rotazione, k, j
    char ins;
    do{
        printf("\033[H\033[J");
        //posizione iniziale della nave
        if(inizio){
            for(int o = 0; o < lunghnav; o++){
                v[0+o][0][0] = '[';
                v[0+o][0][1] = 'x';
                v[0+o][0][2] = ']';
        }
        inizio = 0;
    }
    
    
        //printf della matrice
        for(int i = 0; i<10; i++){
            for(int n = 0; n<10; n++){
                for(int m = 0; m<3; m++){
                        printf("%c", v[i][n][m]);
                }
            }
            printf("\n");
        }
        
        rotazione1 = rotazione;
        scanf(" %c", &ins);
        k1 = k;
        j1 = j;
        //muovi basso
        if(ins == 's'){
            if((k + (lunghnav -1) * (1 - rotazione)) <= 9){ 
                
                k += 1;    
                
            }
        }
        //muovi alto
        if(ins == 'w'){
            if(k > 1){
                k -= 1;
                
            }
        }
        //muovi sx
        if(ins == 'a'){
            if(j > 1){
                j-=1; 
                
            }
        }
        //muovi dx
        if(ins == 'd'){
            if((j + (lunghnav - 1) * rotazione) <= 9){
                j += 1;
                
            }
        }
        //ruota la nave
        if(ins == 'r'){
            if (rotazione){
                if(k + lunghnav - 1 <= 10) 
                rotazione = !rotazione;  
            }
            else{
                if(j + lunghnav - 1 <= 10)
                        rotazione = !rotazione;
            } 
                
            
        }
        
        for(int l = 0; l<lunghnav; l++){  
        v[k1-1 + (1-rotazione1)*l][j1-1 + (rotazione1)*l][0] = '[';
        v[k1-1 + (1-rotazione1)*l][j1-1 + (rotazione1)*l][1] = '-';
        v[k1-1 + (1-rotazione1)*l][j1-1 + (rotazione1)*l][2] = ']';
    }
        for(int n = 0; n<lunghnav; n++){
            v[k-1 + (1 - rotazione)*n][j-1 + (rotazione)*n][0] = '[';
            v[k-1 + (1 - rotazione)*n][j-1 + (rotazione)*n][1] = 'x';
            v[k-1+ (1 - rotazione)*n][j-1 + (rotazione)*n][2] = ']';
        }
        
    }while(ins != 'l');
    
    printf("\033[H\033[J");
    
}
    
        



void main(){
    char v[10][10][3];
    for(int i = 0; i<10; i++){
            for(int n = 0; n<10; n++){
                v[i][n][0] = '[';
                v[i][n][1] = '-';
                v[i][n][2] = ']';
            }
    }
    
    printf("\n");
    inserimento(1, v);
    inserimento(2, v);
    inserimento(3, v);
    inserimento(4, v);
    inserimento(5, v);

    

    printf("Hello");
}
