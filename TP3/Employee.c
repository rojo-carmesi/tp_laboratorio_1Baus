#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"



Employee* employee_new()
{

    Employee* nuevoEmpleado;

    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    return nuevoEmpleado;
}

Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = NULL;
    nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        if(employee_setId(nuevoEmpleado,atoi(idStr)) == 1 ||
                employee_setNombre(nuevoEmpleado, nombreStr)== 1||
                employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))== 1
                || employee_setSueldo(nuevoEmpleado, atoi(sueldo))== 1)
        {
            employee_delete(nuevoEmpleado);
        }
    }
    return nuevoEmpleado;

}

Employee* employee_newParametrosInt(int id,char* nombre,int horasTrabajadas, int sueldo)
{
    Employee* nuevoEmpleado;

    nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        printf("%d",id);
        if(employee_setId(nuevoEmpleado,id) == 1 ||
                employee_setNombre(nuevoEmpleado, nombre)== 1||
                employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas)== 1
                || employee_setSueldo(nuevoEmpleado,sueldo)== 1)
        {
            employee_delete(nuevoEmpleado);
        }
    }

    return nuevoEmpleado;
}

int employee_buscarPorId(LinkedList* pArrayListaDeEmpleados, int idBuscado)
{
    int retorno = -1;
    int auxiliarId;
    int tamanio;
    Employee* auxiliarEmpleado;

    if(pArrayListaDeEmpleados != NULL && idBuscado>0)
    {
        tamanio = ll_len(pArrayListaDeEmpleados);
        for(int i = 0; i<tamanio; i++)
        {
            auxiliarEmpleado = ll_get(pArrayListaDeEmpleados,i);

            if(!employee_getId(auxiliarEmpleado,&auxiliarId)&& auxiliarId == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = 0;
	Employee* auxEmp = NULL;
	int mayorId;
	if(pArrayListEmployee!=NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
			if(i == 0 || auxEmp->id > mayorId)
			{
				mayorId = auxEmp->id;
			}
		}
		*id = mayorId + 1;
		retorno = 1;
	}
	return retorno;
}

void employee_delete(Employee* this)
{
    free(this);
}

int mostrarEmpleado(Employee* empleado)
{
    int error = 0;
    char nombre[51];
    int id;
    int sueldo;
    int horasTrabajadas;

    if(empleado != NULL )
    {
        if(!employee_getHorasTrabajadas(empleado,&horasTrabajadas)&&
                !employee_getId(empleado,&id) && !employee_getNombre(empleado,nombre) &&
                !employee_getSueldo(empleado,&sueldo))
        {
            printf("%d        %10s         %4d                %5d\n",id,nombre,horasTrabajadas,sueldo);
            error = 1;
        }
    }

    return error;
}

int employee_setId(Employee* this, int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre)>0 && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int error = 1;

    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_setSueldo(Employee* this, int sueldo)
{
    int error = 1;

    if(this != NULL && sueldo >=0)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = 1;

    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 1;
    if(this != NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if(this != NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}

int employee_ordenarPorId(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empleadoA = NULL;
    Employee* empleadoB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empleadoA = (Employee*) emp1;
        empleadoB = (Employee*) emp2;


        if(empleadoA->id > empleadoB->id)
        {
            retorno = 1;
        }
        else
        {

            retorno = -1;

        }
    }

    return retorno;
}


int employee_ordenarNombre(void*emp1,void* emp2)
{
    int retorno = 0;
    Employee* empleadoA = NULL;
    Employee* empleadoB = NULL;

    if(emp1 != NULL && emp2 !=NULL)
    {
        empleadoA = (Employee*) emp1;
        empleadoB = (Employee*) emp2;

        if(strcmp(empleadoA->nombre,empleadoB->nombre)>0)
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(empleadoA->nombre,empleadoB->nombre)== 0)
            {
                retorno = 0;
            }else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

int employee_ordenarHorasTrabajadas(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empleadoA = NULL;
    Employee* empleadoB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empleadoA = (Employee*) emp1;
        empleadoB = (Employee*) emp2;


        if(empleadoA->horasTrabajadas > empleadoB->horasTrabajadas)
        {
            retorno = 1;
        }
        else
        {
            if(empleadoA->horasTrabajadas == empleadoB->horasTrabajadas)
            {
                retorno = 0;
            }else
            {
                 retorno = -1;
            }
        }
    }

    return retorno;
}

int employee_ordenarPorSueldo(void*emp1,void* emp2)
{
    int retorno = 0;

    Employee* empleadoA = NULL;
    Employee* empleadoB = NULL;


    if(emp1 != NULL && emp2 != NULL)
    {
        empleadoA = (Employee*) emp1;
        empleadoB = (Employee*) emp2;


        if(empleadoA->sueldo > empleadoB->sueldo)
        {
            retorno = 1;
        }
        else
        {
            if(empleadoA->sueldo == empleadoB->sueldo)
            {
                retorno = 0;
            }else
            {
                 retorno = -1;
            }
        }
    }

    return retorno;
}
