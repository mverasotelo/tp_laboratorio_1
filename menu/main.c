#include <stdio.h>
#include <stdlib.h>
#define SE_SALUDO 1
#define SE_BRINDO 2

char menu();
int main()
{
    char continuar='c';
    char salir;
    int flagSaludo=SE_SALUDO;
    int flagBrindis=SE_BRINDO;

    do{
        switch(menu()){
            case 'a':
                printf("Hola, qué tal?\n");
                system("pause");
                flagSaludo=0;
                break;
            case 'b':
                if(flagSaludo){
                    printf("Debe saludar antes de brindar!\n");
                }else{
                    printf("Chin chin!\n");
                    flagBrindis=0;
                }
                system("pause");
                break;
            case 'c':
                if(flagSaludo){
                    printf("Debe saludar antes de despedirse!\n");
                }
                else if(flagBrindis){
                    printf("Antes de despedirnos, brindemos!\n");
                }else{
                    printf("Chau, nos vemos!\n");
                    flagSaludo=1;
                    flagBrindis=1;
                }
                system("pause");
                break;
            case 'd':
                printf("Está seguro que desea salir (s/n) ?\n");
                fflush(stdin);
                salir = getchar();
                if(salir=='s'){
                    continuar='n';
                    printf("Terminó el programa\n");
                }
                break;
            default:
                printf("Ingrese una opción correcta (a, b, c o d) !\n");
                getch();
                break;
        }
    }
    while(continuar=='c');

    return 0;
}

char menu(){
    char opcion;
    system("cls");
    printf("***Menu de opciones***\n\n a)Saludar \n b)Brindar \n c)Despedir \n d)Salir \n\nIngrese una opción: ");
    fflush(stdin);
    opcion= getchar();
    return opcion;
}
