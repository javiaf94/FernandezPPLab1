#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "fechas.h"
#include "servicios.h"

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED
void inicializarTrabajos(eTrabajo trab[], int tamtrab );
void obtenerDescripcionServicio(char descripcion[], int id, eServicio serv[], int tamserv);
void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamserv);
void mostrarTrabajos(eTrabajo trab[], eServicio serv[], int tamserv, int tamtrab);
