#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"


int main(int argc, char **argv)
{
	no *n;
	lista *l;
	lista *l2;
	lista *l3;
	int i,k;
	l = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	for(i = 2 ; i < 6 ; i++){
			n = criaNo(i);
			insereFim(l2,n);
		}
	printf("\n **lista ** \n");
	imprimeLista(l);
	
	printf("\n **lista 2** \n");
	imprimeLista(l2);
	
	printf("\n **uniao ** \n");
	uniao(l,l2,l3);
	imprimeLista(l3);
	liberaLista(l3);
	l3 = criaLista();
	
	printf("\n **intersecao ** \n");
	intersecao(l,l2,l3);
	imprimeLista(l3);
	
	k = pertence(l,l2);
	printf("\n \n 0 - NAO \n 1 - SIM \n");
	printf("pertence: %d \n",k);
	
	liberaLista(l);
	liberaLista(l2);
	liberaLista(l3);
	return 0;
}

