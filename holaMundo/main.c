#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINEAS 3
#define INT 12

void mostrarMatriz(float matriz[][13], int filas);

/*linea 1, llinea 2,     linea 3
12 internos en cada linea
Matriz de 3 filas(lineas) y 12 columnas(internos)
Hacer un programa que pida la linea y el interno. Guardar lo que se va recaudando en una matriz acumulando las ganancias hasta que el usuario quiera.
Cuando el usuario ya no quiere ingresar informacion mostrar lo que se recaudo en formato de tabla agregando una fila y una columna que muestren los totales por columna y por fila. Indicar en el espacio sobrante(ultimo cuadradito) la recaudacion to*/
int main()
{
    float recaudacion[LINEAS+1][INT+1]={0};
    float totalLinea=0;
    float auxFloat;
    int linea;
    int interno;
    char seguir;

    if(&linea!= &interno){
        printf("Hola");
    }

    do{
        printf("Ingrese linea: ");
        scanf("%i",&linea);
        while(linea<1||linea>LINEAS){
            printf("Error. Ingrese linea: ");
            scanf("%i",&linea);
        }
        printf("Ingrese interno: ");
        scanf("%i",&interno);
        while(interno<1||interno>INT){
            printf("Error. Ingrese interno: ");
            scanf("%i",&interno);
        }
        printf("Ingrese recaudación: ");
        scanf("%f", &auxFloat);
        while(auxFloat<0){
            printf("Error.Ingrese recaudación: ");
            scanf("%f", &auxFloat);
        }
        recaudacion[linea-1][interno-1]+=auxFloat;
        recaudacion[linea-1][INT]+=auxFloat;
        recaudacion[LINEAS][interno-1]+=auxFloat;
        recaudacion[LINEAS][INT]+=auxFloat;

        printf("Desea continuar?\n");
        fflush(stdin);
        seguir=getchar();
    }
    while(seguir!='n');

    mostrarMatriz(recaudacion, LINEAS+1);
    return 0;
}

void mostrarMatriz(float matriz[][13], int filas){
    printf("          ");
    for(int i=0;i<12;i++){
            printf("     %d     ",i+1);
    }
    printf("Total\n");
    for(int i=0;i<filas;i++){
        if(i==3){
            printf("Total    ");
        }else{
            printf("Linea %i  ",i+1);
        }
        for(int j=0;j<13;j++){
            printf("$ %7.2f  ", matriz[i][j]);
        }
        printf("\n");
    }
}

