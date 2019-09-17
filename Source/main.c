#include "tree.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	// Tree * a = criar();
	// inserir(a, "a");
	// inserir(a, "b");
	// inserir(a, "c");
	// inserir(a, "d");
	// inserir(a, "e");
	// inserir(a, "f");
	// inserir(a, "g");	
	// imprimir(a);
	// scanf("%d");

	FILE* arq = OpenDataTxt();

	ShowDataTxt(arq);

}
