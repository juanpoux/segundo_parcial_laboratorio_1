#ifndef EEDITORIAL_H_
#define EEDITORIAL_H_
#define MAXNAME 100
#include "Input.h"

typedef struct
{
	int idEditorial;
	char nombre[MAXNAME];
}eEditorial;

eEditorial* editorial_new();
eEditorial* editorial_newParametros(char *idEditorialStr, char *nombreStr);
int editorial_setIdEditorial(eEditorial *this, int idEditorial);
int editorial_setIdEditorialXTeclado(eEditorial *this);
int editorial_getIdEditorial(eEditorial *this, int *idEditorial);
int editorial_setNombre(eEditorial *this, char *nombre);
int editorial_setNombreXTeclado(eEditorial *this);
int editorial_getNombre(eEditorial *this, char *nombre);
int editorial_mostrarUno(eEditorial *this);
void editorial_encabezado();


#endif /* EEDITORIAL_H_ */
