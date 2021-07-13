

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);


static int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena )
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if( myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer) )
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

static int esFlotante(char* cadena)
{
    int retorno = 1; // devuelve true or false solamente
    int i = 0;
    int contadorPuntos = 0;

    if(cadena != NULL && strlen(cadena)>0)
    {
        fflush(stdin);
        if(cadena[0]!=' ')
        {
            for(; cadena[i] != '\0'; i++)
            {
                if(i == 0 && (cadena[i]=='-' || cadena[i] == '+'))
                {
                    continue;
                }

                if(cadena[i] < '0'|| cadena[i] >'9')
                {
                    if(cadena[i] == '.' && contadorPuntos == 0)
                    {
                        contadorPuntos++;
                    }
                    else
                    {
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }

    return retorno;
}


static int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer)) == 0 && esFlotante(buffer))
        {
            retorno = 0;
            *pResultado = atof(buffer);
        }
    }
    return retorno;
}



static int esNumerica(char* cadena)
{
    int i = 0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;

    int retorno = -1;

    do
    {

        printf("%s",mensaje);

        fflush(stdin);

        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);

        reintentos--;
    }
    while(reintentos > 0);

    return retorno;
}



int utn_getNumeroFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if(getFloat(&buffer) == 0 &&
                    buffer >= minimo &&
                    buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=0);
    }
    return retorno;
}




int getString(char* mensaje, char* mensajeError, int minimo, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);

            fgets(bufferStr,sizeof(bufferStr),stdin);

            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);

            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


int utn_getCadena(char* mensaje, char* mensajeError, int minimo, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(mensaje,mensajeError,minimo,max,&reintentos,bufferStr))
            {
                if(esNombreValido(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int esNombreValido(char* cadena)
{
    int retorno=1;
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {

        if(cadena[i]<'A' || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}




