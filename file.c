#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool null_len(int v[][2])
{
    if (v[0][0] == '\0' && v[0][1] == '\0')
        return true;
    return false;
}
bool controllo_rot(int lunghnav, int y, int x, int p2[][2], int lp2, int rotazione)
{
    if (lunghnav == 1)
        return true;

    bool controllo = false;

    if (!null_len(p2))
    {
        if (rotazione == 1)
        {
            for (int k = 0; k < lp2; k++)
            {
                if (p2[k][1] == x - 1)
                {
                    controllo = true;
                }
            }

            if (!controllo)
            {
                return true;
            }
            else
            {
                if (y - 1 < p2[0][0] && y + lunghnav - 2 >= p2[0][0])
                {
                    return false;
                }
            }
        }
        else
        {

            if (x - 1 <= p2[0][1] && x - 1 + lunghnav > p2[0][1])
            {
                controllo = true;
            }

            if (!controllo)
            {

                return true;
            }
            else
            {

                if (y - 2 + lunghnav < p2[0][0])
                    return true;
                for (int k = 0; k <= lp2; k++)
                {
                    if (y - 1 == p2[k][0])
                        return false;
                }
            }
        }
    }
    return true;
}
bool controllo(int lunghnav, int y, int x, int rotazione, int p2[][2], int lp2, int movimento)
{
    if (lunghnav == 1)
        return true;

    bool controllo = false;
    
    if (!null_len(p2))
    {
        if (movimento == 1)
        {
            for (int i = 0; i < lunghnav; i++)
            {
                for (int k = 0; k < lp2; k++)
                {
                    if (p2[k][0] == y - 2)
                    {
                        controllo = true;
                    }
                }
            }
            if (!controllo)
                return true;
            else
            {
                for (int i = 0; i < lunghnav; i++)
                {
                    for (int k = 0; k < lp2; k++)
                    {
                        if (p2[k][1] == x - 1 + i * (rotazione))
                        {
                            return false;
                        }
                    }
                }
            }
        }

        if (movimento == 2)
        {
            for (int i = 0; i < lunghnav; i++)
            {
                for (int k = 0; k < lp2; k++)
                {
                    if (p2[k][0] == y + (i) * (1 - rotazione))
                    {
                        controllo = true;
                    }
                }
            }
            if (!controllo)
                return true;
            else
            {
                for (int i = 0; i < lunghnav; i++)
                {
                    for (int k = 0; k < lp2; k++)
                    {
                        if (p2[k][1] == x - 1 + i * (rotazione))
                        {
                            printf("False, p2[%d][0] = %d, p2[%d][1]: %d", k, p2[k][0], k, p2[k][0]);
                            return false;
                        }
                    }
                }
            }
        }

        if (movimento == 3)
        {
            for (int i = 0; i < lunghnav; i++)
            {
                for (int k = 0; k < lp2; k++)
                {
                    if (p2[k][1] == x + i * rotazione)
                        controllo = true;
                }
            }
            if (!controllo){
                return true;
            }
            else
            {
                for (int i = 0; i < lunghnav; i++)
                {
                    for (int k = 0; k < lp2; k++)
                    {
                        if (p2[k][0] == y - 1 + i * (1 - rotazione))
                            return false;
                    }
                }
            }
        }

        if (movimento == 4)
        {
            for (int i = 0; i < lunghnav; i++)
            {
                for (int k = 0; k < lp2; k++)
                {
                    if (p2[k][1] == x - 2)
                        controllo = true;
                }
            }
            if (!controllo){
                return true;
            }
                
            else
            {
                for (int i = 0; i < lunghnav; i++)
                {
                    for (int k = 0; k < lp2; k++)
                    {
                        if (p2[k][0] == y - 1 + i * (1 - rotazione))
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

        //printf numeri delle colonne
        printf("%c%c%c%c", 32, 32, 32, 32);
        for(int i = 0; i<10; i++){
            printf("%c  ", 48+i);
        }
        printf("\n");
        //printf della matrice
        for(int i = 0; i<10; i++){
            printf("%c", 65+i);
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
            if(inizio){
                if(y + lunghnav - 1 <= 9)
                    y+=1;
                    mosso = false;
            }
            else if((y + (lunghnav -1) * (1 - rotazione)) <= 9 && controllo(lunghnav, y, x, rotazione, p1, lp1, 2) && controllo(lunghnav, y, x, rotazione, p2, lp2, 2) && controllo(lunghnav, y, x, rotazione, p3, lp3, 2) && controllo(lunghnav, y, x, rotazione, p4, lp4, 2)){ 
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
            if((x + (lunghnav - 1) * rotazione) <= 10 && controllo(lunghnav, y, x, rotazione, p1, lp1, 3) && controllo(lunghnav, y, x, rotazione, p2, lp2, 3)&& controllo(lunghnav, y, x, rotazione, p3, lp3, 3) && controllo(lunghnav, y, x, rotazione, p4, lp4, 3)){
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
        
        
    }
    printf("\033[H\033[x");
    
}
bool colpo_passivo(int p1[][2], int lp1, char x, char y){
    for(int i = 0; i < lp1; i++){
          if((int)x-65 == p1[i][0] && (int)y-47 == p1[i][1]){
               return true;
          }
     }
     return false;
}
bool controllocolpo(int p1[][2], int lp1, char x, char y){
     for(int i = 0; i < lp1; i++){
          if((int)x-65 == p1[i][0] && (int)y-47 == p1[i][1]){
                p1[i][1] = 15;
                p1[i][0] = 15;
               return true;
          }
     }
     return false;
}
bool controlla_affondato(int p[][2], int lp){
    if(null_len(p))
        return true;
    for(int i = 0; i<lp; i++){
        if(p[i][0] != 15){
            return false;
        }
    }

    return true;
}
 


bool spara(char matrice[][11][3], int p1[][2], int p2[][2], int p3[][2], int p4[][2], int p5[][2]){
        printf("%c%c%c%c", 32, 32, 32, 32);
        for(int i = 0; i<10; i++){
            printf("%c  ", 48+i);
        }
        printf("\n");
        for(int i = 0; i<10; i++){
            printf("%c", 65+i);
            for(int n = 0; n<11; n++){
                for(int m = 0; m<3; m++){
                    printf("%c", matrice[i][n][m]);
                }
            }
            printf("\n");
        }
        char spara_riga, spara_colonna;
        do{
            printf("\ninserisci la riga dove sparare: ");
            scanf(" %c", &spara_riga);
        }while(!('A' <= spara_riga <= 'J'));

        do{
            printf("\ninserisci la colonna dove sparare: ");
            scanf(" %c", &spara_colonna);
        }while(!('0' <= spara_colonna <= '9'));

        
        
        if(!(colpo_passivo(p1, 1, spara_riga, spara_colonna) || colpo_passivo(p2, 2, spara_riga, spara_colonna) || colpo_passivo(p3, 3, spara_riga, spara_colonna) || colpo_passivo(p4, 4, spara_riga, spara_colonna) || colpo_passivo(p5, 5, spara_riga, spara_colonna))){
            matrice[(int)spara_riga-65][(int)spara_colonna - 47][1] = '0';
            //printf("sr: %d, sc: %d", (int)spara_riga - 65, (int)spara_colonna - 48);
            printf("Mancato! \n");
        }
        else{
            matrice[spara_riga - 65][spara_colonna - 47][1] = 'X';
            if(controllocolpo(p1, 1, spara_riga, spara_colonna) && controlla_affondato(p1, 1)){
                printf("\aColpito e affondato!\a\n ");
            }
            if(colpo_passivo(p2, 2, spara_riga, spara_colonna) && controlla_affondato(p2, 2)){
                controllocolpo(p2, 2, spara_riga, spara_colonna);
                printf("\aColpito e affondato!\a\n ");
            }
            else if(controllocolpo(p2, 2, spara_riga, spara_colonna)){
                printf("\acolpito!\n ");
            }
            if(colpo_passivo(p3, 3, spara_riga, spara_colonna) && controlla_affondato(p3, 3)){
                printf("\aColpito e affondato!\a\n ");
                controllocolpo(p3, 3, spara_riga, spara_colonna);
            }
            else if(controllocolpo(p3, 3, spara_riga, spara_colonna)){
                printf("\acolpito!\n ");
            }
            if(colpo_passivo(p4, 4, spara_riga, spara_colonna) && controlla_affondato(p4, 4)){
                printf("\aColpito e affondato!\a\n ");
                controllocolpo(p4, 4, spara_riga, spara_colonna);
            }
            else if(controllocolpo(p4, 4, spara_riga, spara_colonna)){
                printf("\acolpito!\n ");
            }
            if(colpo_passivo(p5, 5, spara_riga, spara_colonna) && controlla_affondato(p5, 5)){
                printf("\aColpito e affondato!\a\n ");
                controllocolpo(p5, 5, spara_riga, spara_colonna);
            }
            
            else if(controllocolpo(p5, 5, spara_riga, spara_colonna)){
                printf("\acolpito!\n ");
            }
        }
        printf("\033[H\033[x");
        return(controlla_affondato(p1, 1) && controlla_affondato(p2, 2) && controlla_affondato(p3, 3) && controlla_affondato(p4, 4) && controlla_affondato(p5, 5));
        
        
     
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


    

    char v2[10][11][3];
    int posizioni1_2[1][2];           //N.B = SALVA (y,x) E NON (x, y)
    int posizioni2_2[2][2];
    int posizioni3_2[3][2];
    int posizioni4_2[4][2];
    int posizioni5_2[5][2];
    for(int i = 0; i<10; i++){
            for(int n = 0; n<11; n++){
                v2[i][n][0] = '[';
                v2[i][n][1] = '-';
                v2[i][n][2] = ']';
            }
    }
    
    printf("\n");
    inserimento(1, v2, posizioni1_2, posizioni2_2, posizioni3_2, posizioni4_2, posizioni5_2, 2, 3, 4, 5);
    inserimento(2, v2, posizioni2_2, posizioni1_2, posizioni3_2, posizioni4_2, posizioni5_2, 1, 3, 4, 5);
    inserimento(3, v2, posizioni3_2, posizioni1_2, posizioni2_2, posizioni4_2, posizioni5_2, 1, 2, 4, 5);
    inserimento(4, v2, posizioni4_2, posizioni1_2, posizioni2_2, posizioni3_2, posizioni5_2, 1, 2, 3, 5);
    inserimento(5, v2, posizioni5_2, posizioni1_2, posizioni2_2, posizioni3_2, posizioni4_2, 1, 2, 3, 4);

    //forza sleep
    for(int i = 0; i<pow(2, 18); i++){
        //pass
    }
    printf("\033[H\033[x");

     //sparo
     char m[10][11][3], m2[10][11][3];
     bool vt1 = false, vt2 = false;
     for(int i = 0; i<10; i++){
            for(int n = 0; n<11; n++){
                m[i][n][0] = '[';
                m[i][n][1] = '-';
                m[i][n][2] = ']';
            }
    }
    for(int i = 0; i<10; i++){
            for(int n = 0; n<11; n++){
                m2[i][n][0] = '[';
                m2[i][n][1] = '-';
                m2[i][n][2] = ']';
            }
    }
    while(!vt1 && !vt2){
        vt1 = spara(m, posizioni1_2, posizioni2_2, posizioni3_2, posizioni4_2, posizioni5_2);
        if(!vt1)
            vt2 = spara(m2, posizioni1, posizioni2, posizioni3, posizioni4, posizioni5);
    }
    
    if(vt1){
        printf("\033[H\033[x");
        printf("Giocatore 1 ha vinto!");
    }
    else{
        printf("\033[H\033[x");
        printf("Giocatore 2 ha vinto");
    }
    
}
