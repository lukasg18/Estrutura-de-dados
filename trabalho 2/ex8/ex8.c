#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/listaEncadeada.h"

int *contaZero(lista *l){
	int i,j, pini, pfim;
	int *vet;
	no *aux, *aux2;
	pini = i = pfim = 0;
	vet = malloc(2 * sizeof(int));
	aux = l -> ini;
	
	while(i < l -> tam){
		if(aux -> conteudo == 0){
			j = i;
			aux2 = aux;
			while((j < l -> tam) && (aux2 -> conteudo == 0)){
				j++;
				aux2 = aux2 -> prox;
				}
			pini = i;
			pfim = (j - 1);
		}
		i++;
		if((vet[1] - vet[0]) < (pfim - pini)){
			vet[0] = pini;
			vet[1] = pfim;
		}
		aux = aux -> prox;
		}
	
	return vet;
	}

int main(int argc, char **argv)
{
	lista *l;
	no *n;
	int *i;
	l = criaLista();
	
	n = criaNo(0);
	insereFim(l,n);
	n = criaNo(0);
	insereFim(l,n);
	n = criaNo(1);
	insereFim(l,n);
	n = criaNo(1);
	insereFim(l,n);
	n = criaNo(1);
	insereFim(l,n);
	n = criaNo(0);
	insereFim(l,n);
	n = criaNo(0);
	insereFim(l,n);
	n = criaNo(0);
	insereFim(l,n);
	n = criaNo(1);
	insereFim(l,n);
	
	i = contaZero(l);
	printf("\n**lista normal**\n");
	imprimeLista(l);
	printf("inicio: %d\n",i[0]);
	printf("fim: %d\n",i[1]);
	//~ liberaLista(l);
	
	return 0;
}

