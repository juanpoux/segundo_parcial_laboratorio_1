/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void); //crea uno nuevo (empleado)
int ll_len(LinkedList* this); //devuelve la cantidad de elementos que hay en la lista (tam)
Node* test_getNode(LinkedList* this, int nodeIndex); // no se usa
int test_addNode(LinkedList* this, int nodeIndex,void* pElement); // no se usa
int ll_add(LinkedList* this, void* pElement); //arega uno dentro de la lista
void* ll_get(LinkedList* this, int index); //obtiene uno por index
int ll_set(LinkedList* this, int index,void* pElement); //modifica uno
int ll_remove(LinkedList* this,int index); //elimina uno
int ll_clear(LinkedList* this); //vacia la lista entera, pero no elimina el array
int ll_deleteLinkedList(LinkedList* this); //elimina el array completamente
int ll_indexOf(LinkedList* this, void* pElement); //devuelve la posicion del elemento en el momento que lo pide
int ll_isEmpty(LinkedList* this); //hay por lo menos uno cargado
int ll_push(LinkedList* this, int index, void* pElement); //pone uno en el medio de 2 posiciones
void* ll_pop(LinkedList* this,int index); //elimina y por retorno devuelve los datos del eliminado
int ll_contains(LinkedList* this, void* pElement); //dice si el elemento que le estas pasadno esta dentro del array
int ll_containsAll(LinkedList* this,LinkedList* this2); //si todo lo que estas pasando esta dentro de la lista
LinkedList* ll_subList(LinkedList* this,int from,int to); //crea una sublista desde donde digas hasta donde digas
LinkedList* ll_clone(LinkedList* this); //hace una copia de la lista entera
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //ordenamiento por puntero a funcion con el criterio que arme en la funcion
LinkedList* ll_filter(LinkedList *this, int (*fn)(void *element));
int ll_map(LinkedList *this, int (*fn)(void *element));
LinkedList* ll_map2(LinkedList *this, int (*fn)(void *element));
