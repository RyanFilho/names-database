#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

Tree * criar();
void destruir(Tree * t);

int altura(Tree * t);
int contar_folhas(Tree * t);
void imprimir(Tree * t);

int buscar(Tree * t, char * v);
void inserir(Tree * t, char * v);
void remover(Tree * t, char * v);

