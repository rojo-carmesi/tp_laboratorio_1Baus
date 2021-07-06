/** \brief Transforma los datos del archivo de empleados data.csva modo texto
 * \param pFile ruta al archiv data.csv
 * \param pArrayListEmployee puntero al array de empleados donde depositamos los dat
 * \return devuelve 0 si salio ok -1 si salio mal
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Transforma los datos del archivo de empleados databin.csv modo binario
 * \param pFile ruta al archiv databin.csv
 * \param pArrayListEmployee puntero al array de empleados donde depositamos los datos
 * \return devuelve 0 si salio ok -1 si salio mal
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

