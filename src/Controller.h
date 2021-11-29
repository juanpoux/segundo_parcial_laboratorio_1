#include "LinkedList.h"
#include "eLibro.h"
#include "eEditorial.h"
#include "Input.h"
#include "parser.h"

#define ARCHIVOPRINCIPAL "data.csv"
#define ARCHIVOBINARIO "data.bin"

int controller_loadLibrosFromText(char *path, LinkedList *listaLibros);
int controller_loadEditorialesFromText(char *path, LinkedList *listaEditoriales);
int controller_ListLibros(LinkedList *listaLibros);
int controller_ListLibrosConNombreEditorial(LinkedList *listaLibros, LinkedList *listaEditoriales);
int controller_menuDeOpciones();
int controller_mostrarUnoConNombreEditorial(void *pElement, LinkedList *this);
eEditorial* controller_buscarUnoPorId(LinkedList *this, int id);
void controller_encabezado();
int controller_saveAsText(char *path, LinkedList *lista);
int controller_EditMinotauro(void *pElement);
int controller_sortLibros(LinkedList *lista, LinkedList *listaEditoriales);
int controller_loadLibrosFromTextExcel(char *path, LinkedList *listaLibros);
int controller_saveAsTextExcel(char *path, LinkedList *lista);
int controller_criterioMap(void *pElement);
int controller_mapLibros(char *path, LinkedList *listaLibros, LinkedList *listaEditoriales, LinkedList *listaMap);
int controller_mapLibros2(char *path, LinkedList *listaLibros, LinkedList *listaEditoriales, LinkedList *listaMap);
