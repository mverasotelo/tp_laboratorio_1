#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "empleado.h"
#include "almuerzo.h"
#include "fecha.h"

static char nombres[10][20]={
    "Paula",
    "Julia",
    "Fernanda",
    "Laura",
    "Gonzalo",
    "Mabel",
    "Clarisa",
    "Maria",
    "Hernan",
    "Juan"
};

static int edades[10]={31,38,40,40,35,38,25,32,34,35};

static char sexos[10]={'f','f','f','f','m','f','f','f','m','m'};

static float sueldos[10]={20000,50000,50000,20000,20000,55000,50000,65000,50000,72500};

static eFecha ingreso[10]={{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005},{01,01,2005}};

static int sectores[10]={501,500,502,503,501,501,502,503,500,504};

static int idEmpleadosA[15]={2000,2001,2000,2002,2005,2004,2006,2005,2005,2000,2004,2006,2000,2005,2008};

static int idComidasA[15]={1000,1000,1002,1001,1003,1004,1004,1002,1005,1006,1002,1001,1003,1004,1004};

static eFecha fechasA[15]={{1,5,2021},{10,5,2021},{1,6,2021},{10,6,2021},{6,5,2021},{1,5,2021},{8,5,2021},{4,5,2021},{6,5,2021},{1,5,2021},{10,5,2021},{1,6,2021},{10,6,2021},{6,5,2021},{1,5,2021}};

//prototipos funciones

int hardcodearEmpleados(eEmpleado empleados[],int tam, int cant, int* pLegajo);

int hardcodearAlmuerzos(eAlmuerzo almuerzos[],int tamA, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED

