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

Data* loadData(const char* filepath)
{
    FILE* file = fopen(filepath, "rb");
    if (file != NULL)
    {
        Data* data = (Data*)malloc(sizeof(Data));
        if (data != NULL)
        {
            fread(data, sizeof(Data), 1, file);
        }

        fclose(file);
        return data;
    }

    return NULL;
}

void saveData(const char* filepath, Data* data)
{
    FILE* file = fopen(filepath, "wb");
    if (file != NULL)
    {
        if (data != NULL)
        {
            fwrite(data, sizeof(Data), 1, file);
        }

        fclose(file);
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
}
