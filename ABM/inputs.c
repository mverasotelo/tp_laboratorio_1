#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int menuOpciones(){
    int opcion;
    printf("     GESTION DE EMPLEADOS\n");
    printf("1) Alta Empleado\n");
    printf("2) Modificar Empleado\n");
    printf("3) Baja Empleado\n");
    printf("4) Listar Empleados\n");
    printf("5) Ordenar Empleados\n");
    printf("6) Mostrar Sectores\n");
    printf("7) Cantidad Empleados por Sector\n");
    printf("8) Actualizar sueldos por sector\n");
    printf("9) Total sueldos por sector\n");
    printf("10) Sector que mas cobra\n");
    printf("11) \n");
    printf("12) Mostrar comidas\n");
    printf("13) Alta almuerzo\n");
    printf("14) Listar almuerzos\n");
    printf("15) Total comidas por sector\n");
    printf("16) Comida preferida de cada sector\n");
    printf("17) Sector que mas come milanesa\n");
    printf("18) Sector que mas come milanesa\n");
    printf("19) Salir\n\n");
    opcion=getOption(1,19);
    return opcion;
}

int submenuModificar(){
    int opcion;
    printf("Que dato desea modificar?\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n\n");
	opcion=getOption(1,4);
    return opcion;
}

int submenuInformes(){
    int opcion;
	printf("1. Listado de los empleados ordenados alfabéticamente por apellido y sector.\n");
	printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n\n");
	opcion=getOption(1,2);
    return opcion;
}

int getOption(int min, int max){
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min||opcion>max){
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getString(char *string, int maxLen){
    int retorno=-1;
    char aux[100];
    if(string!=NULL && maxLen>0 && maxLen<99){
        fflush(stdin);
        fgets(aux,100,stdin);
        while(strlen(aux)>maxLen){
            printf("El maximo numero de caracteres permitidos es %d. Reingrese dato: ",maxLen);
            fflush(stdin);
            fgets(aux,100,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(string, aux);
        retorno=0;
    }
    return retorno;
}


int getSalary(float *salary, float salarioMinimo){
    int retorno=-1;
    if(salary!=NULL){
        scanf ("%f", salary);
        while(*salary<salarioMinimo){
            printf ("El salario no puede ser menor a $%.2f. Reingrese salario: ", salarioMinimo);
            fflush(stdin);
            scanf ("%f", salary);
        }
        retorno=0;
    }
    return retorno;
}


int getSector(int* sector, int minSector, int maxSector){
    int retorno=-1;
    if(sector!=NULL){
        scanf ("%d", sector);
        while(*sector<minSector||*sector>maxSector){
            printf ("Error. Ingrese un sector valido: ");
            fflush(stdin);
            scanf ("%d", sector);
        }
        retorno=0;
    }
    return retorno;
}
