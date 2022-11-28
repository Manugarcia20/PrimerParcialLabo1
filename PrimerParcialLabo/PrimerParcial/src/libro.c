/*
 * libro.c
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#include "libro.h"
#include "input.h"

#include "funciones.h"
#include "menu.h"

/// MENU DE OPCIONES
int menuOpciones(){

	int opcion;

		printf("\n1 - ALTA\n");
		printf("\n2 - MODIFICACION\n");
		printf("\n3 - BAJA\n");
		printf("\n4 - INFORMAR\n");
		printf("\n5 - LISTAR\n");
		printf("\n6 - SALIR\n");

		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,6);

		return opcion;
}

int subMenuModificar(){

	int opcion;

		printf("\n\n");
		printf("\nQUE DESEA MODIFICAR?\n");

		printf("\n1 - TITULO\n");
		printf("\n2 - FECHA DE PUBLICACION\n");
		printf("\n3 - PRECIO DEL LIBRO\n");
		printf("\n4 - AUTOR\n");
		printf("\n5 - EDITORIAL\n");
		printf("\n6 - GENERO\n");
		printf("\n7 - SALIR\n");


		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,7);

		return opcion;
}

int subMenuInformes(){
	int opcion;

		printf("\n\n");
		printf("\nQUE DESEA INFORMAR?\n");

		printf("\n1 - Total y promedio de los importes, y cuántos libros superan ese promedio.\n");
		printf("\n2 - Cantidad de libros cuya fecha de publicación es anterior a 01/01/2000\n");
		printf("\n3 - SALIR\n");

		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,3);

		return opcion;
}

int subMenuListar(){
	int opcion;

		printf("\n\n");
		printf("\nQUE DESEA LISTAR?\n");

		printf("\n1 - EDITORIALES");
		printf("\n2 - PAISES");
		printf("\n3 - AUTORES");
		printf("\n4 - GENEROS");
		printf("\n5 - LIBROS");
		printf("\n6 - LIBROS ORDENADOS POR IMPORTE (DESCENDENTE) Y TITULO (ASCENDENTEMENTE)");
		printf("\n7 - LIBROS CUYO GENERO NO SEA NOVELA");
		printf("\n8 - LIBROS DE AUTORES ARGENTINOS QUE CORRESPONDAN A UNA EDITORIAL DETERMINADA \n");


		printf("\n9 - SALIR\n");

		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,9);

		return opcion;
}

int subMenuListaAutoresArgPorEditorial(){
	int opcion;

		printf("\n\n");
		printf("\nQUE EDITORIAL DESEA LISTAR?\n");

		printf("\n1 - ATLANTIDA");
		printf("\n2 - ARGENTA");
		printf("\n3 - COLUMBA");
		printf("\n4 - INTA");
		printf("\n5 - POLAR");

		opcion = getValidInt("\nElija una opcion: ", "Error. Ingrese una opcion valida: ", 1,5);

		return opcion;

}
/// MENU DE OPCIONES



/// EDITORIAL
void mostrarEditorial(eEditorial editoriales[], int tamE){
	 for(int i=0; i<tamE; i++)
	{

	printf("%d %s\n",editoriales[i].idEditorial,editoriales[i].descEditorial);
	}

}

int cargarDescripcionEditorial(eEditorial editoriales[], int tamE, int id, char descEditorial[]){
	int isOk = 0;

	if(editoriales != NULL && tamE> 0 && id >= 1 && id <= 5 && descEditorial != NULL)
	{
		for(int i = 0; i < tamE; i++)
		{
			if(editoriales[i].idEditorial == id)
			{
				strcpy(descEditorial,editoriales[i].descEditorial);
				break;
			}
		}

		isOk = 1;
	}
		return isOk;
}
/// EDITORIAL


/// PAIS
void mostrarPais(ePais paises[], int tamP){
	 for(int i=0; i<tamP; i++)
		{
		printf("%d %s\n",paises[i].idPais,paises[i].descPais);
		}
}
/// PAIS



/// AUTOR
void mostrarAutor(eAutor autores[], int tamA, ePais paises[]){
	for(int i = 0; i< tamA; i++){
		 printf("%d %s %s\n",autores[i].idAutor,autores[i].nombre,paises[(autores[i].idPais)-1].descPais);
	}
}

int cargarDescripcionAutor(eAutor autores[], int tamA, int id, char descAutor[]){
	int isOk = 0;

	if(autores != NULL && tamA> 0 && id >0 && id < 11 && descAutor != NULL)
	{
		for(int i = 0; i < tamA; i++)
		{
			if(autores[i].idAutor == id)
			{
				strcpy(descAutor,autores[i].nombre);
				break;
			}
		}

		isOk = 1;
	}
		return isOk;
}
/// AUTOR


/// GENERO
void mostrarGenero(eGenero generos[], int tamG){
	 for(int i=0; i<tamG; i++)
		{
		printf("%d %s\n",generos[i].idGenero,generos[i].descGenero);
		}
}


int cargarDescripcionGenero(eGenero generos[], int tamG, int id, char descGenero[]){
	int isOk = 0;

	if(generos != NULL && tamG > 0 && id > 0 && id < 6 && descGenero != NULL)
	{
		for(int i = 0; i < tamG; i++)
		{
			if(generos[i].idGenero == id)
			{
				strcpy(descGenero,generos[i].descGenero);
				break;
			}
		}
		isOk = 1;
	}
		return isOk;
}
/// GENERO


/// LIBRO
int inicializarLibros(eLibro libros[], int tam){
	int i;
	int isOK = -1;
	if (libros != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			libros[i].estado = VACIO;
			isOK = 0;
		}
	}
	return isOK;


}
int buscarEspacioLibre(eLibro libros[], int tam, int *pPosicion){
	int isOk = 0;

		if(libros != NULL && tam > 0 && pPosicion != NULL)
		{
			*pPosicion = -1;
			for(int i = 0; i < tam; i++)
			{
				if(libros[i].estado == 0)
				{
					*pPosicion = i;
					break;
				}
			}
			isOk = 1;

		}
		return isOk;

}

int altaLibro(eLibro libros[], int tamL, int *pId, eAutor autores[], int tamA, ePais paises[], int tamP, eEditorial editoriales[], int tamE, eGenero generos[], int tamG){

	int isOk = 0;
		int posicion;
		int idAutor;
		int idEditorial;
		int idGenero;


		eLibro nuevoLibro;


		if (libros != NULL && tamL > 0 && pId != NULL) {


			if (buscarEspacioLibre(libros, tamL, &posicion)) {

				if (posicion == -1)
				{
					printf("\nNo hay lugar en el sistema\n");

				}
				else
				{

					utn_getChar(nuevoLibro.titulo,"\nIngrese un titulo: ","\nError. Ingrese solo letras");

					nuevoLibro.fecha.dia = getValidInt("\nIngrese el dia de publicacion del libro: ","Error. Ingrese solo numeros: ",1,31);
					nuevoLibro.fecha.mes = getValidInt("\nIngrese el mes de publicacion del libro: ","Error. Ingrese solo numeros: ",1,12);
					nuevoLibro.fecha.anio = getValidInt("\nIngrese el anio de publicacion del libro: ","Error. Ingrese solo numeros: ",1800,2022);

				    cargarPrecio(&nuevoLibro.importe, "\nIngrese el precio del libro :  ", "\nError. No ingrese numeros negativos, simbolos ni letras ");

				    printf("\n\n");

				    mostrarAutor(autores,tamA,paises);
				    idAutor = getValidInt("\nIngrese el autor del libro: ", "\nError, ingrese un tipo correcto: ", 1, 10);
				    nuevoLibro.idAutor = idAutor;

				    printf("\n\n");
				    mostrarEditorial(editoriales,tamE);
				   	idEditorial = getValidInt("\nIngrese la editorial del libro: ", "\nError, ingrese un tipo correcto: ", 1, 5);
				   	nuevoLibro.idEditorial = idEditorial;

				   	mostrarGenero(generos,tamG);
				   	idGenero = getValidInt("\nIngrese el genero del libro: ", "\nError, ingrese un tipo correcto: ", 1, 5);
				   	nuevoLibro.idGenero = idGenero;

					nuevoLibro.estado = LLENO;
					nuevoLibro.idLibro = *pId;
					(*pId)++;

					libros[posicion] = nuevoLibro;
					isOk = 1;

				}

			}
		}

			return isOk;


}


int modificarLibros(eLibro libros[], int tamL , int idLibroCambio, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[], int tamP, eGenero generos[], int tamG)
	{
		int isOk;
		int subMenu;
		int posLibroCambio;
		int nuevoAutor;
		int nuevaEditorial;
		int nuevoGenero;
		char respuesta;


					isOk = -1;
					if (libros != NULL && tamL > 0) {
						printf("\n		*** MODIFICACION DE LIBROS ***						\n\n");
						mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG); //--muestro libros activos
						idLibroCambio = getValidInt( "\nIngrese el id del libro a modificar:  ", "Error, ingrese un ID valido:  ", 1, 10);
						posLibroCambio = buscarLibro(libros, tamL, idLibroCambio);
						if (posLibroCambio != -1) //el libro existe
								{

							respuesta = getChar("\nEsta seguro de que quiere modificar el libro %d ? s/n ");
							if (respuesta == 's') {

								do{
								subMenu = subMenuModificar();
								switch(subMenu){
								case 1:
									 printf("\nUsted eligio: MODIFICAR TITULO\n");
									 utn_getChar(libros[posLibroCambio].titulo,"\nIngrese un nuevo titulo: ","\nError. Ingrese solo letras");
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 2:
									 printf("\nUsted eligio: MODIFICAR FECHA DE PUBLICACION\n");
									 libros[posLibroCambio].fecha.dia = getValidInt("\nIngrese el nuevo dia de publicacion: " , "\nError, ingrese un numero: ",1,31);
									 libros[posLibroCambio].fecha.mes = getValidInt("\nIngrese el nuevo mes de publicacion: " , "\nError, ingrese un numero: ",1,12);
									 libros[posLibroCambio].fecha.anio = getValidInt("\nIngrese el nuevo anio de publicacion: " , "\nError, ingrese un numero: ",1800,2022);
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 3:
									 printf("\nUsted eligio: MODIFICAR IMPORTE DEL LIBRO\n");
									 cargarPrecio(&libros[posLibroCambio].importe, "\nIngrese el nuevo importe del libro:  ", "\nError. No ingrese numeros negativos, simbolos ni letras: ");
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 4:
									 printf("\nUsted eligio: MODIFICAR AUTOR\n");
									 mostrarAutor(autores,tamA,paises);
									 nuevoAutor = getValidInt("\nIngrese el id del nuevo autor: " , "\nError, ingrese un id valido: ",1,10);
									 libros[posLibroCambio].idAutor = nuevoAutor;
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 5:
									 printf("\nUsted eligio: MODIFICAR EDITORIAL\n");
									 mostrarEditorial(editoriales,tamE);
									 nuevaEditorial = getValidInt("\nIngrese el id de la nueva editorial: " , "\nError, ingrese un id valido: ",1,5);
									 libros[posLibroCambio].idEditorial = nuevaEditorial;
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 6:
									 printf("\nUsted eligio: GENERO\n");
									 mostrarGenero(generos,tamG);
									 nuevoGenero = getValidInt("\nIngrese el id del nuevo genero: " , "\nError, ingrese un id valido: ",1,5);
									 libros[posLibroCambio].idGenero = nuevoGenero;
									 mostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP,generos,tamG);
									break;
								case 7:
									printf("\nUsted eligio: SALIR\n");
									break;
								default:
									printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
									break;
									isOk =1;
								}
								}while(subMenu !=7);

							}else{
								printf("\nModificacion cancelada");
							}


	}else
	{
		printf("\nNo hay ningun libro cargado con el id %d", idLibroCambio);
	}
					}

		return isOk;
	}

int bajaLibro(eLibro libros[], int tamL, int idLibroBaja, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP, eGenero generos[], int tamG) {
			int isOk;
			int posLibroBaja;
			char respuesta;

			isOk = -1;
			if (libros != NULL && tamL > 0) {
				printf("\n		*** BAJA DE LIBROS ***						\n\n");
				mostrarListaLibros(libros,tamL,autores,tamA,editoriales,tamE,paises,tamP,generos,tamG); //--muestro libros activos
				idLibroBaja = getValidInt( "\nIngrese el id del libro a eliminar:  ", "Error, ingrese un ID valido:  ", 1, 10);
				posLibroBaja = buscarLibro(libros, tamL, idLibroBaja);
				if (posLibroBaja != -1) //el empleado existe
						{
					respuesta = getChar("\nEsta seguro de que quiere eliminar el libro? s/n ");
					if (respuesta == 's') {
						libros[posLibroBaja].estado = VACIO;
						isOk = 1;
					}else{
						printf("\nBaja cancelada");
					}

				} else {
					printf("\nEl id %d no esta registrado en el sistema",idLibroBaja);
				}

			}
			return isOk;
		}
/// LIBRO

















