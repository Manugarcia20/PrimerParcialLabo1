
#include "LinkedList.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* le paso el nombre del archivo
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayListLibro); ///


int controller_listarLibros(LinkedList* pArrayListLibro); ///

/** \brief Ordenar jugadores
 * \param pArrayListJugador LinkedList* le paso la lista de jugadores
 * \return int  devuelve 1 si salio bien
 */
int controller_ordenarLibros(LinkedList* pArrayListLibro); ///

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 * \param path char* le paso el nombre del archivo
 * \param pArrayListSeleccion LinkedList* le paso la lista de jugadores
 * \return int devuelve 1 si salio bien
 */
int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayListJugador);///










