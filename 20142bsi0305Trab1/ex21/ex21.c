#include <stdio.h>
#include "../bibliotecas/listaEncadeada.h"

int main(int argc, char **argv)
{
	lista *l;
	no *n;
	l = criaLista();
	n = criaNo('p');
	insereFim(l,n);
	n = criaNo('P');
	insereFim(l,n);
	n = criaNo('a');
	insereFim(l,n);
	imprimeChar(l);
	printf("palavra trocada: \n");
	trocaPalavra(l);
	imprimeChar(l);
	liberaLista(l);
	
	return 0;
}

