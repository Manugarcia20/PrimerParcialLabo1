/*
 * pais.c
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#include "pais.h"


int CargarDescripcionPais(ePais paises[], int tamP, int id, char descPais[]){
	int isOk = 0;

	if(paises != NULL && tamP > 0 && id > 0 && id < 6 && descPais != NULL)
	{
		for(int i = 0; i < tamP; i++)
		{
			if(paises[i].idPais == id)
			{
				strcpy(descPais,paises[i].descPais);
				break;
			}
		}
		isOk = 1;
	}
		return isOk;
}

void MostrarPais(ePais paises[], int tamP){
	 for(int i=0; i<tamP; i++)
		{
		printf("%d %s\n",paises[i].idPais,paises[i].descPais);
		}
}
