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


void CargarPrecio(float *precio, char mensaje[], char mensajeError[]) {
		char auxPrecio[51];

		printf("%s", mensaje);
		scanf("%s", auxPrecio);

		while (!(esNumericoFlotante(auxPrecio))) {
			printf("%s", mensajeError);
			scanf("%s", auxPrecio);
		}

		*precio = atof(auxPrecio);

	}

int MostrarUnLibro(eLibro libro, eAutor autores[],eEditorial editoriales[], int tamL, int tamA, ePais paises[],int tamP){
		int isOk = 0;
		char descAutor[20];
		char descEditorial[20];
//		char descPais[20];

		if(autores != NULL && tamL > 0)
		{
		CargarDescripcionAutor(autores, tamL, libro.idAutor, descAutor);
//		CargarDescripcionPais(paises,tamP,libro.,descPais);
		CargarDescripcionEditorial(editoriales,tamL,libro.idEditorial,descEditorial);

		printf("\n%d\t%s\t\t%d/%d/%d\t%.2f\t%s\t%s\t\n",    	 libro.idLibro,
															 	     libro.titulo,
																	 libro.fecha.dia,
																	 libro.fecha.mes,
																	 libro.fecha.anio,
																  	 libro.importe,
																	 descAutor,
//																	 descPais,
																	 descEditorial
																  );

		}
		isOk = 1;
		return isOk;
	}

int MostrarListaLibros(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[],int tamP) {

	int i;
	int isOK = 0;

	if (libros != NULL && tamL > 0) {

		printf("---------------------------------------------------------------------------------------------------------\n");
		printf("\n		*** LISTA DE LIBROS ***		\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("ID\tTITULO\tFECHA DE PUBLICACION\tPRECIO\tAUTOR\tEDITORIAL\t\n");
		printf("---------------------------------------------------------------------------------------------------------\n");

		for (i = 0; i < tamL; i++) {
			if (libros[i].estado == LLENO) {
				MostrarUnLibro(libros[i],autores,editoriales,tamA,tamE,paises,tamP);
			}
		}
			isOK = 1;
	}

	return isOK;
}

int BuscarLibro(eLibro libros[], int tamL, int id) {
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
float CalcularTotalYPromedio(eLibro libros[], int tamL,float *promedio){
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
int SuperanPromedio(eLibro libros[], int tamL, float promedio){
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

int CantidadAnteriorFecha(eLibro libros[], int tamL){
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

int OrdenarPorImporteYTitulo(eLibro libros[], int tamL, eAutor autores[], int tamA, eEditorial editoriales[], int tamE, ePais paises[], int tamP){

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
		          					if( libros[i].importe == libros[j].importe ){
		            						 if( strcmp( libros[i].titulo, libros[j].titulo ) > 0 ){
		            			  					 auxLibro = libros[i];
		            			   					 libros[i] = libros[j];
		            			  					 libros[j] = auxLibro;
		            			                        }
		            			                    }
		            			                }
		            			            }
		            			        }
//		                //criterio+condicion de ordenamiento dentro del if > o <          importe
//		                if(libros[i].importe < libros[j].importe)
//		                {
//		                    auxLibro=libros[i];
//		                    libros[i]=libros[j];
//		                    libros[j]=auxLibro;
//		                }
//		                //criterio+condicion de ordenamiento dentro del if > o <          titulo
//		                if(libros[i].importe == libros[j].importe){
//		                if(strcmp(libros[i].titulo,libros[j].titulo) > 0)
//		                {
//		                    auxLibro=libros[i];
//		                    libros[i]=libros[j];
//		                    libros[j]=auxLibro;
//		                }
//		                }
		            }// segundo for
		        }// validacion
		        }// primer for
		       MostrarListaLibros(libros,tamL,autores,tamA,editoriales,tamE,paises,tamP);

		    return 0;


		}

















