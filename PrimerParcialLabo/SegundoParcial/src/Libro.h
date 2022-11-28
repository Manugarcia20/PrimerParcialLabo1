#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int   id;
	char  titulo[100];
	float importe;
	int   idTipo;
}eLibro;

/// @brief reserva espacio en memoria para un puntero a estructura
/// @return retorna un puntero a estructura Jugador con espacio en memoria reservado
eLibro* libro_new();

/// @brief Setea todos los campos de la estructura Jugador
/// @param idStr variable para recibir el id
/// @param nombreCompletoStr variable para recibir el nombreCompleto
/// @param edadStr variable para recibir la edad
/// @param posicionStr variable para recibir la posicion
/// @param nacionalidadStr variable para recibir la nacionalidad
/// @param idSeleccionStr variable para recibir la seleccion
/// @return retorna un puntero de tipo Jugador
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr);

/// @brief Libera el espacio en memoria que ocupa una variable de tipo Jugador
/// @param this le paso una variable de tipo Jugador
void libro_delete(eLibro* this);

/// @brief Setea el valor del id dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param id le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int libro_setId(eLibro* this,int id);

/// @brief Obtiene el valor del id dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param id le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int libro_getId(eLibro* this,int* id);

/// @brief Setea el valor del nombreCompleto dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nombreCompleto le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int libro_setTitulo(eLibro*this, char* titulo);

/// @brief Obtiene el valor del nombreCompleto dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nombreCompleto le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int libro_getTitulo(eLibro* this,char* titulo);

/// @brief Setea el valor de la posicion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param posicion le paso la variable para darle valor y setearla en la estructura
/// @return retorna 0 si sale bien
int libro_setImporte(eLibro* this,float importe);

/// @brief Obtiene el valor de la posicion dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param posicion le paso la variable para obtener el valor de la estructura
/// @return retorna 0 si sale bien
int libro_getImporte(eLibro* this,float* importe);

/// @brief Setea el valor de la nacionalidad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nacionalidad le paso la variable para darle valor y setearla en la estructura
/// @return  retorna 0 si sale bien
int libro_setIdTipo(eLibro* this,int idTipo);

/// @brief Obtiene el valor de la nacionalidad dentro de la estructura de tipo Jugador
/// @param this le paso una variable de tipo Jugador
/// @param nacionalidad le paso la variable para obtener el valor de la estructura
/// @return  retorna 0 si sale bien
int libro_getIdTipo(eLibro* this, int* idTipo);


/// @brief Ordena la lista de libros por importe
/// @param jugador1 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @param jugador2 le paso una variable de tipo puntero a void para usarla luego en el ll_sort y ordenar
/// @return retorna -1 si la primer variable es mayor que la segunda, 1 si la segunda variable es mas grande que la primera, 0 si son iguales
int ordenarLibrosPorImporte(void* libro1,void* libro2);




/// @param pFile le paso el puntero a archivo para que lo use para abrirlo
/// @param pArrayListJugador le paso la lista de jugadores de tipo linkedlist
/// @return retorna 1 si salio bien
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);























#endif // jug_H_INCLUDED
