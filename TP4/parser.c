#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "notebook.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayNotebooks)
{
    int error = -1;
    char bufferDatos[5][128];
    int cantidadElementos;

    eNotebook* nuevaNotebook;
    nuevaNotebook = NULL;

    if(pFile != NULL && pArrayNotebooks != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

        do{

            cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

            if(cantidadElementos == 5)
            {
                nuevaNotebook = notebook_newParametrosChar(bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

                if(nuevaNotebook != NULL)
                {
                    ll_add(pArrayNotebooks,nuevaNotebook);

                    error = 0;
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
 /*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayNotebooks)
{
    int error = -1;
    eNotebook* nuevaNotebook;
    nuevaNotebook = NULL;
    int id;
    char nombre[128];
    int sueldo;
    int horasTrabajadas;


    if(pFile != NULL && pArrayNotebooks != NULL)
    {
        fread(nuevaNotebook,sizeof(eNotebook),1,pFile);

        do
        {
            if(fread(&id,sizeof(int),1,pFile)&&
                fread(nombre,128,1,pFile)&&
                 fread(&horasTrabajadas,sizeof(int),1,pFile)&&
                  fread(&sueldo,sizeof(int),1,pFile))
            {
                nuevaNotebook = employee_newParametrosInt(id,nombre,horasTrabajadas,sueldo);
                ll_add(pArrayNotebooks,nuevaNotebook);
                error = 0;
            }

        }while(!feof(pFile));

        fclose(pFile);
    }

    return error;
}
*/
