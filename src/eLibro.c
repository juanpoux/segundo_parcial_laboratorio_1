#include "eLibro.h"

/**
 * @brief constructor, consigue un espacio en memoria para crear un nuevo elemento
 *
 * @return puntero al espacio de memoria del nuevo elemento
 */
eLibro* libros_new()
{
	return (eLibro*) calloc(1, sizeof(eLibro));
}

/**
 * @brief contruye un dato con los valores que recibe por parametro
 *
 * @param idStr id que recibe en formato texto
 * @param tituloStr titulo del libro
 * @param autorStr autor del libro
 * @param precioStr precio que recibe en formato texto
 * @param idEditorialStr id de editorial que recibe en formato
 * @return retorna el puntero cargado si los datos son correctos, NULL si son incorrectos
 */
eLibro* libros_newParametros(char *idStr, char *tituloStr, char *autorStr, char *precioStr, char *idEditorialStr)
{
	eLibro *aux;
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorialEditorial;

	aux = libros_new();
	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		id = atoi(idStr);
		strncpy(titulo, tituloStr, MAXNAME);
		strncpy(autor, autorStr, MAXNAME);
		precio = atoi(precioStr);
		idEditorialEditorial = atoi(idEditorialStr);
		if(libros_setId(aux, id) || libros_setTitulo(aux, titulo) || libros_setAutor(aux, autor) || libros_setPrecio(aux, precio)
				|| libros_setIdEditorial(aux, idEditorialEditorial))
		{
			aux = NULL;
		}
	}
	return aux;
}

/**
 * @brief modifica el campo autor del libro con el que recibe por parametro
 *
 * @param this estructura libro
 * @param autor valor a agregar en el campo de la estructura
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setAutor(eLibro *this, char *autor)
{
	int retorno;

	retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strncpy(this->autor, autor, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/***
 * @brief modifica el campo autor del libro con el que escribe el usuario
 *
 * @param this  estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setAutorXTeclado(eLibro *this)
{
	int retorno;
	char autor[MAXNAME];

	PedirNombre("Ingrese el autor del libro: ", autor, MAXNAME);
	retorno = -1;
	if(this != NULL)
	{
		libros_setAutor(this, autor);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el dato del campo autor de un libro
 *
 * @param this estructura libro
 * @param autor puntero donde guarda el valor
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getAutor(eLibro *this, char *autor)
{
	int retorno;

	retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strncpy(autor, this->autor, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo titulo del libro con el que recibe por parametro
 *
 * @param this estructura libro
 * @param titulo valor a agregar en el campo de la estructura
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setTitulo(eLibro *this, char *titulo)
{
	int retorno;

	retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		strncpy(this->titulo, titulo, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo titulo del libro con el que ingresa el usuario
 *
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setTituloXTeclado(eLibro *this)
{
	int retorno;
	char titulo[MAXNAME];

	PedirNombre("Ingrese el titulo del libro: ", titulo, MAXNAME);
	retorno = -1;
	if(this != NULL)
	{
		libros_setTitulo(this, titulo);
		retorno = 0;
	}
	return retorno;
}

/***
 * @brief obtiene el dato del campo titulo de un libro
 *
 * @param this estructura libro
 * @param titulo puntero donde guarda el valor
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getTitulo(eLibro *this, char *titulo)
{
	int retorno;

	retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		strncpy(titulo, this->titulo, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo id del libro con el que recibe por parametro
 *
 * @param this estructura libro
 * @param id valor a agregar en el campo de la estructura
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setId(eLibro *this, int id)
{
	int retorno;

	retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo id del libro con el que ingresa el usuiario
 *
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setIdXTeclado(eLibro *this)
{
	int retorno;
	int id;

	retorno = -1;
	PedirEnteroP(&id, "Ingrese el ID del libro: ", "Error ", 0, 999999999);
	if(this != NULL && id > 0)
	{
		libros_setId(this, id);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el dato del campo id de un libro
 *
 * @param this estructura libro
 * @param id puntero donde guarda el valor
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getId(eLibro *this, int *id)
{
	int retorno;

	retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo precio del libro con el que recibe por parametro
 *
 * @param this estructura libro
 * @param precio valor a agregar en el campo de la estructura
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setPrecio(eLibro *this, int precio)
{
	int retorno;

	retorno = -1;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo precio del libro con el que ingresa el usuario
 *
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setPrecioXTeclado(eLibro *this)
{
	int retorno;
	int precio;

	retorno = -1;
	PedirEnteroP(&precio, "Ingrese el precio del libro: ", "Error ", 0, 999999999);
	if(this != NULL && precio > 0)
	{
		libros_setPrecio(this, precio);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el dato del campo precio de un libro
 *
 * @param this estructura libro
 * @param precio puntero donde guarda el valor
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getPrecio(eLibro *this, int *precio)
{
	int retorno;

	retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo idEditorial del libro con el que recibe por parametro
 *
 * @param this estructura libro
 * @param idEditorial valor a agregar en el campo de la estructura
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setIdEditorial(eLibro *this, int idEditorial)
{
	int retorno;

	retorno = -1;
	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo idEditorial del libro con el que ingresa el usuario
 *
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_setIdEditorialXTeclado(eLibro *this)
{
	int retorno;
	int idEditorial;

	retorno = -1;
	PedirEnteroP(&idEditorial, "Ingrese el ID de la editorial: ", "Error ", 0, 999999999);
	if(this != NULL && idEditorial > 0)
	{
		libros_setIdEditorial(this, idEditorial);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el dato del campo idEditorial de un libro
 *
 * @param this estructura libro
 * @param idEditorial puntero donde guarda el valor
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getIdEditorial(eLibro *this, int *idEditorial)
{
	int retorno;

	retorno = -1;
	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief imprime en pantalla los valores de los campos de un libro
 *
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_mostrarUno(eLibro *this)
{
	int retorno;
	int id;
	char titulo[MAXNAME];
	char autor[MAXNAME];
	int precio;
	int idEditorial;

	retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		libros_getId(this, &id);
		libros_getTitulo(this, titulo);
		libros_getAutor(this, autor);
		libros_getPrecio(this, &precio);
		libros_getIdEditorial(this, &idEditorial);
		printf("|%-7d |%-40s |%-20s |%-9d |%-15d|\n", id, titulo, autor, precio, idEditorial);
		Renglones(-1, 101, '-');
	}
	return retorno;
}

/**
 * @brief encabezado para mostrar los datos de un libro
 *
 */
void libros_encabezado()
{
	Renglones(-1, 101, '=');
	printf("%c %-6s %c %-39s %c %-19s %c %-8s %c %-13s %c\n", '|', "id", '|', "titulo", '|', "autor", '|', "precio", '|', "id editorial", '|');
	Renglones(-1, 101, '=');
}

/**
 * @brief obtiene los datos de todos los campos de un libro
 *
 * @param id puntero donde guarda el valor
 * @param titulo puntero donde guarda el valor
 * @param autor puntero donde guarda el valor
 * @param precio puntero donde guarda el valor
 * @param idEditorial puntero donde guarda el valor
 * @param this estructura libro
 * @return -1 si algun parametro es incorrecto, 0 si pudo realizarlo
 */
int libros_getFull(int *id, char *titulo, char *autor, int *precio, int *idEditorial, eLibro *this)
{
	int retorno = -1;

	if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL && this != NULL)
	{
		retorno = 0;
		libros_getId(this, id);
		libros_getTitulo(this, titulo);
		libros_getAutor(this, autor);
		libros_getPrecio(this, precio);
		libros_getIdEditorial(this, idEditorial);
	}
	return retorno;
}

/**
 * @brief compara 2 campos de un libro, funcion criterio para la funcion ll_sort
 *
 * @param libroUno
 * @param libroDos
 * @return retorna 0 si son iguales, 1 si el primero es mayor, -1 si el segundo es mayor
 */
int libros_compararNombres(void *libroUno, void *libroDos)
{
	int retorno;
	eLibro *auxUno;
	eLibro *auxDos;
	char nombreUno[MAXNAME];
	char nombreDos[MAXNAME];

	if(libroUno != NULL && libroDos != NULL)
	{
		auxUno = (eLibro*) libroUno;
		auxDos = (eLibro*) libroDos;
		libros_getAutor(auxUno, nombreUno);
		libros_getAutor(auxDos, nombreDos);
		retorno = stricmp(nombreUno, nombreDos);
	}
	return retorno;
}

/**
 * @brief compara 2 campos de un libro, funcion criterio para la funcion ll_sort
 *
 * @param libroUno
 * @param libroDos
 * @return 0 si son iguales, 1 si el primero es mayor, -1 si el segundo es mayor
 */
int libros_compararTitulos(void *libroUno, void *libroDos)
{
	int retorno;
	eLibro *auxUno;
	eLibro *auxDos;
	char nombreUno[MAXNAME];
	char nombreDos[MAXNAME];

	if(libroUno != NULL && libroDos != NULL)
	{
		auxUno = (eLibro*) libroUno;
		auxDos = (eLibro*) libroDos;
		libros_getTitulo(auxUno, nombreUno);
		libros_getTitulo(auxDos, nombreDos);
		retorno = stricmp(nombreUno, nombreDos);
	}
	return retorno;
}

int libros_compararPrecio(void *libroUno, void *libroDos)
{
	int retorno;
	eLibro *auxUno;
	eLibro *auxDos;
	int precioUno;
	int precioDos;

	if(libroUno != NULL && libroDos != NULL)
	{
		retorno = 0;
		auxUno = (eLibro*) libroUno;
		auxDos = (eLibro*) libroDos;
		libros_getId(auxUno, &precioUno);
		libros_getId(auxDos, &precioDos);
		if(precioUno > precioDos)
		{
			retorno = 1;
		}
		else
		{
			if(precioUno < precioDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int libros_compararId(void *libroUno, void *libroDos)
{
	int retorno;
	eLibro *auxUno;
	eLibro *auxDos;
	int idUno;
	int idDos;

	if(libroUno != NULL && libroDos != NULL)
	{
		retorno = 0;
		auxUno = (eLibro*) libroUno;
		auxDos = (eLibro*) libroDos;
		libros_getId(auxUno, &idUno);
		libros_getId(auxDos, &idDos);
		if(idUno > idDos)
		{
			retorno = 1;
		}
		else
		{
			if(idUno < idDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
