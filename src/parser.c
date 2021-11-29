#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/**
 * @brief parsea los datos de los libros desde el archivo .csv
 *
 * @param pFile archivo
 * @param listaLibros linkedlist donde se guardan los datos
 * @return -1 si algun parametro es invalido, 0 si pudo realizarlo
 */
int parser_LibrosFromText(FILE *pFile, LinkedList *listaLibros)
{
	int retorno;
	char id[MAXNAME];
	char titulo[MAXNAME];
	char autor[MAXNAME];
	char precio[MAXNAME];
	char idEditorial[MAXNAME];
	eLibro *aux;
	int cantidad;

	retorno = -1;
	if(pFile != NULL && listaLibros != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
			if(cantidad == 5)
			{
				aux = libros_newParametros(id, titulo, autor, precio, idEditorial);
				if(aux != NULL)
				{
					ll_add(listaLibros, aux);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

//int parser_LibrosFromText(FILE *pFile, LinkedList *listaLibros)
//{
//	int retorno;
//	char id[MAXNAME];
//	char titulo[MAXNAME];
//	char autor[MAXNAME];
//	char precio[MAXNAME];
//	char idEditorial[MAXNAME];
//	eLibro *aux;
//	int cantidad;
//	char idCmp[MAXNAME] = "id";
//	char tituloCmp[MAXNAME] = "titulo";
//	char autorCmp[MAXNAME] = "autor";
//	char precioCmp[MAXNAME] = "precio";
//	char idEditorialCmp[MAXNAME] = "idEditorial";
//
//	retorno = -1;
//	if(pFile != NULL && listaLibros != NULL)
//	{
//		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
//		if(!stricmp(idCmp, id) && !stricmp(tituloCmp, titulo) && !stricmp(autorCmp, autor) && !stricmp(precioCmp, precio)
//				&& !stricmp(idEditorialCmp, idEditorial))
//		{
//			while(!feof(pFile))
//			{
//				cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
//				if(cantidad == 5)
//				{
//					aux = libros_newParametros(id, titulo, autor, precio, idEditorial);
//					if(aux != NULL)
//					{
//						ll_add(listaLibros, aux);
//						retorno = 0;
//					}
//				}
//			}
//		}
//	}
//	return retorno;
//}

/**
 * @brief parsea los datos de las editoriales desde el archivo .csv
 *
 * @param pFile archivo
 * @param listaLibros linkedlist donde se guardan los datos
 * @return -1 si algun parametro es invalido, 0 si pudo realizarlo
 */
int parser_EditorialesFromText(FILE *pFile, LinkedList *listaEditoriales)
{
	int retorno;
	char idEditorial[MAXNAME];
	char nombre[MAXNAME];
	eEditorial *aux;
	int cantidad;

	retorno = -1;
	if(pFile != NULL && listaEditoriales != NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);
			if(cantidad == 2)
			{
				aux = editorial_newParametros(idEditorial, nombre);
				if(aux != NULL)
				{
					ll_add(listaEditoriales, aux);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

//int parser_EditorialesFromText(FILE *pFile, LinkedList *listaEditoriales)
//{
//	int retorno;
//	char idEditorial[MAXNAME];
//	char nombre[MAXNAME];
//	eEditorial *aux;
//	int cantidad;
//	char idEdCmp[MAXNAME] = "idEditorial";
//	char nombreCmp[MAXNAME] = "nombre";
//
//	retorno = -1;
//	if(pFile != NULL && listaEditoriales != NULL)
//	{
//		fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);
//
//		if(!stricmp(idEdCmp, idEditorial) && !stricmp(nombreCmp, nombre))
//		{
//			while(!feof(pFile))
//			{
//				cantidad = fscanf(pFile, "%[^,],%[^\n]\n", idEditorial, nombre);
//				if(cantidad == 2)
//				{
//					aux = editorial_newParametros(idEditorial, nombre);
//					if(aux != NULL)
//					{
//						ll_add(listaEditoriales, aux);
//						editorial_mostrarUno(aux);
//						retorno = 0;
//					}
//				}
//			}
//		}
//	}
//	return retorno;
//}

/**
 * @brief parsea los datos de los libros desde el archivo .csv separados por columnas
 *
 * @param pFile archivo
 * @param listaLibros linkedlist donde se guardan los datos
 * @return -1 si algun parametro es invalido, 0 si pudo realizarlo
 */
int parser_LibrosFromTextExcel(FILE *pFile, LinkedList *listaLibros)
{
	int retorno;
	char id[MAXNAME];
	char titulo[MAXNAME];
	char autor[MAXNAME];
	char precio[MAXNAME];
	char idEditorial[MAXNAME];
	eLibro *aux;
	int cantidad;

	retorno = -1;
	if(pFile != NULL && listaLibros != NULL)
	{
		libros_encabezado();
		fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor, precio, idEditorial);
		while(!feof(pFile))
		{
			cantidad = fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", id, titulo, autor, precio, idEditorial);
			if(5 == cantidad)
			{
				aux = libros_newParametros(id, titulo, autor, precio, idEditorial);
				if(aux != NULL)
				{
					ll_add(listaLibros, aux);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/**
 * @brief Parsea los datos de los libros desde la lista para guardar en el archivo .csv
 *
 * @param pFile archivo
 * @param listaLibros linkedlist de donde se sacan los datos
 * @return -1 si algun parametro es invalido, 0 si pudo realizarlo
 */
int parser_LibroToText(FILE *pFile, LinkedList *lista)
{
	int retorno;
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorial;
	eLibro *aux;
	int tam;

	tam = ll_len(lista);
	retorno = -1;
	if(pFile != NULL && lista != NULL)
	{
		retorno = 0;
		fprintf(pFile, "%s\n", "id,titulo,autor,precio,idEditorial");
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(lista, i);
			libros_getFull(&id, titulo, autor, &precio, &idEditorial, aux);
			fprintf(pFile, "%d,%s,%s,%d,%d\n", id, titulo, autor, precio, idEditorial);
		}
	}
	return retorno;
}

/**
 * @brief Parsea los datos de los libros desde la lista para guardar en el archivo .csv separado por columnas
 *
 * @param pFile archivo
 * @param listaLibros linkedlist de donde se sacan los datos
 * @return -1 si algun parametro es invalido, 0 si pudo realizarlo
 */
int parser_LibroToTextExcel(FILE *pFile, LinkedList *lista)
{
	int retorno;
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorial;
	eLibro *aux;
	int tam;

	tam = ll_len(lista);
	retorno = -1;
	if(pFile != NULL && lista != NULL)
	{
		retorno = 0;
		fprintf(pFile, "%s\n", "id;titulo;autor;precio;idEditorial");
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(lista, i);
			libros_getFull(&id, titulo, autor, &precio, &idEditorial, aux);
			fprintf(pFile, "%d;%s;%s;%d;%d\n", id, titulo, autor, precio, idEditorial);
		}
	}
	return retorno;
}
