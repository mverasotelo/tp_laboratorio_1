#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

typedef struct{
int id;
char descripcion[20];
float precio;

}eComida;


/** \brief muestra una comida
 *
 * \param comida eComida
 * \return void
 *
 */
void mostrarComida(eComida comida);

/** \brief
 *
 * \param comidas[] eComida
 * \param tam int
 * \return void
 *
 */
void mostrarComidas(eComida comidas[], int tam);

int buscarComida(eComida comidas[], int tam, int id);

int cargarDescripcionComida(int idComida, eComida comidas[], int tamCom, char descripcion[20]);

#endif // COMIDAS_H_INCLUDED
