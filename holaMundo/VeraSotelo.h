#ifndef VERASOTELO_H_INCLUDED
#define VERASOTELO_H_INCLUDED



#endif // VERASOTELO_H_INCLUDED

void swap(int*a, int*b);

/** \brief devuelve el mayor numero de 3
 *
 * \param a int primer numero a evaluar
 * \param b int segundo numero a evaluar
 * \param c int tercer numero a evaluar
 * \return int mayor numero de los 3
 *
 */
int maximum(int a, int b, int c);


/** \brief pasar un caracter a minuscula
 *
 * \param letra char caracter a modificar
 * \return char caracter modificado
 *
 */
char miToLower(char letra);

int esPar(int num);

int duplicar(int num);

float dividir(int a, int b);

int factorial(int a);

int mostrarVectorCaracteres( char* vector, int tam);
int mostrarVector ( int* vector, int tam);
int cargarVectorEnteros (int* vec, int tam);
void mostrarCaracteres(char* caracteres, int tam);
void pasarMayuscula(char* caracteres, int tam);
float calcularPromedio(int* vec, int tam);
int mayorNum(int* vec, int tam);


/** \brief funcion para ordenar un vector de enteros
 *
 * \param vector[] int vector a ordenar
 * \param tam int tamaño del vector
 * \param criterio int 1 para creciente y 0 para decreciente
 * \return void
 *
 */

int ordenarEnteros(int vector[], int tam, int criterio);

void ordenarCaracteres(char vector[], int tam, int criterio);

void toLowerCadena(char texto[]);

