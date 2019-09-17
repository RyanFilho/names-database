#include "tree.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	// Tree * a = criar();
	// inserir(a, 20);
	// inserir(a, 10);
	// inserir(a, 30);
	// inserir(a, 8);
	// inserir(a, 15);	
	// inserir(a, 23);
	// inserir(a, 35);
	// inserir(a, 12);	
	// imprimir(a);
	// remover(a, 23);	
	// remover(a, 30);
	// remover(a, 20);
	// imprimir(a);
	// destruir(a);
	// scanf("%d");
	FILE* arq = ReadDataTxt();

	ShowDataTxt(arq);
}
