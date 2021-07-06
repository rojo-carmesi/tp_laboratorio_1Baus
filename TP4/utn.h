#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED




#ifndef UTN_H_
#define UTN_H_

#define ARRAY_SIZE 4096


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
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/*
 * \brief solicita una cadena de caracteres.
 * \param puntero con la cadena.
 * \param mensaje para pedir la cadena..
 * \param mensaje de error si no es valida.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
/*
 * \brief Valida que la cadena recibida sea un nombre valido
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */
int esNombreValido(char* string, int len);

/*
 * \brief valida que la cadena recibida es un número entero valido
 * \param puntero del string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si es un número entero. 0 (falso) si no lo es.
 */

int esNumericaInt(char* cadena, int len);

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif /*  */

#endif // UTN_H_INCLUDED

