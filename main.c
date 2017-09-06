#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#define MEMSIZE 7

int isFull(Data* data[]);
int isEmpty(Data* data[]);
void clear(Data* data[]);
void setPartFileName(char buffer[], const char* filename, int n);
Data* getSmallest(Data* data[], Data* frozed[]);

int main()
{
	FILE* file = fopen("registers.data", "rb");
	if (file == NULL) return 1;

	int i;
    int partNum = 1;
    Data* memory[MEMSIZE];
    Data* frozed[MEMSIZE];
    Data* smallest = NULL;

    for (i = 0; i < MEMSIZE; i++) 
    {
    	memory[i] = NULL;
    	frozed[i] = NULL;
    }

    for (i = 0; i < MEMSIZE; i++)
    {
    	memory[i] = loadData(file);
        //printf("debug\n");
    }

    while (!isEmpty(memory))
    {
        //printf("debug\n"); 2 vezes
        char s[30];
        setPartFileName(s, "part", partNum);

    	FILE* part = fopen(strcat(s, ".data"), "wb");
    	if (part == NULL) return 1;

    	while (!isFull(frozed))
    	{
            //printf("debug%d\n", partNum);
	    	smallest = getSmallest(memory, frozed);
            //if (partNum >= 2) printf("debug\n");

	    	saveData(part, smallest);

	    	for (i = 0; i < MEMSIZE; i++)
	    	{
	    		if (memory[i] == smallest)
	    		{
                    if (partNum >= 2) printf("debug%d\n", i);
	    			Data* temp = loadData(file);
	    			if (temp->cod < smallest->cod)
	    			{
	    				if (frozed[i] == NULL) frozed[i] = temp;
	    			}

	    			memory[i] = temp;
                    break;
	    		}
	    	}
    	}

    	fclose(part);
        clear(frozed);
        partNum++;
    }

    printf("Acho que deu tudo certo, brou. Confere ae.\n");

    return 0;
    //printf("debug\n");
}

int isFull(Data* data[])
{
	int i;
	for (i = 0; i < MEMSIZE; i++) 
    {
    	if (data[i] == NULL) return 0;
    }

    return 1;
}

int isEmpty(Data* data[])
{
	int i;
	for (i = 0; i < MEMSIZE; i++) 
    {
    	if (data[i] != NULL) return 0;
    }

    return 1;
}

void clear(Data* data[])
{
    int i;
    for (i = 0; i < MEMSIZE; i++)
    {
        data[i] = NULL;
    }
}

void setPartFileName(char buffer[], const char* filename, int n)
{
    char aux[10];
    snprintf(aux, 10, "%d", n);

    strcpy(buffer, filename);
    strcat(buffer, aux);
}

Data* getSmallest(Data* data[], Data* frozed[])
{
	int i;
	Data* smallest = NULL;
	for (i = 0; i < MEMSIZE; i++)
	{
		if (data[i] == frozed[i] || data[i] == NULL) continue;

		if (smallest == NULL) 
			smallest = data[i];

		else if (smallest->cod > data[i]->cod)
		{
			smallest = data[i];
		}
	}

	return smallest;
}

/*Data* jubileu = createData(2492385, "Jubileu");
    Data* jubara = createData(877680, "Seu Jubara");
    Data* fulano = createData(76247, "Fulaninho de Souza Delgado");

    FILE* fileWrite = fopen("registers.data", "wb");
    if (fileWrite == NULL) return 1;

    saveData(fileWrite, jubileu);
    saveData(fileWrite, jubara);
    saveData(fileWrite, fulano);

    fclose(fileWrite);

    free(jubileu);
    free(jubara);
    free(fulano);

    FILE* fileRead = fopen("registers.data", "rb");
    if (fileRead == NULL) return 1;

    Data* d1 = loadData(fileRead);

    fclose(fileRead);

    printData(d1);*/

    /*FILE* file = fopen("registers.data", "wb");
    if (file == NULL) return 1;

    printf("Start!\n");

    int i;
    for (i = 0; i < 20; i++)
    {
        unsigned int cod = rand() % 101;
        char name[50];

        printf("i = %d\n", i);
        scanf("%s", name);

        Data* data = createData(cod, name);
        saveData(file, data);
        printData(data);
        free(data);
    }

    fclose(file);*/

    /*FILE* file = fopen("registers.data", "rb");
    if (file == NULL) return 1;

    Data* data = NULL;
    while ((data = loadData(file)) != NULL)
    {
        printData(data);
        free(data);
        data = NULL;
    }

    fclose(file);*/
