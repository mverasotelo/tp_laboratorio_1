#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VeraSotelo.h"

int menuOpciones(){
    int opcion;
    printf("     GESTION DE EMPLEADOS\n");
    printf("1) ALTAS\n2) MODIFICAR\n3) BAJAS\n4) INFORMAR\n5) SALIR\n\n");
	opcion=getOption(1,5);
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
	printf("1. Listado de los empleados ordenados alfab�ticamente por apellido y sector.\n");
	printf("2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.\n\n");
	opcion=getOption(1,2);
    return opcion;
}

int getOption(int min, int max){
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min&&opcion>max){
        printf("Opcion invalida. Ingrese nuevamente: ");
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getString(char *string, int maxLen){
    int retorno=-1;
    if(string!=NULL){
        fflush(stdin);
        gets(string);
        while(strlen(string)>maxLen){
            printf("El maximo numero de caracteres permitidos es %d. Reingrese dato:",maxLen);
            gets(string);
        }
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
            scanf ("%d", sector);
        }
        retorno=0;
    }
    return retorno;
}

