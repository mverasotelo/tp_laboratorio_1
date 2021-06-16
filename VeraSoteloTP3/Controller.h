#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include "LinkedList.h"
#include "Employee.h"
#include "VeraSotelo.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* nextId);

/** \brief Calcula el proximo ID a ser asignado
 *
 * \param pArrayListEmployee LinkedList* lista
 * \param nextId int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_getId(LinkedList * pArrayListEmployee, int *nextId);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados por criterios
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee, int criterio, int orden);

/** \brief Guarda los datos de los empleados en un archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en un archivo (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

#endif // controller_H_INCLUDED

