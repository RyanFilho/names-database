#include "tree.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	// Tree * a = Create();
	// Insert(a, "a");
	// Insert(a, "b");
	// Insert(a, "c");
	// Insert(a, "d");
	// Insert(a, "e");
	// Insert(a, "f");
	// Insert(a, "g");	

	// Show(a);
	//ReturnDataTxt();
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
