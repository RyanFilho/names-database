#include "../Headers/tree.h"

typedef struct node Node;

struct tree {
	Node * root;
};

struct Node {
	char * name;
	Node * left;
	Node * right;
};

Tree * criar() {
   Tree * a = malloc(sizeof(Tree));
   a->root = NULL;
   return a;
}

void destruir(Tree * a) {
	desalocar_Nodes_rec(a->root);
	free(a);
}

void desalocar_Nodes_rec(Node * root) {
	if (root != NULL) {
		desalocar_Nodes_rec(root->left);
		desalocar_Nodes_rec(root->right);
		free(root);
	}
}

void imprimir(Tree * a) {
	imp_pre(a->root);
	printf("\n");
} 

void imp_pre(Node * root) {
	if (root != NULL) {
		printf("%d ", root->name);
		imp_pre(root->left);
		imp_pre(root->right);
	}
}

void imp_in(Node * root) {
	if (root != NULL) {
		imp_in(root->left);
		printf("%d ", root->name);
		imp_in(root->right);
	}
}

void imp_pos(Node * root) {
	if (root != NULL) {
		imp_pos(root->left);
		imp_pos(root->right);
		printf("%d ", root->name);
	}
}

int altura(Tree * arv) {
	return altura_rec(arv->root);
}

int altura_rec(Node * root) {
	if (root != NULL) {
		int ad = altura_rec(root->right);
		int ae = altura_rec(root->left);
		return (ad > ae ? ad : ae) + 1;
	}
	return -1;
}

int contar_folhas(Tree * arv) {
	return contar_folhas_rec(arv->root);
}

int contar_folhas_rec(Node * root) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			return 1;
		} else {
			return contar_folhas_rec(root->left) +
				   contar_folhas_rec(root->right);
		}
	}
	return 0;
}

int buscar(Tree * arv, char * v) {
	return buscar_rec(arv->root, v);
}

int buscar_rec(Node * root, char * v) {
	if (root != NULL) {
		if (root->name > v) {
			return buscar_rec(root->left, v);
		}
		if (root->name < v) {
			return buscar_rec(root->right, v);
		}
		return 1;
	}
	return 0;
}

Node * inserir_rec(Node * root, char * v) {
	if (root != NULL) {
		int result = strcmp(v, root->name);
		if (result < 0) {
			root->left = inserir_rec(root->left, v);
		}
		if (result > 0) {
			root->right = inserir_rec(root->right, v);
		}
	} else {
		root = malloc(sizeof(Node));
		root->name = v;
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}

void inserir(Tree * arv, char * v) {
	arv->root = inserir_rec(arv->root, v);
}

Node * remover_maior(Node * root, int * pmaior) {
	if (root != NULL) {
		if (root->right != NULL) {
			root->right = remover_maior(root->right, pmaior);
		} else {
			Node * aux = root;
			*pmaior = root->name;
			root = root->left;
			free(aux);
		}
	}
	return root;
}

Node * remover_rec(Node * root, char * v) {
	if (root != NULL) {
		if (root->name > v) {
			root->left = remover_rec(root->left, v);
		} else {
			if (root->name < v) {
				root->right = remover_rec(root->right, v);
			} else { //ENCONTROU
				Node * aux = root;
				// FOLHA (GRAU 0)
				if (root->left == NULL && root->right == NULL) {
					root = NULL;	
					free(aux);
				} else {
					//GRAU 1
					if (root->left == NULL || root->right == NULL) {
						root = root->left != NULL ? root->left : root->right;
						free(aux);
					} else { //GRAU 2
						int maior;
						root->left = remover_maior(root->left, &maior);
						root->name = maior;
					}
				}
			}
		}
	}
	return root;
}

void remover(Tree * tree, char * v) {
	tree->root = remover_rec(tree->root, v);
}
