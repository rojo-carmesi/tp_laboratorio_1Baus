#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = -1;
    char bufferDatos[4][128];
    int cantidadElementos;
    Employee* nuevoEmpleado;
    nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3]);

        do{

            cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3]);

            if(cantidadElementos == 4)
            {
                nuevoEmpleado = employee_newParametrosChar(bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3]);

                if(nuevoEmpleado != NULL)
                {
                    if(!ll_add(pArrayListEmployee,nuevoEmpleado))
                    {
                         error = 0;
                    }
                }
            }else
            {
                break;
            }

        }while(!feof(pFile));

        fclose(pFile);
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = -1;
    int cant;
    Employee* nuevoEmpleado;
    nuevoEmpleado = NULL;


    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        do
        {

            nuevoEmpleado = employee_new();
            cant = fread(nuevoEmpleado,sizeof(Employee),1,pFile);

            if(nuevoEmpleado != NULL && cant == 1)
            {
                ll_add(pArrayListEmployee,nuevoEmpleado);
                error = 0;
            }else
            {
                employee_delete(nuevoEmpleado);
                break;
            }
        }while(!feof(pFile));

    }
      fclose(pFile);
    return error;
}
