#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list List;
typedef struct no No;
typedef struct diary Diary;

FILE* OpenDataTxt();
List* InitializeList();
void AddName(List* list);
void InsertDataList(List* list, Diary diary);
void InsertDataTxtToList(List* list);
void ShowListData(List* list);
void menu();