#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comidas.h"


/** \brief muestra una comida
 *
 * \param comida eComida
 * \return void
 *
 */

void mostrarComida(eComida comida){
    printf("%0d - %10s  -  $ %2.2f\n", comida.id, comida.descripcion, comida.precio);
}


void mostrarComidas(eComida comidas[], int tam){
    printf(" Id  | Descripcion |  Precio\n");
    if(comidas != NULL && tam>0){
        for(int i=0;i<tam;i++){
                mostrarComida(comidas[i]);
            }
    }
    printf("\n");
}

int buscarComida(eComida comidas[], int tam, int id){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (comidas[i].id==id){
            indice=i;
            break;
        }
    }
    return indice;
}

int cargarDescripcionComida(int idComida, eComida comidas[], int tamCom, char descripcion[20]){
    int todoOk=0;
    for(int i=0; i<tamCom;i++){
        if(comidas[i].id==idComida){
            strcpy(descripcion,comidas[i].descripcion);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

