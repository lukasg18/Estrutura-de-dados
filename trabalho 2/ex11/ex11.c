#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	int i;
	lista *l;
	no *n;
	l = criaLista();
	
	for(i = 0; i < 7; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	printf("\n**lista normal**\n");
	imprimeLista(l);
	RemoveNCDinamica(l,1,4);
	//~ removePos(l,2);
	printf("\n**lista trocaPos**\n");
	imprimeLista(l);
	//~ liberaLista(l);
	
	return 0;
}

