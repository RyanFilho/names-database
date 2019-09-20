#include "../Headers/utilities.h"

FILE* OpenDataTxt()
{
    FILE *arq;

    arq = fopen("DataBase/namesDB.txt", "r");

    if(arq != NULL)
        return arq;
}

int CountDataTxt()
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
            countLines++;
    }

    fclose(arq);
    return countLines;
} 

char** ReturnDataTxt()
{
    FILE* arq;
    char line[30];
    char* result;
    int countIndex = 0;

    char** arrayOfNames = malloc(2000 * sizeof(char*));

    arq = OpenDataTxt();
    while (!feof(arq))
    {
        result = fgets(line, 30, arq);

        if(result)
        {
            arrayOfNames[countIndex] = malloc(40 * sizeof(char));
            strcpy(arrayOfNames[countIndex], result);
            //printf("%d\n", countIndex);
            countIndex++;
        }
    }

    return arrayOfNames;
    
}

void ShowDataTxt()
{
    FILE* arq;
    char line[30];
    char* result;

    arq = OpenDataTxt();
    while (!feof(arq))
    {
        result = fgets(line, 100,arq);

        if(result)
            printf("Name: %s\n", line);
    }
    
    fclose(arq);
}