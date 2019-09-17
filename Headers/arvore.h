#include <stdio.h>
#include <stdlib.h>

typedef struct arvore Arvore;

Arvore * criar();
void destruir(Arvore * arv);

int altura(Arvore * arv);
int contar_folhas(Arvore * arv);
void imprimir(Arvore * arv);

int buscar(Arvore * arv, int v);
void inserir(Arvore * arv, int v);
void remover(Arvore * arv, int v);

int buscar2(Arvore * arv, int v);
void inserir2(Arvore * arv, int v);
void remover2(Arvore * arv, int v);
