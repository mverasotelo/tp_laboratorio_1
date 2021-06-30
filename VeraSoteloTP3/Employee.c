#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre,"");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* newEmployee=employee_new();
    if (newEmployee != NULL)
    {
        if (atoi(idStr) > 0 && atoi(horasTrabajadasStr) > 1)
        {
            employee_setId(newEmployee, atoi(idStr));
            employee_setNombre(newEmployee, nombreStr);
            employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
            employee_setSueldo(newEmployee, atoi(sueldo));
        }
        else
        {
            free(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_print(Employee * this){
    int retorno = 0;

    if(this != NULL){
        printf(" %4d  %15s      %6d      %10d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        retorno = 1;
    }
    return retorno;
}


//GETTER Y SETTER ID
int employee_setId(Employee* this,int id)
{
    int retorno=0;
    if(this != NULL && id > 0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno=0;
    if( this != NULL && id != NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER NOMBRE
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if( this != NULL && nombre!=NULL )
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 1)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if( this != NULL && horasTrabajadas!=NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

//GETTER Y SETTER SUELDO
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 1)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

//comparison
int employee_compareId(void* a,void* b)
{
    int retorno = 0;
    Employee * emp1 = NULL;
    Employee * emp2 = NULL;

    if( a != NULL && b != NULL)
    {
         emp1 = (Employee*) a;
         emp2 = (Employee*) b;

        if(emp1->id > emp2 -> id)
        {
            retorno = 1;
        }
        else if(emp1-> id < emp2 -> id)
        {
            retorno = -1;
        }
    }
    return retorno;
}


int employee_compareSueldo(void* a,void* b)
{
    int retorno = 0;
    Employee * emp1 = NULL;
    Employee * emp2 = NULL;

    if( a != NULL && b != NULL)
    {
         emp1 = (Employee*) a;
         emp2 = (Employee*) b;
        if(emp1->sueldo > emp2 -> sueldo)
        {
            retorno = 1;
        }
        else if(emp1-> sueldo < emp2 -> sueldo)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int employee_compareNombre(void* a,void* b)
{
    int retorno = 0;
    Employee * emp1 = NULL;
    Employee * emp2 = NULL;

    if( a != NULL && b != NULL)
    {
         emp1 = (Employee*) a;
         emp2 = (Employee*) b;

        if(strcmp(emp1-> nombre, emp2-> nombre) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(emp1-> nombre, emp2-> nombre) == -1)
        {
            retorno = -1;
        }
    }
    return retorno;
}
