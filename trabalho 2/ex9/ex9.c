#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	int i;
	lista *l;
	no *n;
	l = criaLista();
	
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	printf("\n**lista normal**\n");
	imprimeLista(l);
	//~ trocaPos(l,2,3);
	trocaPos(l,2,3);
	printf("\n**lista trocaPos**\n");
	imprimeLista(l);
	//~ liberaLista(l);
	
	return 0;
}

