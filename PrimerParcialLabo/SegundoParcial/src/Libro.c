
#include "input.h"
#include "Controller.h"
#include "Libro.h"




/// CONSTRUCTORES

eLibro* libro_new(){

	eLibro* pLibro;

	pLibro = (eLibro*) malloc(sizeof(eLibro));

	return pLibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr){

	eLibro* pLibro;

	pLibro = libro_new();

	if(pLibro != NULL){

		if(idStr != NULL && tituloStr != NULL && importeStr != NULL && idTipoStr != NULL){

			libro_setId(pLibro, atoi(idStr));
			libro_setTitulo(pLibro,tituloStr);
			libro_setImporte(pLibro,atof(importeStr));
			libro_setIdTipo(pLibro,atoi(idTipoStr));
		}
	}

	return pLibro;
}


void libro_delete(eLibro* this){

	if(this != NULL){
		free(this);
	}
}

/// SETTERS


int libro_setId(eLibro* this,int id){
	int retorno = -1;

		if(this != NULL && id > 0){

			this->id = id;
			retorno = 0;
		}
		return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo){

	int retorno = -1;

		if(this != NULL && titulo != NULL){
			strcpy(this->titulo,titulo);
			retorno = 0;
		}
		return retorno;
}

int libro_setImporte(eLibro* this,float importe){
	int retorno = -1;

		if(this != NULL && importe > 0){

			this->importe = importe; //
			retorno = 0;
		}
		return retorno;
}
int libro_setIdTipo(eLibro* this,int idTipo){
	int retorno = -1;

			if(this != NULL && idTipo >= 0){

				this->idTipo = idTipo;
				retorno = 0;
			}
			return retorno;
}

/// GETTERS


int libro_getId(eLibro* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int libro_getTitulo(eLibro* this,char* titulo){
	int retorno = -1;

	if(this != NULL && titulo != NULL){
		strcpy(titulo,this->titulo);
		retorno = 0;
		}

	return retorno;
}


int libro_getImporte(eLibro* this,float* importe){
	int retorno = -1;

		if(this != NULL && importe != NULL){

		*importe = this->importe;
		retorno = 0;
		}
		return retorno;
}

int libro_getIdTipo(eLibro* this,int* idTipo){
	int retorno = -1;

		if(this != NULL && idTipo != NULL){

		*idTipo = this->idTipo;
		retorno = 0;
		}
		return retorno;
}



int ordenarLibrosPorImporte(void* libro1,void* libro2){

	int retorno = 0;

	float importe1;
	float importe2;

	eLibro* pLibro1 = NULL;
	eLibro* pLibro2 = NULL;


	pLibro1 = (eLibro*)libro1;
	pLibro2 = (eLibro*)libro2;

	libro_getImporte(pLibro1,&importe1);
	libro_getImporte(pLibro2,&importe2);

		if(importe1 > importe2){
			retorno = 1;
		}
		else{
			if(importe1 < importe2){
			retorno = -1;
			}
		}

		return retorno;
}


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	char id[100];
	char titulo[100];
	char importe[100];
	char idTipo[100];


	int retorno = -1;
	int retornoFscanf;


	eLibro* pLibro;

			if(pArrayListLibro != NULL && pFile != NULL)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,importe,idTipo); //lectura fantasma

				while(feof(pFile) == 0 ){
					retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,importe,idTipo);
					printf("retorno f scanf: %d",retornoFscanf);

					if(retornoFscanf == 4){

	//					printf("%s\n",id);
						pLibro = libro_newParametros(id,titulo,importe,idTipo);

						//printf("\n%s   %s   %s   %s   %s   %s ",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion );
						ll_add(pArrayListLibro,pLibro);
					}


				}

			retorno = 1;
			}else
			{
				printf("\nLa memoria esta llena");

			}

		    return retorno;
}






















//
//int ordenarJugadoresPorNombre(void* jugador1,void* jugador2){
//	int retorno = 0;
//
//	char nombre1[50];
//	char nombre2[50];
//
//	Jugador* pJugador1 = NULL;
//	Jugador* pJugador2 = NULL;
//
//
//	pJugador1 = (Jugador*)jugador1;
//	pJugador2 = (Jugador*)jugador2;
//
//	jug_getNombreCompleto(pJugador1,nombre1);
//	jug_getNombreCompleto(pJugador2,nombre2);
//
//	if(strcmp(nombre1,nombre2) > 0 ){
//			retorno = 1; /// 1 es ascendente (1-10)(A-Z)
//	}
//	else{
//		if(strcmp(nombre1,nombre2) < 0){
//			retorno = -1;   /// 1 es descendente (10-1)(Z-A)
//		}
//	}
//
//	return retorno;
//}
//
//
//int jug_compararPorPosicionYEdad(void* a, void* b)
//{
//	int retorno = 0;
//	char posicion1[32];
//	char posicion2[32];
//	int edad1;
//	int edad2;
//
//	Jugador* jugador1;
//	Jugador* jugador2;
//
//	if(a != NULL && b != NULL)
//	{
//		/// casteo a jugador
//		jugador1 = (Jugador*) a;
//		jugador2 = (Jugador*) b;
//
//		/// obtengo posicion
//		jug_getPosicion(jugador1, posicion1);
//		jug_getPosicion(jugador2, posicion2);
//
//		/// obtengo nacionalidad
//		jug_getEdad(jugador1, &edad1);
//		jug_getEdad(jugador2, &edad2);
//
//		/// comparacion de strings
//		retorno = strcmp(posicion1, posicion2);
//
//		if(retorno > 0)
//		{
//			retorno = 1;
//		}
//		else if(retorno < 0)
//		{
//			retorno = -1;
//		}
//		else /// si son iguales
//        {
//            if(edad1 > edad2)
//            {
//                retorno = 1;
//            }
//            else if(edad1 < edad2)
//            {
//                retorno = -1;
//            }
//        }
//	}
//    return retorno;
//}
//
//
//
//int filtrarPorEdad(void*cantidad){
//	int retorno = 0;
//	int edad;
//
//	Jugador* jugador = NULL;
//
//	if(cantidad!=NULL){
//		jugador = (Jugador*)cantidad;
//		jug_getEdad(jugador,&edad);
//		if(edad<5000){
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}
//
//int filtrarPorNacionalidad(void*cantidad){
//	int retorno = 0;
//	char nacionalidad[50];
//
//	Jugador* jugador = NULL;
//
//	if(cantidad!=NULL){
//
//		jugador = (Jugador*)cantidad;
//		jug_getNacionalidad(jugador,nacionalidad);
//		if(strcmp(nacionalidad,"argentino") == 0){
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}

//int mapear(void*cantidad){
//
//
//
//
//
//	int retorno;
//
//	return retorno;
//}






