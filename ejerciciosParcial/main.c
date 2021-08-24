#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PASAJE 600

/*Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
Nombre, estado civil ("soltero", "casado" o "viudo"), edad( solo mayores de edad, mas de 17),temperatura corporal(validar por favor) y sexo (validar).
nos cobra $600  por pasajero.
</br>a) La cantidad de viudos de mas de 60 años
</br>b) el nombre de la mujer soltera mas joven
</br>c) cuanto sale el viaje total sin descuento y si hay mas del 50% del pasaje que tiene mas de 60 años
, el precio final  tiene  un descuento del 25%, que solo mostramos si corresponde.
*/


int main()
{
    int edad, viudosMay60, edadMjoven, flag, contPasajeros, contMay60;
    float temperatura, totalViaje; //34°-41°
    char inicial, estadoCivil, sexo, seguir, iniMjoven;//s-c-d;

    contPasajeros=0;
    viudosMay60=0;
    edadMjoven=0;
    flag=1;
    contMay60=0;
    totalViaje=0;

    do{
        printf("Ingrese la inicial de su nombre:\n");
        fflush(stdin);
        scanf("%c",&inicial);

        printf("Ingrese su estado civil (s/c/d):\n");
        fflush(stdin);
        scanf("%c",&estadoCivil);
        while(tolower(estadoCivil)!='s'&&tolower(estadoCivil)!='c'&&tolower(estadoCivil)!='d'){
            printf("Error. Ingrese su estado civil (s/c/d):\n");
            fflush(stdin);
            scanf("%c",&estadoCivil);
        }

        printf("Ingrese su edad:\n");
        scanf("%d",&edad);
        while(isdigit(edad)||edad<18){
            fflush(stdin);
            printf("Error. Ingrese su edad:\n");
            scanf("%d",&edad);
        }

        printf("Ingrese la temperatura:\n");
        scanf("%f",&temperatura);
        while(isalpha(temperatura)||temperatura<34||temperatura>41){
            fflush(stdin);
            printf("Error. Ingrese la temperatura:\n");
            scanf("%f",&temperatura);
        }

        printf("Ingrese sexo (f/m):\n");
        fflush(stdin);
        scanf("%c",&sexo);
        while(tolower(sexo)!='f'&&tolower(sexo)!='m'){
            printf("Error. Ingrese sexo (f/m):\n");
            fflush(stdin);
            scanf("%c",&sexo);
        }

        if(edad>60){
            if(estadoCivil=='v'){
                viudosMay60++;
            }
            contMay60++;
        }

        if(sexo=='f'&&estadoCivil=='s'){
            if(flag||edad<edadMjoven){
                edadMjoven=edad;
                iniMjoven=inicial;
                flag=0;
            }
        }

        contPasajeros++;
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }while(seguir=='s');

    if(((contMay60*100)/contPasajeros)>50){
        totalViaje=(PASAJE*contPasajeros)*.75;
    }else{
        totalViaje=PASAJE*contPasajeros;
    }

    printf("La cantidad de viudos mayores a 60 años es %d\n", viudosMay60);
    if(flag==0){
        printf("La inicial de la mujer soltera más jóven es %c\n", iniMjoven);
    }
    printf("El total del viaje es de $ %.2f\n", totalViaje);

    return 0;
}
