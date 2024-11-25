#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>
bool null_len(int v[][2]){
    if(v[0][0] == '\0' || v[0][1]== '\0')
        return true;
    return false;
}
bool controllo_rot(int lunghnav, int y, int x, int p2[][2], int lp2, int rotazione){
    if(lunghnav == 1)
        return true;
    
    bool controllo = false;

    if(!null_len(p2)){
        if(rotazione == 1){
            for(int k = 0; k < lp2; k++){
                if(p2[k][1] == x-1){
                    controllo = true;
                }
            }

            if(!controllo){
                return true;
            }
            else{
                if(y-1 < p2[0][0] && y+lunghnav-2 >= p2[0][0]){
                    return false;
            }
        }

        
        }
        else{
                
                if(x-1 <= p2[0][1] &&  x-1+lunghnav >= p2[0][1]){
                    controllo = true;
                }
                

                if(!controllo){
                    
                    return true;
                }
                else{
                    
                    if(y-2+lunghnav < p2[0][0])
                        return true;
                    for(int k = 0; k<=lp2; k++){
                        if(y-1 == p2[k][0])
                            return false;
                    }
                }
            }
    
}
return true;
}
bool controllo(int lunghnav, int y, int x, int rotazione, int p2[][2], int lp2, int movimento){
    if(lunghnav == 1)
        return true;

    
    bool controllo=false;
    
    if(!null_len(p2)){
        if(movimento==1){
            for(int i = 0; i<lunghnav; i++){
                for(int k = 0; k<lp2; k++){
                    if(p2[k][0] == y-2){
                        controllo = true;
                        
                    }
                }
            }
            if(!controllo)
                return true;
            else{
                for(int i = 0; i<lunghnav; i++){
                    for(int k = 0; k<lp2; k++){
                        if(p2[k][1] == x-1+i*(rotazione)){  
                            return false;
                            
                        }
                    }
                    
                }
            }
        }

        if(movimento == 2){
            for(int i = 0; i<lunghnav; i++){
                for(int k = 0; k<lp2; k++){
                    if(p2[k][0] == y+(i)*(1-rotazione)){
                        controllo = true;
                        
                    }
                }
            }
            if(!controllo)
                return true;
            else{
                for(int i = 0; i<lunghnav; i++){
                    for(int k = 0; k<lp2; k++){
                        if(p2[k][1] == x-1+i*(rotazione)){  
                            return false;
                            
                        }
                    }
                    
                }
            }
        }

        if(movimento == 3){
            for(int i = 0; i<lunghnav; i++){
                for(int k = 0; k<lp2; k++){
                    if(p2[k][1] == x+i*rotazione)
                        controllo = true;
                }
            }
            if(!controllo)
                return true;
            else{
                for(int i = 0; i<lunghnav; i++){
                    for(int k = 0; k<lp2; k++){
                        if(p2[k][0] == y-1+i*(1-rotazione))
                            return false;
                    }
                }
            }
        }

        if(movimento == 4){
            for(int i = 0; i<lunghnav; i++){
                for(int k = 0; k<lp2; k++){
                    if(p2[k][1] == x-2)
                        controllo = true;
                }
            }
            if(!controllo)
                return true;
            else{
                for(int i = 0; i<lunghnav; i++){
                    for(int k = 0; k<lp2; k++){
                        if(p2[k][0] == y-1+i*(1-rotazione))
                            return false;
                    }
                }
            }
        }




    
   
    
    
}
return true;
}
void inserimento(int lunghnav, char v[][11][3], int posizioni[][2], int p1[][2], int p2[][2], int p3[][2], int p4[][2], int lp1, int lp2, int lp3, int lp4){
    //variabili
    
    int y = 1;          //riga, memoria di y (usata nel printf della griglia per rimuovere l'elemento alla precedente posizione)
    int x = 1;          //colonna, memoria di x
    int rotazione = 0;        //rotazione nave. 1 = orizzontale, 0 = verticale
    bool inizio = true, mosso = true;
    int rotazione1=0, y1=1, x1=1;     //memoria di rotazione, y, x
    char ins;
    while(1){
        printf("\033[H\033[x");
        //posizione iniziale della nave
        if(inizio && mosso){
            for(int i = 0; i<lunghnav; i++){
                v[i][0][1] = 'x';
            }
        }

    
        //printf della matrice
        for(int i = 0; i<10; i++){
            for(int n = 0; n<11; n++){
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
            if((y + (lunghnav -1) * (1 - rotazione)) <= 9 && controllo(lunghnav, y, x, rotazione, p1, lp1, 2) && controllo(lunghnav, y, x, rotazione, p2, lp2, 2) && controllo(lunghnav, y, x, rotazione, p3, lp3, 2) && controllo(lunghnav, y, x, rotazione, p4, lp4, 2)){ 
                mosso = false;
                y += 1;    
                
            }
        }
        //muovi alto
        if(ins == 'w'){
            if(y > 1 && controllo(lunghnav, y, x, rotazione, p1, lp1, 1) && controllo(lunghnav, y, x, rotazione, p2, lp2, 1) && controllo(lunghnav, y, x, rotazione, p3, lp3, 1) && controllo(lunghnav, y, x, rotazione, p4, lp4, 1)){
                y -= 1;
                
            }
        }
        //muovi sx
        if(ins == 'a'){
            if(x > 2 && controllo(lunghnav, y, x, rotazione, p1, lp1, 4) && controllo(lunghnav, y, x, rotazione, p2, lp2, 4) && controllo(lunghnav, y, x, rotazione, p3, lp3, 4) && controllo(lunghnav, y, x, rotazione, p4, lp4, 4)){
                x-=1; 
                ;
            }
        }
        //muovi dx
        if(ins == 'd'){
            if((x + (lunghnav - 1) * rotazione) <= 10 && controllo(lunghnav, y, x, rotazione, p1, lp1, 3) && controllo(lunghnav, y, x, rotazione, p2, lp2, 3) && controllo(lunghnav, y, x, rotazione, p3, lp3, 3) && controllo(lunghnav, y, x, rotazione, p4, lp4, 3)){
                x += 1;
                inizio = false;
                
            }
        }
        //ruota la nave
        if(ins == 'r'){
            if (rotazione && !inizio){
                if(y + lunghnav - 1 <= 10 && controllo_rot(lunghnav, y, x, p1, lp1, 1) && controllo_rot(lunghnav, y, x, p2, lp2, 1) && controllo_rot(lunghnav, y, x, p3, lp3, 1) && controllo_rot(lunghnav, y, x, p4, lp4, 1)) 
                rotazione = !rotazione;  
            }
            else if(!inizio){
                if(x + lunghnav - 1 <= 11 && controllo_rot(lunghnav, y, x, p1, lp1, 0) && controllo_rot(lunghnav, y, x, p2, lp2, 0) && controllo_rot(lunghnav, y, x, p3, lp3, 0) && controllo_rot(lunghnav, y, x, p4, lp4, 0))
                        rotazione = !rotazione;
            } 
                
            
        }
        if(ins == 'l' && inizio == false){
            break;
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
        
    }
    for(int i = 0; i<lunghnav;i++){
        posizioni[i][0] = y-1 + (1 - rotazione)*i;
        posizioni[i][1] = x-1 + (rotazione)*i;
        printf("%d %d", posizioni[i][0], posizioni[i][1]);
        
    }
    printf("\033[H\033[x");
    
}
    
        



void main(){
    char v[10][11][3];
    int posizioni1[1][2];           //N.B = SALVA (y,x) E NON (x, y)
    int posizioni2[2][2];
    int posizioni3[3][2];
    int posizioni4[4][2];
    int posizioni5[5][2];
    int a, b;
    for(int i = 0; i<10; i++){
            for(int n = 0; n<11; n++){
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
