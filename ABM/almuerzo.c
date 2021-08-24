#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"


void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
    if(almuerzos!=NULL && tam>0){
        for(int i=0; i<tam;i++){
            almuerzos[i].isEmpty=1;
        }
    }
}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam){
    int indice=-1;
    if(almuerzos!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            if (almuerzos[i].isEmpty){
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tam, int* idAlmuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamCom, eSector sectores[], int tamSect){
    int todoOk=0;
    eAlmuerzo nuevoAlmuerzo;
    int indice=buscarLibreAlmuerzo(almuerzos,tam);
    if(almuerzos != NULL && tam>0 && idAlmuerzo != NULL){
        if(indice==-1){
            printf("No hay lugar disponible.\n");
        }else{
            mostrarEmpleados(empleados,tamEmp,sectores,tamSect);
            nuevoAlmuerzo.idAlmuerzo=*idAlmuerzo;
            printf("    ALTA DE ALMUERZOS\n");
            printf ("Ingrese el legajo: ");
            scanf ("%d", &nuevoAlmuerzo.idEmpleado);
            while(buscarEmpleado(empleados,tamEmp,nuevoAlmuerzo.idEmpleado)==-1){
                printf ("Error. Ingrese un legajo valido: ");
                scanf ("%d", &nuevoAlmuerzo.idEmpleado);
            }
            printf("\n");
            mostrarComidas(comidas, tamCom);
            printf("Ingrese ID comida: ");
            scanf("%d", &nuevoAlmuerzo.idComida);
            while(buscarComida(comidas,tamCom,nuevoAlmuerzo.idComida)==-1){   ///MEJOR FORMA DE VERIFICAR QUE EXISTA EL EMPLEADO
                printf ("Error. Ingrese un ID valido: ");
                scanf ("%d", &nuevoAlmuerzo.idComida);
            }
            printf("Ingrese fecha (dd/mm/aaaa): ");
            scanf ("%d/%d/%d",&nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);
            while(nuevoAlmuerzo.fecha.dia<1||nuevoAlmuerzo.fecha.dia>31||nuevoAlmuerzo.fecha.mes<1||nuevoAlmuerzo.fecha.mes>12){
                printf ("Fecha invalida. Ingrese fecha (dd/mm/aaaa): ");
                scanf ("%d/%d/%d",&nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);
            }
            printf("\n");
            nuevoAlmuerzo.isEmpty=0;
            almuerzos[indice]=nuevoAlmuerzo;
            todoOk=1;
            (*idAlmuerzo)++;
        }
    }
    return todoOk;
}

int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamCom){
    int todoOk=0;
    int flag=1;
    printf(" Id   |  Id comida |  Legajo  |    Fecha\n");
    if(almuerzos != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if(!almuerzos[i].isEmpty){
                mostrarAlmuerzo(almuerzos[i], comidas, tamCom);
                flag=0;
            }
        }
        if(flag){
            printf("No hay almuerzos para mostrar\n");
        }
    todoOk=1;
    }
    printf("\n");
    return todoOk;
}

int mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom){
    int todoOk=0;
    char descripcion[20];
    if(comidas!=NULL && tamCom>0){
        if(cargarDescripcionComida(almuerzo.idComida, comidas, tamCom, descripcion)){
        printf(" %d   %10s    %d      %02d/%02d/%d\n", almuerzo.idAlmuerzo, descripcion, almuerzo.idEmpleado, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
        }
        todoOk=1;
    }
    return todoOk;
}


