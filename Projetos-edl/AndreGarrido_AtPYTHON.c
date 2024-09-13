/*
	Arquivo: AndreGarrido_AtPYTHON.c
	Autor: André Garrido Macedo e Rafael de Mello Turaça
	Data: 26/03/24 08:45
	Descrição: atividade 1. implementacao da funcao add do tipo set do python.
*/


#define Max 27

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
