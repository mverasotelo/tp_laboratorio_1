#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "VeraSotelo.h"

struct{
	int id;
	char name[TAMSTR];
	char lastName[TAMSTR];
	float salary;
	int sector;
	int isEmpty;
}typedef eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list eEmployee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(eEmployee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list eEmployee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Busca si hay lugar libre en un array de eEmployee
 *
 * \param list[] eEmployee - Array
 * \param len int - Tama?o del array
 * \return int - Devuelve el primer indice libre en el array, sino encuentra lugar devuelve -1*
 */
int findEmptyPosition(eEmployee* list, int len);

/** \brief find an Employee by Id en returns the index position in array.
*
 * \param list[] eEmployee - Array
 * \param len int - Tama?o del array
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
 * \param list[] eEmployee - Array
 * \param len int - Tama?o del array
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* list, int len, int id);

/** \brief print the content of employees array
*
* \param list eEmployee* lista de empleados
* \param length int tama?o de la lista
* \return int retorna cantidad de empleados activos
*
*/
int printEmployees(eEmployee* list, int length);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
 * \param list[] eEmployee - Array
 * \param len int - Tama?o del array
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee* list, int len, int order);


/** \brief Cuenta los empleados activos en un listado
 *
 * \param list eEmployee*
 * \param length int
 * \return int Devuelve la cantidad de empleados activos
 *
 */
int countEmployees(eEmployee* list, int length);

/** \brief Modifica datos de empleados activos
 *
 * \param list[] eEmployee - Array
 * \param len int - Tama?o del array
 * \param id int id del empleado
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int modifyEmployee(eEmployee* list, int len, int id);

//Total y promedio de los salarios, y cu?ntos empleados superan el salario promedio.

/** \brief Imprime el total de todos los salarios, el salario promedio y la cantidad de empleados que superan el salario promedio.
 *
 * \param list eEmployee* lista de empleados
 * \param len int tama?o de la lista
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int avarageSalary(eEmployee* list, int len);
