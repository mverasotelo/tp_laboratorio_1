#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"


//constructor sin parametros
eEmpleado* newEmpleado(){    //funcion para crear un nuevo empleado en memoria y limpiar los campos
    eEmpleado* nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    if (nuevoEmpleado != NULL){
        nuevoEmpleado->legajo=0;
        nuevoEmpleado->sexo=0;
        nuevoEmpleado->sueldo=0;
        strcpy(nuevoEmpleado->nombre,"");
    }
    return nuevoEmpleado;
}

//constructor con parametros
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo){    //funcion para crear un nuevo empleado en memoria y limpiar los campos
    eEmpleado* nuevoEmpleado=newEmpleado();
    if (nuevoEmpleado != NULL){
        if (legajo > 0 && sueldo > 0){  //CAPA DE VALIDACION
            nuevoEmpleado->legajo=legajo;
            nuevoEmpleado->sexo=sexo;
            nuevoEmpleado->sueldo=sueldo;
            strcpy(nuevoEmpleado->nombre,nombre);
        }else{
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

//constructor con por buffer con char
eEmpleado* newEmpleadoBuffer(char* legajo, char* nombre, char* sexo, char* sueldo){    //funcion para crear un nuevo empleado en memoria y limpiar los campos
    eEmpleado* nuevoEmpleado=newEmpleado();
    if (nuevoEmpleado != NULL){
        if (legajo > 0 && sueldo > 0){  //CAPA DE VALIDACION
            nuevoEmpleado->legajo=atoi(legajo);
            nuevoEmpleado->sexo=tolower(sexo[0]);
            nuevoEmpleado->sueldo=atof(sueldo);
            strcpy(nuevoEmpleado->nombre,nombre);
        }else{
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

//SETTER PARA EL LEGAJO - Valida y guarda
int empleadoSetLegajo(eEmpleado * emp, int legajo){
    int retorno=0;
    if(emp != NULL && legajo > 1){
        emp->legajo=legajo;
        retorno=1;
    }
    return retorno;
}

//SETTER PARA EL SEXO - Valida y guarda
int empleadoSetSexo(eEmpleado * emp, char sexo){
    int retorno=0;
    if(emp != NULL && (sexo=='f' || sexo=='m')){
        emp->sexo=sexo;
        retorno=1;
    }
    return retorno;
}

//SETTER PARA EL NOMBRE - Valida y guarda
int empleadoSetNombre(eEmpleado * emp, char nombre[]){
    int retorno=0;
    if(emp!=NULL && strlen(nombre)<20 && strlen(nombre)>=3){
        strcpy(emp->nombre, nombre);
        retorno=1;
    }
    return retorno;
}


// GETTER PARA EL LEGAJO - Lee el valor
int empleadoGetLegajo(eEmpleado * emp, int* legajo){
    int retorno=0;
    if( emp != NULL && legajo != NULL){
        *legajo=emp->legajo;
        retorno=1;
    }
    return retorno;
}

// GETTER PARA EL LEGAJO - Lee el valor
int empleadoGetSueldo(eEmpleado * emp, float* sueldo){
    int retorno=0;
    if( emp != NULL && sueldo != NULL && &sueldo>0){
        *sueldo=emp->sueldo;
        retorno=1;
    }
    return retorno;
}

int empleadoGetSexo(eEmpleado * emp, char* sexo){
    int retorno=0;
    if( emp != NULL && sexo != NULL){
        *sexo=emp->sexo;
        retorno=1;
    }
    return retorno;
}

//muestra estructura dinamica
int mostrarEmpleado(eEmpleado* empleado){
    int todoOk=0;
    int legajo=0;
    char sexo;
    float sueldo=0;

    if(empleado!=NULL && empleadoGetLegajo(empleado, &legajo) && empleadoGetSueldo(empleado, &sueldo) && empleadoGetSexo(empleado, &sexo)){
        printf("   %4d   | %12s |  %c  |  $%8.2f\n", legajo, empleado->nombre, sexo, sueldo);
        todoOk=1;
    }
    return todoOk;
}

int mostrarEmpleados(eEmpleado* lista, int tam){
    int todoOk=0;
    if(lista!=NULL && tam>0){
        printf("Legajo     Nombre      Sexo     Sueldo   \n");
        for(int i=0;i<tam;i++){
            mostrarEmpleado(lista+i);
            todoOk=1;
        }
    }
    return todoOk;
}

int mostrarEmpleados2(eEmpleado** lista, int tam){
    int todoOk=0;
    if(lista!=NULL && tam>0){
        printf("  Legajo      Nombre      Sexo     Sueldo\n");
        for(int i=0;i<tam;i++){
            mostrarEmpleado(*(lista+i));
            todoOk=1;
        }
    }
    return todoOk;
}

int inicializarEmpleados(eEmpleado ** lista, int tam){
    int todoOk=0;
    if(lista!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            *(lista+i)=NULL;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarIndice(eEmpleado ** lista, int tam, int* pIndice){
    int todoOk=0;
    *pIndice= -1;
    if(lista!=NULL && tam>0 && pIndice!=NULL){
        for(int i=0;i<tam;i++){
            if(*(lista+i)== NULL){
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int agrandarArray(eEmpleado *** pLista, int * pTam){
    int todoOk=0;
    eEmpleado** aux;
    if(pLista!=NULL && pTam!=NULL){
        aux = (eEmpleado**) realloc(*pLista, sizeof(eEmpleado*) * (*pTam+1));
        if(aux!=NULL){
            *(aux+*pTam)=NULL;
            *pLista=aux;
            *pTam=*pTam+1;
            todoOk=1;
        }
    }
    return todoOk;
}


int ordenarArrayLegajo(eEmpleado ** lista, int tam){
    int todoOk=0;
    eEmpleado* aux = NULL;
    if(lista != NULL && tam > 0){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if(*(lista+i)!=NULL && ((*(lista+i))->legajo > (*(lista+j))->legajo)){
                    aux=*(lista+i);
                    *(lista+i)=*(lista+j);
                    *(lista+j)=aux;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarArrayNombre(eEmpleado ** lista, int tam){
    int todoOk=0;
    eEmpleado* aux = NULL;
    if(lista != NULL && tam > 0){
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                if(*(lista+i)!=NULL && (strcmp((*(lista+i))->nombre, (*(lista+j))->nombre))>0){
                    aux=*(lista+i);
                    *(lista+i)=*(lista+j);
                    *(lista+j)=aux;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int altaEmpleado(eEmpleado ** lista, int tam){
    int todoOk;
    eEmpleado* auxEmpleado;
    int indice;
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    buscarIndice(lista, tam, &indice);

    auxEmpleado = newEmpleado();

    if(auxEmpleado!=NULL && indice!=-1){
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        while(!empleadoSetLegajo(auxEmpleado, legajo))
        {
            printf("Legajo incorrecto. Ingrese legajo: ");
            scanf("%d", &legajo);
        }
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        while(!empleadoSetNombre(auxEmpleado, nombre))
        {
            printf("Hubo un error. Reingrese nombre: ");
            fflush(stdin);
            gets(nombre);
        }
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
        while(!empleadoSetSexo(auxEmpleado, sexo))
        {
            printf("Hubo un error. Ingrese sexo: ");
            setbuf(stdin, NULL);
            scanf("%c", &sexo);
        }
        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo);
        auxEmpleado->sueldo=sueldo;

        *(lista + indice)=auxEmpleado;
        auxEmpleado=NULL;

        todoOk=1;
    }
    return todoOk;
}
