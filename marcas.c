#include <stdio.h>
#include <stdlib.h>
#include "marcas.h"


void mostrarMarcas(eMarca marc[], int tammarc)
{
    printf("ID            DESCRIPCION\n\n");
    for(int i=0; i<tammarc; i++)
    {
        printf("%04d %20s\n", marc[i].id, marc[i].descripcion);
    }
}
