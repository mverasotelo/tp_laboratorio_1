#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"


int hardcodearAlmuerzos(eAlmuerzo almuerzos[],int tamA, int cant, int* pId){
    int totalAlm=0;
    if(almuerzos!=NULL && tamA>0 && cant>=0 && cant<=tamA && pId != NULL){
        for(int i=0; i<cant;i++){
            almuerzos[i].idAlmuerzo=*pId;
            (*pId)++;
            almuerzos[i].idEmpleado=idEmpleadosA[i];
            almuerzos[i].idComida=idComidasA[i];
            almuerzos[i].fecha=fechasA[i];
            almuerzos[i].isEmpty=0;
            totalAlm++;
        }
    }
    return totalAlm;
}

int hardcodearEmpleados(eEmpleado empleados[],int tam, int cant, int* pLegajo){
    int totalEmp=0;
    if(empleados!=NULL && tam>0 && cant>=0 && cant<=tam && pLegajo != NULL){
        for(int i=0; i<cant;i++){
            empleados[i].legajo=*pLegajo;
            (*pLegajo)++;
            strcpy(empleados[i].nombre, nombres[i]);
            empleados[i].edad=edades[i];
            empleados[i].sexo=sexos[i];
            empleados[i].sueldo=sueldos[i];
            empleados[i].fechaIngreso=ingreso[i];
            empleados[i].isEmpty=0;
            empleados[i].idSector=sectores[i];
            totalEmp++;
        }
    }
    return totalEmp;
}

