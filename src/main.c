#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "VeraSotelo.h"


int main(void) {
    setbuf(stdout,NULL);
    //declaro variables
    char lastName[TAMSTR];
	char name[TAMSTR];
    int id=2000;
	int idEmpleado, order, exit, sector;
    float salary;
	eEmployee arrayEmployees[TAM];

	//inicializo toda la nomina en isEmpty=1
	initEmployees(arrayEmployees, TAM);

	do{
		switch(menuOpciones()){
			case 1:
			    //alta de empleado
				printf ("***AGREGAR EMPLEADO***\n");
				printf ("Ingrese nombre: ");
				getString(name, TAMSTR);
				printf ("Ingrese apellido: ");
				getString(lastName, TAMSTR);
				printf ("Ingrese salario: ");
                getSalary(&salary, SUELDOMIN);
				printf ("Ingrese sector: ");
				getSector(&sector, MINSEC, MAXSEC);
                printf("\n");
				if(addEmployee(arrayEmployees, TAM, id, name, lastName, salary, sector)==0){
					printf("Empleado agregado con exito. El ID es %d.\n\n", id);
					id++;
				}else{
					printf("El empleado no puedo ser agregado\n\n");
				}
				break;
			case 2:
			    //modificacion de empleados
                printf ("***MODIFICAR EMPLEADO***\n");
                if(countEmployees(arrayEmployees,TAM)==0){ //sino hay empleados activos, no se puede modificar empleados
                    printf ("Debe haber cargado al menos un empleado.\n\n");
                }else{
                    printf ("Ingrese ID del empleado a modificar: ");
                    scanf ("%d", &idEmpleado);
                    if(modifyEmployee(arrayEmployees, TAM, idEmpleado)==-1){
                        printf ("No pudo realizarse la modificacion.\n\n");
                    }else{
                        printf ("Empleado modificado con exito.\n\n");
                    }
                    printf("\n");
                }
				break;
			case 3:
                //baja de empleados
                printf ("***BORRAR EMPLEADO***\n");
                if(countEmployees(arrayEmployees,TAM)==0){ //sino hay empleados activos, no se puede borrar empleados
                    printf ("Debe haber cargado al menos un empleado.\n\n");
                }else{
                    printf ("Ingrese ID del empleado a borrar: ");
                    scanf ("%d", &idEmpleado);
                    printf("\n");
                        if(removeEmployee(arrayEmployees, TAM, idEmpleado)==0){
                            printf("Empleado borrado con exito\n\n");
                        }else{
                            printf("No pudo realizarse la baja.\n\n");
                        }
                    }
				break;
			case 4:
                //ordenar empleados y mostrar informes
                printf ("***INFORMES EMPLEADOS***\n");
                if(countEmployees(arrayEmployees,TAM)==0){  //sino hay empleados activos, no se puede mostrar empleados
                    printf ("Debe haber cargado al menos un empleado.\n\n");
                }else{
                	if(submenuInformes()==1){
                        printf("Desea mostrar los empleados en orden ascendente(0) o descendente(1)?\n");
                        order=getOption(0,1);
                        printf("\n");
                        sortEmployees(arrayEmployees,TAM,order);
                        if(printEmployees(arrayEmployees,TAM)==-1){
                            printf("Ha ocurrido un error al mostrar  el informe\n\n");
                        }
                	}
                	else{
                        if(avarageSalary(arrayEmployees,TAM)==-1){
                            printf("Ha ocurrido un error al mostrar el informe\n\n");
                        }
                	}
                }
				break;
			case 5:
				//salir del programa, pidiendo confirmacion
				printf("Seguro que desea salir (s/n)?\n");
				fflush(stdin);
				exit = getchar();
                printf("\n");
				if(exit=='s'){
					printf("Programa finalizado\n");
				}
				break;
			default:
			    //opcion invalida
				printf("Debe ingresar una opcion valida\n\n");
				break;
		}
	}while(exit!='s');

	return 0;
}
