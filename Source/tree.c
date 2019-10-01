#include "../Headers/tree.h"

typedef struct node Node;

struct tree {
	Node * root;
};

struct node {
	char * name;
	Node * left;
	Node * right;
};

Tree * Create() {
   Tree * t = malloc(sizeof(Tree));
   t->root = NULL;
   return t;
}

void DestroyNodes(Node * root) {
	if (root != NULL) {
		DestroyNodes(root->left);
		DestroyNodes(root->right);
		free(root);
	}
}

void Destroy(Tree * t) {
	DestroyNodes(t->root);
	free(t);
}

void ShowInOrderNewLine(Node * root) {
	if (root != NULL) {		
		ShowInOrderNewLine(root->left);
		printf("%s\n", root->name);
		ShowInOrderNewLine(root->right);
	}
}

void Show(Tree * a) {
	ShowInOrderNewLine(a->root);
	printf("\n");
} 

int NodeHeight(Node * root) {
	if (root != NULL) {
		int ad = NodeHeight(root->right);
		int ae = NodeHeight(root->left);
		return (ad > ae ? ad : ae) + 1;
	}
	return -1;
}

int Height(Tree * arv) {
	return NodeHeight(arv->root);
}

int Find(Tree * arv, char * v) {
	return FindNode(arv->root, v);
}

int FindNode(Node * root, char * v) {
	if (root != NULL) {
		int result = strcmp(v, root->name);
		if (result < 0) {
			return FindNode(root->left, v);
		}
		if (result > 0) {
			return FindNode(root->right, v);
		}
		return 1;
	}
	return 0;
}

Node * InsertNode(Node * root, char * n) {
	if (root != NULL) {
		int result = strcmp(n, root->name);
		if (result < 0) {
			root->left = InsertNode(root->left, n);
		}
		if (result > 0) {
			root->right = InsertNode(root->right, n);
		}
	} else {
		root = malloc(sizeof(Node));
		root->name = n;
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}

void Insert(Tree * arv, char * n) {
	arv->root = InsertNode(arv->root, n);
}

void ShowInOrderNewLineLike(Node * root, char * substring) {
	if (root != NULL) {		
		ShowInOrderNewLineLike(root->left, substring);
		if (strstr(root->name, substring) != NULL) printf("%s\n", root->name);
		ShowInOrderNewLineLike(root->right, substring);
	}
}

void ShowLike(Tree * a, char * substring) {
	ShowInOrderNewLineLike(a->root, substring);
	printf("\n");
} 

Node * RemoveBigger(Node * root, char * bigger) {
	if (root != NULL) {
		if (root->right != NULL) {
			root->right = RemoveBigger(root->right, bigger);
		} else {
			Node * aux = root;
			bigger = root->name;
			root = root->left;
			free(aux);
		}
	}
	return root;
}

Node * RemoveNode(Node * root, char * v) {
	if (root != NULL) {
		if (strcmp(v, root->name) < 0) {
			root->left = RemoveNode(root->left, v);
		} else {
			if (strcmp(v, root->name) > 0) {
				root->right = RemoveNode(root->right, v);
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
						char * maior;
						root->left = RemoveBigger(root->left, maior);
						root->name = maior;
					}
				}
			}
		}
	}
	return root;
}

void Remove(Tree * arv, char * v) {
	arv->root = RemoveNode(arv->root, v);
}












// // Listar e remover da memória todos os nomes que são maiores, em ordem alfabética, que um nome fornecido.
// void ShowAndRemoveHigherThan(Tree * a, char * value) {
// 	ShowAndRemoveNodeHigherThan(a->root, value);
// 	printf("\n");
// } 

// void ShowAndRemoveNodeHigherThan(Node * root, char * value) {
// 	if (root != NULL) {
		
// 		if (strcmp(value, root->name) > 0)
// 			ShowAndRemoveNodeHigherThan(root->left, value);			
// 			printf("%s\n", root->name);
// 			ShowAndRemoveNodeHigherThan(root->right, value);
			
		
// 	}
// } 
