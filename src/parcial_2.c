/*
 ============================================================================
 Name        : parcial_2.c
 Author      : Juan Poux
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#define ARCHIVOLIBROS "Libros.csv"
#define ARCHIVOEDITORIALES "Editoriales.csv"
#define ARCHIVOMINOTAURO "EditorialMinotauro.csv"
#define ARCHIVOLIBROSEXCEL "LibrosEXCEL.csv"
#define ARCHIVOMAPEADO "mapeado.csv"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList *listaLibros = ll_newLinkedList();
	LinkedList *listaEditoriales = ll_newLinkedList();
	LinkedList *listaMinotauro = ll_newLinkedList();
	LinkedList *listaMap = ll_newLinkedList();
	int salir;
	char archivoLibros[50] = "Libros.csv";
	char archivoEditoriales[50] = "Editoriales.csv";

	do
	{
		switch(controller_menuDeOpciones())
		{
		case 1:
			if(ll_isEmpty(listaLibros) == 1)
			{
//				PedirCadena("Ingrese el nombre del archivo que desea abrir: ", archivoLibros, 50);
				switch(controller_loadLibrosFromText(archivoLibros, listaLibros))
				{
				case -1:
					puts("Parametros invalidos");
					break;
				case 1:
					printf("Error al abrir el archivo \"%s\"\n", archivoLibros);
					break;
				case 0:
					printf("Archivo \"%s\" abierto con exito\n", archivoLibros);
					break;
				}
			}
			else
			{
				puts("Ya hay un archivo cargado!");
			}
//			controller_loadLibrosFromText(ARCHIVOLIBROS, listaLibros);
//			controller_loadLibrosFromTextExcel(ARCHIVOLIBROSEXCEL, listaLibros);
			break;
		case 2:
			if(ll_isEmpty(listaEditoriales) == 1)
			{
//				PedirCadena("Ingrese el nombre del archivo que desea abrir: ", archivoEditoriales, 50);
				switch(controller_loadEditorialesFromText(archivoEditoriales, listaEditoriales))
				{
				case -1:
					puts("Datos invalidos");
					break;
				case 1:
					printf("Error al abrir el archivo \"%s\"\n", archivoEditoriales);
					break;
				case 0:
					printf("Archivo \"%s\" abierto con exito\n", archivoEditoriales);
					break;
				}
			}
			else
			{
				puts("Ya hay un archivo cargado");
			}
			break;
		case 3:
			if(ll_isEmpty(listaLibros) == 1)
			{
				puts("Primero cargue el archivo de libros");
			}
			else
			{
				if(ll_isEmpty(listaEditoriales) == 1)
				{
					puts("Primero cargue el archivo de editoriales");
				}
				else
				{
					if(controller_sortLibros(listaLibros, listaEditoriales))
					{
						puts("Error, parametros invalidos");
					}
				}
			}
			break;
		case 4:
			if(ll_isEmpty(listaLibros) == 1)
			{
				puts("Primero cargue el archivo de libros");
			}
			else
			{
				if(ll_isEmpty(listaEditoriales) == 1)
				{
					puts("Primero cargue el archivo de editoriales");
				}
				else
				{
					if(controller_ListLibrosConNombreEditorial(listaLibros, listaEditoriales))
					{
						puts("Error, parametros invalidos");
					}
				}
			}
			break;
		case 5:
			if(ll_isEmpty(listaLibros) == 1)
			{
				puts("Primero cargue el archivo de libros!");
			}
			else
			{
				if(ll_isEmpty(listaEditoriales) == 1)
				{
					puts("Primero cargue el archivo de editoriales");
				}
				else
				{
					listaMinotauro = ll_filter(listaLibros, controller_EditMinotauro);
					controller_ListLibrosConNombreEditorial(listaMinotauro, listaEditoriales);
					controller_saveAsText(ARCHIVOMINOTAURO, listaMinotauro);
				}
			}
			break;
		case 6:
//			controller_mapLibros(ARCHIVOMAPEADO, listaLibros, listaEditoriales, listaMap);
			listaMap = ll_map2(listaLibros, controller_criterioMap);
			controller_ListLibrosConNombreEditorial(listaMap, listaEditoriales);
			controller_saveAsText(ARCHIVOMAPEADO, listaMap);
			break;
		case 7:
//			controller_saveAsText(ARCHIVOLIBROS, listaLibros);
//			controller_saveAsTextExcel(ARCHIVOLIBROSEXCEL, listaLibros);
			ll_deleteLinkedList(listaLibros);
			ll_deleteLinkedList(listaEditoriales);
			ll_deleteLinkedList(listaMinotauro);
			ll_deleteLinkedList(listaMap);
			PedirEnteroP(&salir, "\n1) Salir \n2) Cancelar \nIngrese una opcion: ", "Error, ingreso invalido\n ", 1, 2);
			break;
		}
	} while(salir != 1);

	return EXIT_SUCCESS;
}
