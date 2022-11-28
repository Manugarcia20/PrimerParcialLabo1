/*
 * libro.h
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <string.h>


#define LLENO 1
#define VACIO 0
#define TAM_E 5
#define TAM_P 5
#define TAM_A 10
#define TAM_G 5
#define TAM_L 10
#define FGETS 51


typedef struct{
	int idEditorial;
	char descEditorial[51];
	int estado;
}eEditorial;


typedef struct{
	int idPais;
	char descPais[51];
	int estado;
}ePais;


typedef struct{
	int idAutor;
	char nombre[51];
	int idPais;
	int estado;

}eAutor;


typedef struct{

	int idGenero;
	char descGenero[51];
	int estado;
}eGenero;


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
	int idGenero;
}eLibro;

/// MENU DE OPCIONES
/// @brief Despliega el menu principal del programa
/// @return retorna la opcion elegida por el usuario para el menu principal del main
int menuOpciones();

/// @brief Despliega un sub menu para las modificaciones
/// @return retorna la opcion elegida por el usuario para el sub menu de modificacion
int subMenuModificar();

/// @brief Despliega un menu de opciones para los informes
/// @return retorna la opcion elegida por el usuario para el sub menu de los informes
int subMenuInformes();

/// @brief Despliega un menu de opciones para listar
/// @return retorna la opcion elegida por el usuario para el sub menu de las listas
int subMenuListar();


/// @brief Despliega un menu de opciones para listar autores argentinos por editorial elegida
/// @return retorna la opcion elegida por el usuario para el sub menu
int subMenuListaAutoresArgPorEditorial();
/// MENU DE OPCIONES


/// EDITORIAL
/// @brief Muestra la lista de editoriales
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
void mostrarEditorial(eEditorial editoriales[], int tamE);

/// @brief Carga la descripcion de las editoriales con su respectivo id
/// @param editoriales Le paso el array de estructuras de tipo eEditorial
/// @param tamE Le paso el tamanio del array editoriales
/// @param id le paso el id con el que tiene que comparar en la condicion del if para cargar una descripcion
/// @param descEditorial le paso el array de caracteres para que en el copien una descripcion
/// @return retorna 1 si se pudo hacer correctamente
int cargarDescripcionEditorial(eEditorial editoriales[], int tamE, int id, char descEditorial[]);
/// EDITORIAL



/// PAIS
/// @brief Muestra la lista de paises
/// @param paises Le paso el array de estructuras de tipo ePais
/// @param tamP Le paso el tamanio del array editoriales
void mostrarPais(ePais paises[], int tamP);
/// PAIS



/// AUTOR
/// @brief Carga la descripcion de los autores con su respectivo id
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param id le paso el id con el que tiene que comparar en la condicion del if para cargar una descripcion
/// @param descAutor le paso el array de caracteres para que en el copien una descripcion
/// @return retorna 1 si se pudo hacer correctamente
int cargarDescripcionAutor(eAutor autores[], int tamA, int id, char descAutor[]);

/// @brief Muestra la lista de autores
/// @param autores Le paso el array de estructuras de tipo eAutor
/// @param tamA Le paso el tamanio del array autores
/// @param paises Le paso el array de estructuras de tipo ePais
void mostrarAutor(eAutor autores[], int tamA, ePais paises[]);
/// AUTOR



/// GENERO
/// @brief Muestra la lista de generos
/// @param paises Le paso el array de estructuras de tipo eGenero
/// @param tamP Le paso el tamanio del array generos
void mostrarGenero(eGenero generos[], int tamG);


/// @brief Carga la descripcion de los generos con su respectivo id
/// @param generos Le paso el array de estructuras de tipo eGenero
/// @param tamG Le paso el tamanio del array generos
/// @param id le paso el id con el que tiene que comparar en la condicion del if para cargar una descripcion
/// @param descGenero le paso el array de caracteres para que en el copien una descripcion
/// @return retorna 1 si se pudo hacer correctamente
int cargarDescripcionGenero(eGenero generos[], int tamG, int id, char descGenero[]);
/// GENERO



/// LIBRO
/// @brief Inicializa todas las posiciones del array libros de tipo Elibro en 0
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tam Le paso el tamanio del array
/// @return retorna 0 si salio bien
int inicializarLibros(eLibro libros[], int tam);


/// @brief Busca un espacio libre en el array libros de tipo eLibro
/// @param libros Le paso el array de estructuras de tipo eLibro
/// @param tam Le paso el tamanio del array
/// @param pPosicion  Le paso el puntero pPosicion para que reciba la posicion encontrada
/// @returnretorna 0 si salio bien
int buscarEspacioLibre(eLibro libros[], int tam, int *pPosicion);

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
int altaLibro(eLibro libros[], int tamL, int *pId, eAutor autores[], int tamA, ePais paises[], int tamP, eEditorial editoriales[], int tamE, eGenero generos[], int tamG);

/// @brief Obtiene el importe cargado por el usuario
/// @param precio Le paso la variable precio puntero para que reciba el valor del importe cargado
/// @param mensaje Le paso el mensaje solicitando al usuario que cargue el importe
/// @param mensajeError Le paso el mensaje de eror en caso de que haya ingresado un caracter no valido
void cargarPrecio(float *precio, char mensaje[], char mensajeError[]);

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
int modificarLibros(eLibro libros[], int tamL , int idLibroCambio, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[], int tamP, eGenero generos[], int tamG);

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
int bajaLibro(eLibro libros[], int tamL, int idLibroBaja, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP, eGenero generos[], int tamG);
/// LIBRO

#endif /* LIBRO_H_ */
