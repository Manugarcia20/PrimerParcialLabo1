/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "input.h"
#include "funciones.h"
#include "editorial.h"
#include "pais.h"
#include "autor.h"
#include "libro.h"



int main(void) {
	int opcion;
	int pId =1;
	int idLibroCambio =0;
	int idLibroBaja =0;
	float promedio =0;
	int informes;
	int listar;
	int flagAlta = 0;

	eEditorial editoriales[TAM_E] = {
			{1,"ATLANTIDA",LLENO},
			{2,"ARGENTA",LLENO},
			{3,"COLUMBA",LLENO},
			{4,"INTA",LLENO},
			{5,"POLAR",LLENO}
	};

	ePais paises[TAM_P] = {
			{1,"ARGENTINA",LLENO},
			{2,"FRANCIA",LLENO},
			{3,"INGLATERRA",LLENO},
			{4,"ALEMANIA",LLENO},
			{5,"ESPANA",LLENO}
	};

	eAutor autores[TAM_A] = {
			{1,"SHAKESPEARE",3,LLENO},
			{2,"CERVANTES",5,LLENO},
			{3,"CORTAZAR",1,LLENO},
			{4,"BORGES",1,LLENO},
			{5,"WILDE",3,LLENO},
			{6,"KAFKA",4,LLENO},
			{7,"VERNE",5,LLENO},
			{8,"TOLSTOI",5,LLENO},
			{9,"NERUDA",1,LLENO},
			{10,"POE",3,LLENO},
	};

	eLibro libros[TAM_L];

	InicializarLibros(libros,TAM_L);

do{
	opcion = menuOpciones();
	switch(opcion){
	case 1:
		printf("\nUsted eligio: ALTA\n");
		AltaPasajero(libros, TAM_L, &pId , autores, TAM_A, paises, TAM_P, editoriales, TAM_E);
		flagAlta = 1;
		break;
	case 2:
		printf("\nUsted eligio: MODIFICACION\n");
		if(flagAlta == 1){
		ModificarLibros(libros, TAM_L , idLibroCambio, autores, TAM_A,editoriales,TAM_E, paises, TAM_P);
		}else{
			printf("\nNo se puede modificar un libro sin antes haber cargado uno\n");
		}
		break;
	case 3:
		printf("\nUsted eligio: BAJA\n");
		if(flagAlta == 1){
		BajaLibro(libros,TAM_L,idLibroBaja,autores, TAM_A, editoriales, TAM_E,paises,TAM_P);
		}else{
			printf("\nNo se puede dar de baja un libro sin antes haber cargado uno\n");
		}
		break;
	case 4:
		printf("\nUsted eligio: INFORMAR\n");
		if(flagAlta == 1)
		{
		do{
		informes = subMenuInformes();
		switch(informes){
		case 1:
			printf("\nUsted eligio: Informar total y promedio de los importes, y cuántos libros superan ese promedio.\n");
			CalcularTotalYPromedio(libros,TAM_L,&promedio);
			SuperanPromedio(libros,TAM_L,promedio);
			break;
		case 2:
			printf("\nUsted eligio: Informar Cantidad de libros cuya fecha de publicación es anterior a 01/01/2000\n");
			CantidadAnteriorFecha(libros,TAM_L);
			break;
		case 3:
			printf("\nUsted eligio: SALIR\n");
			break;
		}
		}while(informes != 3);
	    }else{
	    	printf("\nNo se puede informar nada de algun libro sin antes haber cargado uno\n");
	    }
		break;
		case 5:
		printf("\nUsted eligio: LISTAR\n");
		if(flagAlta == 1)
		{
		do{
			listar = subMenuListar();
			switch(listar){
		case 1:
			printf("\nUsted eligio: Listar editoriales\n");
			MostrarEditorial(editoriales, TAM_E);
			break;
		case 2:
			printf("\nUsted eligio: Listar paises\n");
			MostrarPais(paises, TAM_P);
			break;
		case 3:
			printf("\nUsted eligio: Listar autores\n");
			 MostrarAutor(autores,TAM_A,paises);
			break;
		case 4:
			printf("\nUsted eligio: Listar libros\n");
			MostrarListaLibros(libros,TAM_L,autores, TAM_A, editoriales,TAM_E,paises, TAM_P);
			break;
		case 5:
			printf("\nUsted eligio: Listar libros ordenados por importe (descendentemente) y titulo (ascendentemente)\n");
			OrdenarPorImporteYTitulo(libros,TAM_L,autores,TAM_A,editoriales,TAM_E,paises,TAM_P);
			break;
		case 6:
			printf("\nUsted eligio: SALIR\n");
			break;

			}
		}while(listar != 6);
		}else{
			printf("\nNo se puede listar nada de algun libro sin antes haber cargado uno\n");
		}
		break;
	case 6:
		printf("\nUsted eligio: SALIR\n");
		break;
	}

}while(opcion != 6);





	return EXIT_SUCCESS;
}
