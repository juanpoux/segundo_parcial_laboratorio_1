/*
 * parser.h
 *
 *  Created on: 1 nov. 2021
 *      Author: Negocio
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Input.h"
#include "eLibro.h"
#include "eEditorial.h"
#include <string.h>
#include <ctype.h>

int parser_LibrosFromText(FILE *pFile, LinkedList *listaLibros);
int parser_EditorialesFromText(FILE *pFile, LinkedList *listaEditoriales);
int parser_LibroToText(FILE *pFile, LinkedList *lista);
int parser_LibroToTextExcel(FILE *pFile, LinkedList *lista);
int parser_LibrosFromTextExcel(FILE *pFile, LinkedList *listaLibros);

#endif /* PARSER_H_ */
