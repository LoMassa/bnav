#include <stdio.h>
void crea_mat(int v[100]){      //inserimento primo utente e creazione della griglia (matrice)
  int colonna;
  int riga;
  char ins[3];
  int scelta;
  for(int i = 0; i<6; i++){
    do{
        printf("Inserimento: ");
        scanf("%s", ins);
    while( !( 'A' <= ins[0] <= 'J') || !(ins[1] == '1' && !(ins[2] == '0' || ins[2] == '\0' )) || !('1' <= ins[1] <= '9'));
        do{
          printf("Inserire 1 per mettere la nave in verticale, 2 per inserirla in orizzontale");
          scanf("%d", &scelta);
        }while(!(scelta == 1 || scelta == 2);
        if(scelta = 1);
        
          
        
    }
}
}
void main(){

}
