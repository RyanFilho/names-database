#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree Tree;

Tree * Create();
void Destroy(Tree * t);

int Height(Tree * t);
void Show(Tree * t);

int Find(Tree * t, char * v);
void Insert(Tree * t, char * v);
void Remove(Tree * t, char * v);

