#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/TadPolinomio.h"

int main(int argc, char **argv){
	lista *l;
	lista *l2;
	lista *l3;
	lista *l4;
	lista *l5;
	no *n;
	int i;
	
	l = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	l4 = criaLista();
	l5 = criaLista();
	
	for(i = 0; i < 2; i++){
		n = criaNo(i,i);
		insereFim(l,n);
	}
	for(i = 0; i < 5; i++){
		n = criaNo(i,i);
		insereFim(l2,n);
	}
	printf("\n polinomio 1 : ");
	imprimeLista(l);
	printf("polinomio 2 : ");
	imprimeLista(l2);
	somaPolinomio(l,l2,l3);
	printf(" soma        : ");
	imprimeLista(l3);
	derivar(l3,l4);
	printf(" derivacao   : ");
	imprimeLista(l4);
	multiplica(l,l2,l5);
	printf(" multiplicacao : ");
	imprimeLista(l5);
	
	return 0;
}

