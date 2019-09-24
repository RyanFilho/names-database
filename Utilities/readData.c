#include "../Headers/utilities.h"

struct diary
{
    char name[30];
};

struct no
{
    Diary diary;
    struct No* prox;
};

struct list
{
    int countList;
    No *head;
};

FILE* OpenDataTxt()
{
    FILE *arq;

    arq = fopen("DataBase/namesDB.txt", "r");

    if(arq != NULL)
        return arq;
}

List* InitializeList()
{
    List* list = (List*) malloc(sizeof(List));

    if(list != NULL)
    {
        list->countList = 0;
        list->head = NULL;
    }

    return list;
}

void AddName(List* list)
{
    Diary diary;
    getchar();
    fflush(stdin);
    printf("Escreva seu nome: ");
    fgets(diary.name, 30, stdin);

    InsertDataList(list, diary);

}

void InsertDataTxtToList(List* list)
{
    FILE* arq;
    char line[30];
    char* result;
    int countLines = 0;

    arq = OpenDataTxt();
    while (!feof(arq))
    {
        result = fgets(line, 100,arq);

        if(result)
        {
            No* node = (No*) malloc(sizeof(No));

            strcpy(node->diary.name, result);
            node->prox = list->head;
            list->head = node;
            list->countList++;
        }
            
    }
}

void InsertDataList(List* list, Diary diary)
{
    No* node = (No*) malloc(sizeof(No));

    strcpy(node->diary.name, diary.name);
    node->prox = list->head;
    list->head = node;
    list->countList++;
}

void ShowListData(List* list)
{   
    int cont = 0;
    No* pointer = list->head;

    while (pointer != NULL)
    {
        printf("------- Name %d -------\n", cont+1);
        printf("Name: %s\n", pointer->diary.name);

        pointer = pointer->prox;
        cont++;
    }
}