#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entidad1.h"
static int ent1_generarProximoId (sEntidad1* nombre_array, int len);
static int ent1_buscarPosicionLibre (sEntidad1* nombre_array, int len);
static int ent1_buscarIndicePorId (sEntidad1* nombre_array, int len, int id);


int ent1_init (sEntidad1* nombre_array, int len)
{
    int i;
    for(i=0; i<len; i++)
    {

    }

}
static int ultimoValorDeIdautoincrementable = 0; //variable global para generar un id nuevo -> puede ir adentro de la misma funcion y mantiene su propiedad de global pero no puede se utilizada por otra funcion

int ent1_generarProximoId (sEntidad1* nombre_array, int len)
{
    ultimoValorDeIdautoincrementable++;
    return ultimoValorDeIdautoincrementable;
}

int ent1_buscarPosicionLibre (sEntidad1* nombre_array, int len)
{
    //me devuelve el index del primer item vacio del array
    //la voy a usar para el ALTA.
    int i;
    for(i=0; i<len; i++)
    {
        if(array[i].flagEstado == STATUS_EMPTY)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscarIndicePorDni (sEntidad1* nombre_array, int len, char dni[])
{
    int i;
    for(i=0; i<len; i++)
    {
        if(array[i].flagEstado == STATUS_LOADED)
        {
            if(strcmp(array[i].valueA, dni) == 0)
            {
                retorno = i;
                break,
            }
        }
    }
    return retorno;
}

int ent1_alta (sEntidad1* nombre_array, int len)
{
    int retorno = -1;
    char bufferAuxNombre[50];
    int indexVacio;
    int idNuevo;

    indexVacio = ent1_buscarPosicionLibre (nombre_array, len);//1. buscar posicion libre

    if(indexVacio >= 0)
    {
        //2. generar ID
        idNuevo = ent1_generarProximoId (nombre_array, len);

        if(val_getNombre(bufferAuxNombre, "ingrese nombre: ", "nombre invalido", 3, 50) == 0)//pido datos al ususrio dependiendo del problema
        {
            array[indexVacio].flagEstado = 1;
            array[indexVacio].id = idNuevo;
            strncpy(array[indexVacio].valueA, bufferAuxNombre, 50);
            retorno = 0;
        }
    }
}

int ent1_buscarIndicePorId (sEntidad1* nombre_array, int len, int id)
{

}

int ent1_modificar()
{
    int retorno = -1;
    //1. buesco la posicion donde esta el ID
    //2. pido datos nuevos
    //3. cargo en los campos
    int index = ent1_buscarIndicePorId(nombre_array, len, id);
    if(index >= 0)
    {
        //pido los datos a modificar.
        char bufferAux[50];
        if(val_getUnsignedInt(bufferAux, "ingrese edad: ", "", 3, 50) == 0)
        {
            array[index].valueB = atoi(bufferAux);
            retorno = 0;
        }
    }
    return retorno;
}

int ent1_baja (sEntidad1* nombre_array, int id)
{
    int index = ent1_buscarIndicePorId(nombre_array, len, id);
    if(index >= 0)
    {
        array[index].flagEstado = 0;

    }

}

