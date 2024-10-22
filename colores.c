#include <stdio.h>
#include <stdlib.h>
#include "colores.h"

void mostrarColores(eColor col[], int tamcol)
{
    printf("***** MENU LISTAR COLORES *****\n\n\n");
    printf("ID            DESCRIPCION\n\n");
    for(int i=0; i<tamcol; i++)
    {
        printf("%04d %20s\n", col[i].id, col[i].nombreColor);
    }
}
