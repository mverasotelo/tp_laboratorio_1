#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

void inicializarEmpleados(eEmpleado empleados[], int tam){
    for(int i=0; i<tam;i++){
        empleados[i].isEmpty=1;
    }
}

int buscarLugar(eEmpleado empleados[], int tam){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (!empleadoActivo(empleados[i])){
            indice=i;
            break;
        }
    }
    return indice;
}

int contarEmpleados(eEmpleado empleados[], int tam){
    int cantEmp=0;
    if(empleados!=NULL&&tam<0){
        for(int i=0;i<tam;i++){
            if (empleadoActivo(empleados[i])){
                cantEmp++;
            }
        }
    }
    return cantEmp;
}

int mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int cantidadEmpleados=0;
    int flag=0;
    printf(" Legajo |   Nombre   |  Edad  |  Ingreso   | Sexo |  Sueldo   | Sector \n");
    for(int i=0;i<tam;i++){
        if (empleadoActivo(empleados[i])){
            mostrarEmpleado(empleados[i], sectores,tamSect);
            flag=1;
            cantidadEmpleados++;
        }
    }
    if(!flag){
        printf("No hay empleados para mostrar\n");
    }
    printf("\n");
    return cantidadEmpleados;
}

void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tamSect){
    char descripcion[20];
    cargarDescripcionSectores(empleado.idSector, sectores, tamSect, descripcion);

    printf(" %04d   | %10s |   %d   | %02d/%02d/%d |  %c   | $%7.2f | %3s\n",
        empleado.legajo,
        empleado.nombre,
        empleado.edad,
        empleado.fechaIngreso.dia,
        empleado.fechaIngreso.mes,
        empleado.fechaIngreso.anio,
        empleado.sexo,
        empleado.sueldo,
        descripcion);
}

int buscarEmpleado(eEmpleado empleados[], int tam, int legajo){
    int indiceEmpleado=-1;
    for(int i=0;i<tam;i++){
        if (empleadoActivo(empleados[i]) && empleados[i].legajo==legajo){
            indiceEmpleado=i;
            break;
        }
    }
    return indiceEmpleado;
}

int empleadoActivo(eEmpleado empleado){
    return !empleado.isEmpty;
}

int altaEmpleado(eEmpleado empleados[], int tam, int *pId){
    int todoOk=0;
    int indice=buscarLugar(empleados, tam);
    eEmpleado nuevoEmpleado;
    if(empleados != NULL && tam>0 && pId != NULL){
        if(indice==-1){
            printf("No hay lugar disponible.\n");
        }else{
            nuevoEmpleado.legajo=*pId;
            printf("    ALTA DE EMPLEADOS\n");
            printf ("Legajo: %d\n", nuevoEmpleado.legajo);
            printf ("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf ("Ingrese edad: ");
            scanf ("%d", &nuevoEmpleado.edad);
            while(nuevoEmpleado.edad<18||nuevoEmpleado.edad>65){
                printf ("Error. Ingrese una edad valida: ");
                scanf ("%d", &nuevoEmpleado.edad);
            }
            printf ("Ingrese sexo (f/m): ");
            fflush (stdin);
            scanf ("%c", &nuevoEmpleado.sexo);
            while(nuevoEmpleado.sexo!='f'&&nuevoEmpleado.sexo!='m'){
                printf ("Error. Ingrese sexo (f/m): ");
                fflush (stdin);
                scanf ("%c", &nuevoEmpleado.sexo);
            }
            printf ("Ingrese sueldo: ");
            scanf ("%f", &nuevoEmpleado.sueldo);
            while(nuevoEmpleado.sueldo<0){
                printf ("Error. Ingrese sueldo: ");
                scanf ("%f", &nuevoEmpleado.sueldo);
            }
            printf("Ingrese fecha de ingreso (dd/mm/aaaa): ");
            scanf ("%d/%d/%d",&nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);
            while(nuevoEmpleado.fechaIngreso.dia<1||nuevoEmpleado.fechaIngreso.dia>31||nuevoEmpleado.fechaIngreso.mes<1||nuevoEmpleado.fechaIngreso.mes>12){
                printf ("Fecha invalida. Ingrese fecha de ingreso (dd/mm/aaaa): ");
                scanf ("%f", &nuevoEmpleado.sueldo);
            }
            printf("\n");
            nuevoEmpleado.isEmpty=0;
            empleados[indice]=nuevoEmpleado;
            todoOk=1;
            (*pId)++;
        }
    }
    return todoOk;
}


int modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int todoOk=0;
    int legajo;
    int indice;
    printf("    MODIFICAR EMPLEADOS\n");
    int contEmpleados=mostrarEmpleados(empleados,tam,sectores,tamSect);
    if(contEmpleados>0){
        printf("Ingrese legajo del empleado a modificar: ");
        scanf("%d",&legajo);
        printf("\n");
        indice=buscarEmpleado(empleados,tam,legajo);
        if(indice!=-1){
            modificarDato(empleados,tam,legajo,menuModificacion());
        }else{
            printf("No existe el empleado con el legajo %d.\n\n", legajo);
        }
    }
    return todoOk;
}

void modificarDato(eEmpleado empleados[], int tam, int legajo, int datoModif){
    int indiceEmpleado=buscarEmpleado(empleados,tam,legajo);
    switch (datoModif){
    case 1:
        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(empleados[indiceEmpleado].nombre);
        break;
    case 2:
        printf ("Ingrese edad: ");
        scanf ("%d", &empleados[indiceEmpleado].edad);
        break;
    case 3:
        printf ("Ingrese sexo: ");
        fflush (stdin);
        scanf ("%c", &empleados[indiceEmpleado].sexo);
        break;
    case 4:
        printf ("Ingrese sueldo: ");
        scanf ("%f", &empleados[indiceEmpleado].sueldo);
        while(empleados[indiceEmpleado].sueldo<0){
            printf ("Error. Ingrese sueldo: ");
            scanf ("%f", &empleados[indiceEmpleado].sueldo);
        }
        break;
    case 5:
        printf("Ingrese fecha de ingreso (dd/mm/aaaa): ");
        scanf ("%d/%d/%d",&empleados[indiceEmpleado].fechaIngreso.dia, &empleados[indiceEmpleado].fechaIngreso.mes, &empleados[indiceEmpleado].fechaIngreso.anio);
        break;
    default:
        printf("Opcion invalida\n\n");
    }
}

int menuModificacion(){
    int opcion;
    printf("Dato a modificar:\n");
    printf("1) Nombre\n2) Edad\n3) Sexo\n4) Sueldo\n5) Fecha de ingreso \n6) Sector\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("\n");
    return opcion;
}

int bajaEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int todoOk=0;
    int legajo;
    int indiceEmpleado;
    int contEmpleados;
    char confirmar;
    printf("    BAJA DE EMPLEADOS\n");
    contEmpleados = mostrarEmpleados(empleados,tam, sectores,tamSect);
    if(contEmpleados>0){
        printf("Legajo del empleado a dar de baja: ");
        scanf("%d", &legajo);
        printf("\n");
        indiceEmpleado=buscarEmpleado(empleados,tam,legajo);
        if(indiceEmpleado!=-1){
            printf("Seguro que desea dar de baja al empleado?\n");
            fflush (stdin);
            scanf("%c", &confirmar);
            if(confirmar=='s'){
                empleados[indiceEmpleado].isEmpty=1;
                todoOk=1;
            }else{
                printf("Baja cancelada por el usuario.\n");
            }
        }else{
            printf("No existe el empleado con el legajo %d.\n", legajo);
        }
    }
    return todoOk;
}

void ordenarEmpleadosEdad(eEmpleado empleados[], int tam){
    eEmpleado aux;
    for(int i=0; i<tam-1;i++){
        for(int j=1; j<tam; j++){
            if(empleados[i].edad>empleados[j].edad){
                    aux=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=aux;
            }
        }
    }
}

int ordenarEmpleadosNombre(eEmpleado empleados[], int tam, int orden){
    int todoOk=0;
    eEmpleado aux;
    if(empleados!=NULL && tam>0){
        for(int i=0; i<tam-1;i++){
            for(int j=1; j<tam; j++){
                if(empleadoActivo(empleados[i])&&((orden==0&&strcmp(empleados[i].nombre,empleados[j].nombre)>=0)||(orden==1&&strcmp(empleados[i].nombre,empleados[j].nombre)<0))){
                        aux=empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=aux;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarEmpleados(eEmpleado empleados[], int tam){
    eEmpleado aux;
    int todoOk=0;
    for(int i=0; i<tam-1;i++){
        for(int j=1; j<tam; j++){
            if(empleadoActivo(empleados[i])){
                if(empleados[i].sexo<empleados[j].sexo||(empleados[i].sexo==empleados[j].sexo&&empleados[i].edad>empleados[j].edad)){
                    aux=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=aux;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}
