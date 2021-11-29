#include "eEditorial.h"

/**
 * @brief constructor, consigue un espacio en memoria para crear un nuevo elemento
 *
 * @return puntero al espacio de memoria del nuevo elemento
 */
eEditorial* editorial_new()
{
	return (eEditorial*) calloc(1, sizeof(eEditorial));
}

/**
 * @brief contruye un dato con los valores que recibe por parametro
 *
 * @param idEditorialStr id que recibe en formato texto
 * @param nombreStr nombre de la editorial
 * @return retorna el puntero cargado si los datos son correctos, NULL si son incorrectos
 */
eEditorial* editorial_newParametros(char *idEditorialStr, char *nombreStr)
{
	eEditorial *aux;
	int idEditorial;
	char nombre[MAXNAME];

	aux = editorial_new();
	if(idEditorialStr != NULL && nombreStr != NULL)
	{
		idEditorial = atoi(idEditorialStr);
		strncpy(nombre, nombreStr, MAXNAME);
		if(editorial_setIdEditorial(aux, idEditorial) || editorial_setNombre(aux, nombre))
		{
			aux = NULL;
		}
	}
	return aux;
}

/**
 * @brief modifica el campo id de la editorial con el que recibe por parametro
 *
 * @param this puntero a editorial que se modifica
 * @param idEditorial dato que agrega al campo de la estructura
 * @return -1 si no pudo, 0 si pudo
 */
int editorial_setIdEditorial(eEditorial *this, int idEditorial)
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
 * @brief modifica el campo id de la editorial por el ingresado por el usuario
 *
 * @param this puntero a editorial que se modifica
 * @return -1 si no pudo, 0 si pudo
 */
int editorial_setIdEditorialXTeclado(eEditorial *this)
{
	int retorno;
	int idEditorial;

	retorno = -1;
	PedirEnteroP(&idEditorial, "Ingrese el ID de la editorial: ", "Error ", 0, 999999999);
	if(this != NULL && idEditorial > 0)
	{
		editorial_setIdEditorial(this, idEditorial);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el valor del campo idEditorial
 *
 * @param this puntero a la editorial
 * @param idEditorial puntero donde se guarda el valor pedido
 * @return -1 si algun parametro es invalido, 0 si pudo realiarlo
 */
int editorial_getIdEditorial(eEditorial *this, int *idEditorial)
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
 * @brief modifica el campo nombre de la editorial que recibe por parametro
 *
 * @param this editorial a modificar
 * @param nombre dato que agrega al campo de editorial
 * @return -1 parametros invalidos, 0 pudo realizarlo
 */
int editorial_setNombre(eEditorial *this, char *nombre)
{
	int retorno;

	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief modifica el campo nombre de la editorial por el que escribe el usuario
 *
 * @param this editorial a modificar
 * @return -1 parametros invalidos, 0 pudo realizarlo
 */
int editorial_setNombreXTeclado(eEditorial *this)
{
	int retorno;
	char nombre[MAXNAME];

	PedirNombre("Ingrese el nombre de la editorial: ", nombre, MAXNAME);
	retorno = -1;
	if(this != NULL)
	{
		editorial_setNombre(this, nombre);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el dato nombre de la estructura editorial
 *
 * @param this editorial que recibe
 * @param nombre puntero donde guarda el valor
 * @return -1 si algun parametro fue invalido, 0 si pudo
 */
int editorial_getNombre(eEditorial *this, char *nombre)
{
	int retorno;

	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief imprime en pantalla una editorial con sus datos
 *
 * @param this editorial a imprimir
 * @return -1 si hubo parametros invalidos, 0 si pude
 */
int editorial_mostrarUno(eEditorial *this)
{
	int retorno;
	int idEditorial;
	char nombre[MAXNAME];

	retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		editorial_getIdEditorial(this, &idEditorial);
		editorial_getNombre(this, nombre);
		printf("|%-13d |%-25s |\n", idEditorial, nombre);
		Renglones(-1, 43, '-');
	}
	return retorno;
}

/**
 * @brief encabezado para mostrar editoriales
 *
 */
void editorial_encabezado()
{
Renglones(-1, 43, '=');
printf("%c %-12s %c %-24s %c\n", '|',"ID Editorial",'|',"Nombre",'|');
Renglones(-1, 43, '=');
}
