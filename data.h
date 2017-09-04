#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>

typedef struct Data
{
    unsigned int cod;
    char name[50];
} Data;

Data* createData(unsigned int cod, const char* name);
Data* loadData(FILE* file);
void saveData(FILE* file, Data* data);
void printData(Data* data);

#endif // DATA_H_INCLUDED
