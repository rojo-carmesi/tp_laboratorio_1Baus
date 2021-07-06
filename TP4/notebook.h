#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#define PRECIO 10000
#define MODELO 20
#include "LinkedList.h"
typedef struct{

    int id;
    char modelo[20];
    float precio;
    int anioFabricacion;
    int peso;

}eNotebook;

#endif // NOTEBOOK_H_INCLUDED


/*
 * \brief Constructor del espacio de memoria para la notebook
 *
 * \return devuelve un puntero al espacio de memoria que encontro y si no devuelve NULL
 */

eNotebook* notebook_new();


/** \brief Constructor que inicializa las variables que va recibe por parametro
 * de tipo char
 *
 * \param  id a asignar a la notebook
 * \param   modelo a asignar a la notebook
 * \param   precio a la notebook
 * \param   aniodefabricacion a asignar a la notebook
 * \param   peso  de la notebook
 * \return puntero a la notebook generado
 */

eNotebook* notebook_newParametrosChar(char* idStr,char* modelo,char* precio,char* anioFabricacion, char* peso);

/** \brief libera el espacio de memoria donde se encuentra la  notebook que le pasamos
 * \param puntero a la notebook que deseamos borrar
 */

void notebook_delete(eNotebook* oneEmployee);
/*
 * \brief copia el valor introducido del id y lo copia al array
 * \param puntero array en el guardamos los ids
 * \param número de id introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int notebook_setId(eNotebook* this,int id);
int notebook_getId(eNotebook* this,int* id);
/*
 * \brief recibre el nombre y lo copia al array de nombres
 * \param puntero array en el guardamos los nombres
 * \param nombre introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int notebook_setModelo(eNotebook* this,char* modelo);
int notebook_getModelo(eNotebook* this,char* modelo);

int notebook_setPeso(eNotebook* this, int peso);
int notebook_getPeso(eNotebook* this, int* peso);

int notebook_setAnioFabricacion(eNotebook* this, int anioFabricacion);
int notebook_getAnioFabricacion(eNotebook* this, int* anioFabricacion);


int notebook_setPrecio(eNotebook* this, int precio);
int notebook_getPrecio(eNotebook* this, float* precio);

/** \brief Muestra la notebook pasada por el puntero a donde se ubica
 *
 * \param notebook puntero a la direccion del empleado a mostrar
 * \param
 * \return  0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int printNotebook(eNotebook* notebook);

/** \brief Realiza la busqueda del elemento de la lista de notebooks que deseamos encontrar a partir
 * de pasarle el id como parametro y la lista
 * \param pArrayListaDeNotebooks puntero al array de lista de notebook
 * \param IdBuscado id de la notebook que deseamos encontrar
 * \return elemento notebook que deseamos encontrar, y si no retorna NULL para indicar que no existe
 *
 */

eNotebook* notebook_buscarElementoPorId(LinkedList* pArrayListaDeNotebooks, int idBuscado);

/** \brief Realiza la busqueda del indice de la notebook que deseamos encontrar a partir
 * de pasarle el id como parametro
 * \param pArrayListaDeNotebooks puntero al array de lista de notebook
 * \param IdBuscado id de la notebook que deseamos encontrar
 * \return indice de la notebook que deseamos encontrar, y si no retorna -1 lo cual indica que no exitste
 *
 */

int buscarIndicePorId(LinkedList* pArrayDeNotebooks, int id);

/** \brief Realiza la comparacion de los elementos del array de notebooks
 *  y luego de comparar dependiendo el resultado de esa comparacion devuelve el criterio por el cual lo vamos a ordenar
 * \param note1 puntero void que luego castearemos al tipo de eNotbook
 * \param note2 puntero void que luego castearemos al tipo de eNotbook
 * \return devuelve el criterio de ordenamiento, 1 si el elemento note 1 es mayor a note 2 , -1 si note 2 es mayor a not1, 0 si es igual
 *
 */

int notebook_ordenarPorPrecio(void*note1,void* note2);

/** \brief Realiza el filtrado de los elementos de la lista a partir del parametro ingesado por el cual va a comparar
 * \param puntero al elemento de la lista que casteamos dentro de la funcion
 * \return devuelve 1 si coincide con el criterio y 0 si no lo hace
 *
 */

int notebook_filtrarPorAnio(void* note1);


