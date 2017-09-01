#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int main()
{
    Data* jubileu = createData(2492385, "Jubileu");
    Data* jubara = createData(877680, "Seu Jubara");
    //Data* fulano = createData(76247, "Fulaninho de Souza Delgado");

    saveData("registers.data", jubileu);
    saveData("registers.data", jubara);
    //saveData("registers.data", fulano);

    free(jubileu);
    free(jubara);
    //free(fulano);

    Data* d1 = loadData("registers.data");

    printData(d1);

    return 0;
}
