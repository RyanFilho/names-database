#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

Tree * criar();
void destruir(Tree * arv);

int altura(Tree * arv);
int contar_folhas(Tree * arv);
void imprimir(Tree * arv);

int buscar(Tree * arv, int v);
void inserir(Tree * arv, int v);
void remover(Tree * arv, int v);

int buscar2(Tree * arv, int v);
void inserir2(Tree * arv, int v);
void remover2(Tree * arv, int v);
