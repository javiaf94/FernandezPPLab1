#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "autos.h"
#include "servicios.h"
#include "marcas.h"
#include "colores.h"
#include "trabajos.h"

#define TAMAUT 100
#define TAMTRAB 1
#define TAMMARC 5
#define TAMCOL 5
#define TAMSERV 4


char mostrarMenu();

//No llegue a hacer el alta de trabajos. Deje hardcodeado un array de trabajos para poder mostrarlos.


int main()
{

    eColor colores[TAMCOL] = { {5000, "Negro"},  {5001, "Blanco"},  {5002, "Gris"},  {5003, "Rojo"},  {5004, "Azul"} };
    eServicio servicios[TAMSERV] = { {20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600} };
    eMarca marcas[TAMMARC] = { {1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"} };
    eAuto autos[TAMAUT]; // = { {100, "ABC123", 1000, 5000, 1994, 0} , {101, "ACD345", 1001, 5002, 2001, 0} , {102, "CBD324", 1004, 5004, 2002, 0}, {103, "ZXC456", 1004, 5003, 1997, 0}, {104, "CBS203", 1000, 5004, 2001, 0}};
    eTrabajo trabajos[TAMTRAB]= {4000, "ABC123", 20000, {2,7,1994}};
    inicializarAutos(autos, TAMAUT);
    //inicializarTrabajos(trabajos, TAMTRAB);
    int idProxAut = 100;

    int continuar = 1;
    do
    {
        switch(mostrarMenu())
        {
        case 'a':
            system("cls");
            printf("***** MENU ALTA AUTO *****\n\n\n");
            if(altaAuto(autos, TAMAUT, idProxAut, colores, TAMCOL, marcas, TAMMARC))
            {
                printf("\nSe cargo el auto con exito.\n");
                idProxAut++;
            }
            else
            {
                printf("\nNo se completo la carga del auto.\n");
            }
            system("pause");
            break;

        case 'b':
            modificarAuto(autos, marcas, TAMMARC, colores, TAMCOL, TAMAUT);
            system("pause");
            break;

        case 'c':
            system("cls");
            printf("***** MENU BAJA AUTO*****\n\n\n");
            if(bajaAuto(autos, TAMAUT, marcas, TAMMARC, colores, TAMCOL))
            {
                printf("El auto fue borrado con exito.\n");
            }
            else
            {
                printf("No se borro al auto.\n");
            }
            system("pause");
            break;

        case 'd':
            system("cls");
            ordenarAutos(autos, TAMAUT);
            mostrarAutos(autos, TAMAUT, marcas, TAMMARC, colores, TAMCOL);
            system("pause");
            break;
        case 'e':
            system("cls");
            printf("***** MENU LISTAR MARCAS *****\n\n\n");
            mostrarMarcas(marcas, TAMMARC);
            system("pause");
            break;
        case 'f':
            system("cls");
            mostrarColores(colores, TAMCOL);
            system("pause");
            break;
        case 'g':
            system("cls");
            mostrarServicios(servicios, TAMSERV);
            system("pause");
            break;
        case 'h':
            system("cls");

            system("pause");
            break;
        case 'i':
            system("cls");
            printf("***** MENU LISTAR TRABAJOS *****\n\n\n");
            mostrarTrabajos(trabajos, servicios, TAMSERV, TAMTRAB);
            system("pause");
            break;
        case 'j':
            continuar = 0;
            printf("\nDecidio salir.\n");
            system("pause");
            break;
        default:
            printf("Ingrese una opcion valida (letra de opcion en minusculas)\n");
            system("pause");
            break;

        }
    }while(continuar);

    return 0;
}

char mostrarMenu()
{
    char opcion;
    system("cls");
    printf("**** MENU GESTION LAVADERO DE AUTOS****\n\n");
    printf("a. Alta de auto\n\n");
    printf("b. Modificar auto\n\n");
    printf("c. Baja auto\n\n");
    printf("d. Listar autos\n\n");
    printf("e. Listar marcas\n\n");
    printf("f. Listar colores\n\n");
    printf("g. Listar servicios\n\n");
    printf("h. Alta trabajo\n\n");
    printf("i. Listar trabajos\n\n");
    printf("j. Salir\n\n");
    printf("\n Ingrese la letra de la opcion del menu al que quiere acceder: ");
    fflush(stdin);
    scanf("%c" ,&opcion);
    return opcion;
}







