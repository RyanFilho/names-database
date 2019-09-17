#include "../Headers/Arvore.h"

typedef struct no No;

struct arvore {
	No * raiz;
};

struct no {
	int info;
	No * pai;
	No * esq;
	No * dir;
};

Arvore * criar() {
   Arvore * a = malloc(sizeof(Arvore));
   a->raiz = NULL;
   return a;
}

void destruir(Arvore * a) {
	desalocar_nos_rec(a->raiz);
	free(a);
}

void desalocar_nos_rec(No * raiz) {
	if (raiz != NULL) {
		desalocar_nos_rec(raiz->esq);
		desalocar_nos_rec(raiz->dir);
		free(raiz);
	}
}

void imprimir(Arvore * a) {
	imp_pre(a->raiz);
	printf("\n");
} 

void imp_pre(No * raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->info);
		imp_pre(raiz->esq);
		imp_pre(raiz->dir);
	}
}

void imp_in(No * raiz) {
	if (raiz != NULL) {
		imp_in(raiz->esq);
		printf("%d ", raiz->info);
		imp_in(raiz->dir);
	}
}

void imp_pos(No * raiz) {
	if (raiz != NULL) {
		imp_pos(raiz->esq);
		imp_pos(raiz->dir);
		printf("%d ", raiz->info);
	}
}

int altura(Arvore * arv) {
	return altura_rec(arv->raiz);
}

int altura_rec(No * raiz) {
	if (raiz != NULL) {
		int ad = altura_rec(raiz->dir);
		int ae = altura_rec(raiz->esq);
		return (ad > ae ? ad : ae) + 1;
	}
	return -1;
}

int contar_folhas(Arvore * arv) {
	return contar_folhas_rec(arv->raiz);
}

int contar_folhas_rec(No * raiz) {
	if (raiz != NULL) {
		if (raiz->esq == NULL && raiz->dir == NULL) {
			return 1;
		} else {
			return contar_folhas_rec(raiz->esq) +
				   contar_folhas_rec(raiz->dir);
		}
	}
	return 0;
}

int buscar(Arvore * arv, int v) {
	return buscar_rec(arv->raiz, v);
}

int buscar_rec(No * raiz, int v) {
	if (raiz != NULL) {
		if (raiz->info > v) {
			return buscar_rec(raiz->esq, v);
		}
		if (raiz->info < v) {
			return buscar_rec(raiz->dir, v);
		}
		return 1;
	}
	return 0;
}

No * inserir_rec(No * raiz, int v) {
	if (raiz != NULL) {
		if (raiz->info > v) {
			raiz->esq = inserir_rec(raiz->esq, v);
		}
		if (raiz->info < v) {
			raiz->dir = inserir_rec(raiz->dir, v);
		}
	} else {
		raiz = malloc(sizeof(No));
		raiz->info = v;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	return raiz;
}

void inserir(Arvore * arv, int v) {
	arv->raiz = inserir_rec(arv->raiz, v);
}

No * remover_maior(No * raiz, int * pmaior) {
	if (raiz != NULL) {
		if (raiz->dir != NULL) {
			raiz->dir = remover_maior(raiz->dir, pmaior);
		} else {
			No * aux = raiz;
			*pmaior = raiz->info;
			raiz = raiz->esq;
			free(aux);
		}
	}
	return raiz;
}

No * remover_rec(No * raiz, int v) {
	if (raiz != NULL) {
		if (raiz->info > v) {
			raiz->esq = remover_rec(raiz->esq, v);
		} else {
			if (raiz->info < v) {
				raiz->dir = remover_rec(raiz->dir, v);
			} else { //ENCONTROU
				No * aux = raiz;
				// FOLHA (GRAU 0)
				if (raiz->esq == NULL && raiz->dir == NULL) {
					raiz = NULL;	
					free(aux);
				} else {
					//GRAU 1
					if (raiz->esq == NULL || raiz->dir == NULL) {
						raiz = raiz->esq != NULL ? raiz->esq : raiz->dir;
						free(aux);
					} else { //GRAU 2
						int maior;
						raiz->esq = remover_maior(raiz->esq, &maior);
						raiz->info = maior;
					}
				}
			}
		}
	}
	return raiz;
}

void remover(Arvore * arv, int v) {
	arv->raiz = remover_rec(arv->raiz, v);
}


int buscar2(Arvore * arv, int v) {
	No * raiz = arv->raiz;
	while(raiz != NULL) {
		if (raiz->info == v) {
			return 1;
		}
		raiz = raiz->info > v ? 
			raiz->esq : raiz->dir;
	}
	return 0;
}

void inserir2(Arvore * arv, int v) {
	No * pai = NULL, * raiz = arv->raiz;
	while(raiz != NULL) {
		if (raiz->info == v) {
			return;
		}
		pai = raiz;
		raiz = raiz->info > v ? raiz->esq : raiz->dir;
	}
	raiz = malloc(sizeof(No));
	raiz->info = v;
	raiz->esq = NULL;
	raiz->dir = NULL;
	if (pai == NULL) {
		arv->raiz = raiz;
	} else {
		if (pai->info > v) {
			pai->esq = raiz;
		} else {
			pai->dir = raiz;
		}
	}
}

void remover2(Arvore * arv, int v) {
	No * pai = NULL, * raiz = arv->raiz;
	//COME�A COM UMA BUSCA
	while(raiz != NULL) {
		if (raiz->info == v) {
			break;
		}
		pai = raiz;
		raiz = raiz->info > v ? 
			raiz->esq : raiz->dir;
	}
	if (raiz == NULL) {
		return;
	}
	// FOLHA (GRAU 0)
	if (raiz->esq == NULL && raiz->dir == NULL) {
		if (pai != NULL) {
			if (pai->info > raiz->info) {
				pai->esq = NULL;
			} else {
				pai->dir = NULL;
			}
		} else {
			arv->raiz = NULL;
		}
		free(raiz);
	} else {
		//GRAU 1
		if (raiz->esq == NULL || raiz->dir == NULL) {
			if (pai != NULL) {
				if (raiz->esq != NULL) {
					if (pai->info > raiz->info) {
						pai->esq = raiz->esq;
					} else {
						pai->dir = raiz->esq;
					}
				} else {
					if (pai->info > raiz->info) {
						pai->esq = raiz->dir;
					} else {
						pai->dir = raiz->dir;
					}
				}
			} else {
				if (raiz->esq != NULL) {
					arv->raiz = raiz->esq;
				} else {
					arv->raiz = raiz->dir;
				}
			}
			free(raiz);
		} else { //GRAU 2
			No * no_maior = raiz->esq;
			//percorre � direita at� NULO
			pai = raiz;
			while(no_maior->dir != NULL) {
				pai = no_maior;
				no_maior = no_maior->dir;
			}
			raiz->info = no_maior->info;
			if (pai == raiz) {
				pai->esq = no_maior->esq;				
			} else {
				pai->dir = no_maior->esq;
			}
			free(no_maior);
		}
	}
}




