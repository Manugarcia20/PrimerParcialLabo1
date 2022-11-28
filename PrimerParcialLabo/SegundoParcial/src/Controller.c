#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "LinkedList.h"
#include "input.h"
#include "Libro.h"
#include "menu.h"


int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayListLibro)
{
		int retorno = -1;
		FILE * pArchivo = NULL;


		printf("path: %s",path);

		pArchivo = fopen(path,"r");

		if(pArrayListLibro != NULL && path != NULL && pArchivo != NULL){

		if(parser_LibroFromText(pArchivo,pArrayListLibro) == 1){
		}
		printf("\nDATOS DE LIBROS PARSEADOS CORRECTAMENTE ");
		retorno = 1;
		}else{
			printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE LOS LIBROS");
		}

		fclose(pArchivo);

return retorno;
}

int controller_listarLibros(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int tamList;
	int i;

	int id;
	char titulo[50];
	float importe;
	int idTipo;
	char auxIdTipo[50];


	eLibro *auxLibro;

		if (pArrayListLibro != NULL) {
			tamList = ll_len(pArrayListLibro);

			printf("\n  ID		TITULO					IMPORTE			ID TIPO  	");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------\n");
			for (i = 0; i < tamList; i++) {

				auxLibro = (eLibro*) ll_get(pArrayListLibro, i);

				libro_getId(auxLibro,&id);
				libro_getTitulo(auxLibro,titulo);
				libro_getImporte(auxLibro,&importe);
				libro_getIdTipo(auxLibro,&idTipo);

				if(idTipo == 1){
				strcpy(auxIdTipo,"PAPEL");
				}
				else{
					if(idTipo == 2){
						strcpy(auxIdTipo,"EBOOK");
					}
				}


				printf("| %-5d | %-35s	    | 	%-10.2f	 |	%-15s|\n",id,titulo,importe,auxIdTipo);

				retorno = 1;
			}
		}
		return retorno;
}

int controller_ordenarLibros(LinkedList* pArrayListLibro)
{
	int retorno = -1;

		if(ll_sort(pArrayListLibro, ordenarLibrosPorImporte, 0) > -1){
		printf("\nLISTA ORDENADA POR IMPORTE DESCENDENTE: \n");
		controller_listarLibros(pArrayListLibro);
		retorno = 1;
		}
		return retorno;
}





int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayListLibro)
{

		int id;
		char titulo[30];
		float  importe;
		int idTipo;

		int retorno = -1;


		int cantidad;

		FILE* archivo = NULL;
		eLibro* pJugador = NULL;

		cantidad = ll_len(pArrayListLibro);

		archivo = fopen(path,"w");

		if(archivo != NULL && pArrayListLibro != NULL && path != NULL)
		{
			fprintf(archivo,"id,titulo,importe,idTipo\n");

			for(int i = 0; i < cantidad;i++)
			{
				pJugador = (eLibro*) ll_get(pArrayListLibro, i);

				 libro_getId(pJugador,&id);
				 libro_getTitulo(pJugador,titulo);
				 libro_getImporte(pJugador,&importe);
				 libro_getIdTipo(pJugador,&idTipo);

				fprintf(archivo,"%d,%s,%.2f,%d\n",id,titulo,importe,idTipo);
//				printf("%d retornoFscanf\n", retornoFscanf);
			}
				retorno = 1;
		}
		fclose(archivo);

return retorno;
}


//int controller_generarJugadoresModoBinario(char* path,LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
//
//	int retorno = -1;
//	int cantidad;
//
////	int cantConv = 0;
//	FILE *pArchivoBinario = NULL;
//	Jugador *pJugador = NULL;
//
//
//	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
//	{
//
//	pArchivoBinario = fopen(path, "wb");
//
//	cantidad = ll_len(pArrayListJugador);
//
//
//	for (int i = 0; i < cantidad; i++)
//	{
//		pJugador = (Jugador*)ll_get(pArrayListJugador, i); /// obtengo la posicion del jugador
//		fwrite(pJugador,sizeof(Jugador),1,pArchivoBinario); /// escribe el archivo binario
//		retorno = 0;
//	}
//	}
//
//
//	fclose(pArchivoBinario);
//
//
//return retorno;
//}


///** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
// *
// * \param path char*
// * \param pArrayListJugador LinkedList*
// * \return int
// *
// */
//int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
//{
//	int retorno = -1;
//
//	FILE* pArchivoBinario;
//
//	pArchivoBinario = fopen(path,"rb");
//
//	if(path != NULL && pArrayListJugador != NULL && pArrayListJugador)
//	{
//
//		if(parser_JugadorFromBinary(pArchivoBinario,pArrayListJugador) == 0)
//		{
//			printf("\nDATOS DE JUGADORES BINARIOS PARSEADOS CORRECTAMENTE\n");
//				retorno = 0;
//		}
//		else
//		{
//			printf("\nNO SE PUDIERON PARSEAR LOS DATOS DE JUGADORES BINARIOS\n");
//		}
//	}
//
//	fclose(pArchivoBinario);
//
//	controller_listarJugadores(pArrayListJugador);
//
//return retorno;
//}


