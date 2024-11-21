

//handle degli inserimenti

#include <stdio.h>
int main() {
    char s; int i = 1, k = 1;
    while(1){
        do{
            scanf("%c", &s);
            if(s == 'd'){
                if(i <= 9){
                    i += 1;
                    printf("aumentato %d\n", i);
                }
            }
            if(s == 'a'){
                if(i >= 1){
                    i -= 1;
                    printf("diminuito %d\n", i);
                }
            }
            if(s == 'w'){
                if(k >= 1){
                    k-=1;
                    printf("diminuito %d\n", k);
                }
            }
            if(s == 's'){
                if(k <= 9){
                    k += 1;
                    printf("aumentato %d\n", k);
                }
            }
        }while(s != 9);
        if(s == 9)
            break;
        
    }
    
}
