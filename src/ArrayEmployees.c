#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(eEmployee* list, int len){
	int retorno=-1;
    if(list!=NULL && len>0){
       for(int i=0; i<len;i++){
    	  list[i].isEmpty=TRUE;
        }
       retorno=0;
    }
	return retorno;
}


int findEmptyPosition(eEmployee* list, int len){
    int index=-1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if (list[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}


int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int retorno=-1; //error
	int index=findEmptyPosition(list, len);
    eEmployee newEmployee;
	if(list!=NULL && len>0 && index!=-1){
        newEmployee.id=id;
        strcpy(newEmployee.name, name);
        strcpy(newEmployee.lastName, lastName);
        newEmployee.salary=salary;
        newEmployee.sector=sector;
        newEmployee.isEmpty=FALSE;
        list[index]=newEmployee;
    	retorno=0;
    	}
    return retorno;
}


int findEmployeeById(eEmployee* list, int len, int id){
    int index=-1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if (!list[i].isEmpty && list[i].id==id){
            	index=i;
                break;
            }
        }
    }
    return index;
}


int modifyEmployee(eEmployee* list, int len, int id){
    char confirmacion;
    char dato[9];
    int retorno=-1;
    int index;
    eEmployee aux;
    if(list!=NULL && len>0){ //si la lista existe, su largo es mayor a 0 y hay al menos un empleado activo
        index=findEmployeeById(list,len,id);
        if(index==-1){
            printf("El ID ingresado no existe. ");
        }else{
            aux=list[index];
            switch(submenuModificar()){
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    getString(aux.name, TAMSTR);
                    strcpy(dato, "nombre");
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    getString(aux.name, TAMSTR);
                    strcpy(dato, "apellido");
                    break;
                case 3:
                    printf("Ingrese nuevo salario: ");
                    getSalary(&aux.salary, SUELDOMIN);
                    strcpy(dato, "salario");
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    getSector(&aux.sector, MINSEC, MAXSEC);
                    strcpy(dato, "sector");
                    break;
            }
            printf("\n");
            printf("Esta seguro de que desea modificar el %s del empleado con ID %d (s/n)? ", dato, id);
            fflush(stdin);
            scanf("%c", &confirmacion);
            if(confirmacion=='s'){
                list[index]=aux;
                retorno=0;
            }else{
                printf("Modificacion cancelada por el usuario. ");
            }
        }
    }
    return retorno;
}


int removeEmployee(eEmployee* list, int len, int id){
	char confirmacion;
	int retorno=-1;
	int index;
    if(list!=NULL && len>0){
        index=findEmployeeById(list,len,id);
        if(index==-1){
            printf("El ID ingresado no existe. ");
        }else{
            printf("Esta seguro de que desea borrar el empleado con ID %d (s/n)? ", id);
            fflush(stdin);
            scanf("%c", &confirmacion);
            if(confirmacion=='s'){
                list[index].isEmpty=TRUE;
                retorno=0;
            }else{
                printf("Baja cancelada por el usuario. ");
            }
        }
    }
    return retorno;
}


int countEmployees(eEmployee* list, int length){
    int cEmployees=0;
    if(list!=NULL && length>0){
        for(int i=0;i<length;i++){
            if (!list[i].isEmpty){
            	cEmployees++;
            }
        }
    }
    return cEmployees;
}


int sortEmployees(eEmployee* list, int len, int order){
	int retorno=-1;
	eEmployee aux;
    if(list!=NULL && len>0 && countEmployees(list,len)!=0){
        for(int i=0; i<len-1;i++){
            for(int j=1; j<len; j++){
            	if((order==0&&strcmp(list[i].lastName,list[j].lastName)<0)||(order==1&&strcmp(list[i].lastName,list[j].lastName)>0)||(strcmp(list[i].lastName,list[j].lastName)==0&&(list[i].sector<list[j].sector))){
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
        }
        retorno=0;
    }
return retorno;
}


int printEmployees(eEmployee* list, int length){
	int retorno=-1;
    if(list!=NULL && length>0 && countEmployees(list,length)!=0){
        printf(" LEGAJO |        NOMBRE        |         APELLIDO        |   SALARIO   | SECTOR \n");
        for(int i=0;i<length;i++){
            if(!list[i].isEmpty){
            printf(" %04d   | %20s |   %20s  | $%10.2f |  %02d\n",
                list[i].id,
                list[i].name,
                list[i].lastName,
                list[i].salary,
                list[i].sector);
                retorno=0;
            }
        }
        printf("\n");
    }
    return retorno;
}

int avarageSalary(eEmployee* list, int len){
    int retorno=-1;
    float totalSalarios=0;
    int contEmpleados=0;
    float salarioPromedio;

    if(list!=NULL && len>0 && countEmployees(list,len)!=0){
        for(int i=0;i<len;i++){
            if (!list[i].isEmpty){
            	totalSalarios+=list[i].salary;
            }
        }
        salarioPromedio=totalSalarios/(countEmployees(list,len));
        for(int i=0;i<len;i++){
            if (!list[i].isEmpty&&list[i].salary>salarioPromedio){
                contEmpleados++;
            }
            retorno=0;
        }
        printf("Total salarios: $%8.2f\n", totalSalarios);
        printf("Salario promedio: $%8.2f\n", salarioPromedio);
        printf("Usuarios que superan el salario promedio: %d\n\n", contEmpleados);
    }
    return retorno;
}
