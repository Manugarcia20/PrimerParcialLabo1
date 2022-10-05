/*
 * pais.h
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#ifndef PAIS_H_
#define PAIS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LLENO 1
#define VACIO 0
#define TAM_P 5


typedef struct{
	int idPais;
	char descPais[51];
	int estado;
}ePais;


//int CargarDescripcionPais(ePais paises[], int tamP, int id, char descPais[]);

/// @brief Muestra la lista de paises
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array editoriales
void MostrarPais(ePais paises[], int tamP);

#endif /* PAIS_H_ */
