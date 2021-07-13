#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


#ifndef UTN_H_
#define UTN_H_

#define ARRAY_SIZE 4096
#define INTENTOS 2

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
 * \brief solicita una cadena de caracteres.
 * \param puntero con la cadena.
 * \param mensaje para pedir la cadena..
 * \param mensaje de error si no es valida.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return 0 si ha salido ok. -1 si no.
 */

int utn_getCadena(char* mensaje, char* mensajeError, int minimo, int max, int reintentos, char* resultado);

/*
 * \brief Valida que la cadena recibida sea un nombre valido
 * \param puntero con el string validado.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */

int esNombreValido(char* cadena);


int getString(char* mensaje, char* msgError, int minimo, int maximo, int* reintentos, char* resultado);

#endif /* UTN_H_ */

#endif // UTN_H_INCLUDED
