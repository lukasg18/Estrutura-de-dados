#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

void criaNo(no *n, int i){
	n->conteudo = i;
}

void criaLista(lista *l){
	l -> fim = 0;
}

void insereFim(lista *l, no n){
	l -> vet[l->fim] = n;
	l -> fim++;
}

void inserePos(lista *l, no n, int pos){
	int i;
	if(pos >= l -> fim){
		insereFim(l,n);
	}else{
		for(i = l -> fim; i > pos; i--){
			l -> vet[i] = l -> vet[i - 1];
		}
		l -> vet[pos] = n;
		l->fim++;
	}
}

void insereIni(lista *l, no n){
	inserePos(l,n,0);
}

no *retornaPos(lista *l, int pos){
	if(pos < l->fim)
		return &l->vet[pos];
	else
		return NULL;
}

void imprimeLista(lista *l){ /* do inicio ao Fim*/
	int i;
	no n;
	for(i = 0; i < l->fim; i++){
		n = l->vet[i];
		printf("conteudo: %d \n", n.conteudo);
	}
}

void imprimeListaInverso(lista *l){ /* do fim ao inicio*/
	int i;
	no n;
	for(i = (l->fim - 1); i >0 ; i--){
		n = l->vet[i];
		printf("conteudo: %d \n", n.conteudo);
	}
}

int fimanhoLista(lista l){
	return l.fim;
}

void liberaLista(lista *l){
	l -> fim = 0;
}

void removePos(lista *l, int pos){
	int i;
	if(pos < l-> fim){
		if(pos == (l->fim - 1)){ /* se a posicao for a ultima */
			l -> fim--;
		}else{
			for(i = pos; i < (l->fim - 1); i++){   /* para as demais posicoes*/
				l -> vet[i] = l -> vet[i+1];
			}
			l -> fim--;
		}
	}
}

no *buscaValor(lista *l, int x){
	int i;
	for(i = 0; i < l->fim; i++){
		if(l -> vet[i].conteudo == x){
			return &l->vet[i];
		}
	}
	return NULL;
}

int buscaPos(lista *l, int x){
	int i;
	for(i = 0; i < l->fim; i++){
		if(l -> vet[i].conteudo == x){
			return i;
		}
	}
	return -1;
}

void trocaPos(lista *l, int pos1, int pos2){
	no aux;
	if((pos1 < l -> fim) && (pos2 < l -> fim)){
		aux = l->vet[pos1];
		removePos(l,pos1);
		inserePos(l,aux,pos2);
	}
}

void insereNCopias(lista *l,no n, int pos, int ncopia){
	int i;
	if((pos + ncopia) < l -> fim){
		for(i = pos; i < (pos+ncopia); i++){
			l->vet[i] = n;
		}
	}
}

void removeNElem(lista *l, int pos, int qtd){
	int i;
	if((pos+qtd) < l -> fim){
		for(i = pos; i < (pos+qtd); i++){
			removePos(l,pos);
		}
	}
}

void ordenaListaDecre(lista *l){
	int i,verifica;
	no aux;
	i = 0;
	verifica = 1;
	while(verifica != 0){
		verifica = 0;
		for(i = 0; i < (l->fim - 1); i++){
			if(l->vet[i+1].conteudo > l -> vet[i].conteudo){
				aux = l->vet[i];
				l -> vet[i] = l -> vet[i+1];
				l -> vet[i+1] = aux;
				verifica++;
			}
		}
	}
}

void ordenaListaCres(lista *l){
	int i,verifica;
	no aux;
	i = 0;
	verifica = 1;
	while(verifica != 0){
		verifica = 0;
		for(i = 0; i < (l->fim - 1); i++){
			if(l->vet[i+1].conteudo < l -> vet[i].conteudo){
				aux = l->vet[i];
				l -> vet[i] = l -> vet[i+1];
				l -> vet[i+1] = aux;
				verifica++;
			}
		}
	}
}

int verificaOrdena(lista *l){
	if(l->vet[1].conteudo < l -> vet[0].conteudo){
		return 0; /* lista Descente*/
	}else{
		return 1; /*lista Crescente*/
	}
}

void copiaLista(lista *l2, lista *l1){
	int i;
	for(i = 0; i < l1->fim; i++){
		insereFim(l2,l1->vet[i]);
	}
}

void copiaListaSemOcorrencia(lista *l2, lista *l1){
	int i,j,verifica;
	i = j = verifica = 0; 
	while(i < l1->fim){
		verifica = 0;
		j = 0;
		while(j < l2 -> fim){
			if( l1 -> vet[i].conteudo == l2 -> vet[j].conteudo){
				verifica++;
			}
			j++;
		}
		if(verifica == 0){
			insereFim(l2,l1->vet[i]);
		}
		i++;
	}
}

void inverteLista(lista *l,lista *aux){
	int i,j;
	j = 0;
	copiaListaSemOcorrencia(aux,l);
	for(i = (l-> fim - 1); i >= 0; i--){
		l->vet[j] = aux -> vet[i];
		j++;
	}
}

void intercalaLista(lista *l1, lista *l2, lista *l3){
	int i,j;
	no *aux;
	i = j = 0;
	while(i < (l1 -> fim) || j < (l2 -> fim)){
		if(i < (l1 -> fim)){
			if(j < (l2 -> fim)){
				if((l1 -> vet[i].conteudo) < (l2 ->vet[j].conteudo)){
					aux = buscaValor(l3,l1->vet[i].conteudo);
					if(aux == NULL){
						insereFim(l3,l1 -> vet[i]);
					}
					i++;
				}else{
					aux = buscaValor(l3,l2->vet[j].conteudo);
					if(aux == NULL){
						insereFim(l3,l2 -> vet[j]);
					}
					j++;
				}		
			}else{
				aux = buscaValor(l3,l1->vet[i].conteudo);
					if(aux == NULL){
						insereFim(l3,l1 -> vet[i]);
					}
				i++;
			}
		}else{
			aux = buscaValor(l3,l2->vet[j].conteudo);
			if(aux == NULL){
				insereFim(l3,l2 -> vet[j]);
			}
			j++;
		}
	}
}

void insereNoRepetidos(lista *l1, lista*l2, lista*l4){
	int i,j;
	for(i = 0; i < l1->fim; i++){
		for(j = i; j < (l1->fim - 1); j++){
			if(l1 -> vet[i].conteudo == l1 -> vet[j+1].conteudo){
				insereFim(l4,l1 -> vet[i]);
			}
		}
	}
	for(i = 0; i < l2->fim; i++){
		for(j = i; j < (l2->fim - 1); j++){
			if(l1 -> vet[i].conteudo == l2 -> vet[j+1].conteudo){
				insereFim(l4,l2 -> vet[i]);
			}
		}
	}
}

void retiraIniInsereFim(lista *l, int x){
	int i;
	if(x < l->fim){
		for(i = 0; i < x; i++){
			insereFim(l,l->vet[0]);
			removePos(l,0);
		}
	}
}
