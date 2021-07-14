/** \brief Carga los datos del archivo data.csv en modo texto
 *
 * \param  path ruta del archivo que tiene los datos
 * \param  pArrayListEmployee puntero al archivo de lista de empleados
 * \param ID puntero al id autoincremental
 * \return 0 si salio ok -1 si salio mal
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int *id);

/** \brief Carga los datos del archivo databin.csv en modo binario
 *
 * \param  path ruta del archivo que tiene los datos
 * \param  pArrayListEmployee puntero al archivo de lista de empleados
 * \param ID puntero al id autoincremental
 * \return 0 si salio ok -1 si salio mal
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee,int *id);

/** \brief Realiza el alta del empleado recibiendo un puntero a la lista
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 *\param ID puntero a integer que autogenera el ID del empleado en tiempo de ejecucion
 * \return 0 si salio ok -1 si hubo error
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
/** \brief Realiza  la modificacion de un empleado de la lista solicitando el id como referencia
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Realiza la baja de un empleado de la lista solicitando el id como referencia
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Realiza la muestra de los empleados cargados en la lista
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Realiza el ordenamienteo de los elementos en el array
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Realiza el guardado de los datos en modo texto con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (data.csv)
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 *\param  path ruta al archivo csv
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Realiza el guardado de los datos en modo binario con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (databin.csv)
 *
 * \param  pArrayListEmployee punteroa la lista de empleado
 *\param  path ruta al archivo csv
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


