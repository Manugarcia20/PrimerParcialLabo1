/*
 * libro.c
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#include "libro.h"
#include "input.h"
#include "editorial.h"
#include "autor.h"
#include "funciones.h"
#include "menu.h"

int InicializarLibros(eLibro libros[], int tam){
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
int BuscarEspacioLibre(eLibro libros[], int tam, int *pPosicion){
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

int AltaLibro(eLibro libros[], int tamL, int *pId, eAutor autores[], int tamA, ePais paises[], int tamP, eEditorial editoriales[], int tamE){

	int isOk = 0;
		int posicion;
		int idAutor;
		int idEditorial;


		eLibro nuevoLibro;


		if (libros != NULL && tamL > 0 && pId != NULL) {


			if (BuscarEspacioLibre(libros, tamL, &posicion)) {

				if (posicion == -1)
				{
					printf("\nNo hay lugar en el sistema\n");

				}
				else
				{
					while (getStringLetras("\nIngrese un titulo: ", nuevoLibro.titulo) == -1)
					{
						fflush(stdin);
						printf("\nCaracteres invalidos. Por favor, ingrese solo letras: ");
					}

					nuevoLibro.fecha.dia = getValidInt("\nIngrese el dia de publicacion del libro: ","Error. Ingrese solo numeros: ",1,30);
					nuevoLibro.fecha.mes = getValidInt("\nIngrese el mes de publicacion del libro: ","Error. Ingrese solo numeros: ",1,12);
					nuevoLibro.fecha.anio = getValidInt("\nIngrese el anio de publicacion del libro: ","Error. Ingrese solo numeros: ",1700,2022);

				    CargarPrecio(&nuevoLibro.importe, "\nIngrese el precio del libro :  ", "\nError. Ingrese solo numeros: ");



				    printf("\n\n");

				    MostrarAutor(autores,tamA,paises);
				    idAutor = getValidInt("\nIngrese el autor del libro: ", "\nError, ingrese un tipo correcto: ", 1, 10);
				    nuevoLibro.idAutor = idAutor;

				    printf("\n\n");
				    MostrarEditorial(editoriales,tamE);
				   	idEditorial = getValidInt("\nIngrese la editorial del libro: ", "\nError, ingrese un tipo correcto: ", 1, 5);
				   	nuevoLibro.idEditorial = idEditorial;

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


int ModificarLibros(eLibro libros[], int tamL , int idLibroCambio, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[], int tamP)
	{
		int isOk;
		int subMenu;
		int posLibroCambio;
		int nuevoAutor;
		int nuevaEditorial;
		char respuesta;


					isOk = -1;
					if (libros != NULL && tamL > 0) {
						printf("\n		*** MODIFICACION DE LIBROS ***						\n\n");
						MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP); //--muestro libros activos
						idLibroCambio = getValidInt( "\nIngrese el id del libro a modificar:  ", "Error, ingrese un ID valido:  ", 1, 10);
						posLibroCambio = BuscarLibro(libros, tamL, idLibroCambio);
						if (posLibroCambio != -1) //el libro existe
								{

							respuesta = getChar("\nEsta seguro de que quiere modificar el libro %d ? s/n ");
							if (respuesta == 's') {

								do{
								subMenu = subMenuModificar();
								switch(subMenu){
								case 1:
									printf("\nUsted eligio: MODIFICAR TITULO\n");
									while (getStringLetras("\nIngrese un nuevo titulo: ", libros[posLibroCambio].titulo) == -1)
									{
										printf("\nCaracteres invalidos. Por favor, ingrese solo letras");
									}
									MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP);
									break;
								case 2:
									printf("\nUsted eligio: MODIFICAR FECHA DE PUBLICACION\n");
									libros[posLibroCambio].fecha.dia = getValidInt("\nIngrese el nuevo dia de publicacion: " , "\nError, ingrese un numero: ",1,30);
									libros[posLibroCambio].fecha.mes = getValidInt("\nIngrese el nuevo mes de publicacion: " , "\nError, ingrese un numero: ",1,12);
									libros[posLibroCambio].fecha.anio = getValidInt("\nIngrese el nuevo anio de publicacion: " , "\nError, ingrese un numero: ",1800,2022);
									MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP);
									break;
								case 3:
									printf("\nUsted eligio: MODIFICAR IMPORTE DEL LIBRO\n");
									CargarPrecio(&libros[posLibroCambio].importe, "\nIngrese el nuevo importe del libro:  ", "\nError. Ingrese solo numeros");
									MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP);
									break;
								case 4:
									printf("\nUsted eligio: MODIFICAR AUTOR\n");
									 MostrarAutor(autores,tamA,paises);
									 nuevoAutor = getValidInt("\nIngrese el id del nuevo autor: " , "\nError, ingrese un id valido: ",1,10);
									 libros[posLibroCambio].idAutor = nuevoAutor;
									 MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP);
									break;
								case 5:
									printf("\nUsted eligio: MODIFICAR EDITORIAL\n");
									 MostrarEditorial(editoriales,tamE);
									nuevaEditorial = getValidInt("\nIngrese el id de la nueva editorial: " , "\nError, ingrese un id valido: ",1,5);
									libros[posLibroCambio].idEditorial = nuevaEditorial;
									MostrarListaLibros(libros,tamL,autores,tamA, editoriales,tamE,paises,tamP);
									break;
								case 6:
									printf("\nUsted eligio: SALIR\n");
									break;
								default:
									printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
									break;
								}
								}while(subMenu !=6);

								isOk =1;
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

int BajaLibro(eLibro libros[], int tamL, int idLibroBaja, eAutor autores[], int tamA, eEditorial editoriales[], int tamE,ePais paises[],int tamP) {
			int isOk;
			int posLibroBaja;
			char respuesta;

			isOk = -1;
			if (libros != NULL && tamL > 0) {
				printf("\n		*** BAJA DE LIBROS ***						\n\n");
				MostrarListaLibros(libros,tamL,autores,tamA,editoriales,tamE,paises,tamP); //--muestro libros activos
				idLibroBaja = getValidInt( "\nIngrese el id del libro a eliminar:  ", "Error, ingrese un ID valido:  ", 1, 10);
				posLibroBaja = BuscarLibro(libros, tamL, idLibroBaja);
				if (posLibroBaja != -1) //el empleado existe
						{
					respuesta = getChar("\nEsta seguro de que quiere eliminar el libro? s/n ");
					if (respuesta == 's') {
						libros[posLibroBaja].estado = VACIO;
						isOk = 0;
					}else{
						printf("\nBaja cancelada");
					}

				} else {
					printf("\nEl id %d no esta registrado en el sistema",idLibroBaja);
				}

			}
			return isOk;
		}


















