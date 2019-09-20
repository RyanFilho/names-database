#include "tree.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	Tree * a = Create();
	Insert(a, "Ryan Sampaio");
	Insert(a, "Lysando Carioca");
	Insert(a, "Samuel Camilo");
	Insert(a, "Bill Gates");
	Insert(a, "Linus Tovald");
	Insert(a, "Kent Beck");
	Insert(a, "Jah Rastafari");	

	ShowLike(a, "an");

	char** retorno = ReturnDataTxt();
	int countList = CountDataTxt();
	int count;
	
	printf("Count Names in List: %d\n", countList);
	for(count = 0; count < countList; count++)
	{
		printf("Names: %s\n", retorno[count]);
	}


	return 0;

}
