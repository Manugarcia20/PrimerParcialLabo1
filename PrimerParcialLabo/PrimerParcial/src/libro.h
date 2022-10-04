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

int InicializarLibros(eLibro libros[], int tam);
int BuscarEspacioLibre(eLibro libros[], int tam, int *pPosicion);

int AltaPasajero(eLibro libros[], int tamL, int *pId, eAutor autores[], int tamA, ePais paises[], int tamP, eEditorial editoriales[], int tamE);
void CargarPrecio(float *precio, char mensaje[], char mensajeError[]);

int ModificarLibros(eLibro libros[], int tamL , int idLibroCambio, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[], int tamP);
int BajaLibro(eLibro libros[], int tamL, int idLibroBaja, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP);
#endif /* LIBRO_H_ */
