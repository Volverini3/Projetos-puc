/*
	Lista alocacao sequencial
	Autor: André Garrido Macedo
	data: 19/03/24 07:21
	Descrição:
*/

#include<stdio.h>
#include<time.h>

#define Max 1001
#define Fantasma 63

typedef struct{
	int tam; // tamanho da lista
	char vetor[Max];
} Lista ;

Lista criarLista();
int obterTamanho(Lista);
void mostrarLista(Lista);
char obterElemento(Lista , int);
Lista inserir(Lista , char);
Lista gerarTeste(Lista , int);

int main(){
	Lista B;
	B = criarLista();
	int x;
	x = obterTamanho(B);
	printf("tamanho = %d\n" , x);
	mostrarLista(B); 
	
	B = inserir(B , 'a');
	B = inserir(B , 's');
	B = inserir(B , 'p');
	B = inserir(B , 'a');
	B = inserir(B , 's');
	
	x = obterTamanho(B);
	printf("tamanho = %d\n" , x);
	
	mostrarLista(B);
	char f = obterElemento(B , 6);
	printf("\nna pos 6 = %c\n" , f);
	
	Lista C;
	C = criarLista(C);
	C = gerarTeste(C , 10);
	mostrarLista(C);
	
	char el; 
	for(int i = 1 ; i <= C.tam; i++){
		el = obterElemento(C , i);
		printf("\n elemento %d = %c", i , el);
	}
	printf("\ntamanho = %d\n" , obterTamanho(C));
	
	printf("\n fim \n");
	return 0;
}

Lista criarLista(){
	Lista A;
	A.tam = 0;
	return A;
}

int obterTamanho(Lista A){
	int t = A.tam ;
	return t ; 
}

void mostrarLista(Lista A){

	if(A.tam > 0){
		for(int i = 1 ; i <= A.tam ; i++){
			printf("%c" , A.vetor[i]);
		}
	}
	else{
		printf("lista vazia\n");
	}
}
char obterElemento(Lista A , int x){
	char i;
	if((x <= A.tam)&&(x > 0)){
		i = A.vetor[x];
	}
	else{
		i = Fantasma;
	}
	return i;
} 

Lista inserir(Lista A , char i){
	int x = A.tam + 1 ; 
	A.vetor[x] = i;
	A.tam = x; 
	return A;
}

Lista gerarTeste(Lista A, int tm){
	srand((int)time(NULL));
	int rd;
	for(int i = 1; i <= tm ; i++){
		rd = (rand() % 25) + 65;
		A.vetor[i] = rd;
		A.tam++;
	}
	return A;
}













