#include <stdio.h>
#include <stdlib.h>
#include "VeraSotelo.h"

int maximum(int a, int b, int c){

    int max;

    if(a>b&&a>c){
        max=a;
    }else if(b>c){
        max=b;
    }else{
        max=c;
    }



    return max;
}

void swap(int *a, int *b){

    int aux;

    aux=*a;
    *a=*b;
    *b=aux;
}

char miToLower(char letra){
    if(letra>='A'&&letra<='Z'){
        letra=letra+32;
    }
    return letra;
}

int esPar(int num){
    return num%2==0; //devuelve el resultado del operador relacional - tb se puede hacer !(num%2) devuelve 0 o 1 pero invertido
}

int duplicar(int num){
    return num*2;
}

float dividir(int a, int b){
    float rta;
    if(b!=0){
        rta=(float)a/b;
    }
    return rta;
}

int factorial(int a){
    int fact;
    if(a==0||a==1){
        fact=1;
    }else{
        fact=a*factorial(a-1);
    }
    return fact;
}

int mostrarVector ( int* vector, int tam){
    int retorno=0;
    if(vector!=NULL&&tam>0){
        for(int i=0; i<tam; i++){
            printf("%d ", vector[i]);
        }
        printf("\n");
        retorno=1;
    }
    return retorno;
}

int cargarVectorEnteros (int* vec, int tam){
    int retorno=0;
    if(vec!=NULL&&tam>0){
        for(int i=0; i<tam; i++){
            printf("Ingrese un número: ");
            scanf("%d", &vec[i]);
        }
        retorno=1;
    }
    return retorno;
}

void mostrarCaracteres(char* caracteres, int tam){
    for(int i=0;i<tam;i++){
        printf("%c ", caracteres[i]);
    }
    printf("\n");
}

void pasarMayuscula(char* caracteres, int tam){
    for(int i=0;i<tam;i++){
        if(caracteres[i]<122&&caracteres[i]>96){
            caracteres[i]=caracteres[i]-32;
        }
    }
}

float calcularPromedio(int* vec, int tam){
    int acumulador=0;
    for(int i=0;i<tam;i++){
        acumulador+=vec[i];
    }
    return (float)acumulador/tam;
}

int mayorNum(int* vec, int tam){
    int mayor;
    for(int i=0;i<tam;i++){
        if(i==0||vec[i]>mayor){  //me ahorro el flag
            mayor=vec[i];
        }
    }
    return mayor;
}

void ordenarCaracteres(char vector[], int tam, int criterio){
    int aux;

    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
           if(vector!=NULL&&(criterio&&tolower(vector[i])>tolower(vector[j]))|| (!criterio&&tolower(vector[i])<tolower(vector[i]))){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}

int ordenarEnteros(int vector[], int tam, int criterio){
    int aux;
    int todoOk=0;

    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
           if(vector!=NULL&&(criterio&&vector[i]>vector[j]) || (!criterio&&vector[i]<vector[j])){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
            int todoOk=1;
        }
    }
    return todoOk;
}

void toLowerCadena(char texto[]){
    for(int i=0;texto[i]!='\0';i++){
        if(texto[i]<123&&texto[i]>96){
            texto[i]=texto[i]-32;
        }
    }
}





