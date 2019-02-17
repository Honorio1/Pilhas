#include <stdio.h>
#include <stdlib.h>
#include "pilhaSequencial.h"

struct pilha{
	int qtd;
	struct aluno dados[MAX];
};

Pilha *cria_Pilha(){
	Pilha *pi;
	
	pi = (Pilha*) malloc(sizeof(struct pilha));
	
	if(pi != NULL){
		pi->qtd = 0;
	}
	
	return pi;
}

//Destruir a pilha
void libera_Pilha(Pilha *pi){
	free(pi);
}

//Tamanho da pilha
int tamanho_Pilha(Pilha *pi){
	if(pi == NULL){
		return -1;
	}else
		return pi->qtd;
}

//Retorna se a pilha está cheia;
int Pilha_cheia(Pilha *pi){
	if(pi == NULL){
		return -1;
	}
	return(pi->qtd = MAX);
}

//Retorna de a pilha esta vazia
int Pilha_vazia(Pilha *pi){
	if(pi == NULL){
		return -1;
	}
	return(pi->qtd == 0);
}

//Inserindo um elemento na pilha
int insere_Pilha(Pilha *pi, struct aluno al){
	if(pi == NULL){
		return 0;
	}
	if(pi->qtd == MAX){
		return 0;
	}
	pi->dados[pi->qtd] = al;
	pi->qtd++;
	return 1;
}

//Removendo um elemento da pilha
int remove_Pilha(Pilha *pi){
	if(pi == NULL || pi->qtd == 0){
		return 0;
	}
	pi->qtd--;
	return 1;
}

//Consulta o topo da pilha
int consulta_topo_pilha(Pilha *pi, struct aluno *al){
	if(pi == NULL || pi->qtd == 0){
		return 0;
	}
	*al = pi->dados[pi->qtd-1];
	return 1;
}
	
