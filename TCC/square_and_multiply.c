#include <stdio.h>
#include <stdlib.h>

#define p 6399395417 //teste primos com 10 digitos
#define q 2196825613
#define n p*q
#define e (p-1) * (q-1)


/*ToDo:
        - geração de chaves
            -definição das chaves publicas e privadas (escolher valores primos)
        - criptografar mensagens
        - descriptografar
*/


char* encriptarMensagem(char);
char* decriptarMensagem(char);
int squareAndMultiply(int[] , int , char);

int main(){
    


    return 0;
}


int squareAndMultiply(int x[], int tamanho , char* mensagem){
    int c = 1;
    for(int i = tamanho; i >= 0 ; i--){
        c = ((c*c) % n); 
        if(x[i] == 1){
            c = ((c*mensagem[i]) % n);
        }
    }
    return c;
}