#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCAS_H_INCLUDED

void mostrarMarcas(eMarca marc[], int tammarc);
