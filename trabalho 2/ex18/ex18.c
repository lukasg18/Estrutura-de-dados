#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/deque.h"

int main(int argc, char **argv)
{
	int i;
	fila *l;
	fila *l2;
	no *n;
	l = criaFila();
	l2 = criaFila();
	
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereFim(l,n);
	}
	for(i = 0; i < 5; i++){
		n = criaNo(i);
		insereIni(l2,n);
	}
	printf("\n**deque inserindo no fim**\n");
	imprimeDeque(l);
	removeFim(l);
	printf("\n**deque removendo Fim**\n");
	imprimeDeque(l);
	printf("\n**deque inserindo no inicio**\n");
	imprimeDeque(l2);
	removeIni(l2);
	printf("\n**deque removendo inicio**\n");
	imprimeDeque(l2);
	
	
	
	//~ liberaLista(l);
	
	return 0;
}

