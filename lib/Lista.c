#include "Lista.h"

// Cria uma lista vazia
lista_t *criaLista(lista_t *l){
	l = (lista_t *) malloc(sizeof(lista_t));
	if(l != NULL){
		l->quantidade = 0;
		l->primeiro = NULL;
		return l;
	}
	printf(KRED "\t Erro: lista_t *criaLista(lista_t *l);\n" KRESET);
	return NULL;
}

// Cria um nó com o valor=num
node_t *criaNode(int num){
	node_t *n = (node_t *) malloc(sizeof(node_t));
	if(n != NULL){
		n->valor = num;
		n->proximo = NULL;
		return n;
	}
	printf(KRED "\t Erro: node_t *criaNode(int num);\n" KRESET);
	return NULL;
}

// Retorna se esta vazia (1=sim 0=não)
int vazia(lista_t *l){
	if(l->primeiro == NULL)
		return 1;
	else
		return 0;
}

// Retorna quantidade de uma lista
int quantidade(lista_t* l){
	return (l->quantidade);
}

// Insere valor no inicio
void insereInicio(lista_t* l, int num){
	node_t *novo = criaNode(num);
	novo->proximo = l->primeiro;
	l->primeiro = novo;
	l->quantidade++;
}


// Insere valor no fim
void insereFim(lista_t* l, int num){
	if(vazia(l)){
		insereInicio(l,num);
		return;
	}
	
	node_t *novo = criaNode(num);
	node_t *tmp = l->primeiro;
	
	while(tmp->proximo != NULL){
		tmp = tmp->proximo;
	}
	tmp->proximo = novo;
	l->quantidade++;
}

// Insere na posição ordenada
void insere(lista_t* l, int num){
	if(vazia(l)){
		insereInicio(l,num);
		return;
	}
	if(l->primeiro->valor > num){
		insereInicio(l,num);
		return;
	}
	
	node_t *novo = criaNode(num);
	node_t *tmp = l->primeiro;
		
	while(tmp->proximo != NULL){
		if(tmp->proximo->valor > num){
			novo->proximo = tmp->proximo;
			tmp->proximo = novo;
			l->quantidade++;
			return;
		}
		tmp = tmp->proximo;
	}
	
	tmp->proximo = novo;
	l->quantidade++;
}

// Imprime a lista na tela
void exibe(lista_t *l){
	if(vazia(l)){
		printf("Lista vazia!\n");
		return;
	}
	
	node_t *tmp;
	tmp = l->primeiro;
	printf("Lista: ");
	while(tmp != NULL){
		printf("%d, ", tmp->valor);
		tmp = tmp->proximo;
	}
	printf("\n");
}

// Remove o primeiro
void removeInicio(lista_t *l) {
	if(vazia(l)){
		printf("Lista vazia\n");
		return;
	}
	
	node_t *tmp = l->primeiro;
	l->primeiro = tmp->proximo;
	l->quantidade--;
	free(tmp);
			
}

// Remove o valor
void removeLista(lista_t* l, int num){
	if(l->primeiro->valor == num){
		removeInicio(l);
		return;
	}
	
	node_t *tmp = l->primeiro;

		
	while(tmp->proximo != NULL){
		if(tmp->proximo->valor == num){
			node_t *tmp2 = tmp->proximo;
			tmp->proximo = tmp->proximo->proximo;
			
			free(tmp2);
			l->quantidade--;
			return;
		}
		tmp = tmp->proximo;
	}
	
	printf(KRED "\t Erro: valor (%d) não encontrado em void removeLista(lista_t* l, int num);\n" KRESET, num);
}

int removeFila(lista_t* l){
	int i = l->primeiro->valor;
	removeInicio(l);
	return i;
}

lista_t* uniListas(lista_t* l1, lista_t* l2){
	if(vazia(l1))	return l2;
	if(vazia(l2))	return l1;
	
	node_t *tmp = l1->primeiro;
	
	while(tmp->proximo != NULL){
		tmp = tmp->proximo;
	}
	
	tmp->proximo = l2->primeiro;
	l1->quantidade += l2->quantidade;
	return l1;
}
