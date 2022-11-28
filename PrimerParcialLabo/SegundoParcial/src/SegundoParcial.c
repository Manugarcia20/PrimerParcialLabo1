#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "input.h"
#include "Libro.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);

    int option;
    char respuesta;
    int flagGuardar = 0;
    char guardar;
    char nombreArchivo[100];
    char extension[50];



    LinkedList* listaLibros = ll_newLinkedList();



    do{
    option = menuOpciones();
        switch(option)
        {
            case 1:
            	printf("\nUsted eligio: CARGA DE ARCHIVO\n");
            	utn_getChar(nombreArchivo,"\nIngrese el nombre del archivo: ","\nError. Ingrese solo letras: ");
            	utn_getChar(extension,"\nIngrese la extension del archivo: ","\nError. Ingrese solo letras: ");
            	strcat(nombreArchivo,extension);

            	printf("\nEl nombre de archivo es : %s\n",nombreArchivo);

            	if(controller_cargarLibrosDesdeTexto(nombreArchivo,listaLibros) == 1){
            		printf("\nARCHIVO DE LIBROS CARGADO CORRECTAMENTE\n");
            	}else{
            		printf("\nERROR, NO SE PUDO CARGAR EL ARCHIVO DE LIBROS\n");
            	}
                break;
            case 2:
            	printf("\nUsted eligio: IMPRIMIR LIBROS\n");
            	if((ll_isEmpty(listaLibros) == 0)){
            		controller_listarLibros(listaLibros);
            	}
            	break;
            case 3:
            	printf("\nUsted eligio: ORDENAR LIBROS POR IMPORTE DESCENDENTE\n");
            	controller_ordenarLibros(listaLibros);
            	break;
            case 4:
            	printf("\nUsted eligio: GENERAR ARCHIVO DE SALIDA ORDENADO\n");
            	controller_guardarLibrosModoTexto("librosOrdenadosImporte.csv",listaLibros);
                break;
            case 5:
            	printf("\nUsted eligio: INCREMENTAR PRECIOS DE LIBROS\n");

                break;
            case 6:
                printf("\nUsted eligio: GUARDAR LISTA DE LIBROS CON PRECIO INCREMENTADO\n");
                break;
            case 7:
            	printf("\nUsted eligio: SALIR\n");
            	if(flagGuardar == 1){
            	respuesta = getChar("\nEsta seguro de que quiere cerrar el programa? s/n: ");
            		if(respuesta == 's'||respuesta == 's')
            		{
            		printf("\nAdios!!");
            		option = 8;
            		}
            	}else{
            		guardar = getChar("\nATENCION! No se guardaron los cambios en los archivos. Desea salir igualmente? s/n: ");
            		if(guardar == 's' || guardar == 'S'){
            			option = 8;
            		}
            	}
                break;
        }
    }while(option != 8);

    return 0;
}

