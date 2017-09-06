#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
	char filename[20];
	scanf("%s", filename);

	FILE* file = fopen(filename, "rb");
	if (file == NULL) return 1;
	
	Data* data = NULL;

	while ((data = loadData(file)) != NULL)
	{
		printData(data);
		free(data);
	}

	fclose(file);

	return 0;
}