#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "utn.h"



eNotebook*  notebook_new()
{

	eNotebook* nuevaNotebook;

	nuevaNotebook = (eNotebook*) malloc(sizeof(eNotebook));

	return nuevaNotebook;
}



eNotebook* notebook_newParametrosChar(char* idStr,char* modelo,char* precio,char* anioFabricacion, char* peso)
{
	eNotebook* nuevaNotebook;
    nuevaNotebook = NULL;
	nuevaNotebook = notebook_new();

	if(nuevaNotebook != NULL)
	{

		if(notebook_setId(nuevaNotebook,atoi(idStr)) == 1 ||
			notebook_setModelo(nuevaNotebook, modelo)== 1||
            notebook_setPrecio(nuevaNotebook, atof(precio)) == 1
			|| notebook_setAnioFabricacion(nuevaNotebook, atoi(anioFabricacion)) == 1
            || notebook_setPeso(nuevaNotebook, atoi(peso)) == 1)

		{
			notebook_delete(nuevaNotebook);
		}

	}
	return nuevaNotebook;

}




void notebook_delete(eNotebook* this)
{
    free(this);
}


int printNotebook(eNotebook* notebook)
{
    int error = 0;
    char modelo[MODELO];
    int id;
    float precio;
    int anioFabricacion;
    int peso;

    if(notebook != NULL )
    {
        if(!notebook_getAnioFabricacion(notebook,&anioFabricacion) &&
           !notebook_getId(notebook,&id) && !notebook_getModelo(notebook,modelo) &&
           !notebook_getPrecio(notebook,&precio) && !notebook_getPeso(notebook,&peso))
        {

            printf("%d           %15s            %10.2f           %10d               %10d\n",id,modelo,precio,anioFabricacion,peso);
            error = 1;
        }
    }

    return error;
}

int notebook_setId(eNotebook* this, int id)
{
	int error = 1;

	if(this != NULL && id>0)
	{
		this->id = id;
		error = 0;
	}
	return error;
}

int notebook_setPeso(eNotebook* this, int peso)
{
	int error = 1;

	if(this != NULL && peso>0)
	{
		this->peso = peso;
		error = 0;
	}
	return error;
}

int notebook_getPeso(eNotebook* this, int* peso)
{
	int error = 1;

	if(this != NULL && peso != NULL)
	{
		*peso = this->peso;
		error = 0;
	}
	return error;
}


int notebook_setModelo(eNotebook* this, char* modelo)
{
	int error = 1;

	if(this != NULL && strlen(modelo)>0 && strlen(modelo)<128)
	{
		strcpy(this->modelo,modelo);
		error = 0;
	}
	return error;
}

int notebook_setPrecio(eNotebook* this, int precio)
{
	int error = 1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		error = 0;
	}
	return error;
}

int notebook_setAnioFabricacion(eNotebook* this, int anioFabricacion)
{
	int error = 1;

	if(this != NULL && anioFabricacion >=0)
	{
		this->anioFabricacion = anioFabricacion;
		error = 0;
	}
	return error;
}

int notebook_getId(eNotebook* this,int* id)
{
	int error = 1;

	if(this != NULL && id !=NULL)
	{
		*id = this->id;
		error = 0;
	}
	return error;
}

int notebook_getModelo(eNotebook* this,char* modelo)
{
	int error = 1;
	if(this != NULL && modelo !=NULL)
	{
		strcpy(modelo,this->modelo);
		error = 0;
	}
	return error;
}

int notebook_getPrecio(eNotebook* this,float* precio)
{
	int error = 1;
	if(this != NULL && precio !=NULL)
	{
		*precio = this->precio;
		error = 0;
	}
	return error;
}

int notebook_getAnioFabricacion(eNotebook* this,int* AnioFabricacion)
{
	int error = 1;
	if(this != NULL && AnioFabricacion !=NULL)
	{
		*AnioFabricacion = this->anioFabricacion;
		error = 0;
	}
	return error;
}

eNotebook* notebook_buscarElementoPorId(LinkedList* pArrayListaDeNotebooks, int idBuscado)
{
    eNotebook* auxNotebook;
    auxNotebook = NULL;

    if(pArrayListaDeNotebooks != NULL && idBuscado>0)
    {
        int tamanio = ll_len(pArrayListaDeNotebooks);

        for(int i = 0; i<tamanio; i++)
        {
            auxNotebook = (eNotebook*) ll_get(pArrayListaDeNotebooks,i);

            if(idBuscado == auxNotebook->id )
            {
                return auxNotebook;
                break;
            }else
            {
               auxNotebook = NULL;
            }
        }
    }

    return auxNotebook;
}

int buscarIndicePorId(LinkedList* pArrayDeNotebooks, int id)
{
    eNotebook* auxNotebook;
    auxNotebook = NULL;
    int indice = -1;
    if(pArrayDeNotebooks != NULL && id>0)
    {
        int tamanio = ll_len(pArrayDeNotebooks);

        for(int i = 0; i<tamanio; i++)
        {
            auxNotebook = (eNotebook*) ll_get(pArrayDeNotebooks,i);

            if(id == auxNotebook->id )
            {
                indice = (i);
                return i;
                break;
            }
        }
    }

    return indice;
}





int notebook_ordenarPorPrecio(void* note1,void* note2)
{
    int retorno = 0;
    eNotebook* notebookA = (eNotebook*) note1;
    eNotebook* notebookB = (eNotebook*) note2;


    if(notebookA->precio > notebookB->precio)
    {
        retorno = 1;
    }else
    {
        if(notebookA->precio < notebookB->precio)
        {
            retorno = -1;
        }
    }

    return retorno;
}

int notebook_filtrarPorAnio(void* note1)
{
    int retorno = 0;

    eNotebook* notebookA = (eNotebook*) note1;


    if(notebookA->anioFabricacion > 2000)
    {
        retorno = 1;
    }

    return retorno;
}
