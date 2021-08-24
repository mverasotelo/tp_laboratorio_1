#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"
#include "fecha.h"

typedef struct {
    int legajo;
    char nombre [20];
    int edad;
    char sexo;
    eFecha fechaIngreso;
    float sueldo;
    int idSector;
    int isEmpty;
}eEmpleado;


/** \brief Inicializa el campo "isEmpty" de todos los valores de la lista de empleados en 1 (libre)
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado empleados[], int tam);


/** \brief Busca si hay lugar libre en la lista de empleados
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \return int - Devuelve el primer indice libre en la lista, sino hay lugar devuelve -1
 *
 */
int buscarLugar(eEmpleado empleados[], int tam);


/** \brief cuenta empleados activos en una lista
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \return int - Devuelve cantidad de empleados activos
 *
 */
int contarEmpleados(eEmpleado empleados[], int tam);


/** \brief Muestra la lista de empleados activos y devuelve cantidad, sino hay empleados lo indica con un printf y devuelve 0
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param sectores eSector - Lista de sectores
 * \param tamSect int - Tamaño de la lista de sectores
 * \return int - Devuelve el primer indice libre en la lista, sino hay lugar devuelve -1
 *
 */
int mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);


/** \brief Muestra los datos de un empleado
 *
 * \param empleado eEmpleado - Empleado a mostrar
 * \param sectores eSector - Lista de sectores
 * \param tamSect int - Tamaño de la lista de sectores
 * \return void - Imprime los datos de un empleado
 *
 */
void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tamSect);


/** \brief Busca empleado en una lista por su número de legajo
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param legajo int - Num de legajo a buscar
 * \return int - Devuelve indice de la lista donde esta ubicado el empleado, sino se encuentra devuelve -1
 *
 */
int buscarEmpleado(eEmpleado empleados[], int tam, int legajo);

/** \brief Indica si un empleado esta activo
 *
 * \param empleado eEmpleado - empleado a evaluar
 * \return int - Devuelve 1 si esta activo y 0 si esta inactivo
 *
 */
int empleadoActivo(eEmpleado empleado);

void ordenarEmpleadosEdad(eEmpleado empleados[], int tam);

int ordenarEmpleadosNombre(eEmpleado empleados[], int tam, int orden);

int ordenarEmpleados(eEmpleado empleados[], int tam);

int altaEmpleado(eEmpleado empleados[], int tam, int *pId);

int bajaEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);

int modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);

int menuModificacion();

void modificarDato(eEmpleado empleados[], int tam, int legajo, int datoModif);


#endif // EMPLEADO_H_INCLUDED
