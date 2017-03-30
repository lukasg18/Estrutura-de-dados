#include <stdio.h>
#include "../bibliotecas/listaEstatica.h"

int main(){
	int i;
    lista l;
    no n;
    criaLista(&l);
    for(i = 0; i < 10; i++){
		criaNo(&n,i);
		insereFim(&l,n); /* inserindo no Fim*/
	}
	printf("\n *** removendo a 2 pos***\n");
	removePos(&l,2);
	imprimeLista(&l);
	
	liberaLista(&l);
	
    return 0;
}

