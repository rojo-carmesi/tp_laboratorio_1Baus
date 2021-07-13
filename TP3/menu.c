#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"
int menu(int*pOpcionMenu)
{
    int error = 1;
    int opcion;

    if(pOpcionMenu != NULL)
    {

        system("cls");
        do
        {
            printf("*** Menu de Opciones ***\n\n");
            printf("1 Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
            printf("2 Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
            printf("3 Alta de empleado\n");
            printf("4 Modificar datos de empleado\n");
            printf("5 Baja de empleado\n");
            printf("6 Listar empleados\n");
            printf("7 Ordenar empleados\n");
            printf("8 Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
            printf("9 Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
            printf("10 Finalizar programa\n");

            if(!utn_getNumero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",0,10,4))
            {
                error = 0;
            }

        }
        while(opcion<1 || opcion>10);
        *pOpcionMenu = opcion;
    }
    return error;
}
