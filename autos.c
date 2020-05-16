#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "autos.h"
#include "colores.h"
#include "marcas.h"

void inicializarAutos(eAuto aut[], int tamaut )
{
    for(int i=0; i<tamaut; i++)
    {
        aut[i].isEmpty = 1;
    }
}


void obtenerDescripcionColor(char descripcion[], int id, eColor col[], int tamcol)
{
    for(int i =0; i<tamcol; i++)
    {
        if(id==col[i].id)
        {
            strcpy(descripcion, col[i].nombreColor);
        }
    }

}

void obtenerDescripcionMarca(char descripcion[], int id, eMarca marc[], int tammarc)
{
    for(int i =0; i<tammarc; i++)
    {
        if(id==marc[i].id)
        {
            strcpy(descripcion, marc[i].descripcion);
        }
    }
}


void ordenarAutos(eAuto aut[], int tamaut)
{
    eAuto auxAut;
    for (int i=0; i<tamaut-1;i++)
    {
        for(int j=i+1; j<tamaut; j++)
        {
            if (aut[i].idMarca > aut[j].idMarca)
            {
                auxAut = aut[i];
                aut[i] = aut[j];
                aut[j] = auxAut;
            }
        }
    }
    for (int i=0; i<tamaut-1;i++)
    {
        for(int j=i+1; j<tamaut; j++)
        {
            if (strcmp(aut[i].patente , aut[j].patente) >= 0 && aut[i].id == aut[j].id)
            {
                auxAut = aut[i];
                aut[i] = aut[j];
                aut[j] = auxAut;
            }
        }
    }
}


void mostrarAuto(eAuto aut, eMarca marc[], int tammarc, eColor col[], int tamcol)
{
    char descMarca[20];
    char descColor[20];
    obtenerDescripcionColor(descColor, aut.idColor, col, tamcol);
    obtenerDescripcionMarca(descMarca, aut.idMarca, marc, tammarc);
    printf("%3d      %6s %20s   %15s        %4d\n", aut.id, aut.patente, descMarca, descColor, aut.modelo);
}

void mostrarAutos(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol)
{
    printf("****** LISTA DE AUTOS ******\n\n\n");
    printf("ID      PATENTE                MARCA             COLOR      MODELO\n\n");
    int flag=0;
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty == 0)
        {
            mostrarAuto(aut[i], marc, tammarc, col, tamcol);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("No hay autos ingresados\n");
    }
}

int buscarLibre(eAuto aut[], int tamaut)
{
    int indice = -1;
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].isEmpty)
        {
            indice = i;
        }
    }
    return indice;
}


int altaAuto(eAuto aut[], int tamaut, int id, eColor col[] , int tamcol, eMarca marc[], int tammarc)
{
    int indice = buscarLibre(aut, tamaut);
    int exito = 0;
    if(indice<0)
    {
        printf("No hay lugares libres\n");
    }
    else
    {
        eAuto auxAut;
        auxAut.id = id;

        getString(auxAut.patente, "Ingrese patente: ", 7);

        mostrarMarcas(marc, tammarc);
        getInt(&auxAut.idMarca, "\nIngrese el ID de la marca del auto: ", "\nError, ingrese un numero valido.\n", 1000, 1004);

        mostrarColores(col, tamcol);
        getInt(&auxAut.idColor, "\nIngrese el ID del color del auto: " , "\nError, ingrese un numero valido.\n", 5000, 5004 );

        printf("\nIngrese modelo (anio): ");
        fflush(stdin);
        scanf("%d", &auxAut.modelo);

        printf("\n\n");
        printf("ID      PATENTE                MARCA             COLOR      MODELO\n\n");
        mostrarAuto(auxAut, marc, tammarc, col, tamcol);
        if(getYesOrNo("\nConfirma que desea cargar el siguiente auto?(s/n)\n", "Error, ingrese una opcion valida.\n"))
        {
            auxAut.isEmpty=0;
            aut[indice] = auxAut;
            exito = 1;
        }
    }
    return exito;
}

int existeAuto(eAuto aut[], int id, int tamaut)
{
    int indice = -1;
    for(int i=0; i<tamaut; i++)
    {
        if(aut[i].id == id && aut[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuModificar()
{
    int opcion;
    printf("***** MENU MODIFICACION AUTOS *****\n\n\n");
    printf("1. Modificar color\n\n");
    printf("2. Modificar modelo\n\n");
    printf("3. Salir de menu modificar\n\n");
    getInt(&opcion, "\n Ingrese el numero de opcion del menu al que desea ingresar: ", "\nError, ingrese un numero de opcion valido", 1, 3);
    return opcion;
}

void modificarAuto(eAuto aut[], eMarca marc[], int tammarc, eColor col[], int tamcol, int tamaut)
{
    system("cls");
    printf("***** MENU MODIFICACION AUTOS *****\n\n\n");
    int id;
    printf("ingrese el ID del auto que desea modificar: ");
    scanf("%d", &id);
    int indice = existeAuto(aut, id, tamaut);
    if (indice == -1)
    {
        printf("\n\nEl auto no existe \n");
    }
    else
    {
        eAuto auxAut;
        printf("\nAuto encontrado.\n");
        printf("ID      PATENTE                MARCA             COLOR      MODELO\n\n");
        mostrarAuto(aut[indice], marc, tammarc, col, tamcol);
        system("pause");
        system("cls");
        switch(menuModificar())
        {
            case 1:
                system("cls");
                printf("***** MENU MODIFICACION AUTOS *****\n\n\n");
                printf("*** Modificar color ***\n\n");
                mostrarColores(col, tamcol);
                getInt(&auxAut.idColor, "\nIngrese el codigo del color al que desea cambiar: ", "\nError, ingrese un codigo valido.\n", 5000, 5004);
                printf("\n\nID      PATENTE                MARCA             COLOR      MODELO\n\n");
                mostrarAuto(aut[indice], marc, tammarc, col, tamcol);
                printf("\nSeguro que desea modificar el color del auto?");
                if(getYesOrNo("Ingrese s/n.", "\nError, ingrese una respuesta valida.\n"))
                {
                    aut[indice].idColor = auxAut.idColor;
                    printf("El color se cambio correctamente.\n");
                }
                else
                {
                    printf("No se modifico el color.\n");
                }
                break;

            case 2:
                system("cls");
                printf("***** MENU MODIFICACION AUTOS *****\n\n\n");
                printf("*** Modificar modelo ***\n\n");
                printf("Ingrese el modelo por el cual desea modificar: ");
                fflush(stdin);
                scanf("%d", &auxAut.modelo);
                printf("ID      PATENTE                MARCA             COLOR      MODELO\n\n");
                mostrarAuto(aut[indice], marc, tammarc, col, tamcol);
                printf("\nSeguro que desea modificar el modelo del auto por %d ? ", auxAut.modelo);
                if(getYesOrNo("Ingrese s/n.", "\nError, ingrese una respuesta valida.\n"))
                {
                    aut[indice].modelo = auxAut.modelo;
                    printf("El modelo se cambio correctamente.\n");
                }
                else
                {
                    printf("No se modifico el modelo.\n");
                }
                break;
        }
    }
}

int bajaAuto(eAuto aut[], int tamaut, eMarca marc[], int tammarc, eColor col[], int tamcol)
{
    int id;
    int exito = 0;
    printf("ingrese el ID que desea borrar: ");
    scanf("%d", &id);
    int indice = existeAuto(aut, id, tamaut);
    if (indice == -1)
    {
        printf("El auto no existe \n");
    }
    else
    {
            printf("ID      PATENTE                MARCA             COLOR      MODELO\n\n");
            mostrarAuto(aut[indice], marc, tammarc, col, tamcol);
        if (getYesOrNo("\nEsta seguro que desea eliminar al siguiente auto?(s/n)", "\nError, ingrese una opcion valida"))
        {
            aut[indice].isEmpty = 1;
            exito = 1;
        }
    }
    return exito;
}
