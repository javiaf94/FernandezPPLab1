#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

void mostrarServicios(eServicio serv[], int tamserv);
