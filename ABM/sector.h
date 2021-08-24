#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char sector[20];
}eSector;

/** \brief Carga la descripcion de un sector, a partir de su id
 *
 * \param idSector int - Id del sector
 * \param sectores[] eSector- Lista de sectores
 * \param tamSect int - Tamaño de la lista
 * \param descripcion[20] char -Descripcion del sector
 * \return int devuelve 1 si esta todo Ok, devuelve 0 sino se pudo obtener la descripcion
 *
 */
int cargarDescripcionSectores(int idSector, eSector sectores[], int tamSect, char descripcion[20]);


/** \brief  - Muestra los sectores de una lista
 *
 * \param sectores[] eSector - Lista de sectores
 * \param tam int - Tamaño de la lista
 * \return void
 *
 */
int mostrarSectores(eSector sectores[], int tam);


/** \brief Muestra la informacion de un sector
 *
 * \param sector eSector - Sector a mostras
 * \return void
 *
 */
void mostrarSector(eSector sector);

#endif // SECTOR_H_INCLUDED
