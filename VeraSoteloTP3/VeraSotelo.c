#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VeraSotelo.h"

int menuOpciones()
{
    int opcion;
    printf("\n                             NOMINA DE EMPLEADOS\n");
    printf("  __________________________________________________________________________\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n\n");
    opcion=getOption(1,10);
    return opcion;
}

int submenuCriterio()
{
    int opcion;
    printf("1. Ordenar por ID.\n");
    printf("2. Ordenar por nombre.\n");
    printf("3. Ordenar por sueldo.\n\n");
    opcion=getOption(1,3);
    return opcion;
}

int submenuOrden()
{
    int opcion;
    printf("1. Descendiente\n");
    printf("2. Ascendiente.\n\n");
    opcion=getOption(1,2);
    return opcion;
}

int submenuModificacion()
{
    int opcion;
    printf("1. Nombre\n");
    printf("2. Horas trabajadas\n");
    printf("3. Sueldo\n\n");
    opcion=getOption(1,3);
    return opcion;
}

int getOption(int min, int max)
{
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min||opcion>max)
    {
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getNombre(char *nombre, int maxLen)
{
    int retorno=0;
    char aux[maxLen+5];
    if(nombre!=NULL && maxLen>0 && maxLen<maxLen+5)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(aux,maxLen+5,stdin);
        while(strlen(aux)>maxLen)
        {
            printf("El maximo numero de caracteres permitidos es %d. Reingrese nombre: ",maxLen);
            fflush(stdin);
            fgets(aux,maxLen+5,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(nombre, aux);
        retorno=1;
    }
    return retorno;
}
