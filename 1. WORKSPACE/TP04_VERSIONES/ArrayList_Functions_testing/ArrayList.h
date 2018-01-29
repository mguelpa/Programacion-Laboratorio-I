/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

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

#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList{

    void** pElements;
    int reservedSize;
    int size;

    struct ArrayList* (*clone)();
    struct ArrayList* (*subList)();
    int    (*deleteArrayList)();

    int     (*add)();
    int     (*push)();
    int     (*set)();

    int     (*isEmpty)();
    int     (*contains)();
    int     (*containsAll)();
    int     (*len)();

    int     (*remove)();
    int     (*clear)();

    int     (*indexOf)();
    void*   (*get)();
    void*   (*pop)();

    int     (*sort)();

}typedef ArrayList;
#endif

ArrayList* al_newArrayList (void);                          //-> Crea un nuevo ArrayList y retorna su direccion.
ArrayList* al_clone    (ArrayList* this);                   //-> Crea un nuevo ArrayList copia del ArrayList original.
ArrayList* al_subList  (ArrayList* this, int from, int to); //-> Crea un nuevo ArrayList con el subconjunto especificado.
int al_deleteArrayList (ArrayList* this);                   //-> Elimina el ArrayList.

int al_add  (ArrayList* this, void* pElement);              //-> Inserta un elemento al final del ArrayList.
int al_push (ArrayList* this, int index, void* pElement);   //-> Inserta un elemento en el índice pasado y desplaza el resto.
int al_set  (ArrayList* this, int index, void* pElement);   //-> Inserta un elemento en el índice especificado.

int al_remove (ArrayList* this, int index);                 //-> Elimina el elemento del índice especificado.
int al_clear  (ArrayList* this);                            //-> Elimina todos los elementos de ArrayList.

int al_indexOf (ArrayList* this, void* pElement);           //-> Retorna el índice del primer elemento encontrado.
void* al_get   (ArrayList* this, int index);                //-> Retorna la direccion del elemento del índice especificado.
void* al_pop   (ArrayList* this, int index);                //-> Retorna la direccion del elemento y luego lo quita de la lista.

int al_isEmpty     (ArrayList* this);                       //-> Comprueba la existencia de alemenos un elemento.
int al_contains    (ArrayList* this, void* pElement);       //-> Comprueba la existencia del elemento.
int al_containsAll (ArrayList* this, ArrayList* pList2);    //-> Comprueba si todos los elementos de lista2 existen en lista1.
int al_len (ArrayList* this);                               //-> Retorna el tamaño del ArrayList.

int al_sort(ArrayList* this, int (*pFunc)(void*, void*), int order); //-> Ordena los elementos recibiendo la funcion.

// Private function
int resizeUp (ArrayList* this);                           //-> Incrementa los valores del ArrayList.
int resizeDown (ArrayList* this);                         //-> Decrementa los valores del ArrayList.
int expand (ArrayList* this, int index);                  //-> Expande el array de punteros.
int contract (ArrayList* this, int index);                //-> Contrae el array de puntero.
//_________________________________________

void al_debugShow(ArrayList* this);
