/** \brief Carga los datos del archivo data.csv en modo texto
 *
 * \param  path ruta del archivo que tiene los datos
 * \param  pArrayDeNotebook puntero al archivo de lista de notebooks
 * \return 0 si salio ok -1 si salio mal
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayDeNotebook);


/** \brief Realiza la muestra del listado de las notebooks
 *
 * \param  pArraynotebook puntero al array de notebooks
 * \
 * \return 0 si salio ok -1 si salio mal
 *
 */


int controller_ListNotebook(LinkedList* pArrayDeNotebook);


/** \brief Realiza el guardado de los datos en modo texto con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (data.csv)
 *
 * \param  pArrayDeNotebook punteroa la lista de notebooks
 *\param  path ruta al archivo csv
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayDeNotebook);




