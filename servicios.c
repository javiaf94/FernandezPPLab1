#include <stdio.h>
#include <stdlib.h>
#include "servicios.h"

void mostrarServicios(eServicio serv[], int tamserv)
{
    printf("***** MENU LISTAR SERVICIOS *****\n\n\n");
    printf("ID             DESCRIPCION\n\n");
    for(int i=0; i<tamserv; i++)
    {
        printf("%05d %20s\n", serv[i].id, serv[i].descripcion);
    }
}
