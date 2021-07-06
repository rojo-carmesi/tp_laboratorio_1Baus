#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE 128
#define HORAS 1000000
#define SUELDO 5000000
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
 * \brief Constructor del espacio de memoria para el empleado
 *
 * \return devuelve un puntero al espacio de memoria que encontro y si no devuelve NULL
 */
Employee* employee_new();

/** \brief Constructor que inicializa las variables que va recibe por parametro
 * de tipo int mayoritariamente
 *
 * \param  id a asignar al empleado
 * \param   nombre a asigna al empleado
 * \param   horasTrabajasad a asignar al empleado
 * \param   sueldo a asigna al empleado
 * \return puntero al empleado generado
 *
 */

Employee* employee_newParametrosInt(int id,char* nombre,int horasTrabajadas, int sueldo);
/** \brief Constructor en formato char que inicializa las variables que va recibe por parametro
 * que son de tipo char mayormente
 *
 * \param  id char a asignar al empleado
 * \param   nombre a asigna al empleado
 * \param   horasTrabajadas char asignar al empleado
 * \param   sueldo char a asigna al empleado
 * \return puntero  al empleado generado
 *
 */
Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief libera el espacio de memoria donde se encuentra el empleado que le pasamos
 * \param puntero al empleado que deseamos borrar
 */

void employee_delete(Employee* oneEmployee);
/*
 * \brief copia el valor introducido del id y lo copia al array
 * \param puntero array en el guardamos los ids
 * \param número de id introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setId(Employee* this,int id);

/*
 * \brief Obtiene el valor de Id contenido en ese espacio del array
 * \param puntero array en el guardamos los ids
 * \param número de id que obtenimos

 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int employee_getId(Employee* this,int* id);
/*
 * \brief recibre el nombre y lo copia al array de nombres
 * \param puntero array en el guardamos el nombres
 * \param nombre introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setNombre(Employee* this,char* nombre);
/*
 * \brief Obtiene el valor de nopmbre contenido en ese espacio del array
 * \param puntero array en el guardamos los nombres
 * \param nombre obtenido

 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int employee_getNombre(Employee* this,char* nombre);
/*
 * \brief recibre las horas trabajadas y lo copia al array de emp en horas trabajadas
 * \param puntero array en el guardamos las horas trabajadas
 * \param horas trabajadas introducidas

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/*
 * \brief Obtiene el valor de horas trabajadas en ese espacio del array
 * \param puntero array en el obtenemos las horas
 * \param horas obtenidas

 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/*
 * \brief recibre el sueldo y lo copia al array de emp en sueldo
 * \param puntero array en el guardamos el sueldo
 * \param sueldo introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setSueldo(Employee* this,int sueldo);

/*
 * \brief Obtiene el valor de sueldo en ese espacio del array
 * \param puntero array en el obtenemos el sueldo
 * \param sueldo obtenido

 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra el empleado pasado por el puntero a donde se ubicad
 *
 * \param empleado puntero a la direccion del empleado a mostrar
 * \param
 * \return  0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int mostrarEmpleado(Employee* empleado);

/** \brief Genera el proximo id del empleado a partir de la busqueda del ultimo id generado
 * y se lo asgina al nuevo empleado creado
 * \param pArrayListaDeEmpleados puntero a la lista de empleados
 * \param
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int generarIdEmpleado(LinkedList* pArrayListaDeEmpleados);

/** \brief Realiza el incremento de la constante ID que esta inicializada en 0 y la retorna
 * \return ID autoincremental
 */
int employee_generarId();

/** \brief Realiza el seteo de la ultima ID que tomaremos como referencia
 * \return void no retorna nada
 */
void employee_setPrimerId(int valorInt);

/** \brief Realiza la busqueda del empleado por el Id pasado por ferencia
 * \param pArrayListaDeEmpleados puntero a la lista de empleados
 * \param IdBuscado
 * \return 0 si lo econtro sin problemas, -1 si hubo un error.
 */

int employee_buscarPorId(LinkedList* pArrayListaDeEmpleados, int idBuscado);

/** \brief Realiza el ordenamiento segun el criterio en este caso el ID
 * \param emp1 puntero a void de empleado
 * \param emp2 puntero a void de empleado
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int employee_ordenarPorId(void*emp1,void* emp2);
/** \brief Realiza el ordenamiento segun el criterio en este caso el nombre
 * \param emp1 puntero a void de empleado
 * \param emp2 puntero a void de empleado
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int employee_ordenarNombre(void*emp1,void* emp2);
/** \brief Realiza el ordenamiento segun el criterio en este caso horas trabajadsa
 * \param emp1 puntero a void de empleado
 * \param emp2 puntero a void de empleado
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int employee_ordenarHorasTrabajadas(void*emp1,void* emp2);

/** \brief Realiza el ordenamiento segun el criterio en este caso el sueldo
 * \param emp1 puntero a void de empleado
 * \param emp2 puntero a void de empleado
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int employee_ordenarPorSueldo(void*emp1,void* emp2);
#endif // employee_H_INCLUDED
