#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;
    system("cls");

    do{
        printf("***** TP4 LINKEDLIST ***\n\n");
        printf("-----------------------------\n")

        utn_getNumeroInt(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",0,10,4);

       }while(opcion<1 || opcion>10);

   return opcion;
}
