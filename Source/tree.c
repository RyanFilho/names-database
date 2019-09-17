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

void ShowPreOrder(Node * root) {
	if (root != NULL) {
		printf("%s ", root->name);
		ShowPreOrder(root->left);
		ShowPreOrder(root->right);
	}
}

void ShowInOrder(Node * root) {
	if (root != NULL) {
		ShowInOrder(root->left);
		printf("%s ", root->name);
		ShowInOrder(root->right);
	}
}

void ShowPosOrder(Node * root) {
	if (root != NULL) {
		ShowPosOrder(root->left);
		ShowPosOrder(root->right);
		printf("%s ", root->name);
	}
}

void Show(Tree * a) {
	ShowPreOrder(a->root);
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


int LeavesCount(Tree * arv) {
	return NodesLeavesCount(arv->root);
}

int NodesLeavesCount(Node * root) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			return 1;
		} else {
			return NodesLeavesCount(root->left) +
				   NodesLeavesCount(root->right);
		}
	}
	return 0;
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

Node * RemoveBigger(Node * root, char * pmaior) {
	if (root != NULL) {
		if (root->right != NULL) {
			root->right = RemoveBigger(root->right, pmaior);
		} else {
			Node * aux = root;
			pmaior = root->name;
			root = root->left;
			free(aux);
		}
	}
	return root;
}

Node * RemoveNode(Node * root, char * n) {
	if (root != NULL) {
		int result = strcmp(n, root->name);
		if (result < 0) {
			root->left = RemoveNode(root->left, n);
		} else {
			if (result > 0) {
				root->right = RemoveNode(root->right, n);
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

void Remove(Tree * tree, char * n) {
	tree->root = RemoveNode(tree->root, n);
}
