#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos);
int esNombreValido(char* cadena);
int utn_getCadena(char* mensaje, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getString(char* mensaje, char* msgError, int minimo, int maximo, int* reintentos, char* resultado);

#endif // UTN_H_INCLUDED
