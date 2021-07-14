#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagBinario = 1;
    int flagTexto = 1;
    int proximoId = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        menu(&option);


        switch((option))
        {
        case 1:
            if(!flagBinario)
            {
                printf("Usted esta trabajando con el archivo en binario!\n");

            }
            else
            {
                if(!flagTexto)
                {
                    printf("Usted ya abrio el archivo en modo texto!\n");
                }
                else
                {
                    if(!controller_loadFromText("data.csv",listaEmpleados,&proximoId))
                    {
                        flagTexto = 0;
                        printf("Empleados cargados en modo texto\n\n");

                    }
                    else
                    {

                        printf("\nProblemas con la carga de los empleados\n");
                    }
                }
            }
                break;

            case 2:
                if(!flagTexto)
                {
                    printf("Usted esta trabajando con el archivo en texto\n");

                }
                else
                {
                    if(!flagBinario)
                    {
                        printf("Usted ya abrio el archivo en modo binario!\n");
                    }
                    else
                    {

                        if(!controller_loadFromBinary("data.bin",listaEmpleados,&proximoId))
                        {
                            flagBinario = 0;
                            printf("Empleados cargados en modo binario\n\n");

                        }
                        else
                        {
                            printf("\nProblemas con la carga de los empleados\n");
                        }
                    }

                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados,&proximoId))
                {
                    printf("Alta exitosa!\n");
                }
                else
                {
                    printf("Error al cargar el empleado\n");
                }
                break;
            case 4:

                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Usted ha salido de la modificacion de empleados!\n");
                    }
                    else
                    {
                        printf("Error al modificar los empleados\n");
                    }
                }
                else
                {
                    printf("La lista no contiene empleados para modificar\n");
                }

                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados))
                {

                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Baja exitosa!\n");
                    }
                    else
                    {
                        printf("La baja ha sido cancelada por el usuario\n");
                    }

                }
                else
                {
                    printf("No hay empleados en la lista\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados))
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("La lista se encuentra vacia\n");
                }

                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_sortEmployee(listaEmpleados))
                    {
                        printf("Ordenamiento exitoso!\n");
                    }
                    else
                    {
                        printf("Error al ordenar los empleados\n");
                    }
                }
                else
                {
                    printf("No hay empleados en la lista para ordenar\n");
                }

                break;
            case 8:
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    flagTexto = 1;
                    printf("\nEl archivo data.csv se guardo en modo texto\n");
                }
                else
                {
                    printf("Ocurrio un problema al guardar el archivo en modo texto\n");
                }

                break;
            case 9:

                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    flagBinario = 1;
                    printf("\nEl archivo databin.bin se guardo en modo binario\n");
                }
                else
                {
                    printf("Ocurrio un problema al guardar el archivo en modo binario\n");
                }

                break;
            }

            system("pause");

        }
        while(option != 10);

        ll_deleteLinkedList(listaEmpleados);
        free(listaEmpleados);

        return 0;
    }


