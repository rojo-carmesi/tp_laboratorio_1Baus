#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* f;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL && !parser_EmployeeFromText(f,pArrayListEmployee))
        {
            printf("\nArchivo cargado exitosamente\n");
            retorno = 0;

        }
        else
        {
            printf("\nError al cargar el archivo\n");
        }
    }

    fclose(f);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    FILE* f;

    if(path !=NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"rb");

        if(f != NULL && !parser_EmployeeFromBinary(f,pArrayListEmployee))
        {
            error = 0;
        }

        fclose(f);
    }

    return error;
}

/** \brief Controla que el alta de los empleados sea exitosa
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    Employee* nuevoEmpleado;
    nuevoEmpleado = NULL;

    if(pArrayListEmployee != NULL)
    {

        if(utn_getCadena(nombre,51,"Ingrese el nombre del empleado\n","Error, re ingres el nombre\n",5)&&
                utn_getNumeroInt(&horasTrabajadas,"Ingrese las horas que trabajo el empleado\n","Error, re ingrese las horas\n",0,100,4)&&
                utn_getNumeroInt(&sueldo,"Ingrese el sueldo del empleado\n","Error, re ingrese las horas\n",1,99999,4))
        {
            error = 0;
            id = employee_generarId();
            nuevoEmpleado = employee_newParametrosInt(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListEmployee,nuevoEmpleado);
        }

    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    char nombre[NOMBRE];
    int horasTrabajadas;
    int sueldo;
    int opcionMenu;
    int indice;

    Employee* auxiliarEmpleado;
    auxiliarEmpleado = NULL;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumeroInt(&id,"\nIngrese la id del Empleado que desea modificar\n",
                            "\nError, ingrese un numero valido\n",0,5000,4))
        {
            indice = employee_buscarPorId(pArrayListEmployee,id);

            if(indice == -1)
            {
                printf("No hay empleados con esa ID\n");

            }
            else
            {
                auxiliarEmpleado = ll_get(pArrayListEmployee,indice);

                printf("\n EMPLEADO A MODIFICAR\n\n");

                printf("\nID     NOMBRE      HORAS TRABAJADAS      SUELDO\n");
                printf("-------------------------------------------------\n\n");
                mostrarEmpleado(auxiliarEmpleado);

                do
                {
                    if(utn_getNumeroInt(&opcionMenu,
                                        "\n*** MENU DE MODIFICACION ***\nIngrese la opcion para modificar el campo\n1 Nombre\n2 Horas Trabajadas\n3 Sueldo\n4 Salir"
                                        ,"Error,ingrese una opcion valida",0,4,4))
                    {
                        switch(opcionMenu)
                        {
                        case 1:
                            if(utn_getCadena(nombre,NOMBRE,"\nIngrese el nuevo nombre\n","Error, vuelva a ingresar el nombre\n",
                                             4))
                            {
                                if(!employee_setNombre(auxiliarEmpleado,nombre))
                                {
                                    printf("\nEl nombre se modifico con exito\n");
                                    ll_set(pArrayListEmployee,indice,auxiliarEmpleado);
                                }
                            }

                            break;
                        case 2:
                            if(utn_getNumeroInt(&horasTrabajadas,"\nIngrese las horas trabajadas\n","Error, ingrese un numero valido\n",
                                                0,HORAS,4))
                            {
                                if(!employee_setHorasTrabajadas(auxiliarEmpleado,horasTrabajadas))
                                {
                                    printf("\n Las horas se han modificado con exito\n");
                                    ll_set(pArrayListEmployee,indice,auxiliarEmpleado);

                                }
                            }
                            break;
                        case 3:
                            if(utn_getNumeroInt(&sueldo,"\nIngrese el nuevo sueldo\n","Error, ingrese un numero valido\n",
                                                0,SUELDO,4))
                            {
                                if(!employee_setSueldo(auxiliarEmpleado,sueldo))
                                {
                                    printf("\nEl sueldo se modifico con exito\n");
                                    ll_set(pArrayListEmployee,indice,auxiliarEmpleado);

                                }
                            }

                            break;
                        case 4:

                            retorno = 1;
                            break;
                        }
                    }

                }
                while(opcionMenu != 4);

            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int confirmaBaja = 0;
    int indice;

    Employee* auxiliarEmpleado;
    auxiliarEmpleado = NULL;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumeroInt(&id,"\nIngrese la id del Empleado que desea dar de baja\n",
                            "\nError, ingrese un numero valido\n",0,5000,4))
        {
            indice = employee_buscarPorId(pArrayListEmployee,id);

            if(indice == -1)
            {
                printf("No hay empleados con esa ID\n");

            }
            else
            {

                auxiliarEmpleado = ll_get(pArrayListEmployee,indice);

                printf("\n EMPLEADO A DAR DE BAJA\n\n");

                printf("\nID     NOMBRE      HORAS TRABAJADAS      SUELDO\n");
                printf("-------------------------------------------------\n\n");
                mostrarEmpleado(auxiliarEmpleado);

                    if(utn_getNumeroInt(&confirmaBaja,"Confirma la baja del empleado?\n1-Si\n2-No\n","Error, opcion incorrecta\n",1,2,4))
                    {
                        if(confirmaBaja == 1)
                        {
                            retorno = 1;
                            ll_remove(pArrayListEmployee,indice);

                        }
                        else
                        {
                            if(!confirmaBaja)
                            {
                                retorno = 0;
                            }

                        }

                    }
                }

            }
        }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int flag = 0;

    if(pArrayListEmployee != NULL)
    {
        error = 0;
        printf("ID     NOMBRE      HORAS TRABAJADAS      SUELDO\n");
        printf("-------------------------------------------------\n\n");

        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            if(((Employee*)ll_get(pArrayListEmployee,i))!= NULL)
            {
                mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,i));
                flag = 1;
            }
        }


        if(flag == 0)
        {
            printf("\nNo hay empleados en la lista\n");
        }

        error = 0;
    }


    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int opcionMenu;
    int criterio;
    int tamanio;

    if(pArrayListEmployee != NULL)
    {
        tamanio = ll_len(pArrayListEmployee);


        if(tamanio > 2)
        {
            if(utn_getNumeroInt(&opcionMenu,"Ingrese la opcion para ordenar\n\n1 Id\n2 Nombre\n3 Horas Trabajadas\n4 Sueldo\n","Error, re ingrese criterio\n",0,5,4))
            {
                if(utn_getNumeroInt(&criterio,"Ingrese el criterio para ordenar\n0 Ascendente\n1 Descendente\n","Error, re ingrese criterio\n",0,1,4))
                {
                    error = 0;

                        switch(opcionMenu)
                        {
                        case 1:
                                if(!criterio)
                                {
                                    printf("\nListado ordenardo por ID ascendente\n");
                                    ll_sort(pArrayListEmployee,employee_ordenarPorId,criterio);
                                }else
                                {
                                    printf("\nListado ordenardo por ID descendente\n");
                                    ll_sort(pArrayListEmployee,employee_ordenarPorId,criterio);
                                }
                            break;
                        case 2:
                            if(!criterio)
                            {
                                printf("\nListado ordenardo por nombre ascendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarNombre,criterio);
                            }else
                            {
                                printf("\nListado ordenardo por nombre descendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarNombre,criterio);
                            }
                            break;
                        case 3:
                            if(!criterio)
                            {
                                printf("\nListado ordenardo por horas trabajadas ascendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarHorasTrabajadas,criterio);
                            }else
                            {
                                printf("\nListado ordenardo por horas trabajadas descendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarHorasTrabajadas,criterio);
                            }
                            break;
                        case 4:
                            if(!criterio)
                            {
                                printf("\nListado ordenardo por sueldos ascendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,criterio);
                            }else
                            {
                                printf("\nListado ordenardo por sueldos  descendente\n");
                                ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,criterio);
                            }
                            break;
                        }
                }
            }
        }
        else
        {
            printf("\nNo hay empleados en la lista\n");
            error = 1;
        }
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    int id;
    char nombre[NOMBRE];
    int horasTrabajadas;
    int sueldo;
    int tamanio;

    Employee* empleado;
    empleado = NULL;

    FILE* f;


    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen("data.csv","w");

        if(f != NULL)
        {
            tamanio = ll_len(pArrayListEmployee);
            fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i = 0; i<tamanio; i++)
            {
                empleado = ll_get(pArrayListEmployee,i);

                if(!employee_getId(empleado,&id) && !employee_getNombre(empleado,nombre)&&
                        !employee_getHorasTrabajadas(empleado,&horasTrabajadas)&&
                        !employee_getSueldo(empleado,&sueldo))
                {
                    fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
                    error = 0;
                }
            }
            fclose(f);
        }
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    int tamanio;
    Employee* empleado;
    empleado = NULL;

    FILE* f;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"wb");

        if(f != NULL)
        {

            tamanio = ll_len(pArrayListEmployee);

            for(int i = 0; i<tamanio; i++)
            {
                empleado = ll_get(pArrayListEmployee,i);

                if(empleado != NULL)
                {

                    fwrite(empleado,sizeof(Employee),1,f);
                    error = 0;
                }
            }

        }
        fclose(f);
    }
    return error;
}

