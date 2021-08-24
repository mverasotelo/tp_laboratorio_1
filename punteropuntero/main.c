#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main()
{
    int tam=5;
    /*int legajo;
    char nombre[50];
    char sexo;
    float sueldo;*/
    int cant;
    int indice;
    int flag=0;
    eEmpleado * aux=NULL;
    eEmpleado ** lista= (eEmpleado**) malloc(sizeof(eEmpleado*)*tam);
    inicializarEmpleados(lista, tam);

    char buffer[4][20];

    FILE* f=fopen("empleados.csv", "r");

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }else{
        //fscanf(f, "%s", nombre); //lectura fantasma del encabezado
        cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do{
            //cant=fscanf(f,"%d,%[^,],%c,%f", &legajo, nombre, &sexo, &sueldo); //POR TIPO DE DATO
            cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant<4){
                break;
            }

            buscarIndice(lista, tam, &indice);
            if(indice!=-1){
                //aux=newEmpleadoParam(legajo, nombre, tolower(sexo), sueldo);
                aux=newEmpleadoBuffer(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(aux!=NULL){
                    *(lista+indice)=aux;
                    printf("%4d | %10s | %c | %.2f\n", aux->legajo, aux->nombre, aux->sexo, aux->sueldo);
                    aux=NULL;
                }else{
                    printf("Empleado null\n");
                }
            }else{
                if(agrandarArray(&lista,&tam)){
                    buscarIndice(lista, tam, &indice);
                    if(indice!=-1){
                        //aux=newEmpleadoParam(legajo, nombre, sexo, sueldo);
                        aux=newEmpleadoParam(atoi(buffer[0]), buffer[1], tolower(buffer[2][0]), atof(buffer[3]));
                        *(lista+indice)=aux;
                        printf("%4d | %10s | %c | %.2f\n", aux->legajo, aux->nombre, aux->sexo, aux->sueldo);
                    }
                }else{
                    printf("No pude agrandar el array\n");
                }
            }
        }while(!feof(f));
    }

    fclose(f);

    /* //GUARDAR EMPLEADOS EN UN ARCHIVO DE TEXTO
    f=fopen("empleados2.csv", "w");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }else{

        for(int i=0;i<tam;i++){
            if(*(lista+i)!=NULL){
                cant=fprintf(f,"%d, %s, %c, %.2f\n", (*(lista+i))->legajo,(*(lista+i))->nombre,(*(lista+i))->sexo,(*(lista+i))->sueldo);
                if(cant<4){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag){
        printf("Ocurrio un problema al guardar los empleados!\n");
    }else{
        printf("Empleados guardados con exito!\n");
    }

    fclose(f);*/

    //ESCRIBIR DATOS EN UN ARCHIVO BINARIO
    f = fopen("empleados3.bin", "wb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }else{
        for(int i=0;i<tam;i++){
            if(*(lista+i)!=NULL){
                cant=fwrite(*(lista+1), sizeof(eEmpleado), 1, f);
                if(cant<1){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag){
        printf("Ocurrio un problema al guardar los empleados!\n");
    }else{
        printf("Empleados guardados con exito!\n");
    }

    fclose(f);

    f = fopen("empleados3.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }else{
        while(!feof(f)){
            buscarIndice(lista,tam, &indice);
            if(indice!= -1){
                aux=newEmpleado();
                if (aux!=NULL){
                    cant=fread(aux, sizeof(eEmpleado), 1, f);
                    if(cant==1){
                        *(lista + indice) = aux;
                        aux=NULL;
                    }else{
                        if(feof(f)){ //IF PARA NO INTENTAR LEER UN EMPLEADO DESPUES DE FEOF
                            free(aux);
                            break;
                        }
                        flag=2;
                    }
               }else{
                   flag=1;
                   break;
               }
            }else{
                if(agrandarArray(&lista, &tam)){
                    printf("Se redimensiono el array\n");
                }else{
                    flag=3;
                    break;
                }
            }
        }
    }

    fclose(f);

    if(flag==0){
        printf("Se redimensiono el array\n");
    }else if(flag==1){
        printf("No hay espacio para un nuevo empleado\n");
    }else if(flag==2){
        printf("No se pudo leer un empleado\n");
    }else{
        printf("No se pudo agarrar el array\n");
    }


    /*int tam=3; //no se puede usar define porque el tamaño puede cambiar con agrandarArray()
    int indice;

    //crea lista de punteros a punteros de empleados
    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*)*tam);

    //inicializo la lista de punteros a empleados a NULL
    if(inicializarEmpleados(lista, tam)){
        printf("Empleados inicializados con exito.\n\n");
    }else{
        printf("No se consiguio lugar.\n");
        exit(EXIT_FAILURE);
    }

    buscarIndice(lista, tam, &indice);
    if(indice!=-1){
        //a lo que apunta lista le estoy asignando la direccion de memoria que es lo que me devuelve newEmpleadoParam
        *(lista + indice)= newEmpleadoParam(1235, "Pablo", 'm', 15000);
    }else{
        printf("No se consiguio lugar\n");
    }

    buscarIndice(lista, tam, &indice);
    if(indice!=-1){
        *(lista + indice)= newEmpleadoParam(1236, "Juan", 'm', 200000);
    }else{
        printf("No se consiguio lugar\n");
    }

    buscarIndice(lista, tam, &indice);
    if(indice!=-1){
        *(lista + indice)= newEmpleadoParam(1234, "Jose", 'm', 200000);
    }else{
        if(agrandarArray(&lista, &tam)){
            buscarIndice(lista, tam, &indice);
            *(lista + indice)= newEmpleadoParam(1234, "Jose", 'm', 200000);
        }
    }

    buscarIndice(lista, tam, &indice);
    if(indice!=-1){
        *(lista + indice)= newEmpleadoParam(1232, "Martin", 'm', 280000);
    }else{
        printf("No hay lugar. Voy a tratar de agrandar el array.\n\n");
        if(agrandarArray(&lista, &tam)){
            buscarIndice(lista, tam, &indice);
            if(indice!=-1){
                *(lista + indice)= newEmpleadoParam(1232, "Martin", 'm', 250000);
                printf("Carga exitosa en el indice %d.\n\n", indice);
            }else{
                printf("No hay caso.\n");
            }
        }
    }

    mostrarEmpleados2(lista, tam);
    printf("\n");
    ordenarArrayNombre(lista, tam);
    mostrarEmpleados2(lista, tam);

    free(lista);*/
    return 0;
}


    /*int*** s =(int***) malloc(sizeof(int**)); //triple puntero a int

    int* p= (int*) malloc (sizeof(int));  //puntero a entero

    *p=5;

    int** r =(int**) malloc(sizeof(int*)); //doble puntero a int

    *r=p; // guardo en r (**) la direccion de memoria de p (*)

    s=&r; // guardo en s(***) la direccion de memoria de r(**)


    printf("Valor espacio apuntado por p: %d\n", *p );
    printf("Direccion de memoria de p: %p\n", p );
    printf("Direccion de memoria de p desde r: %p\n", *r );
    printf("Direccion de memoria de p desde s: %p\n", **s );
    printf("\n");

    printf("Valor espacio apuntado por r: %d\n", **r );
    printf("Direccion de memoria de r: %p\n", r );
    printf("Direccion de memoria de r desde s: %p\n", *s );
    printf("\n");

    printf("Valor espacio apuntado por s: %d\n", ***s );
    printf("Direccion de memoria de s: %p\n", s);*/
