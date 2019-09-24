#include "../Headers/utilities.h"

void menu()
{   
    List *list;
    int option;

    list = InitializeList();

    do
    {
        printf("----- MENU -----\n");
        printf("(1) Carregar Dados (TXT)\n");
        printf("(2) Listar Nomes em Ordem Alfabetica (Nao)\n");
        printf("(3) Listar Nomes por Substring (Nao)\n");
        printf("(4) Inserir Novo Nome (Memoria)\n");
        printf("(5) Remover Nome (Memoria) (Nao)\n");
        printf("(6) - (Nao)\n");
        printf("(7) - (Nao)\n");
        printf("(8) Salvar Conteudo em TXT (Nao)\n");
        printf("(9) Tamanho da Lista\n");
        printf("(0) Sair\n");
        printf("----------------\n");
        printf("Digite uma Opção: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                system("clear");
                printf("------- Carregando Dados -------\n");
                InsertDataTxtToList(list);
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 2:
                system("clear");
                printf("----- Listar por Ordem Alfabetica -----\n");
                ShowListData(list);
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 3:
                // system("clear");
                // printf("----- Calculo IMC -----\n");
                // calcularIMC(lista);
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
                break;
            case 4:
                system("clear");
                printf("----- Cadastro -----\n");
                AddName(list);
                printf("Done...\n");
                //getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            case 5:
                // system("clear");
                // printf("----- Tamanho Lista -----\n");
                // printf("Tamanho lista de pacientes: %d\n", lista->qtd);
                // printf("-------------------------\n");
                // getchar();
                // printf("Pressione qualquer tecla para voltar...");
                // getchar();
                // system("clear");
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
            case 9:
                system("clear");
                printf("----- Tamanho Lista -----\n");
                printf("Tamanho lista de nomes: %d\n", list->countList);
                printf("Done...\n");
                getchar();
                printf("Pressione qualquer tecla para voltar...");
                getchar();
                system("clear");
                break;
            default:
                //liberaLista(lista);
                break;
        }

    } while (option != 0);
    
}