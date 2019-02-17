#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

//Cria pilha vazia
Pilha *cria_Pilha(){
	Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
	
	if(pi != NULL){
		*pi = NULL;
	}
	
	return pi;
}


//inserção de um nodo em pilha encadeada
int insere_Pilha(Pilha *pi, struct aluno al){
	if(pi == NULL){
		return 0;	
	}
	Elem *no;
	no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = al;	
	no->prox = (*pi);
	*pi = no;
	
	return 1;
}

//Desempilha um nodo de um pilha encadeada
int remove_Pilha(Pilha *pi){
	if(pi == NULL){
		return 0;
	}
	if((*pi) == NULL){
		return 0;
	}
	Elem *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

//Consulta a pilha encadeada
int consulta_Pilha(Pilha *pi, struct aluno *al){
	if(pi == NULL){
		return 0;	
	}
	if((*pi) == NULL){
		return 0;
	}
	*al = (*pi)->dados;
	return 1;
}

//Destroi de uma pilha encadeada;
void libera_Pilha(Pilha *pi){
	if(pi != NULL){
		Elem *no;
		while((*pi) != NULL){
			no = *pi;
			*pi = (*pi)->prox;
			free(no);
		}
		free(pi);
	}
}

//Verifica de pilha esta cheia
int Pilha_cheia(Pilha *pi){
	return 0;
}

//Verifica de pilha esta vazia
int Pilha_vazia(Pilha *pi){
	if(pi == NULL){
		return 1;
	}
	if(*pi == NULL){
		return 1;
	}
	return 0;
}
