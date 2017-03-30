#ifndef __listaDuplaHead__h
#define __listaDuplaHead__h

typedef struct no{
	int num;
	struct no *prox;
	struct no *antes;
}no; 

no *inicia();
int vazia(no *LISTA);
void insereInicio(no *LISTA, int i);
void exibe(no *LISTA);
void libera(no *LISTA);

#endif
