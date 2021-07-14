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
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int *id)
{
    int retorno = -1;
    FILE* f;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"r");

        if(f != NULL)
        {
            (*id) = parser_EmployeeFromText(f,pArrayListEmployee);
            (*id)++;

            if(*id>1)
            {
                retorno = 0;
            }

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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee,int *id)
{
    int error = -1;
    FILE* f;

    if(path !=NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"rb");

        if(f != NULL )
        {
            (*id) = parser_EmployeeFromBinary(f,pArrayListEmployee);
            (*id)++;

            if(*id>1)
            {
                error = 0;
            }

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
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int error = -1;
    int flagPrimerEmp;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;


    Employee* auxEmp;
    auxEmp = NULL;

    if(pArrayListEmployee != NULL)
    {


        if(!utn_getCadena("Ingrese el nombre del empleado\n","Error, nombre invalido\n",3,51,4,nombre)&&
                !utn_getNumero(&horasTrabajadas,"Ingrese las horas que trabajo el empleado\n","Error, re ingrese las horas\n",0,999,5)&&
                !utn_getNumero(&sueldo,"Ingrese el sueldo del empleado\n","Error, re ingrese el sueldo\n",1,9999999,5))
        {

            auxEmp = employee_new();

            if(auxEmp != NULL)
            {

                if(!employee_setId(auxEmp,(*id))
                        && !employee_setNombre(auxEmp,nombre)
                        && !employee_setHorasTrabajadas(auxEmp,horasTrabajadas)
                        && !employee_setSueldo(auxEmp,sueldo))
                {
                    ll_add(pArrayListEmployee,auxEmp);
                    (*id)++;
                    error = 0;

                }
                else
                {
                    printf("No hay espacio para mas empleados\n");
                    free(auxEmp);
                }
            }
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
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    int opcionMenu;
    int indice;

    Employee* auxiliarEmpleado;
    auxiliarEmpleado = NULL;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(!utn_getNumero(&id,"\nIngrese la id del Empleado que desea modificar\n",
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
                    if(!utn_getNumero(&opcionMenu,
                                      "\n*** MENU DE MODIFICACION ***\nIngrese la opcion para modificar el campo\n1 Nombre\n2 Horas Trabajadas\n3 Sueldo\n4 Salir"
                                      ,"Error,ingrese una opcion valida",0,4,4))
                    {
                        switch(opcionMenu)
                        {
                        case 1:
                            if(!utn_getCadena("Ingrese el nombre del empleado\n","Error, nombre invalido\n",3,51,3,nombre))
                            {
                                if(!employee_setNombre(auxiliarEmpleado,nombre))
                                {
                                    printf("\nEl nombre se modifico con exito\n");
                                    ll_set(pArrayListEmployee,indice,auxiliarEmpleado);
                                }
                            }

                            break;
                        case 2:
                            if(!utn_getNumero(&horasTrabajadas,"\nIngrese las horas trabajadas\n","Error, ingrese un numero valido\n",
                                              0,1000,4))
                            {
                                if(!employee_setHorasTrabajadas(auxiliarEmpleado,horasTrabajadas))
                                {
                                    printf("\n Las horas se han modificado con exito\n");
                                    ll_set(pArrayListEmployee,indice,auxiliarEmpleado);

                                }
                            }
                            break;
                        case 3:
                            if(!utn_getNumero(&sueldo,"\nIngrese el nuevo sueldo\n","Error, ingrese un numero valido\n",
                                              0,999999999,4))
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

        if(!utn_getNumero(&id,"\nIngrese la id del Empleado que desea dar de baja\n",
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

                if(!utn_getNumero(&confirmaBaja,"Confirma la baja del empleado?\n1-Si\n2-No\n","Error, opcion incorrecta\n",1,2,4))
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
    int tam;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[51];
    Employee* aux;
    aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        error = 0;
        printf("ID     NOMBRE      HORAS TRABAJADAS      SUELDO\n");
        printf("-------------------------------------------------\n\n");
        tam = ll_len(pArrayListEmployee);

        for(int i = 0; i<tam; i++)
        {
            aux = ll_get(pArrayListEmployee,i);

            if(aux!= NULL && !employee_getId(aux,&id)
                    && !employee_getNombre(aux,nombre)
                    && !employee_getSueldo(aux,&sueldo)
                    && !employee_getHorasTrabajadas(aux,&horasTrabajadas))
            {

                printf("%d        %10s         %4d                %5d\n",id,nombre,horasTrabajadas,sueldo);
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
            if(!utn_getNumero(&opcionMenu,"Ingrese la opcion para ordenar\n\n1 Id\n2 Nombre\n3 Horas Trabajadas\n4 Sueldo\n","Error, re ingrese criterio\n",0,5,4))
            {
                if(!utn_getNumero(&criterio,"Ingrese el criterio para ordenar\n0 Ascendente\n1 Descendente\n","Error, re ingrese criterio\n",0,1,4))
                {
                    error = 0;

                    switch(opcionMenu)
                    {
                    case 1:
                        if(!criterio)
                        {
                            printf("\nListado ordenardo por ID ascendente\n");
                            ll_sort(pArrayListEmployee,employee_ordenarPorId,criterio);
                        }
                        else
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
                        }
                        else
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
                        }
                        else
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
                        }
                        else
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
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    int tamanio;
    int opcion = 1;
    Employee* empleado;
    empleado = NULL;

    FILE* f;


    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path,"w");

        if(f != NULL)
        {
            if(!utn_getNumero(&opcion,"Se sobreescribiran los datos ya existentes\nDesea guardar?\n1-Si\n2-No",
                              "Error, re ingrese la opcion\n",1,2,4))
            {
                if(opcion)
                {
                    f = fopen(path,"w");

                    if(f !=NULL)
                    {
                        tamanio = ll_len(pArrayListEmployee);
                        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
                        for(int i = 0; i<tamanio; i++)
                        {
                            empleado = (Employee*) ll_get(pArrayListEmployee,i);

                            if(!employee_getId(empleado,&id) && !employee_getNombre(empleado,nombre)&&
                                    !employee_getHorasTrabajadas(empleado,&horasTrabajadas)&&
                                    !employee_getSueldo(empleado,&sueldo))
                            {
                                fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
                                error = 0;
                            }
                            empleado = NULL;
                        }
                    }
                    else
                    {
                        printf("Error al abrir el archivo\n");
                    }
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
    int opcion = 1;
    Employee* empleado;
    empleado = NULL;

    FILE* f;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"wb");

        if(f != NULL)
        {
            if(!utn_getNumero(&opcion,"Se sobreescribiran los datos ya existentes\nDesea guardar?\n1-Si\n2-No",
                              "Error, re ingrese la opcion\n",1,2,4))
            {
                if(opcion)
                {
                    tamanio = ll_len(pArrayListEmployee);

                    for(int i = 0; i<tamanio; i++)
                    {
                        empleado = (Employee*) ll_get(pArrayListEmployee,i);

                        if(empleado != NULL)
                        {

                            fwrite(empleado,sizeof(Employee),1,f);
                            error = 0;
                        }
                    }
                }
            }

        }
        fclose(f);
    }
    return error;
}

