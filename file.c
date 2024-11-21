#include <stdio.h>
#include <stdbool.h>
void inserimento(int lunghnav, char v[][10][3]){
     //variabili
     
     int k = 1;          //riga, memoria di k (usata nel printf della griglia per rimuovere l'elemento alla precedente posizione)
     int j = 1;          //colonna, memoria di j
     char ins;
     int rotazione = 1;        //rotazione nave. 1 = orizzontale, 0 = verticale
     int inizio = 1;

        do{
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
          
          
            scanf(" %c", &ins);
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
               
          for(int i = 0; i<10; i++){
               for(int n = 0; n<10; n++){
                    v[i][n][0] = '[';
                    v[i][n][1] = '-';
                    v[i][n][2] = ']';
               }
     }
            for(int n = 0; n<lunghnav; n++){
               v[k-1 + (1 - rotazione)*n][j-1 + (rotazione)*n][0] = '[';
               v[k-1 + (1 - rotazione)*n][j-1 + (rotazione)*n][1] = 'x';
               v[k-1+ (1 - rotazione)*n][j-1 + (rotazione)*n][2] = ']';
            }
            
        }while(ins != 'l');
        
        
    
         
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
     inserimento(5, v);

     printf("Hello");
}
