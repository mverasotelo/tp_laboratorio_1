#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "fecha.h"
#include "empleado.h"
#include "comidas.h"


typedef struct{ //hace que la relacion entre empleados y comidas sea 1:1

int idAlmuerzo;
int idEmpleado;
int idComida;
int isEmpty;
eFecha fecha;

}eAlmuerzo;

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam);

int altaAlmuerzo(eAlmuerzo almuerzos[], int tam, int* idAlmuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eSector sectores[], int tamSect);

int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamCom);

int mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom);


#endif // ALMUERZO_H_INCLUDED

