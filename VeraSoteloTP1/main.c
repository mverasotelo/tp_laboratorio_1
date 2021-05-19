#include <stdio.h>
#include <stdlib.h>
#include "VeraSotelo.h"

int main()
{
    int flagX=1;
    int flagY=1;
    int flagCalc=1;
    unsigned long int factX, factY;
    float division, multiplicacion, resta, suma, x, y;
    char salir;

    do{
        system("cls");
        switch(menuOpciones(x, y,flagX,flagY)){
            case 1:
            	// pedir primer operando
                printf("Ingrese el 1er operando: ");
            	x=getNum();
                flagX=0;
                flagCalc=1;
                break;
            case 2:
            	//pedir segundo operando
                printf("Ingrese el 2do operando: ");
            	y=getNum();
                flagY=0;
                flagCalc=1;
                break;
            case 3:
            	//si los 2 operandos fueron ingresados, calcular todas las funciones
                if(flagX==0&&flagY==0){
                    suma=sumar(x,y);
                    resta=restar(x,y);
                    division=dividir(x,y);
                    multiplicacion=multiplicar(x,y);
                    factX=factorial((int)x);
                    factY=factorial((int)y);
                    flagCalc=0;
                    printf("Se han realizado los calculos correctamente\n\n");
                }else{
                    printf("Debe ingresar ambos operandos para realizar los calculos\n\n");
                }
                system("pause");
                break;
            case 4:
            	//si previamente se han calculado las operaciones, informar resultados
                if(flagCalc==0){
                    informarResultados(x, y, suma, resta, division, multiplicacion, factX, factY);
                }else{
                    printf("Debe calcular los resultados antes de informarlos\n\n");
                }
                system("pause");
                break;
            case 5:
            	//salir del programa, pidiendo confirmacion
                printf("Seguro que desea salir (s/n)?\n");
                fflush(stdin);
                salir = getchar();
                if(salir=='s'){
                    printf("Programa finalizado\n");
                }
                break;
            default:
                printf("Debe ingresar una opcion valida\n\n");
                system("pause");
                break;
        }
    }while(salir!='s');

    return 0;
}
