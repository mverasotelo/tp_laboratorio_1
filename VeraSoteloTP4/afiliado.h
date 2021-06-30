#ifndef AFILIADO_H_INCLUDED
#define AFILIADO_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[20];
    int antiguedad;
    char plan;
}eAfiliado;

//PROTOTIPOS
void mostrarAfiliados(LinkedList * this);
void mostrarAfiliado(eAfiliado * afiliado);
int compararId(void* a, void* b);

#endif // AFILIADO_H_INCLUDED

