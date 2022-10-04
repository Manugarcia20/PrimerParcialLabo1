/*
 * autor.c
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#include "autor.h"

void MostrarAutor(eAutor autores[], int tamA, ePais paises[]){
	for(int i = 0; i< tamA; i++){
		 printf("%d %s %s\n",autores[i].idAutor,autores[i].nombre,paises[(autores[i].idPais)-1].descPais);
	}
}

int CargarDescripcionAutor(eAutor autores[], int tamA, int id, char descAutor[]){
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
