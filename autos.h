#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "colores.h"
#include "marcas.h"

typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

#endif // AUTOS_H_INCLUDED

void inicializarAutos(eAuto aut[], int tamaut);
void obtenerDescripcionColor(char descripcion[], int id, eColor col[], int tamcol);
void obtenerDescripcionMarca(char descripcion[], int id, eMarca marc[], int tammarc);
void ordenarAutos(eAuto aut[], int tamaut);
void mostrarAuto(eAuto aut, eMarca marc[], int tammarc, eColor col[], int tamcol);
void mostrarAutos(eAuto aut[] , int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol);
int buscarLibre(eAuto aut[], int tamaut);
int altaAuto(eAuto aut[], int tamaut, int id, eColor col[] , int tamcol, eMarca marc[], int tammarc);
int existeAuto(eAuto aut[], int id, int tamaut);
int menuModificar();
void modificarAuto(eAuto aut[], eMarca marc[], int tammarc, eColor col[], int tamcol, int tamaut);
int bajaAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol);
