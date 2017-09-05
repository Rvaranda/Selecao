#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Data* createData(unsigned int cod, const char* name)
{
    Data* data = (Data*)malloc(sizeof(Data));
    if (data != NULL)
    {
        data->cod = cod;
        strcpy(data->name, name);
    }

    return data;
}

Data* loadData(FILE* file)
{

    Data* data = (Data*)malloc(sizeof(Data));

    if (data != NULL)
    {
        fread(&data->cod, sizeof(unsigned int), 1, file);
        fread(data->name, sizeof(char), sizeof(data->name), file);

        if (feof(file)) return NULL;
    }

    return data;
}

void saveData(FILE* file, Data* data)
{
    if (data != NULL)
    {
        fwrite(&data->cod, sizeof(unsigned int), 1, file);
        fwrite(data->name, sizeof(char), sizeof(data->name), file);
    }
}

void printData(Data* data)
{
    if (data != NULL)
    {
        printf("Code: %u\n", data->cod);
        printf("Name: %s\n", data->name);
        printf("--------------------\n");
    }
    else printf("NULL Data\n");
}
