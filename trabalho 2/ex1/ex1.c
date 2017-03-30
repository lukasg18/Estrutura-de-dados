#include <stdio.h>
#include "../bibliotecas/listaEstatica.h"

int main(){
	int i;
    lista l;
    no n;
    criaLista(&l);
    for(i = 0; i < 5; i++){
		criaNo(&n,i);
		insereFim(&l,n);
	}
	printf("\n *** removendo pos1 e colocando na pos2***\n");
	trocaPos(&l,2,3);
	imprimeLista(&l);
	
	liberaLista(&l);
	
    return 0;
}

