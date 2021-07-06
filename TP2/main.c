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

int main() {


	Employee EmployeesList[TAMANIO];

	char nombre[NOMBRE];
	char apellido[APELLIDO];
	float salario;
	int sector;
	int opcionesMenu;
	int auxMenu;
	int bajaMenu;
	int confirmarBaja;
	int id = 0;
	int idBuscado;
	int auxId;

	initEmployee(EmployeesList,TAMANIO);

	 do{

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
		 		   printf("\nAlta exitosa\n");
		 		 }else
		 		 {
		 			 printf("\nError el empleado no pudo ser cargado");
		 		 }
		 		 system("pause");
		 	 break;
		 	 case 2:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
		 		 {
		 			do{

		 				printf("***MENU DE BAJAS***\n");

		 				mostrarEmployees(EmployeesList, TAMANIO);
		 				utn_getNumero(&bajaMenu, "Ingrese la opcion deseada\n 1 Dar de baja un empleado\n 2 Salir\n ","Opcion no valida\n",1, 2, 3);

		 				if(bajaMenu == 1)
		 				{
		 					if(utn_getNumero(&auxId,"Ingrese el ID del empleado\n","Error, ID inexistente\n",1, 1000, 3))
		 					{
		 						confirmarBaja = removeEmployee(EmployeesList, TAMANIO, auxId);

		 						if(confirmarBaja)
		 						{
		 							printf("Baja exitosa!\n");
		 						}else
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

		 			}while(bajaMenu != 2);

		 		 }else
		 		 {
		 			 printf("No es posible realizar  bajas ya que no hay ningun empleado\n");
		 		 }
		 		system("pause");
		 	 break;
		 	 case 3:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
		 		 {
		 			 mostrarEmployees(EmployeesList,TAMANIO);
		 			 printf("Ingrese el id del empleado que desea modificar\n");
		 			 scanf("%d",&idBuscado);
		 			 auxId = findEmployeeById(EmployeesList,TAMANIO,idBuscado);

		 			 if(modificarEmployee(EmployeesList,TAMANIO,auxId)==0)
		 			 {
		 				 printf("El empleado fue modificado con exito\n");
		 			 }else
		 			 {
		 				 printf("Error en la modificacion\n");
		 			 }

		 		 }else
		 		 {
		 			 printf("No hay empleados en la lista\n");
		 		 }
		 		system("pause");
		 	 break;
		 	 case 4:
		 		 if(verificarExistencia(EmployeesList,TAMANIO))
		 		 {

		 			if(utn_getNumero(&auxMenu,"Ingrese el criterio por el cual desea ordenar\n0-Ascendente\n1-Descendente\n","Error, ingrese 0 o 1 para el criterio\n",0,1,3))
		 			{
		 				if(!auxMenu)
		 				{
		 					sortEmployees(EmployeesList, TAMANIO, ASCENDENTE);
		 				}else
		 				{
		 					sortEmployees(EmployeesList, TAMANIO, DESCENDENTE);
		 				}

		 				mostrarEmployees(EmployeesList,TAMANIO);
		 				mostrarInfoSalarios(EmployeesList,TAMANIO);
		 			}else
		 			{
		 				printf("Error al mostrar los empleados\n");
		 			}

		 			 system("pause");

		 		 }else
		 		 {
		 			 printf("No hay empleados para informar\n");
		 		 }

		 		system("pause");
		 	 break;
		 }

	    }while(opcionesMenu != 5);

	return 0;
}
