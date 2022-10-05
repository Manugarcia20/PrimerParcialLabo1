/*
 * funciones.h
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "libro.h"
#include "autor.h"
#include "editorial.h"

/// @brief Obtiene el importe cargado por el usuario
/// @param precio Le paso la variable precio puntero para que reciba el valor del importe cargado
/// @param mensaje Le paso el mensaje solicitando al usuario que cargue el importe
/// @param mensajeError Le paso el mensaje de eror en caso de que haya ingresado un caracter no valido
void CargarPrecio(float *precio, char mensaje[], char mensajeError[]);


/// @brief Muestra un libro
/// @param libro Le paso el array de estructuras de tipo eLibro
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamL Le paso el tamanio del array libros
/// @param tamA Le paso el tamanio del array autores
/// @param paises Le paso el array de estructuras de tipo ePaises
/// @param tamP Le paso el tamanio del array paises
/// @return retorna 1 si se hizo correctamente
int MostrarUnLibro(eLibro libro, eAutor autores[],eEditorial editoriales[], int tamL, int tamA,ePais paises[],int tamP);

/// @brief Muestra la lista de los libros cargados por el usuario
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array paises
/// @return retorna 1 si se hizo correctamente
int MostrarListaLibros(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP);

/// @brief Busca la existencia del libro con el id ingresado por el usuario
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param id Le paso el id que el usuario cargo para buscar el libro con ese mismo id
/// @return retorna la posicion del libro
int BuscarLibro(eLibro libros[], int tamL, int id);

/// @brief Calcula el importe total de todos los libros y realiza el promedio de los mismos y los muestra
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param promedio Le paso la variable promedio puntero para que almacene el promedio calculado y pasarlo por referencia
/// @return retorna 1 si se hizo correctamente
float CalcularTotalYPromedio(eLibro libros[], int tamL, float* promedio);

/// @brief Calcula cuantos libros superan el importe promedio y los muestra
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param promedio le paso la variable promedio para que la utilize en el calculo de superan promedio
/// @return retorna 1 si se hizo correctamente
int SuperanPromedio(eLibro libros[], int tamL, float promedio);

/// @brief Calcula cuantos libros son anteriores a determinada fecha de publicacion
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @return retorna 1 si se hizo correctamente
int CantidadAnteriorFecha(eLibro libros[], int tamL);

/// @brief Ordena la lista de libros por importe descendente y titulo ascendente
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tamL Le paso el tamanio del array libros
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array paises
/// @return retorna 0 si salio bien
int OrdenarPorImporteYTitulo(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[], int tamP);


#endif /* FUNCIONES_H_ */
