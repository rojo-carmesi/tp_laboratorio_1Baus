#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "utn.h"
#include "controller.h"
#include "notebook.h"


#define TAMANIO 20



int main()
{
    int indiceId;
    int indice;
    int from;
    int to;
    int id;
    int tamanioLinkedList;

    LinkedList* listaDeNotebooks;
    LinkedList* listaDeNotebooks2;

    eNotebook auxNotebook;
    eNotebook* pAuxNotebook;
    eNotebook* pAuxNotebook2;

    printf("\n\n");
    printf("**********************************************  TP4 LINKEDLIST  ***********************************************\n");

    listaDeNotebooks = ll_newLinkedList();

    printf("\n|-----------------------LL_ISEMPTY-----------------------|\n\n");

    if(ll_isEmpty(listaDeNotebooks))
    {
        printf("LL_isEmpty = 1 la lista esta vacia\n");
    }


    if(!controller_loadFromText("notebooks.csv",listaDeNotebooks))// CARGAMOS EL ARCHIVO
    {

    }
    else
    {
        printf("Error al abrir el archivo\n");
    }

    if(!ll_isEmpty(listaDeNotebooks))
    {
        printf("\nLL_isEmpty = 0 la lista contiene elementos\n\n");
        controller_ListNotebook(listaDeNotebooks);
    }



    printf("\n|-----------------------LL_LEN-----------------------|\n\n");
    tamanioLinkedList =  ll_len(listaDeNotebooks);
    printf("El tamanio del linkedList es %d: \n",tamanioLinkedList);

    printf("\n|-----------------------LL_ADD-----------------------|\n\n");
    printf("Agregamos un elemento a la lista\n\n");
    printf("id : 11   Modelo : EX60  Precio: 100.560  Anio Fabricacion:  2000  Peso: 5\n");

    auxNotebook.id = 11;
    strcpy(auxNotebook.modelo,"EX60");
    auxNotebook.precio = 100.560;
    auxNotebook.anioFabricacion = 2000;
    auxNotebook.peso = 5;

    pAuxNotebook = notebook_new();
    notebook_setId(pAuxNotebook,auxNotebook.id);
    notebook_setModelo(pAuxNotebook,auxNotebook.modelo);
    notebook_setPrecio(pAuxNotebook,auxNotebook.precio);
    notebook_setAnioFabricacion(pAuxNotebook,auxNotebook.anioFabricacion);
    notebook_setPeso(pAuxNotebook,auxNotebook.peso);

    if(!ll_isEmpty(listaDeNotebooks))
    {
        ll_add(listaDeNotebooks,pAuxNotebook);
        controller_ListNotebook(listaDeNotebooks);
        printf("\nElemento agregado con exito\n");
    }

    printf("\n|-----------------------LL_GET-----------------------|\n\n");
    controller_ListNotebook(listaDeNotebooks);

    if(!utn_getNumeroInt(&id,"\nIngrese el ID de la notebook que desea ver\n","Error, ingrese un numero valido\n",1,100,4))
    {
        indice = buscarIndicePorId(listaDeNotebooks,id);
        pAuxNotebook2 = ll_get(listaDeNotebooks,indice);

        printNotebook(pAuxNotebook2);
    }

    printf("\n|-----------------------LL_INDEXOF-----------------------|\n\n");
    controller_ListNotebook(listaDeNotebooks);

    if(!ll_isEmpty(listaDeNotebooks))
    {
        utn_getNumeroInt(&indiceId,"\nIngrese el ID de la notebook la cual  desea ver el indice\n","Error, ingrese un numero valido\n",0,100,4);
        pAuxNotebook2 = (eNotebook*) notebook_buscarElementoPorId(listaDeNotebooks,indiceId);
        indiceId = ll_indexOf(listaDeNotebooks,pAuxNotebook2);
        printf("ID                MODELO                PRECIO               ANIODEFABRICACION             PESO KG\n");
        printf("---------------------------------------------------------------------------------------------------------------\n\n");
        printNotebook(pAuxNotebook2);
        printf("\nSe encuentra en el indice: %d\n",indiceId);
    }


    printf("\n|-----------------------LL_SET-----------------------|\n\n");
    printf("\nSeteamos un nuevo elemento en el indice 5\n");

    printf("\n\n");
    controller_ListNotebook(listaDeNotebooks);

    auxNotebook.id = 48;
    strcpy(auxNotebook.modelo,"COLECO");
    auxNotebook.precio = 6000.560;
    auxNotebook.anioFabricacion = 1996;
    auxNotebook.peso = 20;

    pAuxNotebook = notebook_new();
    notebook_setId(pAuxNotebook,auxNotebook.id);
    notebook_setModelo(pAuxNotebook,auxNotebook.modelo);
    notebook_setPrecio(pAuxNotebook,auxNotebook.precio);
    notebook_setAnioFabricacion(pAuxNotebook,auxNotebook.anioFabricacion);
    notebook_setPeso(pAuxNotebook,auxNotebook.peso);

    printf("\n\n");
    printf("ID                MODELO                PRECIO               ANIODEFABRICACION             PESO KG\n");
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
    printNotebook(pAuxNotebook);
    printf("\n\n");

    if(!ll_set(listaDeNotebooks,5,pAuxNotebook))
    {
        controller_ListNotebook(listaDeNotebooks);
        printf("\nElemento agregado con exito\n");
    }

    printf("\n|-----------------------LL_REMOVE-----------------------|\n\n");
    controller_ListNotebook(listaDeNotebooks);
    printf("\nBorramos el elemento en el indice 9\n\n");

    if(!ll_remove(listaDeNotebooks,9))
    {
        printf("\nElemento eliminado con exito\n\n");
        controller_ListNotebook(listaDeNotebooks);
    }

    printf("\n\n");
    printf("\n|-----------------------LL_PUSH-----------------------|\n\n");
    printf("Insertamos un nuevo elemento en el indice 6 y desplazamos el que se encontraba ahi anteriormente\n\n");

    auxNotebook.id = 74;
    strcpy(auxNotebook.modelo,"EKOLE");
    auxNotebook.precio = 7890.560;
    auxNotebook.anioFabricacion = 2004;
    auxNotebook.peso = 11;

    pAuxNotebook = notebook_new();
    notebook_setId(pAuxNotebook,auxNotebook.id);
    notebook_setModelo(pAuxNotebook,auxNotebook.modelo);
    notebook_setPrecio(pAuxNotebook,auxNotebook.precio);
    notebook_setAnioFabricacion(pAuxNotebook,auxNotebook.anioFabricacion);
    notebook_setPeso(pAuxNotebook,auxNotebook.peso);


    if(!ll_push(listaDeNotebooks,6,pAuxNotebook))
    {
        controller_ListNotebook(listaDeNotebooks);
    }


    printf("\n\n");
    printf("\n|-----------------------LL_POP-----------------------|\n\n");
    printf("Borramos el elemento en el indice 2, y devolvemos su puntero\n\n");
    controller_ListNotebook(listaDeNotebooks);
    printf("\n\nEl puntero al elemento eleiminado es: %p\n\n",ll_pop(listaDeNotebooks,2));
    controller_ListNotebook(listaDeNotebooks);

    printf("\n\n");
    printf("\n|-----------------------LL_CONTAINS-----------------------|\n\n");
    if(!utn_getNumeroInt(&id,"Ingrese el ID del elemento que desea verificar si se existe en la lista\n","Error, ingrese un numero valido",1,1000,4))
    {
        pAuxNotebook = notebook_buscarElementoPorId(listaDeNotebooks,id);

        if(pAuxNotebook != NULL)
        {
            if(ll_contains(listaDeNotebooks,pAuxNotebook))
            {
                printNotebook(pAuxNotebook);
                printf("\nEl elemento se encuentra dentro de la lista!\n");
            }
            else
            {
                printf("\nProblema para encontrar el elemento\n");
            }
        }
        else
        {
            printf("\n\nNo existe un elemento con esa ID\n\n");
        }
    }


    printf("\n\n");
    printf("\n|-----------------------LL_SUBLIST-----------------------|\n\n");
    controller_ListNotebook(listaDeNotebooks);
    if(!utn_getNumeroInt(&indiceId,"\nIngrese el ID desde el que desea copiar la lista\n","Error, ingrese un ID valido\n",1,1000,4)
            &&!utn_getNumeroInt(&id,"\nIngrese el ID hasta el que desea copiar la lista\n","Error, ingrese un ID valido\n",1,1000,4))
    {
        from = buscarIndicePorId(listaDeNotebooks,indiceId);
        to = buscarIndicePorId(listaDeNotebooks,id);


        listaDeNotebooks2 = ll_subList(listaDeNotebooks,from,to+1);

        if(listaDeNotebooks2 != NULL)
        {
            printf("SubLista generada con exito!\n");
            controller_ListNotebook(listaDeNotebooks2);
        }
    }


    printf("\n\n");
    printf("\n|-----------------------LL_CLONE----------------------|\n\n");
    printf("\nClonamos la lista entera\n");
    controller_ListNotebook(listaDeNotebooks);


    listaDeNotebooks2 = ll_clone(listaDeNotebooks);

    if(listaDeNotebooks2 != NULL)
    {
        printf("\nClon de la lista generada con exito!\n\n");
        controller_ListNotebook(listaDeNotebooks2);
    }


    printf("\n\n");
    printf("\n|-----------------------LL_CONTAINSALL----------------------|\n\n");
    printf("\nVerificamos que la lista clonada contenga los mismos elementos que la lista original\n");

    if(ll_containsAll(listaDeNotebooks,listaDeNotebooks2))
    {
        printf("\nLas listas contienen los mismos elementos!\n");
        printf("\n************* ORIGINAL****************\n");

        controller_ListNotebook(listaDeNotebooks);
        printf("\n\n");
        printf("\n************* CLON DE LISTA****************\n");

        controller_ListNotebook(listaDeNotebooks2);
    }

    printf("\n\n");
    printf("\n|-----------------------LL_SORT-----------------------|\n\n");
    ll_sort(listaDeNotebooks2,notebook_ordenarPorPrecio,0);

    controller_ListNotebook(listaDeNotebooks2);

    printf("\n\n");
    printf("\n|-----------------------LL_FILTER-----------------------|\n\n");

   listaDeNotebooks2 = ll_filter(listaDeNotebooks,notebook_filtrarPorAnio);

    controller_ListNotebook(listaDeNotebooks2);
    controller_saveAsText("listrafiltradaporanio.csv",listaDeNotebooks2);


    printf("\n\n");
    printf("\n|-----------------------LL_CLEAR-----------------------|\n\n");
    printf("\nBorramos todos los elementos de la lista\n\n");

    if(!ll_clear(listaDeNotebooks))
    {
        printf("\nElementos de la lista eliminados con con exito!\n");
        controller_ListNotebook(listaDeNotebooks);
    }

    printf("\n\n");
    printf("\n|-------------LL_DELETE----------------------|\n\n");
    printf("Borramos la lista\n\n");

    if(!ll_deleteLinkedList(listaDeNotebooks))
    {
        printf("Lista eliminada con exito!\n");
    }



    return 0;
}
