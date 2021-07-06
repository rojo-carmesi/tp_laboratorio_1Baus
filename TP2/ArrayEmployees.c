/*
 * ArrayEmployees.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Martin
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "ArrayEmployees.h"

int menu(int *opcionMenu)
{

	int retornoError = 0;
	int opcion;


	printf("\n*** MENU DE OPCIONES ***\n\n");
	printf("-----------------------------------\n");
	printf("   Ingrese opcion: \n");
	printf("   1 ALTA \n");
	printf("   2 BAJA \n");
	printf("   3 MODIFICAR \n");
	printf("   4 INFORMAR\n");
	printf("   5 SALIR\n");
	printf("-----------------------------------\n");

	if(utn_getNumero(&opcion,"Ingrese la opcion deseada\n","Error, re ingrese la opcion\n",1, 5, 4))
	{
        *opcionMenu = opcion;
		retornoError = 1;
	}

	return retornoError;
}

int initEmployee(Employee* list, int lenght)
{
	int retornoError = -1;

	if(list != NULL && lenght>0)
	{
		for(int i = 0; i<lenght; i++)
		{
			list[i].isEmpty = 1;
		}
		retornoError = 0;
	}

	return retornoError;
}

int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector)
{

    int retornoError = -1;
    int indice;

    if(list!= NULL && lenght > 0 && id > 0 && name != NULL && lastName !=NULL)
    {
        indice = buscarLibre(list, lenght);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
          list[indice].id = id;
          strcpy(list[indice].name,name);
          strcpy(list[indice].lastName,lastName);
          list[indice].salary = salary;
          list[indice].sector = sector;
          list[indice].isEmpty = 0;
          retornoError = 0;
        }
    }

    return retornoError;
}

int mostrarUnEmployee(Employee* lista, int indice)
{
	int retornoError = 0;

	if(lista !=NULL && indice > -1)
	{
		printf("%4d  %10s     %10s             %.2f            %3d\n",lista[indice].id,lista[indice].name,lista[indice].lastName,lista[indice].salary,lista[indice].sector);
		retornoError = 0;
	}

	return retornoError;
}

int mostrarEmployees(Employee* lista, int tamanio)
{
	int retornoError = -1;

	printf(" Id        Nombre         Apellido        Salario             Sector\n");
	printf("-------------------------------------------------------------------------\n");
	if(lista != NULL && tamanio>0)
	{
		for(int i = 0; i<tamanio; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarUnEmployee(lista,i);
			}
		}
		printf("\n");
		retornoError = 0;
	}
	return retornoError;
}

int mostrarInfoSalarios(Employee* lista, int tamanio)
{
	int retorno = -1;

	int contador = 0;
	int contSalarioMayor = 0;
	float acumuladorSalarios = 0;
	float promedioSalario = 0;

	if(lista != NULL && tamanio>0)
	{
		printf("**** INFORME SALARIOS ****\n");
		printf("---------------------------\n");

		for(int i = 0; i<tamanio; i++)
		{
			if(lista[i].isEmpty == 0)
			{

				retorno = 1;
				acumuladorSalarios += lista[i].salary;
				contador++;

			}
		}




		promedioSalario = (float) acumuladorSalarios / contador;

		for(int i = 0; i<tamanio; i++)
		{
			if((promedioSalario < lista[i].salary && lista[i].isEmpty == 0 ))
			{
				contSalarioMayor++;
			}
		}

		printf("El total de los salarios es de: $%.4f\n",acumuladorSalarios);
		printf("El salario promedio de los empleados es de: $%.4f\n",promedioSalario);
		printf("La cantidad de empleados que superan el sueldo promedio es de: %d\n",contSalarioMayor);

	}


	return retorno;
}

int cargarDatosEmployee(char* nombre, char *apellido, float *salario, int *sector, int sizeName,int sizeLastName)
{
	int retornoError = 0;


	if(nombre != NULL && apellido != NULL && salario != NULL && sector != NULL)
	{
		if(utn_getCadena(nombre, sizeName, "Ingrese el nombre del empleado\n","Error, nombre demasiado largo\n" ,3)&&
				utn_getCadena(apellido, sizeLastName, "Ingrese el apellido del empleado\n","Error, apellido demasiado largo\n" ,3)&&
				utn_getNumero(sector, "Ingrese el sector del empleado\n 100 - 200","Error, sector inexistente", 100, 200, 3)&&
				utn_getNumeroFloat(salario,"Ingrese el salario\n","Error, ingrese nuevamente el salario",0, 999999999999999.000, 3))
		{
			retornoError = 1;
		}



	}
	return retornoError;
}

int modificarEmployee(Employee* lista, int tamanio, int indice)
{
	int retornoError = -1;
	int opcionMenu;

	if(lista != NULL && tamanio > 0 && indice > -1)
	{
		do{
			printf("\n**** MODIFICAR DATOS EMPLEADO ***\n1->Nombre\n2->Apellido\n3->Salario\n4->Sector\n5->Salir");
			scanf("%d",&opcionMenu);

			switch(opcionMenu)
			{
			   case 1:
				   printf("Ingrese el nombre: ");
				   fflush(stdin);
				   gets(lista[indice].name);
				   retornoError = 0;
			   break;
			   case 2:
				   printf("Ingrese el apellido: ");
				   fflush(stdin);
				   gets(lista[indice].lastName);
			   break;
			   case 3:
				   printf("Ingrese el salario: ");
				   scanf("%f",&lista[indice].salary);
				   retornoError = 0;
			   break;
			   case 4:
				   printf("Ingrese el sector");
				   scanf("%d",&lista[indice].sector);
				   retornoError = 0;
			   break;
			   case 5:
			   break;
			}
		}while(opcionMenu != 5);
	}
	return retornoError;
}

int removeEmployee(Employee* list, int lenght, int id)
{
	int retorno = 0;
	int indice = 0;

	if(list != NULL && lenght>0 && id>0)
	{
		indice = findEmployeeById(list,lenght,id);

		if(indice != -1)
		{
			list[indice].isEmpty = -1;
			retorno = 1;
		}

	}
	return retorno;
}

int buscarLibre(Employee* lista, int lenght)
{
	int indice = -1;

	for(int i = 0; i<lenght; i++)
	{
		if(lista[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int findEmployeeById(Employee* list, int lenght, int id)
{
	int indice = -1;

	if(list !=NULL && lenght >0 && id<lenght && id>=0)
	{
		for(int i = 0; i<lenght; i++)
		{
			if((list[i].id == id) && (list[i].isEmpty == 0))
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int verificarExistencia(Employee* lista, int lenght)
{
	int retorno = 0;

	if(lista != NULL && lenght > 0)
	{
		for(int i = 0; i<lenght; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				retorno = 1;

			}
		}
	}
	return retorno;
}

int sortEmployees(Employee* list, int lenght, int order)
{
	int retorno = 0;
	Employee auxEmployee;


	if(list != NULL && lenght >0 && ( order == 1 || order == 0))
	{
		retorno = 1;



		for(int i = 0; i<lenght-1; i++)
		{
			for(int j = i+1; j <lenght;j++)
			{

				if((strcmp(list[i].lastName,list[j].lastName)<0 && order== 1) || (strcmp(list[i].lastName,list[j].lastName)>0 && order== 0))
				{
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;


				}else
				{
					if(strcmp(list[i].lastName,list[j].lastName) == 0)
					{

						if((list[i].sector>list[j].sector && order== 0) || (list[i].sector<list[j].sector && order== 1))
						{
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;


						}
					}

				}
			}
		}
	}

	return retorno;
}
