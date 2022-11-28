/*
 * funciones.c
 *
 *  Created on: 1 oct. 2022
 *      Author: manu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "funciones.h"
#include "libro.h"


void cargarPrecio(float *precio, char mensaje[], char mensajeError[]) {
		char auxPrecio[51];

		printf("%s", mensaje);
		scanf("%s", auxPrecio);

		while (!(esNumericoFlotante(auxPrecio))) {
			printf("%s", mensajeError);
			scanf("%s", auxPrecio);
		}

		*precio = atof(auxPrecio);

	}

int mostrarUnLibro(eLibro libro, eAutor autores[],eEditorial editoriales[], int tamL, int tamA, ePais paises[],int tamP, eGenero generos[], int tamG){
		int isOk = 0;
		char descAutor[20];
		char descEditorial[20];
		char descGenero[20];

		if(autores != NULL && tamL > 0)
		{
		cargarDescripcionAutor(autores, tamL, libro.idAutor, descAutor);
		cargarDescripcionGenero(generos,tamG,libro.idGenero,descGenero);
		cargarDescripcionEditorial(editoriales,tamL,libro.idEditorial,descEditorial);

		printf("\n %-5d 	%-15s     %d/%d/%d      	  %-15.2f %-12s %-12s %-12s \n",
																     libro.idLibro,
															 	     libro.titulo,
																	 libro.fecha.dia,
																	 libro.fecha.mes,
																	 libro.fecha.anio,
																  	 libro.importe,
																	 descAutor,
																	 descGenero,
																	 descEditorial
																  );

		}
		isOk = 1;
		return isOk;
	}

int mostrarListaLibros(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[],int tamP, eGenero generos[], int tamG) {

	int i;
	int isOK = 0;

	if (libros != NULL && tamL > 0) {

		printf("--------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n		*** LISTA DE LIBROS ***		\n");
		printf("--------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 TITULO		FECHA DE PUBLICACION	   PRECIO	  AUTOR		GENERO	    EDITORIAL	\n");
		printf("---------------------------------------------------------------------------------------------------------------------------\n");

		for (i = 0; i < tamL; i++) {
			if (libros[i].estado == LLENO) {
				mostrarUnLibro(libros[i],autores,editoriales,tamA,tamE,paises,tamP,generos,tamG);
			}
		}
			isOK = 1;
	}

	return isOK;
}

int buscarLibro(eLibro libros[], int tamL, int id) {
		int posicionLibro;

		posicionLibro = -1; /*En caso de no haber espacio, lista nula o id inexistente*/

		if (libros != NULL && tamL > 0) {
			for (int i = 0; i < tamL; i++) {
				if (libros[i].idLibro == id) {
					posicionLibro = i;
				}
			}
		}
		return posicionLibro;
	}
float calcularTotalYPromedio(eLibro libros[], int tamL,float *promedio){
	int isOk =0;
	float acumImporte =0;
	int cantImporte =0;


	for(int i = 0; i < tamL ;i++){
		if(libros[i].estado == LLENO){
		acumImporte = acumImporte + libros[i].importe;
		cantImporte++;
		}
	}

	*promedio = (float)acumImporte/cantImporte;


	printf("El importe total es %.2f y el promedio de los importes es %.2f",acumImporte,*promedio);
	isOk =1;

	return isOk;
}
int superanPromedio(eLibro libros[], int tamL, float promedio){
	int isOk =0;
	int superan = 0;
	for(int i = 0; i < tamL ;i++){
			if(libros[i].estado == LLENO && libros[i].importe > promedio){
				superan++;
			}
		}
	printf("\nHay %d libro/s que superan el promedio ",superan);
	isOk =1;


	return isOk;
}

int cantidadAnteriorFecha(eLibro libros[], int tamL){
	int isOk = 0;
	int cantAnterior = 0;

	for(int i = 0; i < tamL ;i++){
		if(libros[i].estado == LLENO && libros[i].fecha.anio < 2000){
			cantAnterior++;
		}
	}
		isOk = 1;
		printf("\nHay %d libro/s cuya fecha de publicación es anterior al 01/01/2000 ",cantAnterior);

	return isOk;

}

int ordenarPorImporteYTitulo(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[], int tamP,eGenero generos[],int tamG){

	   eLibro auxLibro;


		        for(int i=0; i<tamL-1; i++)
		        {
		        	if(libros[i].estado == LLENO){

		            for(int j=i+1; j<tamL; j++)
		            {
		            	   for(int i=0; i<tamL-1; i++){
		         			for( int j=i+1; j<tamL; j++ ){
		            			                //       'M' > 'F'
		            			 if( libros[i].importe < libros[j].importe ){
		            			 			 auxLibro = libros[i];
		            						  libros[i] = libros[j];
		            			 			 libros[j] = auxLibro;
		            			 }
		            			                // 'M' < 'F'  'F' == 'F'  'M' == 'M'
		     					 else{
		          					if(libros[i].importe == libros[j].importe ){
		            						 if( strcmp( libros[i].titulo, libros[j].titulo ) > 0 ){
		            			  					 auxLibro = libros[i];
		            			   					 libros[i] = libros[j];
		            			  					 libros[j] = auxLibro;
		            			                        }
		            			                    }
		            			                }
		            			            }
		            			        }

		            }// segundo for
		        }// validacion
		        }// primer for
		       mostrarListaLibros(libros,tamL,autores,tamA,editoriales,tamE,paises,tamP,generos,tamG);

		    return 0;


		}


int librosDistintoANovela(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[],int tamP, eGenero generos[], int tamG){
	int isOk =0;

	for(int i = 0; i < tamL ;i++){
			if(libros[i].estado == LLENO && libros[i].idGenero != 5){
				mostrarUnLibro(libros[i],autores,editoriales,tamA,tamE,paises,tamP,generos,tamG);
				}
			}
isOk = 1;
	return isOk;
}


///Listar todos los libros de autores argentinos que correspondan a una editorial determinada.

int listarLibrosArgentinosDeterminados(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[],
		int tamE ,ePais paises[],int tamP, eGenero generos[], int tamG)
{

	int isOk = -1;

	int editorialElegida;


	  printf("\n\n");

	  mostrarEditorial(editoriales,tamE);
	  editorialElegida = getValidInt("\nElija el id de la editorial a listar por autores argentinos: ","\nError. Ingrese solo letras: ",1,5);

	  printf("\nID	 TITULO		FECHA DE PUBLICACION	   PRECIO	  AUTOR		GENERO	    EDITORIAL	\n");

	  for(int i = 0; i < tamL ;i++)
	 {
		if(libros[i].estado == LLENO) /// si se cargaron los libros
		{
			for(int j = 0;j<tamA;j++)
			{
				if(autores[j].idPais == 1 && libros[i].idAutor == autores[j].idAutor)
				{
					for(int k=0;k<tamE;k++)
					{
						if(libros[i].idEditorial == editorialElegida && editoriales[k].idEditorial == editorialElegida)
						{
							for(int g=0;g<tamG;g++)
							{
								if(libros[i].idGenero == generos[g].idGenero)
								{
								mostrarUnLibro(libros[i],&autores[j],&editoriales[k],tamL,tamA,paises,tamP,&generos[g],tamG);
								isOk =1;
								}
							}
						}
					}
				}
			}
		}
	 }

return isOk;
}




































