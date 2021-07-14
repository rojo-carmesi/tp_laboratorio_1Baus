#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/*
 * \brief pide un número entero
 * \param puntero para guardar el número entero
 * \param mensaje del menu para pedir el numero
 * \param mensaje de error si no es valido
 * \param  numero minimo aceptado
 * \param  numero maximo aceptado
 * \param cantidad de reintentos

 * \return 0 si ha salido ok. -1 si no lo logro
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/*
 * \brief pide un número float
 * \param puntero para guardar el número float
 * \param mensaje del menu para pedir el numero
 * \param mensaje de error si no es valido
 * \param  float minimo aceptado
 * \param  float maximo aceptado
 * \param cantidad de reintentos

 * \return 0 si ha salido ok. -1 si no lo logro
 */

int utn_getNumeroFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos);

/*
 * \brief Valida que la cadena recibida sea un nombre valido
 * \param puntero con el string validado.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */

int esNombreValido(char* cadena);
/*
 * \brief solicita una cadena de caracteres.
 * \param puntero con la cadena.
 * \param mensaje para pedir la cadena..
 * \param mensaje de error si no es valida.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return 0 si ha salido ok. -1 si no.
 */

int utn_getCadena(char* mensaje, char* msgError, int minimo, int maximo, int reintentos, char* resultado);

/*
 * \brief Valida que la cadena recibida sea un string valido
 * \param mensaje para pedir cadena
 * \param mensaje Error pra mostrar el error.
 * \param minimo minimo de la cadena
 * \param maximo de la cadena
 * \param reintentos escalar que determina los reintentos.
 * \param variable donde se guarda el string validado.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */
int getString(char* mensaje, char* msgError, int minimo, int maximo, int* reintentos, char* resultado);

#endif // UTN_H_INCLUDED
