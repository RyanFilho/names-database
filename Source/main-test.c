#include "tree.c"

int main(int argc, char *argv[])
{

	FILE* arq = OpenDataTxt();
	printf("Total de Linhas: %d\n", CountDataTxt(arq));

}