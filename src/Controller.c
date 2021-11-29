#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/// @brief Carga los datos de libros desde el archivo
///
/// @param path
/// @param listaLibros
/// @return -1 si hubo algun error, 1 se pudo abrir el archivo pero no se pudieron parsear los datos, 0 salio ok
int controller_loadLibrosFromText(char *path, LinkedList *listaLibros)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && listaLibros != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			retorno = 1;
			if(!parser_LibrosFromText(pFile, listaLibros))
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/// @brief Carga los datos de libros desde el archivo por columnas
///
/// @param path
/// @param listaLibros
/// @return -1 si hubo algun error, 1 se pudo abrir el archivo pero no se pudieron parsear los datos, 0 salio ok
int controller_loadLibrosFromTextExcel(char *path, LinkedList *listaLibros)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && listaLibros != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			retorno = 1;
			if(!parser_LibrosFromTextExcel(pFile, listaLibros))
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/// @brief Carga los datos de editoriales desde el archivo
///
/// @param path
/// @param listaLibros
/// @return -1 si hubo algun error, 1 se pudo abrir el archivo pero no se pudieron parsear los datos, 0 salio ok
int controller_loadEditorialesFromText(char *path, LinkedList *listaEditoriales)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && listaEditoriales != NULL)
	{
		retorno = 1;
		pFile = fopen(path, "r");
		if(pFile != NULL && !parser_EditorialesFromText(pFile, listaEditoriales))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

//int controller_ListLibros(LinkedList *listaLibros)
//{
//	int retorno;
//	int tam;
//	eLibro *aux;
//
//	retorno = -1;
//	if(listaLibros != NULL)
//	{
//		tam = ll_len(listaLibros);
//		libros_encabezado();
//		retorno = 0;
//		for(int i = 0; i < tam; i++)
//		{
//			aux = ll_get(listaLibros, i);
//			libros_mostrarUno(aux);
//		}
//		//Renglones(-1, 101, '-');
//	}
//	return retorno;
//}

/// @brief hace una lista de los libros con el nombre de la editorial en vez del id de editorial
///
/// @param listaLibros ll de libros
/// @param listaEditoriales ll de editoriales
/// @return -1 si algun parametro es invalido, 0 si salio bien
int controller_ListLibrosConNombreEditorial(LinkedList *listaLibros, LinkedList *listaEditoriales)
{
	int retorno;
	int tam;
	void *aux;

	retorno = -1;
	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		tam = ll_len(listaLibros);
		controller_encabezado();
		retorno = 0;
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(listaLibros, i);
			controller_mostrarUnoConNombreEditorial(aux, listaEditoriales);
		}
	}
	return retorno;
}

/// @brief muestra un libro con el nombre de la editorial en vez de su id
///
/// @param pElement libro que recibe para mostrar
/// @param this lista de editoriales para buscar el id
/// @return -1 si algun parametro es invalido, 0 si pudo realizarlo
int controller_mostrarUnoConNombreEditorial(void *pElement, LinkedList *this)
{
	int retorno;
	eLibro *auxLibro;
	eEditorial *auxEditorial;
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorial;
	char nombre[MAXNAME];

	retorno = -1;
	if(this != NULL && pElement != NULL)
	{
		auxLibro = (eLibro*) pElement;
		libros_getFull(&id, titulo, autor, &precio, &idEditorial, auxLibro);
		auxEditorial = controller_buscarUnoPorId(this, idEditorial);
		if(auxEditorial != NULL)
		{
			retorno = 0;
			editorial_getNombre(auxEditorial, nombre);
			printf("|%-7d |%-40s |%-20s |%-9d |%-20s|\n", id, titulo, autor, precio, nombre);
			Renglones(-1, 106, '-');
		}
	}
	return retorno;
}

/// @brief Menu principal
///
/// @return retorna la opcion elegida
int controller_menuDeOpciones()
{
	int retorno;

	PedirEnteroP(&retorno,
			"\n\t\t\t--------------------------------\n"
					"\t\t\t******* MENU DE OPCIONES *******\n"
					"\t\t\t--------------------------------"
					"\n1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro. "
					"\n2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial "
					"\n3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.  "
					"\n4. Imprimir por pantalla todos los datos de los libros "
					"\n5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la "
					"función ll_filter* del LinkedList. Guardar el listado en un archivo csv. "
					"\n6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map. "
					"\n7. Salir: \nIngrese una opcion:", "error ", 1, 7);

	return retorno;
}

/**
 * @brief encabezado para libros con nombre de editorial
 *
 */
void controller_encabezado()
{
	Renglones(-1, 106, '=');
	printf("%c %-6s %c %-39s %c %-19s %c %-8s %c %-18s %c\n", '|', "ID", '|', "Titulo", '|', "Autor", '|', "Precio", '|', "Editorial", '|');
	Renglones(-1, 106, '=');
}

/**
 * @brief busca y retorna una editorial por su id
 *
 * @param this lista de editoriales
 * @param id id a buscar
 * @return retorna la editorial si pudo encontrarla
 */
eEditorial* controller_buscarUnoPorId(LinkedList *this, int id)
{
	int tam;
	int idEditorial;
	eEditorial *aux;

	if(this != NULL)
	{
		tam = ll_len(this);
		for(int i = 0; i < tam; i++)
		{
			aux = (eEditorial*) ll_get(this, i);
			editorial_getIdEditorial(aux, &idEditorial);
			if(id == idEditorial)
			{
				break;
			}
			else
			{
				aux = NULL;
			}
		}
	}
	return aux;
}

/**
 * @brief guarda los datos de libros en un archivo .csv
 *
 * @param path ruta del archivo
 * @param lista lista a guardar
 * @return -1 si hubo algun parametro invalido, 0 si pudo
 */
int controller_saveAsText(char *path, LinkedList *lista)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && lista != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL && !parser_LibroToText(pFile, lista))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

/**
 * @brief guarda los datos de libros en un archivo .csv en formato columnas
 *
 * @param path ruta del archivo
 * @param lista lista a guardar
 * @return -1 si hubo algun parametro invalido, 0 si pudo
 */
int controller_saveAsTextExcel(char *path, LinkedList *lista)
{
	int retorno;
	FILE *pFile;
	retorno = -1;
	if(path != NULL && lista != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL && !parser_LibroToTextExcel(pFile, lista))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;
}

/**
 * @brief funcion que llama ll_filter que indica si guarda o no el dato en la lista filtrada
 *
 * @param pElement elemento que verifica
 * @return 0 si NO cumple la condicion, 1 si la cumple
 */
int controller_EditMinotauro(void *pElement)
{
	int retorno = 0;
	eLibro *aux;
	int idEdi;

	aux = (eLibro*) pElement;
	libros_getIdEditorial(aux, &idEdi);
	if(idEdi == 4)
	{
		retorno = 1;
	}
	return retorno;
}

//int controller_FiltrarEditoriales(void *pElement, void *pElement2)
//{
//	int retorno = 0;
//	eLibro *aux;
//	int idEdi;
//	eEditorial *auxEdi;
//	LinkedList *listaEdit = ll_newLinkedList();
//
//	aux = (eLibro*) pElement;
//	auxEdi = (eEditorial*) pElement2;
//
//
//	if(idEdi == 4)
//	{
//		retorno = 1;
//	}
//	return retorno;
//}

/**
 * @brief menu de opciones de ordenamientos, crea una lista nueva, la reordena y la borra al imprimirla en pantalla
 *
 * @param lista lista de libros
 * @param listaEditoriales lista de editoriales
 * @return -1 si hubo algun parametro invalido, 0 si pudo
 */
int controller_sortLibros(LinkedList *lista, LinkedList *listaEditoriales)
{
	int retorno;
	int opcion;
	int order;
	LinkedList *aux;

	retorno = -1;
	if(lista != NULL)
	{
		aux = ll_clone(lista);
		retorno = 0;
		PedirEnteroP(&opcion, "1) Ordenar por autor \n2) Ordenar por titulos \n3) Ordenar por precio"
				"\n4) Ordenar por ID de libros \nIngrese una opcion: ", "Error, ingreso invalido \n", 1, 4);
		switch(opcion)
		{
		case 1:
			puts("\t  *************** Ordenar por autor ***************");
			PedirEnteroP(&order, "1) Ordenar de A a Z \n0) Ordenar de Z a A \nIngrese una opcion: ", "Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, libros_compararNombres, order);
			break;
		case 2:
			puts("\t  *************** Ordenar por titulo ***************");
			PedirEnteroP(&order, "1) Ordenar de A a Z \n0) Ordenar de Z a A \nIngrese una opcion: ", "Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, libros_compararTitulos, order);
			break;
		case 3:
			puts("\t  *************** Ordenar por precio ***************");
			PedirEnteroP(&order, "1) Ordenar de forma ascendente \n0) Ordenar de forma descendente \nIngrese una opcion: ",
					"Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, libros_compararPrecio, order);
			break;
		case 4:
			puts("\t  *************** Ordenar por ID ***************");
			PedirEnteroP(&order, "1) Ordenar de forma ascendente \n0) Ordenar de forma descendente \nIngrese una opcion: ",
					"Error, ingreso invalido \n", 0, 1);
			ll_sort(aux, libros_compararId, order);
			break;
		}
		controller_ListLibrosConNombreEditorial(aux, listaEditoriales);
		ll_deleteLinkedList(aux);
	}
	return retorno;
}

int controller_criterioMap(void *pElement)
{
	int retorno = 0;
	eLibro *aux;
	int idEdi;
	int precio;
	int precioConDesc;

	aux = (eLibro*) pElement;
	libros_getIdEditorial(aux, &idEdi);
	libros_getPrecio(aux, &precio);
	if(idEdi == 1 && precio > 299)
	{
		precioConDesc = RealizarDescuentoEnteros(precio, 30);
		libros_setPrecio(aux, precioConDesc);
		retorno = 1;
	}
	if(idEdi == 2 && precio < 201)
	{
		precioConDesc = RealizarDescuentoEnteros(precio, 10);
		libros_setPrecio(aux, precioConDesc);
		retorno = 1;
	}
	return retorno;
}

int controller_mapLibros(char *path, LinkedList *listaLibros, LinkedList *listaEditoriales, LinkedList *listaMap)
{
	int retorno = -1;

	if(path != NULL && listaLibros != NULL && listaEditoriales != NULL && listaMap != NULL)
	{
		retorno = 0;

		listaMap = ll_clone(listaLibros);
		ll_map(listaMap, controller_criterioMap);

//		controller_ListLibrosConNombreEditorial(listaMap, listaEditoriales);
		controller_saveAsText(path, listaMap);
	}
	return retorno;
}
