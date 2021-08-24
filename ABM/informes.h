#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "empleado.h"
#include "almuerzo.h"
#include "sector.h"

/** \brief Muestra la cantidad de empleados en un sector
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param sectores[] eSector - Lista de sectores
 * \param tamSect int - Tamaño de la lista de sectores
 * \return int devuelve la cantidad de empleados
 *
 */
int empleadosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);

/** \brief Aumentar sueldo de un sector
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param sectores[] eSector - Lista de sectores
 * \param tamSect int - Tamaño de la lista de sectores
 * \return int - Devuelve 1 si esta todo Ok, devuelve 0 si hay algun error
 *
 */
int aumentarSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);


/** \brief Muestra el total de los salarios de cada sector
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param sectores[] eSector
 * \param tamSect int
 * \return int
 *
 */
int aPonerla(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);


/** \brief Muestra el sector que mas cobra
 *
 * \param empleados[] eEmpleado - Lista total de empleados
 * \param tam int - Tamaño de la lista de empleados
 * \param sectores[] eSector
 * \param tamSect int
 * \return int
 *
 */

int sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamSect);

int totalesComidaxSector(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA, eComida comidas[], int tamC);

int comidaPreferidaSector(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA, eComida comidas[], int tamC);

int SectorAmanteMilanesa(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA);

#endif // INFORMES_H_INCLUDED
