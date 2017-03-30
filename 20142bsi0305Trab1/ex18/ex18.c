#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	no *n;
	lista *l;
	int i,k;
	l = criaLista();
	
	for(i = 1 ; i < 5 ; i++){
			n = criaNo(i);
			insereFim(l,n);
		}
	printf("\n **lista ** \n");
	imprimeLista(l);
	printf("\n **achaKesimo** \n");
	for(i = 1; i < 5; i++){
		k = achaKEsimo(l,i);
		printf("o %d maior elemento da lista eh: %d \n",i,k);
	}
	printf("\n \n");
	
	liberaLista(l);
	return 0;
}

