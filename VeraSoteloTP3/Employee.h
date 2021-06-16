#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


//prototipos funciones empleados

/** \brief Crea un empleado con los campos vacios
 *
 * \return Employee* retorna la direccion de memoria del empleado
 */
Employee* employee_new();

/** \brief Crea un empleado con los campos pasados por parametro
 *
 * \param idStr char* string de ID
 * \param nombreStr char* string de nombre
 * \param horasTrabajadasStr char* string de horas trabajadas
 * \param sueldo char* string de sueldo
 * \return Employee* retorna la direccion de memoria del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);


/** \brief Elimina un empleado, liberando su espacio en memoria
 *
 * \return void
 *
 */
void employee_delete();

/** \brief Imprime todos los campos de un empleado
 *
 * \param this Employee* empleado
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_print(Employee * this);

/** \brief Setea el ID de un empleado
 *
 * \param this Employee* empleado
 * \param id int
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Obtiene el ID de un empleado
 *
 * \param this Employee* empleado
 * \param id int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setea el ID de un empleado
 *
 * \param this Employee* empleado
 * \param nombre char*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea las horas trabajadas de un empleado
 *
 * \param this Employee* empleado
 * \param horasTrabajadas int
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* empleado
 * \param horasTrabajadas int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setea el sueldo de un empleado
 *
 * \param this Employee* empleado
 * \param sueldo int
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* empleado
 * \param sueldo int*
 * \return int - devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara sueldos de dos empleados
 *
 * \param a void* empleado A
 * \param b void* empleado B
 * \return int devuelve 1 si el sueldo del empleado A es mayor al del empleado B, -1 si es menor y 0 si son iguales
 *
 */
int employee_compareSueldo(void* a,void* b);

/** \brief Compara nombres de dos empleados
 *
 * \param a void* empleado A
 * \param b void* empleado B
 * \return int devuelve 1 si el nombre del empleado A es mayor al del empleado B, -1 si es menor y 0 si son iguales
 *
 */
int employee_compareNombre(void* a,void* b);

/** \brief Compara ID de dos empleados
 *
 * \param a void* empleado A
 * \param b void* empleado B
 * \return int devuelve 1 si el ID del empleado A es mayor al del empleado B, -1 si es menor y 0 si son iguales
 *
 */
int employee_compareId(void* a,void* b);

#endif // employee_H_INCLUDED
