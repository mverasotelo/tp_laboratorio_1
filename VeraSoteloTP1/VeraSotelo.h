#ifndef VERASOTELO_H_INCLUDED
#define VERASOTELO_H_INCLUDED


/** \brief menu de opciones para pedir dos operandos,realizar los calculos y salir
 *
 * \param operandoA float operando A ingresado para mostrarlo en el menu una vez ingresado
 * \param operandoB float operando B ingresado para mostrarlo en el menu una vez ingresado
 * \param flagA int bandera indicando que se ha ingresado el operando A
 * \param flagB int bandera indicando que se ha ingresado el operando B
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuOpciones(float operandoA, float operandoB, int flagA, int flagB);

/** \brief pide un numero
 *
 * \return int numero ingresado por el ususario
 *
 */
float getNum();

/** \brief suma entre 2 números reales
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float resultado de la suma
 *
 */
float sumar(float a, float b);

/** \brief resta entre 2 números reales
 *
 * \param a float primer operando
 * \param b float segundo operando
 * \return float resultado de la resta
 *
 */
float restar(float a, float b);

/** \brief división entre 2 números reales
 *
 * \param a float dividendo
 * \param b float divisor
 * \return float cociente
 *
 */
float dividir(float a, float b);

/** \brief multiplicación entre 2 números reales
 *
 * \param a float factor 1
 * \param b float factor 2
 * \return float producto
 *
 */
float multiplicar(float a, float b);

/** \brief calculo de factorial de un numero entero positivo
 *
 * \param n float numero a calcular
 * \return unsigned long float resultado del calculo
 *
 */
unsigned long int factorial(int n);

/** \brief valida que el operando del factorial sea numero positivo e igual o menor a 12
 *
 * \param operando int numero a calcular
 * \return unsigned long float factorial
 *
 */
void validarFactorial(int operando, int fact);

/** \brief informa los resultados de todas las operaciones
 *
 * \param operandoA float operando A
 * \param operandoB float operando B
 * \param suma float resultado de la suma entre A y B
 * \param resta float resultado de la resta entre A y B
 * \param division float resultado de la division entre den A por B
 * \param multiplicacion float resultado del producto entre A y B
 * \param factA unsigned longint factorial de A
 * \param factB unsigned longint factorial de B
 * \return void
 *
 */
void informarResultados(float operandoA, float operandoB, float suma, float resta, float division, float multiplicacion, unsigned long int factA, unsigned long int factB);

#endif /* VERASOTELO_H_ */
