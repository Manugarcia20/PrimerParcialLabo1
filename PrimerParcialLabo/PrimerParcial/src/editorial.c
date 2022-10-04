/*
 * editorial.c
 *
 *  Created on: 30 sep. 2022
 *      Author: manu
 */

#include "editorial.h"

void MostrarEditorial(eEditorial editoriales[], int tamE){
	 for(int i=0; i<tamE; i++)
	{
	printf("%d %s\n",editoriales[i].idEditorial,editoriales[i].descEditorial);
	}

}

int CargarDescripcionEditorial(eEditorial editoriales[], int tamE, int id, char descEditorial[]){
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