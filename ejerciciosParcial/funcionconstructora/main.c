#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);
int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados(eEmpleado* lista, int tam);
int empleadoSetLegajo(eEmpleado * emp, int legajo);
//getters
int empleadoGetLegajo(eEmpleado * emp, int* legajo);
int empleadoGetSueldo(eEmpleado * emp, float* sueldo);
int empleadoGetSexo(eEmpleado * emp, char* sexo);


int main()
{
    eEmpleado* pEmp = newEmpleado();
    eEmpleado* pEmp2 = newEmpleadoParam(1000, "Mercedes", 'f', 5000);

    if(pEmp==NULL){
        printf("Problemas al crear el empleado\n");
        exit(1);
    }

    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)*3);

    (lista+0)->sexo='f';
    (lista+0)->sueldo=50000;
    (lista+0)->legajo=120;
    strcpy((lista+0)->nombre,"Mercedes");

    (lista+1)->sexo='f';
    (lista+1)->sueldo=55000;
    (lista+1)->legajo=121;
    strcpy((lista+1)->nombre,"Jose");

    (lista+2)->sexo='m';
    (lista+2)->sueldo=60000;
    (lista+2)->legajo=122;
    strcpy((lista+2)->nombre,"Pedro");

    mostrarEmpleados(lista,3);
    printf("\n");

    /*strcpy(pEmp->nombre, "Mercedes");
    pEmp->sexo='f';
    pEmp->sueldo=35000;
    empleadoSetLegajo(pEmp, 6);
    mostrarEmpleado(pEmp);
    mostrarEmpleado(pEmp2);
    free(pEmp);
    free(pEmp2);*/

    free(lista);
    return 0;
}

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

//SETTER PARA EL LEGAJO - Valida y guarda
int empleadoSetLegajo(eEmpleado * emp, int legajo){
    int retorno=0;
    if(emp != NULL && legajo > 1){
        emp->legajo=legajo;
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
    char sexo=NULL;
    float sueldo=0;

    if(empleado!=NULL && empleadoGetLegajo(empleado, &legajo) && empleadoGetSueldo(empleado, &sueldo) && empleadoGetSexo(empleado, &sexo)){
        printf("Nombre: %s | Legajo: %d | Sexo: %c | Sueldo: $%.2f\n", empleado->nombre, legajo, sexo, sueldo);
        todoOk=1;
    }
    return todoOk;
}

int mostrarEmpleados(eEmpleado* lista, int tam){
    int todoOk=0;
    if(lista!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            mostrarEmpleado(lista+i);
            todoOk=1;
        }
    }
    return todoOk;
}


