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
    int isOver = 0;
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
    }

    while (!isEmpty(memory))
    {
        char s[30];
        setPartFileName(s, "part", partNum);

    	FILE* part = fopen(strcat(s, ".data"), "wb");
    	if (part == NULL) return 1;

    	while (!isFull(frozed) && !isEmpty(memory))
    	{
	    	smallest = getSmallest(memory, frozed);

	    	if (smallest != NULL) saveData(part, smallest);

	    	for (i = 0; i < MEMSIZE; i++)
	    	{
	    		if (memory[i] == smallest)
	    		{
	    			Data* temp = loadData(file);
	    			if (temp != NULL)
	    			{
		    			if (temp->cod < smallest->cod)
		    			{
		    				if (frozed[i] == NULL) frozed[i] = temp;
		    			}
	    			}

	    			memory[i] = temp;
	    		}
	    	}

	    	if (smallest == NULL)
	    	{
	    		if (!isFull(memory))
	    		{
	    			break;
	    		}
	    	}
    	}

    	fclose(part);
        clear(frozed);
        partNum++;
    }

    printf("Processo concluido. Particoes criadas e ordenadas.\n");
    fclose(file);

    return 0;
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
