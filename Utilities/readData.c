#include "../Headers/readData.h";

FILE* ReadDataTxt()
{
    FILE *arq;

    arq = fopen("../DataBase/namesDB.txt", "rt");

    if(arq != NULL)
        return arq;
}

void ShowDataTxt(FILE* arq)
{
    char line[100];
    char* result;

    while (!feof(arq))
    {
        result = fgets(line, 100,arq);
        if(result)
            printf("Name: %s\n", line);
    }
    
    fclose(arq);

}