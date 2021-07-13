/*
 ============================================================================
 Name        : TP2.c
 Author      : Martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAMANIO 1000
#define NOMBRE 51
#define APELLIDO 51
#define ASCENDENTE 1
#define DESCENDENTE 0

int main()
{


    Employee EmployeesList[TAMANIO];

    char nombre[NOMBRE];
    char apellido[APELLIDO];
    float salario;
    int sector;
    int opcionesMenu;
    int auxMenu;
    int bajaMenu;
    int auxmodif;
    int confirmarBaja;
    int id = 0;
    int idBuscado;
    int auxId;

    initEmployee(EmployeesList,TAMANIO);

    do
    {

        auxMenu = menu(&opcionesMenu);

        while(!auxMenu)
        {
            auxMenu = menu(&opcionesMenu);

        }

        switch(opcionesMenu)
        {
        case 1:

            if(cargarDatosEmployee(nombre,apellido,&salario,&sector,NOMBRE,APELLIDO))
            {
                id++;
                addEmployee(EmployeesList,TAMANIO,id,nombre,apellido,salario,sector);
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Error el empleado no pudo ser cargado\n");
            }

            break;
        case 2:
            if(verificarExistencia(EmployeesList,TAMANIO))
            {
                mostrarEmployees(EmployeesList,TAMANIO);
                printf("Ingrese el id del empleado que desea modificar\n");
                scanf("%d",&idBuscado);
                auxId = findEmployeeById(EmployeesList,TAMANIO,idBuscado);

                auxmodif = modificarEmployee(EmployeesList,TAMANIO,auxId);
                if(!auxmodif)
                {
                    printf("El empleado fue modificado con exito\n");
                }
                else
                {
                    if(auxmodif == -1)
                    {
                        printf("Ocurrio un error al modificar el empleado\n");
                    }
                }
            }
            else
            {
                printf("No hay empleados en la lista\n");
            }

            break;
        case 3:

            if(verificarExistencia(EmployeesList,TAMANIO))
            {
                do
                {

                    printf("***MENU DE BAJAS***\n");

                    mostrarEmployees(EmployeesList, TAMANIO);
                    if(!utn_getNumero(&bajaMenu, "Ingrese la opcion deseada\n 1 Dar de baja un empleado\n 2 Salir\n ","Opcion no valida\n",1, 2, 3))
                    {
                        if(bajaMenu == 1)
                        {
                            if(!utn_getNumero(&auxId,"Ingrese el ID del empleado\n","Error, ID inexistente\n",1, 1000, 3))
                            {
                                confirmarBaja = removeEmployee(EmployeesList, TAMANIO, auxId);

                                if(confirmarBaja)
                                {
                                    printf("Baja exitosa!\n");
                                }
                                else
                                {
                                    printf("ID inexistente\n");
                                }

                                if(!verificarExistencia(EmployeesList,TAMANIO))
                                {
                                    printf("No hay mas empleados para dar de baja!\n");
                                    bajaMenu = 2;
                                }

                            }
                        }
                    }


                }
                while(bajaMenu != 2);

            }
            else
            {
                printf("No es posible realizar  bajas ya que no hay ningun empleado\n");
            }
            break;
        case 4:
            if(verificarExistencia(EmployeesList,TAMANIO))
            {

                if(!utn_getNumero(&auxMenu,"Ingrese el criterio por el cual desea ordenar\n0-Ascendente\n1-Descendente\n","Error, ingrese 0 o 1 para el criterio\n",0,1,3))
                {
                    if(!auxMenu)
                    {
                        sortEmployees(EmployeesList, TAMANIO, ASCENDENTE);
                    }
                    else
                    {
                        sortEmployees(EmployeesList, TAMANIO, DESCENDENTE);
                    }

                    mostrarEmployees(EmployeesList,TAMANIO);
                    mostrarInfoSalarios(EmployeesList,TAMANIO);
                }
                else
                {
                    printf("Error al mostrar los empleados\n");
                }
            }
            else
            {
                printf("No hay empleados para informar\n");
            }
            break;

        case 5:
            printf("Usted ha salido del programa\n");
            break;
        }
        system("pause");
    }
    while(opcionesMenu != 5);

    return 0;
}
