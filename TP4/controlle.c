#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"utn.h"
#include "LinkedList.h"
#include "notebook.h"
#include "parser.h"
#include "controller.h"




int controller_loadFromText(char* path , LinkedList* pArrayNotebooks)
{
    int retorno = -1;
    FILE* f;

    if(path != NULL && pArrayNotebooks != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL && !parser_EmployeeFromText(f,pArrayNotebooks))
        {
            printf("\nLista generada con exito!\n\n");
            retorno = 0;

        }else
        {
            printf("\nError al cargar el archivo\n");
        }
    }

        fclose(f);

    return retorno;
}


int controller_ListNotebook(LinkedList* pArrayDeNotebook)
{
    int error = 1;
    int flag = 0;

	if(pArrayDeNotebook != NULL)
	{
	    error = 0;
        printf("ID                MODELO                PRECIO               ANIODEFABRICACION             PESO KG\n");
        printf("---------------------------------------------------------------------------------------------------------------\n\n");
		for(int i = 0; i<ll_len(pArrayDeNotebook); i++)
		{
			if(((eNotebook*)ll_get(pArrayDeNotebook,i))!= NULL)
			{
				printNotebook((eNotebook*)ll_get(pArrayDeNotebook,i));
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("\nNo hay empleados en la lista\n");
		}

		error = 0;
	}else
	{
	    printf("No hay una lista disponible para mostrar\n");
	}


    return error;
}




/** \brief Guarda los datos de las notebooks en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArrayDeNotebook)
{
    int error = -1;
    int id;
    char modelo[MODELO];
    float precio;
    int anioDeFabricacion;
    int peso;

    eNotebook* notebook;
    notebook = NULL;

    FILE* f;


    if(pArrayDeNotebook != NULL && path != NULL)
    {
        f = fopen(path,"w");

        if(f != NULL)
        {
            int tamanio = ll_len(pArrayDeNotebook);
             fprintf(f,"id,modelo,precio,anioDeFabricacion,peso\n");
            for(int i = 0; i<tamanio; i++)
            {
                notebook = ll_get(pArrayDeNotebook,i);

                if(!notebook_getId(notebook,&id) && !notebook_getModelo(notebook,modelo)&&
                   !notebook_getPrecio(notebook,&precio)&&
                   !notebook_getAnioFabricacion(notebook,&anioDeFabricacion)&&
                   !notebook_getPeso(notebook,&peso));
                {

                   fprintf(f,"%d,%s,%.2f,%d,%d\n",id,modelo,precio,anioDeFabricacion,peso);
                    error = 0;
                }
             }
             fclose(f);
          }
    }
    return error;
}


