#include "../Headers/utilities.h"

FILE* OpenDataTxt()
{
    FILE *arq;

    arq = fopen("../DataBase/namesDB.txt", "rt");

    if(arq != NULL)
        return arq;
}

int CountDataTxt(FILE* arq)
{
    char line[30];
    char* result;
    int countLines = 0;

    while (!feof(arq))
    {
        result = fgets(line, 100,arq);

        if(result)
            countLines++;
    }
    
    fclose(arq);

    return countLines;
} 

// char* ReturnDataTxt(FILE* arq)
// {
//     char line[30];
//     char* result;
//     int countIndex = 0;

//     int countList = CountDataTxt(arq);
//     char* arrayOfNames[countList];

//     while(!feof(arq))
//     {
//         result = fgets(line, 30, arq);

//         if(result)
//         {
//             arrayOfNames[countIndex] = line;
//         }

//         countIndex++;
//     }

//     return arrayOfNames;
// }

void ShowDataTxt(FILE* arq)
{
    char line[30];
    char* result;

    while (!feof(arq))
    {
        result = fgets(line, 100,arq);

        if(result)
            printf("Name: %s\n", line);
    }
    
    fclose(arq);

}