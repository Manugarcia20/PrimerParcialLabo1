/*
 * editorial.h
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LLENO 1
#define VACIO 0
#define TAM_E 5

typedef struct{
	int idEditorial;
	char descEditorial[51];
	int estado;
}eEditorial;

/// @brief Muestra la lista de editoriales
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
void MostrarEditorial(eEditorial editoriales[], int tamE);

/// @brief Carga la descripcion de las editoriales con su respectivo id
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @param id le paso el id con el que tiene que comparar en la condicion del if para cargar una descripcion
/// @param descEditorial le paso el array de caracteres para que en el copien una descripcion
/// @return retorna 1 si se pudo hacer correctamente
int CargarDescripcionEditorial(eEditorial editoriales[], int tamE, int id, char descEditorial[]);

#endif /* EDITORIAL_H_ */
