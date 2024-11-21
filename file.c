#include <stdio.h>
#include <stdbool.h>
void inserimento(int lunghnav, char v[][10][3]){
     //variabili
     
     int k = 1, k1=1;          //riga, memoria di k (usata nel printf della griglia per rimuovere l'elemento alla precedente posizione)
     int j = 1, j1=1;          //colonna, memoria di j
     char ins;
     

        do{
          //posizione iniziale della nave
          if(k==1 && j==1){
               v[0][0][0] = '[';
               v[0][0][1] = 'x';
               v[0][0][2] = ']';
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
          
          
            scanf("%c", &ins);
            //muovi basso
            if(ins == 's'){
                if(k <= 9){
                    k1 = k;
                    j1 = j;
                    k += 1;    
                    
                }
            }
            //muovi alto
            if(ins == 'w'){
                if(k > 1){
                    k1 = k;
                    j1 = j;
                    k -= 1;
                    
                }
            }
            //muovi sx
            if(ins == 'a'){
                if(j > 1){
                    j1 = j;
                    k1 = k;
                    j-=1; 
                    
                }
            }
            //muovi dx
            if(ins == 'd'){
                if(j <= 9){
                    j1 = j;
                    k1 = k;
                    j += 1;
                    
                }
            }
            v[k-1][j-1][0] = '[';
            v[k-1][j-1][1] = 'x';
            v[k-1][j-1][2] = ']';
            v[k1-1][j1-1][0] = '[';
            v[k1-1][j1-1][1] = '-';
            v[k1-1][j1-1][2] = ']';
            
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
     inserimento(1, v);
     printf("Hello");
}

