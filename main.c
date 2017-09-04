#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main()
{
    Data* jubileu = createData(2492385, "Jubileu");
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

    printData(d1);

    return 0;
}
