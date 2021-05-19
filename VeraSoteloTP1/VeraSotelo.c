#include <stdio.h>
#include <stdlib.h>
#include "VeraSotelo.h"

int menuOpciones(float operandoA, float operandoB, int flagA, int flagB){
    int opcion;

    printf("*** CALCULADORA ***\n");
    printf("1. Ingresar 1er operando (A=");
    if(flagA){
        printf("x)\n");
    }else{
        printf("%.2f)\n", operandoA);
    }
    printf("2. Ingresar 2do operando (B=");
        if(flagB){
        printf("y)\n");
    }else{
        printf("%.2f)\n", operandoB);
    }
    printf("3. Calcular todas las operaciones\n"
    		"    a) Calcular la suma (A+B)\n"
    		"    b) Calcular la resta (A-B)\n"
    		"    c) Calcular la division (A/B)\n"
    		"    d) Calcular la multiplicacion (A*B)\n"
    		"    e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

float getNum(){
	float num;
    scanf("%f", &num);
    printf("\n");
    return num;
}

float sumar(float a, float b){
    return a+b;
}

float restar(float a, float b){
    return a-b;
}

float dividir(float a, float b){
    return a/b;
}

float multiplicar(float a, float b){
    return a*b;
}

unsigned long int factorial(int n){
    unsigned long int fact=1;
    if(n==0){
        fact=1;
    }else{
        for(int i=1;i<=n;i++){
            fact*=i;
        }
    }
    return fact;
}

void informarResultados(float operandoA, float operandoB, float suma, float resta, float division, float multiplicacion, unsigned long int factA, unsigned long int factB){
    printf("a) El resultado de %.2f + %.2f es: %.2f\n", operandoA, operandoB, suma);
    printf("b) El resultado de %.2f - %.2f es: %.2f\n", operandoA, operandoB, resta);
    if(operandoB!=0){
        printf("c) El resultado de %.2f / %.2f es: %.2f\n",operandoA, operandoB, division);
    }else{
        printf("c) No se puede dividir por 0\n");
    }
    printf("d) El resultado de %.2f * %.2f es: %.2f\n", operandoA, operandoB, multiplicacion);
    printf("e) El factorial de %d es: ", (int)operandoA);
    validarFactorial((int)operandoA, factA);
    printf("y el factorial de %d es: ", (int)operandoB);
    validarFactorial((int)operandoB, factB);
    printf("\n\n");
}

void validarFactorial(int operando, int fact){
    if(operando<0){
        printf("no existe ");
    }
    else if(operando>12){
        printf("no se puede calcular para numeros mayores a 12 ");
    }
    else{
        printf("%ld ",factorial(operando));
    }
}
