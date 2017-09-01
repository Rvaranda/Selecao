#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct Data
{
    unsigned int cod;
    char name[15];
} Data;

Data* createData(unsigned int cod, const char* name);
Data* loadData(const char* filepath);
void saveData(const char* filepath, Data* data);
void printData(Data* data);

#endif // DATA_H_INCLUDED
