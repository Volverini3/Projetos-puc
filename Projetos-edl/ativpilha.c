#include<stdio.h>
#include "booleano.h"
#define Max 101
#define ghost 63
#define sinal 0

typedef struct{
	int topo;
	unsigned char vetor[Max];
}Pilha;

Pilha criarPilha(Pilha *);
bool PilhaVazia(Pilha *);
unsigned char acessarPilha(Pilha *);
void pushPilha(Pilha * , unsigned char);
void popPilha(Pilha *);
void esvaziarPilha(Pilha *);

Pilha criarPilha(Pilha * p){
	p->topo = sinal;
	//printf("pilha criada");
	return * p;
}

bool PilhaVazia(Pilha * p){
	bool x = FALSE;
	if(p->topo == sinal){
		x = TRUE;
	}
	return x;
}

unsigned char acessarPilha(Pilha * p){
	unsigned char n = ghost;
	if(!PilhaVazia(p)){
		n = p->vetor[p->topo];
	}
	return n;
}

void pushPilha(Pilha * p , unsigned char n){
	p->vetor[p->topo] = n;
	p->topo = p->topo + 1;
}

void popPilha(Pilha * p){
	if(!PilhaVazia(p)){
		p->topo = p->topo - 1;
	}
}

void esvaziarPilha(Pilha * p){
	while(p->topo != 0){
		p->topo = p->topo - 1;
	}
}

int main(){
	int i;
	Pilha p;
	criarPilha(&p);
	printf("%d\n", acessarPilha(&p));
	
	
	pushPilha(&p , 4);
	pushPilha(&p , 5);
	
	printf("%d\n" , acessarPilha(&p));
	printf("topo = %d\n" , p.topo);
	printf("lista completa: \n");
	for(i = 0; i <= p.topo ; i++){
		printf("%d: %d\n" , i , p.vetor[i]);
	}
	popPilha(&p);
	
	printf("%d\n" , acessarPilha(&p));
	printf("topo = %d\n" , p.topo);
	printf("lista completa: \n");
	for(i = 0; i <= p.topo ; i++){
		printf("%d: %d\n" , i , p.vetor[i]);
	}
	popPilha(&p);
	printf("%d\n" , acessarPilha(&p));
	printf("topo = %d\n" , p.topo);
	printf("lista completa: \n");
	for(i = 0; i <= p.topo ; i++){
		printf("%d: %d\n" , i , p.vetor[i]);
	}
	popPilha(&p);
	printf("%d\n" , acessarPilha(&p));
	printf("topo = %d\n" , p.topo);
	printf("lista completa: \n");
	for(i = 0; i <= p.topo ; i++){
		printf("%d: %d\n" , i , p.vetor[i]);
	}
	
	
	
	
	
	
	
	return 0;
}