/*
 * ArrayEmployees.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Martin
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/*Breif La funcion menu se ejecuta para mostrar un menu de opciones que el usuario debe elegir
 * retorna 0 si se ejecuto correctamente
 * 1 si no se pudo realizar, se obtiene el resultado mediante un puntero.
 *
 * param puntero "OpcionMenu" que indica la posicion de memoria donde se guardara el resultado.
 * return retorna 0 si salio bien o 1 salio mal.
 */
int menu(int *opcionMenu);

/*Brief Para incicar que todas las posiciones en el array estan vacias
 * esta funcion recorre el array y pone el flag"isEmpty" en 1,retorna 0 si se ejecuto correctamente
 * 1 si no se pudo realizar
 *
 * param Employee lista (lista de empleados)
 * param tamañao del array que pasamos por referencia
 * return 0 si esta ok o 1 si salio mal
 */
int initEmployee(Employee* list, int lenght);

/*Brief La funcion valida que el indice no sea 0 agrega los datos a la lista de empleados con los valores recibidos por referencia.
 * retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Lenght tamanio del vector recebido por referencia.
 * param Id identificacion del empleado que estamos cargando
 * param Name vector de char del nombre ingresado
 * param LastName vector de char del apellido ingresado
 * param Salary variable que guarda el salario recibido por referencia
 * param Sector variable que guarda el sector recibido por referencia
 *
 * return 0 si esta ok o 1 si salio mal
 */
int addEmployee(Employee* list, int lenght, int id, char name[],char lastName[],float salary,int sector);

/*Brief solicita los datos que va a contener la lista de empleados
 * que luego pasaremos a la funcion agregar mediante referencia
 * retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Nombre donde se guardara el nombre solocitado
 * param Apellido donde se guardara el apellido solicitado
 * param Salario donde se guardara el salario solicitado
 * param Sector donde se guardara el sector solcitado
 *
 * return 0 si esta ok o 1 si salio mal
 */

int cargarDatosEmployee(char* nombre, char *apellido, float *salario, int *sector, int sizeName,int sizeLastName);

/*Brief muestra la lista de empleados recibiendo como parametro el array de lista de empleados y el tamanio del mismo
 * retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Employee lista el vector de empleados
 * param Tamanio tamanio del vector
 *
 * return 0 si esta ok o 1 si salio mal
 */
int mostrarEmployees(Employee* lista, int tamanio);

/*Brief muestra un de empleados recibiendo como parametro el array de lista de empleados y indice donde esta el empleado a mostrar
 * retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Employee lista el vector de empleados
 * param Indice el indice del empleado
 *
 * return 0 si esta ok o 1 si salio mal
 */

int mostrarUnEmployee(Employee* lista, int indice);

/*Brief la funcion recorre el array y verifica que haya alguno empleado cargado
 *
 *param Employee lista recibe la lista de empleados a recorrer
 *param Lenght tamanio del array
 *
 *return retorna el indice encontrado
 */

int buscarLibre(Employee* list, int lenght);

/*Brief la funcion recorre el array en busca del empleado con el id indicado por referencia
 *retorna el indice el empleado buscado
 *
 * param Employee list array con la lista de empleados
 * param Lenght tamaño del array
 * param Id identificacion del empleado buscado
 *
 * return indice relacionado al empleado buscado
 *
 */

int findEmployeeById(Employee* list, int lenght, int id);

/*Brief la funcion da baja logica del empleado buscado poniendo el flag IsEmpty en 1 segun el id del empleado
 *retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Employee list array de empleados
 * param Lenght tamaño del array
 * param Id identificacion del empleado buscado
 *
 *return 0 si esta ok o 1 si salio mal
 */

int removeEmployee(Employee* list, int lenght, int id);

/*Brief la funcion modifica los datos del empleado buscado por su id
 * retorna 0 si se ejecuto correctamente 1 si no se pudo realizar
 *
 * param Employee list array de empleados
 * param Lenght tamaño del array
 * param Indice posicion del id del empleado buscado
 *
 * return 0 si esta ok o 1 si salio mal
 */

int modificarEmployee(Employee* lista, int tamanio, int indice);

/*Brief la funcion verifica la existencia de datos en el Array
 * param lista el vector de empleados
 * param lenght tamanio del vector
 */

int verificarExistencia(Employee* lista, int lenght);

/*Brief la funcion ordena el array de empleados recibiendo el tamaño y el criterio de ordenamiento
 * param lista de empleados estructura
 * param tamanio de la lista
 * param criterio de ordenamiento
 * return 1 si salio bien 0 si salio mal
 */

int sortEmployees(Employee* list, int lenght, int order);

/*Brief la funcion informa los datos de la nomina de empleadoos recibiendo la lista y el tamanio
* param lista de empleados estructura
* param tamanio de la lista
* return 1 si salio bien 0 si salio mal
*/
int mostrarInfoSalarios(Employee* lista, int tamanio);
