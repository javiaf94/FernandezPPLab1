#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "autos.h"
#include "colores.h"
#include "marcas.h"
#include "fechas.h"
#include "trabajos.h"

void obtenerDescripcionServicio(char descripcion[], int id, eServicio serv[], int tamserv)
{
    for(int i =0; i<tamserv; i++)
    {
        if(id == serv[i].id)
        {
            strcpy(descripcion, serv[i].descripcion);
        }
    }

}

void inicializarTrabajos(eTrabajo trab[], int tamtrab )
{
    for(int i=0; i<tamtrab; i++)
    {
        trab[i].isEmpty = 1;
    }
}

void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamserv)
{
    char descripcion[20];
    obtenerDescripcionServicio(descripcion, trab.idServicio, serv, tamserv);
    printf("%4d     %6s          %15s      %02d/%02d/%4d\n", trab.id, trab.patente, descripcion, trab.fecha.dia, trab.fecha.mes, trab.fecha.anio);

}

void mostrarTrabajos(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab)
{
    printf("****** LISTA DE TRABAJOS ******\n\n\n");
    printf("ID      PATENTE                 SERVICIO          FECHA\n\n");
    int flag=0;
    for(int i=0; i<tamtrab; i++)
    {
        if(trab[i].isEmpty == 0)
        {
            mostrarTrabajo(trab[i], serv, tamserv);
            flag=1;
        }

    }
    if (flag==0)
    {
        printf("No hay trabajos ingresados\n");
    }
}

