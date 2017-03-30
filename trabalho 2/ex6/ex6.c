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
	printf("\n*** removendo do inicio e colocando no final***\n");
	retiraIniInsereFim(&l,2);
	imprimeLista(&l);
	liberaLista(&l);
	
    return 0;
}

