#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/listaEncadeada.h"


int main(int argc, char **argv)
{
	no *n;
	lista *l;
	int *vet;
	int i,k;
	l = criaLista();
	vet = (int*)malloc(5 * sizeof(int));
	
	for(i = 0 ; i < 5 ; i++){
		vet[i] = i;
	}
	for(i = 0 ; i < 5 ; i++){
		printf("%d \n", vet[i]);
	}
	k = removerVetor(1,5,vet); /* removendo a posicao 1 do vetor*/
	printf("\n");
	for(i = 0 ; i < 4 ; i++){
		printf("%d \n", vet[i]);
	}
	printf("novo tamanho: %d\n",k);
	printf("\n **lista ** \n");
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	imprimeLista(l);
	printf("\n");
	
	liberaLista(l);
	return 0;
}

