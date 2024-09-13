/*
	Arquivo: PilhaPan.h
	Autor: André Garrido Macedo
	Data: 16/04/24 07:37
	Descrição:conversao de notacao infixa para posfixa
*/

#include<stdio.h>
#include "Booleano.h"
#define MaxPilha 100
#define Sinal 0
#define fantasma -1

typedef struct {
	int topo;
    unsigned char Vetor[MaxPilha];
} Pilha;

Pilha criarPilha(); // cria a pilha vazia
Pilha construirPilha(int); // constroi pilha de 1 a n
void mostrarPilha(Pilha); // mostra a pilha
bool pilhaVazia(Pilha);
unsigned char acessarTopo(Pilha);
int obterTamanho(Pilha);
int contarPilha(Pilha , unsigned char); //conta quantos tem ate o valor dado
Pilha pushPilha(Pilha , unsigned char);
Pilha popPilha(Pilha);
Pilha inverter(Pilha , int); // inverter N itens na parte superior da pilha

//Implementacao

Pilha criarPilha(){
	Pilha p;
	p.topo = 0;
	return p;
}

Pilha construirPilha(int n){
	Pilha p;
	p.topo = n;
	for(int i = 1 ; i <= n ; i++){
		p.Vetor[i] = i;
	}
}

void mostrarPilha(Pilha p){
	int i;
	if(p.topo != 0){
	for(i = 1; i <= p.topo ; i++)
		printf("%d\n" , p.Vetor[i]);
	}
}

bool pilhaVazia(Pilha p){
	bool ok = false;
	if(p.topo == 0){
		ok = true;
	}
	return ok;
}

unsigned char acessarTopo(Pilha p){
	int topo = p.topo;
	unsigned char n;
	if(p.topo != 0)
		n = p.Vetor[topo];
	else 
		n = 0; //a confirmar
		
	return n;
}

int obterTamanho(Pilha p){
	int tamanho = p.topo;
	return tamanho;
}

int contarPilha(Pilha p , unsigned char n){ 
	//de cima para baixo 
	int i = 1;
	int j = p.topo;
	while(p.Vetor[j] != n){
		i++;
		j--;
	}
	return i;
		
}

Pilha pushPilha(Pilha p , unsigned char n){
	int tamanho = p.topo + 1;
	if(p.topo != MaxPilha){
		p.vetor[tamanho] = n;
		p.topo = tamanho;
	}
	return p;
}

Pilha popPilha(Pilha p){
	if(p.topo != 0){ 
		p.topo = p.topo - 1;
	}
	return p;
}

Pilha inverter(Pilha p, int n){
	unsigned char aux[n];
	int pos = p.topo;
	int cont = 1;
	int i;
	while(cont != n){
		pos--;
		cont++;
	}
	cont = 0;
	for(i = pos; i<= p.topo ; i++){
		aux[cont] = p.Vetor[i];
		cont++;
	}
	
	
	for(i = pos; i <= p.topo ; i++){
		p.Vetor[i] = aux[cont];
		cont--;
	}
	return p;
}

