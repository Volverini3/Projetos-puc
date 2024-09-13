/*
	Algoritmo Knuth
	Autor: André Garrido Macedo
	data: 05/03/24 08:51
	Descrição:
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	int a[36];
	a[0] = 0;
	int m = 35;
	int n = m;
	int rd, i , j ;
	
	char texto[50][50];
	
	int grupos[8][6];
	
	int cont = 0;
	srand((int)time(NULL));
	for(i = 1; i <= m; i++)
	{
		a[i] = i;
		printf("%d " , a[i]);
	}
	printf("\n\n");
	
	do
	{
		int aux = 0;
		rd = (rand() % n) + 1 ; 
		aux = a[n];
		a[n] = a[rd];
		a[rd] = aux;
		n--;
	}while(n != 1);
	
	for(i = 1; i <= m; i++)
	{
		printf("%6d " , a[i]);
		cont++;
		if(cont == 5)
		{
		
			cont = 0;
			printf("\n");
		}
	}
	printf("\n");
	
	j = 1;

	for(i = 1; i <= 5 ; i++){
		for(cont = 1; cont <= 7 ; cont++){
			grupos[i][cont] = a[j];
			j++;
		}
	}
	
	
	int x = 1;
	for(i = 1; i <= 5 ; i++){
		printf("grupo %d : " , x);
		x++;
		for(cont = 1 ; cont <= 7 ; cont++){
				printf("%6d", grupos[i][cont]);
			}
			printf("\n");
	}
	
	return 0;
}