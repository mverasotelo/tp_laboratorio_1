#ifndef VERASOTELO_H_INCLUDED
#define VERASOTELO_H_INCLUDED

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();

/** \brief submenu de criterio de ordenamiento
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuCriterio();

/** \brief submenu de orden (ascendente / descendente)
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuOrden();


/** \brief submenu de modificaicon
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuModificacion();


/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);


/** \brief Pide un nombre al usuario y lo valida
 *
 * \param nombre char* nombre
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getNombre(char *nombre, int maxLen);


/** \brief Pide el nombre de archivo al usuario y lo valida
 *
 * \param nombre char* path
 * \param maxLen int maximo de caracteres permitidos
 * \return int devuelve 1 si esta todo OK y 0 si algo salio mal
 *
 */
int getPath(char *path, int maxLen);

#endif // VERASOTELO_H_INCLUDED
