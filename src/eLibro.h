#ifndef ELIBRO_H_
#define ELIBRO_H_
#define MAXNAME 100
#include "Input.h"
typedef struct
{
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorial;
}eLibro;

eLibro* libros_new();
eLibro* libros_newParametros(char *idStr, char *tituloStr, char *autorStr, char *precioStr, char *idEditorialStr);

int libros_setAutor(eLibro *this, char *autor);
int libros_setAutorXTeclado(eLibro *this);
int libros_getAutor(eLibro *this, char *autor);
int libros_setTitulo(eLibro *this, char *titulo);
int libros_setTituloXTeclado(eLibro *this);
int libros_getTitulo(eLibro *this, char *titulo);
int libros_setId(eLibro *this, int id);
int libros_setIdXTeclado(eLibro *this);
int libros_getId(eLibro *this, int *id);
int libros_setPrecio(eLibro *this, int precio);
int libros_setPrecioXTeclado(eLibro *this);
int libros_getPrecio(eLibro *this, int *precio);
int libros_setIdEditorial(eLibro *this, int idEditorial);
int libros_setIdEditorialXTeclado(eLibro *this);
int libros_getIdEditorial(eLibro *this, int *idEditorial);
int libros_mostrarUno(eLibro *this);
void libros_encabezado();
int libros_getFull(int *id, char *titulo, char *autor, int *precio, int *idEditorial, eLibro *this);
int libros_compararNombres(void *libroUno, void *libroDos);
int libros_compararTitulos(void *libroUno, void *libroDos);
int libros_compararPrecio(void *libroUno, void *libroDos);
int libros_compararId(void *libroUno, void *libroDos);

#endif /* ELIBRO_H_ */
