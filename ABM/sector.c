#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

int mostrarSectores(eSector sectores[], int tam){
    int todoOk=0;
    printf(" SECTORES\n");
    if(sectores!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            mostrarSector(sectores[i]);
        }
        todoOk=1;
    }
    printf("\n");
    return todoOk;
}

void mostrarSector(eSector sector){
    printf("%02d- %s\n",sector.id, sector.sector);
}
/*
int cargarDescripcionSectores(int idSector, eSector sectores[], int tamSect, char descripcion[20]){
    int todoOk=0;
    for(int i=0; i<tamSect;i++){
        if(sectores[i].id==idSector){
            strcpy(descripcion,sectores[i].sector);
            break;
        }
    }
    return todoOk;
}*/
