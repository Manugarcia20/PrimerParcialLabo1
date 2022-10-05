/*
 * libro.h
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <string.h>
#include "autor.h"
#include "editorial.h"
#define LLENO 1
#define VACIO 0
#define TAM_L 5

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int idLibro;
	char titulo[51];
	eFecha fecha;
	float importe;
	int idAutor;
	int idEditorial;
	int estado;

}eLibro;

/// @brief Inicializa todas las posiciones del array libros de tipo Elibro en 0
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tam Le paso el tamanio del array
/// @return retorna 0 si salio bien
int InicializarLibros(eLibro libros[], int tam);


/// @brief Busca un espacio libre en el array libros de tipo eLibro
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tam Le paso el tamanio del array
/// @param pPosicion  Le paso el puntero pPosicion para que reciba la posicion encontrada
/// @returnretorna 0 si salio bien
int BuscarEspacioLibre(eLibro libros[], int tam, int *pPosicion);

/// @brief Realiza el proceso de alta de un libro pidiendo todos los datos para cargarlos en una posicion del array
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param pId Le paso la variable pId puntero para que reciba el valor del id autoincremental
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array paises
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @return retorna 1 si el alta se pudo hacer correctamente
int AltaLibro(eLibro libros[], int tamL, int *pId, eAutor autores[], int tamA, ePais paises[], int tamP, eEditorial editoriales[], int tamE);

/// @brief Obtiene el importe cargado por el usuario
/// @param precio Le paso la variable precio puntero para que reciba el valor del importe cargado
/// @param mensaje Le paso el mensaje solicitando al usuario que cargue el importe
/// @param mensajeError Le paso el mensaje de eror en caso de que haya ingresado un caracter no valido
void CargarPrecio(float *precio, char mensaje[], char mensajeError[]);

/// @brief Realiza el proceso de modificacion de los datos requeridos cuando el usuario asi lo desea
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param idLibroCambio variable para almacenar el id que el usuario ingresa para modificarlo
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array paises
/// @return retorna 1 si la modificacion se pudo hacer correctamente
int ModificarLibros(eLibro libros[], int tamL , int idLibroCambio, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[], int tamP);

/// @brief Realiza una baja logica de los datos de un libro cuando el usuario ingresa su id
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param idLibroBaja variable para almacenar el id que el usuario ingresa para darlo de baja
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param editoriales Le paso el array de estructuras de tipo eEditoriales
/// @param tamE Le paso el tamanio del array editoriales
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array paises
/// @return retorna 0 si la baja se pudo hacer correctamente
int BajaLibro(eLibro libros[], int tamL, int idLibroBaja, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP);
#endif /* LIBRO_H_ */
