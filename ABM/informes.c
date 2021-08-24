#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

int empleadosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int contEmpleados=0;
    int idSector;
    if(empleados!=NULL && sectores!=NULL && tam>0 && tamSect>0){
        mostrarSectores(sectores, tamSect);
        printf("Ingrese ID del sector: ");
        scanf("%d",&idSector);
        if(idSector<500||idSector>500+(tamSect-1)){
            printf("Error.Ingrese ID del sector: ");
            scanf("%d",&idSector);
        }
        for(int i=0;i<tam;i++){
            if (empleados[i].idSector==idSector&&empleados[i].isEmpty==0){
                contEmpleados++;
            }
        }
    }
    return contEmpleados;
}

int aumentarSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int todoOk=0;
    int porcentaje;
    int idSector;
    if(empleados!=NULL && sectores!=NULL && tam>0 && tamSect>0){
        mostrarSectores(sectores, tamSect);
        printf("Ingrese ID del sector: ");
        scanf("%d",&idSector);
        if(idSector<500||idSector>500+(tamSect-1)){
            printf("Error.Ingrese ID del sector: ");
            scanf("%d",&idSector);
        }
        printf("Ingrese porcentaje: ");
        scanf("%d",&porcentaje);
        for(int i=0;i<tam;i++){
            if (empleados[i].idSector==idSector&&empleados[i].isEmpty==0){
                empleados[i].sueldo+=(empleados[i].sueldo*porcentaje)/100;
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int aPonerla(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int todoOk=0;
    float totalSector;
    float montoTotal=0;
    if(empleados!=NULL && tam>0 && sectores!=NULL && tamSect>0){
        for(int i=0;i<tamSect;i++){
            printf("Sector: %s\n", sectores[i].sector);
            totalSector=0;
            for(int j=0;j<tam;j++){
                if(empleados[j].isEmpty==0&&sectores[i].id==empleados[j].idSector){
                    totalSector+=empleados[j].sueldo;
                    montoTotal+=totalSector;
                }
            }
        printf("Total: $%.2f\n\n", totalSector);
        }
        printf("\nSueldo total: $%.2f\n\n", montoTotal);
        todoOk=1;
    }
    return todoOk;
}



int sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamSect){
    int todoOk=0;
    float totalSector[tamSect];
    float sectorMasCaro=0;
    float auxFloat;
    int idSector;

    if(empleados!=NULL && tam>0 && sectores!=NULL && tamSect>0){
        for(int s=0; s<tamSect; s++){
            auxFloat=0;
            idSector=sectores[s].id;
            for(int e=0;e<tam; e++){
                if(empleadoActivo(empleados[e])&&idSector==empleados[e].idSector){
                    auxFloat+=empleados[e].sueldo;
                }
            }
            totalSector[s]=auxFloat;
        }

        for(int s=0; s<tamSect; s++){
            if(totalSector[s]>sectorMasCaro){
                sectorMasCaro=totalSector[s];
            }
        }

        printf("Sector/es que mas cobra/n: ");
        for(int s=0; s<tamSect; s++){
            if(totalSector[s]==sectorMasCaro){
                printf("%s ", sectores[s].sector);
            }
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int totalesComidaxSector(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA, eComida comidas[], int tamC){
    int todoOk=0;
    int flag=1;
    int idSector;
    float total;
    if(empleados!=NULL && tamE>0 && sectores!=NULL && tamS>0){
        printf("TOTAL GASTOS COMIDA POR SECTOR\n\n");
        for(int i=0; i<tamS;i++){
            total=0;
            idSector=sectores[i].id;
            for(int j=0;j<tamE;j++){
                if(empleadoActivo(empleados[j])&&empleados[j].idSector==idSector){
                    for(int k=0; k<tamA; k++){
                        if(!almuerzos[k].isEmpty&&almuerzos[k].idEmpleado==empleados[j].legajo){
                            for(int l=0;l<tamC;l++){
                                if(comidas[l].id==almuerzos[k].idComida){
                                    total+=comidas[l].precio;
                                    flag=0;
                                }
                            }
                        }
                    }
                }
            }
        if(flag){
            printf("No se registraron comidas en el sector %s\n", sectores[i].sector);
        }else{
            printf("Sector %s: $%.2f\n", sectores[i].sector, total);
        }
        todoOk=1;
        }
    }
    printf("\n");
    return todoOk;
}

//CHEQUEAR ESTE
int comidaPreferidaSector(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA, eComida comidas[], int tamC){
    int todoOk=0;
    int idSector;
    int contComidas[tamC];
    int comidaPreferida = 0;
    char comida[10];
    int flag=1;

    if(empleados!=NULL && tamE>0 && sectores!=NULL && tamS>0 && almuerzos!=NULL && tamA>0 && comidas!=NULL && tamC>0){
        printf("COMIDA PREFERIDA POR SECTOR\n\n");
        for(int i=0; i<tamS;i++){
            idSector=sectores[i].id;
            for(int j=0;j<tamE;j++){
                if(empleadoActivo(empleados[j])&&empleados[j].idSector==idSector){
                    for(int k=0; k<tamA; k++){
                        if(!almuerzos[k].isEmpty&&almuerzos[k].idEmpleado==empleados[j].legajo){
                            for(int l=0;l<tamC;l++){
                                if(comidas[l].id==almuerzos[k].idComida){
                                    contComidas[l]++;
                                    flag=0;
                                }
                            }
                        }
                    }
                }
            }
        //comparo los contadores de comida de cada sector para ver cual es el mayor
        for(int l=0;l<tamC;l++){
            if(comidaPreferida<contComidas[l]){
                comidaPreferida=contComidas[l];
                strcpy(comida,comidas[l].descripcion);
                }
            }
        //imprimo la comida favorita de cada sector: si el sector no consumio ninguna comida lo informo, si hay empate de comidas, informo todas
        printf("Comida favorita del sector %s: ", sectores[i].sector);
        if(flag){
            printf("El sector no consumio comidas");
        }else{
            printf("%s", comida);
            /*
            for(int l=0;l<tamC;l++){
                if(comidaPreferida==contComidas[i]){
                    printf("%s ", comidas[l].descripcion);
                }
            }*/
        }
        printf("\n");
        todoOk=1;
        }
    printf("\n");
    }
    return todoOk;
}

int SectorAmanteMilanesa(eSector sectores[], int tamS, eEmpleado empleados[], int tamE, eAlmuerzo almuerzos[], int tamA){
    int todoOk=0;
    int idMilanesa=1000;
    int contadores[tamS];
    int maxMilanesas=0;
    int flag=1;
    for(int i=0;i<tamS;i++){
        contadores[i]=0;
    }
    if(empleados!=NULL && tamE>0 && sectores!=NULL && tamS>0 && almuerzos!=NULL && tamA>0){
        printf("SECTOR AMANTE DE LAS MILANESAS\n\n");
        for(int i=0; i<tamA;i++){
            if(!almuerzos[i].isEmpty&&almuerzos[i].idComida==idMilanesa){
                for(int j=0;j<tamE;j++){
                    if(empleadoActivo(empleados[j])&&empleados[j].legajo==almuerzos[i].idEmpleado){
                        for(int k=0;k<tamS;k++){
                            if(empleados[j].idSector==sectores[k].id){
                                contadores[k]++;
                                flag=0;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<tamS;i++){
            if(maxMilanesas<contadores[i]){
                maxMilanesas=contadores[i];
            }
        }

        if(flag){
            printf("Ningun sector comio milanesa\n");
        }else{
            printf("Sector/es amante/s de las milanesas: ");
            for(int i=0;i<tamS;i++){
                if(maxMilanesas==contadores[i]){
                    printf("%s ", sectores[i].sector);
                }
            }
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

