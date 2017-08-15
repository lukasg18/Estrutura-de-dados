#include <stdio.h>
#include <stdlib.h>
#include "listaDuplaHead.h"

int main(void)
{
	int i;
	no *LISTA;
	LISTA = inicia();
	for(i = 0; i < 5; i++){
		insereInicio(LISTA,i);
	}
	exibe(LISTA);

	free(LISTA);
	return 0;


}
