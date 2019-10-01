#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

void menu();

int main(int argc, char *argv[]) {

	// Tree * a = Create();
	// Insert(a, "Ryan Sampaio");
	// Insert(a, "Lysando Carioca");
	// Insert(a, "Samuel Camilo");
	// Insert(a, "Bill Gates");
	// Insert(a, "Linus Tovald");
	// Insert(a, "Kent Beck");
	// Insert(a, "Jah Rastafari");	

	// ShowLike(a, "an");

	menu();
	
	return 0;

}


void menu()
{   
    int option;

    Tree * arvore = Create();
	Insert(arvore, "Ryan Sampaio");
	Insert(arvore, "Lysando Carioca");
	Insert(arvore, "Samuel Camilo");
	Insert(arvore, "Bill Gates");
	Insert(arvore, "Linus Tovald");
	Insert(arvore, "Kent Beck");
	Insert(arvore, "Jah Rastafari");

    do
    {
        system("clear");
        printf("----- MENU -----\n");
        printf("(1) Carregar Nomes do Arquivo\n");
        printf("(2) Listar Nomes em Ordem Alfabetica\n");
        printf("(3) Listar Nomes por Substring\n");
        printf("(4) Inserir Novo Nome na Arvore\n");
        printf("(5) Remover Nome da Arvore\n");
        printf("(8) Salvar Nomes no Arquivo\n");
        printf("(0) Sair\n");
        printf("----------------\n");
        printf("Digite uma Opção: ");
        scanf("%d", &option);
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        switch(option)
        {
            case 1:
                system("clear");
                printf("------- Carregando Dados -------\n");

                char line[30];
                FILE *fp;                
                fp = fopen("namesDB.txt", "r"); // read mode
                
                if (fp == NULL)
                {
                    printf("Não foi possível encontrar o arquivo!\n");
                    break;
                }
                
                while(fgets(line, sizeof line, fp) != NULL)
                    Insert(arvore, line);
                
                fclose(fp);

                printf("Feito...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 2:
                system("clear");
                printf("(2) Listar Nomes em Ordem Alfabetica\n\n");
                Show(arvore);
                printf("\nPressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 3:
                system("clear");
                printf("(3) Listar Nomes por Substring\n");
                printf("Informe a substring:\n");
                char substring[30] = "";
                fgets(substring, sizeof(substring), stdin);
                strtok(substring, "\n");
                printf("Nomes encontrados:\n");
                ShowLike(arvore, substring);
                printf("Pressione qualquer tecla para voltar...");                
                getchar();                
                system("clear");
                break;
            case 4:
                system("clear");
                printf("(4) Inserir Novo Nome na Arvore\n");
                printf("Informe o nome a ser inserido:\n");
                char newName[30] = "";
                fgets(newName, sizeof(newName), stdin);
                strtok(newName, "\n");
                Insert(arvore, newName);
                printf("Nome inserido com sucesso!\n");
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 5:                
                system("clear");
                printf("(5) Remover Nome da Arvore\n");
                printf("Informe o nome a ser removido:\n");
                char removeName[30] = "";
                fgets(removeName, sizeof(removeName), stdin);
                strtok(removeName, "\n");
                Remove(arvore, removeName);
                printf("Nome removido com sucesso!\n");
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 6:
                // system("clear");
                // printf("------- Exibindo Lista -------\n");
                // exibirListaPacientes(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 7:
                // system("clear");
                // printf("------- Exibindo Lista -------\n");
                // exibirListaPacientes(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 8:
                // system("clear");
                // printf("------- Exibindo Lista -------\n");
                // exibirListaPacientes(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            default:
                break;
        }

    } while (option != 0);
    Destroy(arvore);
}