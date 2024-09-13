
/* Atividade Hashing - turma A
  Arquivo: < nome sobrenome>_Hash.c
  Autor: Pato Donald
  Date: 22/09/09 09:40
  Descrição: Exemplo de utilização de uma tabela Hash com tratamento 
            de colisões por encadeamento.
            Cada item tem uma chave = número inteiro positivo e 
			um valor = letra do alfabeto. 
*/

#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

# define M 11
# define fantasma '?'
# define hash(k , M)  k % M

typedef struct Celula{
        unsigned int cle;		// campo cle guarda a chave
        unsigned char letra;	// campo letra guarda o valor associado à chave
        struct Celula* next;
}Celula;

typedef Celula* TabelaH[M];   // Uma tabela desse tipo é um array de pointer para Celula

void criarHashTable(TabelaH);
void put(TabelaH, unsigned int, unsigned char);
unsigned char get(TabelaH, unsigned int);
void mostrarTabela(TabelaH);

int main (){
//	TESTE EM DESENVOLVIMENTO
	TabelaH A;
    unsigned char a;
    unsigned int k; 
    criarHashTable(A);
    printf("\n");  	mostrarTabela(A);printf("\n");        
	printf(" Insercao \n");
	k = 22;	printf("inserir chave = %d  letra A\n", k ); 	put(A,k, 'A'); 
	k = 33;  printf("inserir chave = %d  letra B\n", k ); 	put(A,k, 'B'); 
	k = 27;	printf("inserir chave = %d  letra C\n", k ); 	put(A,k, 'C'); 
	k = 67;	printf("inserir chave = %d  letra M \n", k ); 	put(A,k, 'M'); 
	printf("\n");  	mostrarTabela(A);printf("\n");    
	k = 22;	printf("inserir chave = %d  letra Y\n" , k ); 	put(A,k, 'Y'); 
	
	printf("\n");	mostrarTabela(A);	printf("\n");	
//    
//	printf("\n Busca \n");
//  k = 33; a = get(A,k);   
//	if (a == fantasma) printf("chave = %d   item inexistente \n",k);
//	else printf("chave = %d  letra = %c \n", k,a);
//   
//  k = 11; a = get(A,k);
//	if (a == fantasma) printf("chave = %d   item inexistente \n",k);
//	else printf("chave = %d  letra = %c \n", k,a);
//
//	k = 22;  a = get(A,k);
//	if (a == fantasma) printf("chave = %d   item inexistente \n",k);
//	else printf("chave = %d  letra = %c \n", k,a);
//
//	k = 67;  a = get(A,k);
//	if (a == fantasma) printf("chave = %d   item inexistente \n",k);
//	else printf("chave = %d  letra = %c \n", k,a);
//	
    printf("\n  FIM \n");
    return 0;
}

void criarHashTable(TabelaH dic){
    int i;
    for(i=0; i < M; i++) dic[i] = NULL;
}

void mostrarTabela(TabelaH dic){
	int i;
	Celula* p;
    for(i=0; i < M; i++) {
    	p = dic[i];
    	printf("\n %d - ",i);
    	if (p == NULL) printf(" lista vazia ");
		else{
			 	do {
					printf("  %d  %c  ", p->cle, p->letra);
					p = p->next;
				}while (p!=NULL);
			}
	}
	printf("\n");	
}


void put(TabelaH dic, unsigned int k, unsigned char ch){
	int hc = hash(k , M);
	Celula * c , *aux;
	if(dic[hc] == NULL){
		c = malloc(sizeof(Celula));
		c->cle = k;
		c->letra = ch;
		c->next = NULL;
		dic[hc] = c;
	}else{
		aux = dic[hc];
		while((aux != NULL)&&(aux->cle != k)){
			aux = aux->next;
		}
		if(aux == NULL){
			c = malloc(sizeof(Celula));
			c->cle = k;
			c->letra = ch;
			c->next = NULL;
			aux = c; 
		}
		else aux->letra = ch;
	}
	
}

unsigned char get(TabelaH dic, unsigned int k){
	// EM EXECUÇÃO
}
