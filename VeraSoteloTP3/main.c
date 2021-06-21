#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "VeraSotelo.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    char salir;
    char sobreescribir;
    int criterio;
    int orden;
    int nextId = 1;
    int flagFile = 1;

    //Creo la linked list
    LinkedList* listaEmpleados = ll_newLinkedList();

    //Si es NULL salgo del programa
    if(listaEmpleados == NULL){
        printf("ERROR: No se ha podido crear la nomina de empleados\n");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menuOpciones())
        {
            case 1:  // Cargar los datos de los empleados desde el archivo data.csv (modo texto)
                if(flagFile){
                    if(controller_loadFromText("data.csv",listaEmpleados)){
                        printf("Carga de empleados exitosa\n\n");
                        controller_getId(listaEmpleados, &nextId);
                        flagFile = 0;
                    }else{
                        printf("ERROR: Ha ocurrido un error al cargar los empleados\n\n");
                    }
                }else{
                    printf("Ya existe un archivo cargado. Desea sobreescribir los datos (s/n) ?\n");
                    fflush(stdin);
                    sobreescribir = getchar();
                    printf("\n");
                    if(sobreescribir == 's'){
                        controller_deleteEmployees(listaEmpleados);
                        ll_clear(listaEmpleados);
                        if(controller_loadFromText("data.csv",listaEmpleados)){
                            printf("Carga de empleados exitosa\n\n");
                            controller_getId(listaEmpleados, &nextId);
                        }else{
                            printf("ERROR: Ha ocurrido un error al cargar los empleados\n\n");
                        }
                    }
                }
                break;

            case 2:  // Cargar los datos de los empleados desde el archivo data.bin (modo binario).
                if(flagFile){
                    if(controller_loadFromBinary("data.bin", listaEmpleados)){
                        printf("Carga de empleados exitosa\n\n");
                        controller_getId(listaEmpleados, &nextId);
                        flagFile=0;
                    }else{
                        printf("ERROR: Ha ocurrido un error al cargar los empleados\n\n");
                    }
                }else{
                    printf("Ya existe un archivo cargado. Desea sobreescribir los datos (s/n) ?\n");
                    fflush(stdin);
                    sobreescribir = getchar();
                    printf("\n");
                    if(sobreescribir == 's'){
                        controller_deleteEmployees(listaEmpleados);
                        ll_clear(listaEmpleados);
                        if(controller_loadFromBinary("data.bin", listaEmpleados)){
                            printf("Carga de empleados exitosa\n\n");
                            controller_getId(listaEmpleados, &nextId);
                        }else{
                            printf("ERROR: Ha ocurrido un error al cargar los empleados\n\n");
                        }
                    }
                }
                break;

            case 3:  // Alta de empleado
                if(ll_len(listaEmpleados) > 0){
                    if(controller_addEmployee(listaEmpleados, &nextId)){
                        printf("Alta de empleado exitosa\n\n");
                    }else{
                        printf("ERROR: No se ha podido dar de alta el empleado\n\n");
                    }
                }else{
                    printf("ERROR: Primero debe cargar la lista desde un archivo\n\n");
                }
                break;

            case 4: // Modificar datos de empleado
                if(ll_len(listaEmpleados) > 0){
                    if(controller_editEmployee(listaEmpleados)){
                        printf("Modificacion de empleado exitosa\n\n");
                    }else{
                        printf("ERROR: No se ha podido modificar el empleado\n\n");
                    }
                }else{
                    printf("ERROR: No hay empleados cargados\n\n");
                }
                break;

            case 5: // Baja de empleado
                if(ll_len(listaEmpleados) > 0){
                    if(controller_removeEmployee(listaEmpleados)){
                        printf("Baja de empleado exitosa\n\n");
                    }else{
                        printf("ERROR: No se ha podido dar de baja el empleado\n\n");
                    }
                }else{
                    printf("ERROR: No hay empleados cargados\n\n");
                }
                break;

            case 6: // Listar empleados
                if(!controller_ListEmployee(listaEmpleados)){
                    printf("No hay empleados para mostrar\n\n");
                }
                break;

            case 7: // Ordenar empleados
                if(ll_len(listaEmpleados) > 0){
                    criterio = submenuCriterio();
                    orden = submenuOrden()-1;
                    if(controller_sortEmployee(listaEmpleados, criterio, orden)){
                        printf("Lista ordenada exitosamente\n\n");
                    }else{
                        printf("ERROR: No se ha podido ordenar la lista\n\n");
                    }
                }else{
                    printf("ERROR: No hay empleados cargados\n\n");
                }
                break;

            case 8: //Guardar los datos de los empleados en el archivo data.csv (modo texto).
                if(flagFile == 0){
                    if(controller_saveAsText("data.csv",listaEmpleados)){
                        printf("La lista se ha guardado exitosamente\n\n");
                    }else{
                        printf("ERROR: Ha ocurrido un problema al guardar los empleados\n\n");
                    }
                }else{
                        printf("ERROR: Primero debe cargar los datos desde algun archivo\n\n");
                }
                break;

            case 9: // Guardar los datos de los empleados en el archivo data.bin (modo binario).
                if(flagFile == 0){
                    if(controller_saveAsBinary("data.bin",listaEmpleados)){
                        printf("La lista se ha guardado exitosamente\n\n");
                    }else{
                        printf("ERROR: Ha ocurrido un problema al guardar los empleados\n\n");
                    }
                }else{
                        printf("ERROR: Primero debe cargar los datos desde algun archivo\n\n");
                }
                break;

            case 10: // Salir
                printf("Esta seguro de que desea salir?\n");
                fflush(stdin);
                salir = getchar();
                printf("\n");
                if(salir == 's'){
                    controller_deleteEmployees(listaEmpleados);
                    ll_deleteLinkedList(listaEmpleados); //elimina la linked list
                    printf("Programa finalizado\n\n");
                }
                break;
        }
    }while(salir != 's');

    return 0;
}

