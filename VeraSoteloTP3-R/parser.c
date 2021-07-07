#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char buffer[4][20];
    int cant;
    Employee * aux = NULL;

    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant == 4)
            {
                aux=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(aux!=NULL)
                {
                    ll_add(pArrayListEmployee,aux);
                    aux=NULL;
                }
                else
                {
                    printf("No se pudo cargar el empleado\n");
                }
                retorno=1;
            }
            else
            {
                printf("Ha ocurrido un error al leer los datos\n");
            }
        }
        while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cant;
    Employee * aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            aux=employee_new();
            if (aux != NULL)
            {
                cant = fread(aux, sizeof(Employee), 1, pFile);
                if(cant==1)
                {
                    ll_add(pArrayListEmployee,aux);
                    aux=NULL;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
