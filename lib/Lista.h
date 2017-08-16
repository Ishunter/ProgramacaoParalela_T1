#include <stdio.h>
#include <stdlib.h>
#include "Colours.h"

typedef struct node_t {
	int valor;
	struct node_t *proximo;
} node_t;

typedef struct lista_t {
	int quantidade;
	struct node_t *primeiro;
} lista_t;

typedef struct node_t node_t;
typedef struct lista_t lista_t;

lista_t *criaLista(lista_t *l);
node_t *criaNode(int num);

int vazia(lista_t* l);
int quantidade(lista_t* l);
void exibe(lista_t* l);

void insereInicio(lista_t* l, int num);
void insereFim(lista_t* l, int num);
void insere(lista_t* l, int num);

void removeInicio(lista_t *l);
void removeLista(lista_t *l, int num);

int removeFila(lista_t* l);
