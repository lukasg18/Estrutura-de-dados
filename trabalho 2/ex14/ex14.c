#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	int i;
	lista *l;
	lista *l2;
	lista *l3;
	lista *l4;
	no *n;
	l = criaLista();
	l2 = criaLista();
	l3 = criaLista();
	l4 = criaLista();
	
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	for(i = 2; i < 7; i++){
		n = criaNo(i);
		insereFim(l2,n);
	}
	printf("\n**lista normal**\n");
	imprimeLista(l);
	uniao2(l,l2,l3);
	printf("\n**lista normal 2**\n");
	imprimeLista(l2);
	printf("\n**Uniao sem repeticao**\n");
	imprimeLista(l3);
	intersecao2(l,l2,l4);
	printf("\n**Intersecao sem repeticao**\n");
	imprimeLista(l4);
	
	
	//~ liberaLista(l);
	
	return 0;
}

