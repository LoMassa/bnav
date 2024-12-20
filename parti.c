#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
bool null_len(int v[][2]){
    if(v[0][0] == '\0' || v[0][1]== '\0')
        return true;
    return false;
}
bool controllo(int lunghnav, char v[][10][3], int y, int x, int rotazione, int p1[][2], int lp1, int p2[][2], int lp2, int p3[][2], int lp3, int p4[][2], int lp4){
    if(lunghnav == 1)
        return true;

    
    
    for(int i = 0; i<lp1-1;i++) {
        for(int n = 0; n<lunghnav; n++){
                
                if(p1[i][0] == y-1 + (1 - rotazione)*n) //erorre
                    return false;
                if(p1[i][1] == x-1 + (rotazione)*n)     //errore
                    return false; 
            }
    }
    
    if(!null_len(p2)){
        for(int i = 0; i<lp2;i++) {
            for(int n = 0; n<lunghnav; n++){
                    
                    if(p2[i][0] == y-1 + (1 - rotazione)*n)
                        return false;
                    if(p2[i][1] == x-1 + (rotazione)*n)
                        return false; 
                }
        }
    }
    
    if(!null_len(p3)){
        for(int i = 0; i<lp3;i++) {
            for(int n = 0; n<lunghnav; n++){
                    
                    if(p3[i][0] == y-1 + (1 - rotazione)*n)
                        return false;
                    if(p3[i][1] == x-1 + (rotazione)*n)
                        return false; 
                }
        }
    }
    if(!null_len(p4)){
        for(int i = 0; i<lp4;i++) {
            for(int n = 0; n<lunghnav; n++){
                    
                    if(p4[i][0] == y-1 + (1 - rotazione)*n)
                        return false;
                    if(p4[i][1] == x-1 + (rotazione)*n)
                        return false; 
                }
        }
    }
    
    return true;
}
void inserimento(int lunghnav, char v[][10][3], int posizioni[][2], int p1[][2], int p2[][2], int p3[][2], int p4[][2], int lp1, int lp2, int lp3, int lp4){
    //variabili
    
    int y = 1;          //riga, memoria di y (usata nel printf della griglia per rimuovere l'elemento alla precedente posizione)
    int x = 1;          //colonna, memoria di x
    int rotazione = 1;        //rotazione nave. 1 = orizzontale, 0 = verticale
    int inizio = 1;
    int rotazione1=1, y1=1, x1=1;     //memoria di rotazione, y, x
    char ins;
    do{
        printf("\033[H\033[x");
        //posizione iniziale della nave
        
    
    
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
        y1 = y;
        x1 = x;
        //muovi basso
        if(ins == 's'){
            if((y + (lunghnav -1) * (1 - rotazione)) <= 9 && controllo(lunghnav, v, y, x, rotazione, p1, lp1, p2, lp2, p3, lp3, p4, lp4)){ 
                
                y += 1;    
                
            }
        }
        //muovi alto
        if(ins == 'w'){
            if(y > 1&& controllo(lunghnav, v, y, x, rotazione, p1, lp1, p2, lp2, p3, lp3, p4, lp4)){
                y -= 1;
                
            }
        }
        //muovi sx
        if(ins == 'a'){
            if(x > 1 && controllo(lunghnav, v, y, x, rotazione, p1, lp1, p2, lp2, p3, lp3, p4, lp4)){
                x-=1; 
                
            }
        }
        //muovi dx
        if(ins == 'd'){
            if((x + (lunghnav - 1) * rotazione) <= 9&& controllo(lunghnav, v, y, x, rotazione, p1, lp1, p2, lp2, p3, lp3, p4, lp4)){
                x += 1;
                
            }
        }
        //ruota la nave
        if(ins == 'r'){
            if (rotazione){
                if(y + lunghnav - 1 <= 10) 
                rotazione = !rotazione;  
            }
            else{
                if(x + lunghnav - 1 <= 10)
                        rotazione = !rotazione;
            } 
                
            
        }
        
        for(int l = 0; l<lunghnav; l++){  
        v[y1-1 + (1-rotazione1)*l][x1-1 + (rotazione1)*l][0] = '[';
        v[y1-1 + (1-rotazione1)*l][x1-1 + (rotazione1)*l][1] = '-';
        v[y1-1 + (1-rotazione1)*l][x1-1 + (rotazione1)*l][2] = ']';
    }
        for(int n = 0; n<lunghnav; n++){
            v[y-1 + (1 - rotazione)*n][x-1 + (rotazione)*n][0] = '[';
            v[y-1 + (1 - rotazione)*n][x-1 + (rotazione)*n][1] = 'x';
            v[y-1+ (1 - rotazione)*n][x-1 + (rotazione)*n][2] = ']';
        }
        
    }while(ins != 'l');
    for(int i = 0; i<lunghnav;i++){
        posizioni[i][0] = y-1 + (1 - rotazione)*i;
        posizioni[i][1] = x-1 + (rotazione)*i;
        
    }
    printf("\033[H\033[x");
    
}
    
        



void main(){
    char v[10][10][3];
    int posizioni1[1][2];           //N.B = SALVA (y,x) E NON (x, y)
    int posizioni2[2][2];
    int posizioni3[3][2];
    int posizioni4[4][2];
    int posizioni5[5][2];
    int a, b;
    for(int i = 0; i<10; i++){
            for(int n = 0; n<10; n++){
                v[i][n][0] = '[';
                v[i][n][1] = '-';
                v[i][n][2] = ']';
            }
    }
    
    printf("\n");
    inserimento(1, v, posizioni1, posizioni2, posizioni3, posizioni4, posizioni5, 2, 3, 4, 5);
    inserimento(2, v, posizioni2, posizioni1, posizioni3, posizioni4, posizioni5, 1, 3, 4, 5);
    inserimento(3, v, posizioni3, posizioni1, posizioni2, posizioni4, posizioni5, 1, 2, 4, 5);
    inserimento(4, v, posizioni4, posizioni1, posizioni2, posizioni3, posizioni5, 1, 2, 3, 5);
    inserimento(5, v, posizioni5, posizioni1, posizioni2, posizioni3, posizioni4, 1, 2, 3, 4);



    printf("Hello");
}
