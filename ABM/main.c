#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "informes.h"
#include "sector.h"
#include "comidas.h"
#include "almuerzo.h"
#include "inputs.h"
#include "dataWarehouse.h"
#define TAM 10
#define TAMSEC 5
#define TAMC 6
#define TAMA 20


int main()
{
    int pId=2000;
    int pIdAlm=1000;
    int orden;
    eEmpleado empleados[TAM];
    eAlmuerzo almuerzos[TAMA];
    inicializarEmpleados(empleados, TAM);
    inicializarAlmuerzos(almuerzos,TAMA);
    hardcodearEmpleados(empleados, TAM, TAM, &pId);
    hardcodearAlmuerzos(almuerzos, TAMA, 15, &pIdAlm);
    char salir;

    eSector sectores[TAMSEC] ={
        {500,"Ventas"},
        {501,"Legales"},
        {502,"Sistemas"},
        {503,"RRHH"},
        {504,"Contable"}
    };

    eComida comidas[TAMC]={
        {1000,"Milanesa",100},
        {1001,"Fideos",120},
        {1002,"Churrasco",140},
        {1003,"Ensalada",160},
        {1004,"Pescado",110},
        {1005,"Empanada",60}
    };

    //menu de opciones
    do{
        switch(menuOpciones()){
        case 1:
            if(altaEmpleado(empleados, TAM, &pId)){
                printf("Alta exitosa!\n\n");
            }else{
                printf("No se ha podido realizar el alta\n\n");
            }
            break;
        case 2:
            modificarEmpleado(empleados, TAM, sectores, TAMSEC);
            break;
        case 3:
            if(bajaEmpleado(empleados, TAM, sectores, TAMSEC)){
                printf("Baja exitosa!\n\n");
            }else{
                printf("No se ha podido realizar la baja\n\n");
            }
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, TAMSEC);
            break;
        case 5:
            printf("Desea ordenar los empleados por orden ascendente (0) o descendiente (1)? ");
            scanf("%d", &orden);
            while(orden!=0&&orden!=1){
                printf("Error. Ingrese 0 para ascendente y 1 para descendiente: ");
                scanf("%d", &orden);
            }
            if(ordenarEmpleadosNombre(empleados, TAM, orden)){
                printf("La lista se ha ordenado correctamente!\n\n");
            }else{
                printf("Error. No se ha podido ordenar la lista de empleados.\n\n");
            }
            break;
        case 6:
            mostrarSectores(sectores, TAMSEC);
            break;
        case 7:
            printf("La cantidad de empleados del sector es: %d\n\n", empleadosSector(empleados, TAM, sectores, TAMSEC));
            break;
        case 8:
            aumentarSueldoSector(empleados, TAM, sectores, TAMSEC);
            break;
        case 9:
            aPonerla(empleados,TAM,sectores,TAMSEC);
            break;
        case 10:
            if(!sectorQueMasCobra(empleados, TAM, sectores, TAMSEC)){
                printf("No se ha podido calcular el sector que mas cobra.\n\n");
            }
            break;
        case 11:
            break;
        case 12:
            mostrarComidas(comidas,TAMC);
            break;
        case 13:
            if(altaAlmuerzo(almuerzos,TAMA,&pIdAlm, empleados, TAM, comidas, TAMC,sectores,TAMSEC)){
                printf("Carga exitosa!\n\n");
            }else{
                printf("No se ha podido cargar el almuerzo\n\n");
            }
            break;
        case 14:
            if(!mostrarAlmuerzos(almuerzos,TAMA,comidas,TAMC)){
                printf("No se han podido listar los almuerzos\n\n");
            }
            break;
        case 15:
            totalesComidaxSector(sectores, TAMSEC, empleados, TAM, almuerzos, TAMA, comidas, TAMC);
            break;
        case 16:
            comidaPreferidaSector(sectores, TAMSEC, empleados, TAM, almuerzos, TAMA, comidas, TAMC);
            break;
        case 17:
            SectorAmanteMilanesa(sectores, TAMSEC, empleados, TAM, almuerzos, TAMA);
            break;
        case 18:
            SectorAmanteMilanesa(sectores, TAMSEC, empleados, TAM, almuerzos, TAMA);
            break;
        case 19:
            printf("Está seguro de que desea salir?\n");
            fflush(stdin);
            salir=getchar();
            printf("\n");
            if(salir=='s'){
                printf("Programa finalizado\n\n");
            }
            break;
        }
    }while(salir!='s');

    return 0;
}

