#include <stdio.h>
#include <stdlib.h>

int main()
{
    //escribir un archivo binario
    int x=352;

    FILE *f = fopen("miArchivo.bin", "wb");
    if(f==NULL){
        printf("No se puedo abrir el archivo\n\n");
    }else{
        if(fwrite(&x, sizeof(int), 1, f)){
            printf("Se escribio correctamente el archivo\n\n");
        }else{
            printf("No se escribio correctamente el archivo\n\n");
        }
    }

    printf("x = %d\n", x);

    fclose(f);

    //leer un archivo binario
    int y;

    f = fopen("miArchivo.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
    }else{
        if(fread(&y, sizeof(int), 1, f)==1){
            printf("Se leyo correctamente el archivo\n");
            printf("y = %d\n", y);
        }else{
            printf("No se leyo correctamente el archivo\n");
        }
    }

    fclose(f);

    //escribir un archivo texto
    int num=456;

    f = fopen("archivo.txt", "w");
    if(f==NULL){
        printf("No se puedo abrir el archivo\n\n");
    }else{
        fprintf(f, "%d", num);
    }

    printf("num = %d\n", num);
    printf("\n");

    fclose(f);

    //leer un archivo texto caracter por caracter con fgetc
    char letra;
    f = fopen("archivo.txt", "r");
    if(f==NULL){
        printf("No se puedo abrir el archivo\n\n");
    }else{
        while(!feof(f)){
            letra=fgetc(f);
            printf("%c",letra);
        }
    }
    printf("\n");

    fclose(f);

    //leer un archivo texto por cadena con fscanf y parsearlo a int
    char cadena[3];
    int numero;
    f = fopen("archivo.txt", "r");
    if(f==NULL){
        printf("No se puedo abrir el archivo\n\n");
    }else{
        fscanf(f,"%s", cadena);
        fscanf(f, "%d", &numero);
        printf("Dato como cadena: %s\n",cadena);
        printf("Dato como int: %d\n",numero);

    }

    printf("\n");

    fclose(f);

    //escribir vector de enteros en un archivo
    int vec[] = {1,2,3,4,5};

    f = fopen("miArchivo.bin", "wb");
    if(f==NULL){
        printf("No se puedo abrir el archivo\n\n");
    }else{
        if(fwrite(vec, sizeof(int), 5, f)==5){
            printf("Se escribio correctamente el archivo\n");
        }else{
            printf("No se escribio correctamente el archivo\n");
        }
    }
    printf("\n");

    fclose(f);

    //leer vector de enteros de un archivo con un DO WHILE (para cuando no se los elem que voy a leer)
    int z;

    f = fopen("miArchivo.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n\n");
    }else{
        do{
            if(fread(&z, sizeof(int), 1, f)== 1){
            printf("z = %d\n", z);
            }else{
            printf("Termino el archivo\n\n");
            break;
            }
        }while(1);
    }
    printf("\n");

    fclose(f);

    //leer vector de enteros de un archivo directamente (para cuando  se los elem que voy a leer)
   int vec2[5];

    f = fopen("miArchivo.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n\n");
    }else{
        if(fread(vec2, sizeof(int), 5, f)==5){
            printf("Se leyo correctamente el archivo\n\n");
        }else{
            printf("NO se leyo correctamente el archivo\n\n");
        }
    }

    printf("Datos: ");
    for(int i=0;i<5;i++){
        printf("%d ", vec2[i]);
    }
    printf("\n\n");

    fclose(f);


    //leer vector de enteros de un archivo con un feof() y validando tambien con el retorno de fread() para que no repita el ultimo valor
    int a;

    f = fopen("miArchivo.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n\n");
    }else{
        while(!feof(f)){
            if(fread(&a, sizeof(int), 1, f) == 1){
                printf("a = %d\n", a);
            }
        }
    }
    printf("\n");

    fclose(f);

    //leer vector de enteros de un archivo con un feof() y validando con una variable de cantidad
    int b;
    int cant;

    f = fopen("miArchivo.bin", "rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n\n");
    }else{
        while(!feof(f)){
            cant=fread(&b, sizeof(int), 1, f);
            if(cant<1){
                break;
            }
            printf("b = %d\n", b);
        }
    }
    printf("\n");

    fclose(f);

    return 0;
}
