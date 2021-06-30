#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "rb");

        if(f==NULL)
        {
            printf("No se pudo abrir el archivo\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            if(parser_EmployeeFromBinary(f, pArrayListEmployee))
            {
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* nextId)
{
    int retorno = 0;
    Employee * aux =  NULL;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        aux =  employee_new();
        if(aux != NULL)
        {
            employee_setId(aux,*nextId);
            getNombre(nombre, 128);
            employee_setNombre(aux,nombre);
            printf("Ingrese horas trabajadas: ");
            scanf("%d", &horasTrabajadas);
            employee_setHorasTrabajadas(aux,horasTrabajadas);
            printf("Ingrese sueldo: ");
            scanf("%d", &sueldo);
            employee_setSueldo(aux,sueldo);
            printf("\n");

            ll_add(pArrayListEmployee, aux);
            (*nextId)++;
            retorno = 1;
        }
    }
    return retorno;
}

int controller_getId(LinkedList * pArrayListEmployee, int *nextId){
    int retorno = 0;
    int mayorId = 0;
    Employee * emp = NULL;

    if(pArrayListEmployee != NULL){
        for(int i=0; i<ll_len(pArrayListEmployee);i++){
            emp = ll_get(pArrayListEmployee, i);
            if(emp->id > mayorId)
            {
               mayorId = emp->id;
            }
        }
        *nextId = mayorId + 1;
        retorno = 1;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee * emp =  NULL;
    char nombre[128];
    int horasTrabajadas;
    int id;
    int indice = -1;
    int tam;
    int sueldo;


    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        emp =  employee_new();
        controller_ListEmployee(pArrayListEmployee);

        if(emp != NULL && tam > 0)
        {
            printf("Ingrese ID del empleado a modificar: ");
            scanf("%d", &id);
            printf("\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                emp = ll_get(pArrayListEmployee,i);
                if(emp->id == id)
                {
                    indice = i;
                    break;
                }
            }

            if(indice != -1)
            {
                switch(submenuModificacion())
                {
                case 1:
                    getNombre(nombre, 128);
                    if(employee_setNombre(emp,nombre))
                    {
                        retorno = 1;
                    }
                    break;
                case 2:
                    printf("Ingrese horas trabajadas: ");
                    scanf("%d", &horasTrabajadas);
                    if(employee_setHorasTrabajadas(emp,horasTrabajadas)){
                        retorno = 1;
                    }
                    break;
                case 3:
                    printf("Ingrese sueldo: ");
                    scanf("%d", &sueldo);
                    if(employee_setSueldo(emp,sueldo))
                    {
                        retorno = 1;
                    }
                    break;
                }
            }
            else
            {
                printf("No se ha encontrado el empleado con ID %d.", id);
            }
            printf("\n");
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee * emp = NULL;
    int indice = -1;
    int id;
    char salir;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese ID del empleado a borrar: ");
        scanf("%d", &id);

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            emp = ll_get(pArrayListEmployee,i);
            if(emp->id == id)
            {
                indice = i;
                break;
            }
        }
        printf("\n");

        if(indice != -1)
        {
            printf("Esta seguro de que desea eliminar el empleado (s/n) ?\n");
            fflush(stdin);
            salir = getchar();
            if(tolower(salir) == 's')
            {
                employee_delete(emp);
                ll_remove(pArrayListEmployee, indice);
                retorno = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n\n");
            }
        }
        else
        {
            printf("No se ha encontrado el empleado con ID %d\n\n", id);
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* aux = NULL;
    int tam = ll_len(pArrayListEmployee);

    printf("   ID       NOMBRE         HORAS TRAB.       SUELDO\n");
    if(pArrayListEmployee != NULL )
    {
        if(tam > 0)
        {
            for(int i=0;i<tam;i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                employee_print(ll_get(pArrayListEmployee,i));
            }
            printf("\n\n");
        }
        else
        {
            printf("No hay empleados para mostrar\n\n");
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee, int criterio, int orden)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        switch(criterio)
        {
            case 1:
                if(ll_sort(pArrayListEmployee,employee_compareId,orden))
                {
                    retorno = 1;
                }
                break;
            case 2:
                if(ll_sort(pArrayListEmployee,employee_compareNombre,orden))
                {
                    retorno = 1;
                }
                break;
            case 3:
                if(ll_sort(pArrayListEmployee,employee_compareSueldo, orden))
                {
                    retorno = 1;
                }
                break;
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int tam;
    int cant;
    Employee * aux = NULL;

    FILE* f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pArrayListEmployee != NULL)
        {
            tam = ll_len(pArrayListEmployee);
            for(int i=0;i<tam;i++)
            {
                aux=ll_get(pArrayListEmployee, i);
                if(aux != NULL){
                    cant = fprintf(f,"%d, %s, %d, %d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
                    if(cant < 4)
                    {
                        break;
                    }
                }
                retorno = 1;
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int tam;
    int cant;
    Employee * aux = NULL;

    FILE* f=fopen(path, "wb");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(pArrayListEmployee != NULL){
            tam = ll_len(pArrayListEmployee);
            for(int i=0;i<tam;i++){
                aux=ll_get(pArrayListEmployee, i);
                if(aux != NULL){
                    cant = fwrite(aux, sizeof(Employee), 1, f);
                    if(cant < 1){
                        break;
                    }
                }
                retorno = 1;
            }
        }
    }
    fclose(f);
    return retorno;
}

int controller_deleteEmployees(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee);i++)//libera el espacio en memoria de todos los empleados
        {
            aux =ll_get(pArrayListEmployee,i);
            employee_delete(aux);
        }
    }

    return retorno;
}

