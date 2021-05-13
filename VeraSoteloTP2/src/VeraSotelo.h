/*
 * VeraSotelo.h
 *
 *  Created on: 9 may. 2021
 *      Author: mer-v
 */

#ifndef VERASOTELO_H_
#define VERASOTELO_H_


//defines
#define TAM 1000
#define TAMSTR 51
#define SUELDOMIN 10000
#define MINSEC 1
#define MAXSEC 6
#define TRUE 1
#define FALSE 0

//funciones menu de opciones y validacion datos

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();

/** \brief submenu de datos a modificar
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuModificar();

/** \brief submenu de opciones de informes
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuInformes();

/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);

/** \brief pide y valida extension de un string
 *
 * \param string char* string
 * \param maxLen int extension maxima
 * \return int devuelve 0 si esta todo OK y -1 si hay algun error
 *
 */
int getString(char *string, int maxLen);

/** \brief pide y valida salario
 *
 * \param salary float*
 * \param salarioMinimo float sueldo minimo aceptado
 * \return int devuelve 0 si esta todo OK y -1 si hay algun error
 *
 */
int getSalary(float *salary, float salarioMinimo);

/** \brief pide y valida que sea un sector correcto
 *
 * \param sector int*
 * \param minSector int minimo numero de sector
 * \param maxSector int maximo numero de sector
 * \return int devuelve 0 si esta todo OK y -1 si hay algun error
 *
 */
int getSector(int* sector, int minSector, int maxSector);

#endif /* VERASOTELO_H_ */
