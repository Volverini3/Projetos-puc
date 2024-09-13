#define Max 27
#include<stdio.h>

typedef struct{
	unsigned int card;
	unsigned char Set[Max];
} Conjunto;

//interface
Conjunto add(Conjunto, unsigned char);
Conjunto criar(Conjunto);
void mostrar(Conjunto);

int main(){
	printf("conjunto inicial: \n");
	Conjunto A = criar(A);
	mostrar(A);
	
	A = add(A, 3);
	
	printf("teste 1: \n");
	mostrar(A);
	
	
	A = add(A, 11);
	
	printf("teste 2: \n");
	mostrar(A);
}

//implementacao
Conjunto add(Conjunto A , unsigned char b){
	int i = 0;
	int x = A.Set[i];
	while((i < A.card)&&(x != b)){
		x = A.Set[i];
		i++;
	}
	
	if(x != b){
		A.Set[i] = b;
		A.card = A.card + 1;
	}
	return A;
}

Conjunto criar(Conjunto A){
	int i;
	for(i = 0; i < 8; i++){
		A.Set[i] = i;
	}
	A.card = i;
	return A;
}
void mostrar(Conjunto A){
	for(int i = 0; i < A.card ; i++){
		printf("Elemento %d:  %d  \n", i , A.Set[i]);
	}
	printf("tamanho: %d", A.card);
	printf("\n");
}