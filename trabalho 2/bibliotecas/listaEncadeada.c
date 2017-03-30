#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"

no *criaNo(int i){
	no *n;
	n = malloc(sizeof(no));
	n->conteudo = i; 
	n->prox = NULL;
	return n;
}

lista *criaLista(){
		lista *l;
		l = malloc(sizeof(lista));
		l->tam = 0;
		l->ini = l->fim = NULL;
		return l;
	}
	
void insereIni(lista *l, no *n){
		if (l -> tam != 0)
		{
			n -> prox = l -> ini;
		}
		else
			l -> fim = n;
			
		l -> ini = n;	
		l -> tam++;
	}

void insereFim(lista *l, no *n){
		if (l->tam !=0)
		{
			l -> fim -> prox = n;
		}
		else
			l->ini = n;

		l->fim = n;
		l->tam++;
	}
	
/* (a) função numero (L) – retorna o número de elementos da lista L. */		
int tamLista(lista *l){
	return l->tam;
}
	
/* inserindo na posicao */	
void inserePos(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 1)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t - 1; aux = aux -> prox , i++);
		n->prox = aux -> prox;
		aux->prox = n;
		l -> tam++;
	}
	
/* removendo um elemento do inicio*/	
void removeIni(lista *l){
		no *aux;
		aux = malloc(sizeof(no));
		aux = l -> ini;
		l -> ini = l-> ini -> prox;
		free(aux);
		l->tam --;
}

/*procedimento elimina (k, L) – elimina o k-ésimo elemento da lista L. */
void removePos(lista *l,int t){
	int i;
	no *aux;
	no *lixo;
	for(i = 0,aux = l -> ini; i < t-1 ; aux = aux -> prox,i++);
	lixo = aux->prox;
	aux -> prox  = lixo -> prox;
	aux = aux -> prox;
	free(lixo);
	l -> tam --;
	}	

/* funçao de busca */
int busca(lista *l,int i){
		int cont = 0;
		int x = 0;
		no *aux;
		aux = l->ini;
		while(x < (l -> tam)){
			if(aux -> conteudo == i){
				cont++;
			}
			x++;
			aux = aux -> prox;
	}
	return cont;
}


/*concatenar duas listas circulares*/
void concatena(lista *l1, lista *l2, lista *l3){
	no *aux;
	int i,j;
	aux = l1->ini;
	i = j = 0;
	while(i < (l1 -> tam)){
		insereFim(l3,aux);
		aux = aux -> prox;
		i++;
	}
	aux = l2->ini;
	while(j < (l2 -> tam)){
		insereFim(l3,aux);
		aux = aux -> prox;
		j++;
	}
	
}

/* intercalar duas listas ordenadas*/
void intercala(lista *l1, lista*l2, lista *l3){
	no *aux;
	no *aux2;
	int i,j;
	aux = l1 -> ini;
	aux2 = l2 -> ini;
	i = j = 0;
	while(i < (l1 -> tam) || j < (l2 -> tam)){
		if(i < (l1 -> tam)){
			if(j < (l2 -> tam)){
				if((aux -> conteudo) < (aux2 -> conteudo)){
					insereFim(l3,aux);
					aux = aux -> prox;
					i++;
				}else{
					insereFim(l3,aux2);
					aux2 = aux2 -> prox;
					j++;
				}		
			}else{
				insereFim(l3,aux);
				aux = aux -> prox;
				i++;
			}
		}else{
			insereFim(l3,aux2);
			aux2 = aux2 -> prox;
			j++;
		}
	}
}

void imprimeLista(lista *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf("conteudo -> %d \n ", tmp -> conteudo);
			tmp = tmp->prox;
			i--;
		}
	}


//~ void liberaLista(lista *l){
		//~ int i = 0;
		//~ no *tmp;
		//~ while (i < (l -> tam))
		//~ {
			//~ tmp = l->ini->prox;
			//~ free(l->ini);
			//~ l->ini = tmp;
			//~ i++;
		//~ }
		//~ free(l);
	//~ }
	
	void liberaLista(lista *l){
		int i = l->tam;
		no *tmp;
		while (i-- != 0)
		{
			tmp = l->ini->prox;
			free(l->ini);
			l->ini = tmp;
		}
		free(l);
	}

/* fazer uma cópia da lista*/
void copiaLista(lista *l1, lista *l2){
	no *aux;
	no *pega;
	int i;
	liberaLista(l1);
	l1 = criaLista();
	aux = l2 -> ini;
	i = 0;
	while(i < (l2 -> tam)){
		pega = criaNo(aux -> conteudo);
		insereFim(l1,pega);
		aux = aux -> prox;
		i++;
	}
}

/* procedimento troca (k, L , v) – modifica o valor do k-ésimo elemento da lista para v. */
void troca(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 1)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t - 1; aux = aux -> prox , i++);
		n->prox = aux -> prox;
		aux->conteudo = n->conteudo;
		free(n);
	}

/*procedimento insere_esq (k, L, v) – insere o valor v à esquerda do k-ésimo
elemento da lista L. */
void insereEsq(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 0)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t-2; aux = aux -> prox , i++);
		n->prox = aux -> prox;
		aux->prox = n;
		l -> tam++;
	}
	
/*procedimento insere_dir (k, L, v) – insere o valor v à direita do k-ésimo elemento
da lista L. */
void insereDir(lista *l, no *n,int t){
		int i;
		no *aux;
		if(t == 1)
		{
			insereIni(l,n);
			return;
		}
		if(t == l -> tam + 1)
		{
			insereFim(l,n);
			return;
		}
		for( i = 0 , aux = l -> ini; i < t; aux = aux -> prox , i++);
		n->prox = aux -> prox;
		aux->prox = n;
		l -> tam++;
	}

/* Faça a inversão através da inversão dos campos de ligação, e NÃO dos
campos de informação.*/
void inverteLista(lista *l, lista *l2){
	no *aux;
	no *pega;
	aux = l->ini;
	pega = aux;
	while(aux != NULL){
		pega = criaNo(aux -> conteudo);
		if (l2 -> tam != 0)
		{
			pega -> prox = l2 -> ini;
		}
		else
			l2 -> fim = pega;
			
		l2 -> ini = pega;	
		l2 -> tam++;
		aux = aux->prox;
	}
}

void inverteLista2(lista *l){
	no *aux;
	no *pega;
	lista *l2;
	l2 = criaLista();
	aux = l->ini;
	pega = aux;
	while(aux != NULL){
		pega = criaNo(aux -> conteudo);
		if (l2 -> tam != 0)
		{
			pega -> prox = l2 -> ini;
		}
		else
			l2 -> fim = pega;
			
		l2 -> ini = pega;	
		l2 -> tam++;
		aux = aux->prox;
	}
	copiaLista(l,l2);
}


void imprimeChar(lista *l){
		no *tmp = l->ini;
		int i;
		i = (l->tam - 1);
		while (i >-1)
		{
			printf("conteudo -> %c \n ", tmp -> conteudo);
			tmp = tmp->prox;
			i--;
		}
	}

void imprimeListaR(no *n){
		if (n == NULL)
		{
			return;
		}else{
			printf("conteudo -> %d \n ", n -> conteudo);
			imprimeListaR(n = n -> prox);
		}
		
	}

/* intercalar duas listas ordenadas*/
void imparPar(lista *l1, lista*impar, lista *par){
	no *aux;
	int i;
	aux = l1 -> ini;
	i = 0;
	while(i < (l1 -> tam)){
		if((aux -> conteudo) % 2 == 0 ){
			insereFim(par,aux);
		}else{
			insereFim(impar,aux);
		}
		aux = aux -> prox;
		i++;
	}
}

void ordenaListaCrescente(lista *l1, lista *l2){
	int cont, cont2, verifica;
	no *aux;
	no *aux2;
	no *pega;
	
	aux  = l1 -> ini;
	pega = criaNo(aux -> conteudo);
	insereFim(l2,pega);
	aux = aux -> prox;
	cont = 1;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		verifica = 0;
		while(cont2 < l2 -> tam ){
			if(aux->conteudo < aux2 -> conteudo){
				if(cont2 == 0){
					pega = criaNo(aux -> conteudo);
					insereIni(l2,pega);		
					verifica++;
					cont2 = l2 -> tam;
				}else{
					pega = criaNo(aux -> conteudo);
					insereEsq(l2,pega,cont2);
					verifica++;
					cont2 = l2 -> tam;
				}
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		if(verifica == 0){
			pega = criaNo(aux -> conteudo);
			insereFim(l2,pega);
		}
		cont++;
		aux = aux -> prox;
	}
}


void ordenaListaDescrescente(lista *l1, lista *l2){
	int cont, cont2, verifica;
	no *aux;
	no *aux2;
	no *pega;
	
	aux  = l1 -> ini;
	pega = criaNo(aux -> conteudo);
	insereFim(l2,pega);
	aux = aux -> prox;
	cont = 1;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		verifica = 0;
		while(cont2 < l2 -> tam ){
			if(aux->conteudo > aux2 -> conteudo){
				if(cont2 == 0){
					pega = criaNo(aux -> conteudo);
					insereIni(l2,pega);		
					verifica++;
					cont2 = l2 -> tam;
				}else{
					pega = criaNo(aux -> conteudo);
					insereEsq(l2,pega,cont2);
					verifica++;
					cont2 = l2 -> tam;
				}
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		if(verifica == 0){
			pega = criaNo(aux -> conteudo);
			insereFim(l2,pega);
		}
		cont++;
		aux = aux -> prox;
	}
}

int achaKEsimo(lista *l, int k){ 
	int cont;
	no *n;
	lista *l2;
	l2 = criaLista();
	ordenaListaDescrescente(l,l2);
	if(k > l2->tam){
		return 0;
	}else{
		for(cont = 1, n = l2 -> ini; cont < k; n = n->prox, cont++);
		return n -> conteudo;
	}
}

void uniao(lista *l1, lista *l2, lista *l3){
	no *aux;
	no *aux2;
	int i,j;
	aux = l1->ini;
	i = j = 0;
	while(i < (l1 -> tam)){
		aux2 = criaNo(aux->conteudo);
		insereFim(l3,aux2);
		aux = aux -> prox;
		i++;
	}
	aux = l2->ini;
	while(j < (l2 -> tam)){
		aux2 = criaNo(aux -> conteudo);
		insereFim(l3,aux2);
		aux = aux -> prox;
		j++;
	}	
}

void intersecao(lista *l1, lista *l2, lista *l3){
	int cont, cont2;
	no *aux;
	no *aux2;
	no *pega;
	
	cont = 0;
	aux  = l1 -> ini;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		while(cont2 < l2 -> tam ){
			if(aux->conteudo == aux2 -> conteudo){
				pega = criaNo(aux -> conteudo);
				insereFim(l3,pega);		
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		cont++;
		aux = aux -> prox;
	}
}

int pertence(lista *l1, lista *l2){
	int cont, cont2,verifica;
	no *aux;
	no *aux2;
	
	cont = verifica = 0;
	aux  = l1 -> ini;
	while(cont < l1 -> tam ){
		aux2 = l2 -> ini;
		cont2 = 0;
		while(cont2 < l2 -> tam ){
			if(aux->conteudo == aux2 -> conteudo){
				verifica = 1;
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		cont++;
		aux = aux -> prox;
	}
	return verifica; /* 0 - FALSE, 1 - TRUE*/
}

int removerVetor(int k, int n, int *v){
   int j;
   for (j = k+1; j < n; ++j)  
      v[j-1] = v[j];
   return n - 1;
}

int inserirVetor(int k, int x, int n, int v[]){
   int j;
   for (j = n; j > k; --j)  
      v[j] = v[j-1];
   v[k] = x;
   return n + 1;
} 

void trocaPos(lista *l, int pos1, int pos2){
		int i;
		no *aux;
		no *aux2;
		if(pos1 < l->tam && pos2 < l->tam){
			for( i = 0 , aux = l -> ini; i < pos1; aux = aux -> prox , i++);
			aux2 = criaNo(aux ->conteudo);
			removePos(l,pos1);
			printf("%d",aux2 -> conteudo);
			inserePos(l,aux2,pos2);
		}
}

no *buscaPos(lista *l,no *n){
		int x = 0;
		no *aux;
		aux = l->ini;
		while(x < (l -> tam)){
			if(aux -> conteudo == n -> conteudo){
				return aux;
			}
			x++;
			aux = aux -> prox;
	}
	return NULL;
}

void uniao2(lista *l1, lista *l2, lista *l3){
	no *aux;
	no *aux2;
	int i,j;
	aux = l1->ini;
	i = j = 0;
	while(i < (l1 -> tam)){
		aux2 = criaNo(aux->conteudo);
		insereFim(l3,aux2);
		aux = aux -> prox;
		i++;
	}
	aux = l2->ini;
	while(j < (l2 -> tam)){
		aux2 = buscaPos(l3,aux);
		if(aux2 == NULL){
			aux2 = criaNo(aux -> conteudo);
			insereFim(l3,aux2);
		}
		aux = aux -> prox;
		j++;
	}	
}

void intersecao2(lista *l1, lista *l2, lista *l4){
	int cont, cont2;
	no *aux;
	no *aux2;
	no *pega;
	
	cont = 0;
	aux  = l2 -> ini;
	while(cont < l2 -> tam ){
		aux2 = l1 -> ini;
		cont2 = 0;
		while(cont2 < l1 -> tam ){
			pega = buscaPos(l4,aux2);
			if(pega == NULL){
				pega = criaNo(aux2 -> conteudo);
				insereFim(l4,pega);
			}
			cont2++;
			aux2 = aux2 -> prox;
		}
		cont++;
		aux = aux -> prox;
	}
}

void RemoveNCDinamica(lista *l, int pos, int qtd){
	int i;
	if((pos + qtd) < l ->tam){
		for(i = pos; i < (qtd + pos); i++){
			removePos(l,i-qtd);
		}
	}
}
