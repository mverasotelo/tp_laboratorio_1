#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);
eEmpleado* newEmpleadoBuffer(char* legajo, char* nombre, char* sexo, char* sueldo);


int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados(eEmpleado* lista, int tam);

//setters
int empleadoSetLegajo(eEmpleado * emp, int legajo);
int empleadoSetSexo(eEmpleado * emp, char sexo);
int empleadoSetNombre(eEmpleado * emp, char nombre[]);
//getters
int empleadoGetLegajo(eEmpleado * emp, int* legajo);
int empleadoGetSueldo(eEmpleado * emp, float* sueldo);
int empleadoGetSexo(eEmpleado * emp, char* sexo);

//funciones array de puntero a punteros
int mostrarEmpleados2(eEmpleado** lista, int tam);
int inicializarEmpleados(eEmpleado ** lista, int tam);
int buscarIndice(eEmpleado ** lista, int tam, int* pIndice);
int agrandarArray(eEmpleado *** lista, int * tam);
int ordenarArrayLegajo(eEmpleado ** lista, int tam);
int ordenarArrayNombre(eEmpleado ** lista, int tam);

int altaEmpleado(eEmpleado ** lista, int tam);


#endif // EMPLEADO_H_INCLUDED
