#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;


#endif // COLORES_H_INCLUDED

void mostrarColores(eColor col[], int tamcol);
