#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"


Socio* soc_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Socio* nuevoSocio = malloc(sizeof(Socio));
    soc_setNombre(nuevoSocio,nombre);
    soc_setApellido(nuevoSocio,apellido);
    soc_setDni(nuevoSocio,dni);
    soc_setId(nuevoSocio,id);
    soc_setEstado(nuevoSocio,estado);

    return nuevoSocio;
}


int soc_delete(Socio* this)
{
    free(this);
    return 0;
}


int soc_setNombre(Socio* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}


char* soc_getNombre(Socio* this)
{
    return this->nombre;
}


int soc_setApellido(Socio* this,char* apellido)
{
    strcpy(this->apellido,apellido);
    return 0;
}


char* soc_getApellido(Socio* this)
{
    return this->apellido;
}


int soc_setDni(Socio* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}


char* soc_getDni(Socio* this)
{
    return this->dni;
}


int soc_setId(Socio* this,int id)
{

    this->id = id;
    return 0;
}

int soc_getId(Socio* this)
{
    return this->id;
}

int soc_setEstado(Socio* this,int estado)
{

    this->estado = estado;
    return 0;
}

int soc_getEstado(Socio* this)
{
    return this->estado;
}


Socio* soc_findById(ArrayList* pArraySocio, int id)
{
    Socio* returnAux = NULL;
    int i;

    if(pArraySocio != NULL)
    {
        for(i=0; i<al_len(pArraySocio); i++)
        {
            returnAux = al_get(pArraySocio, i);
            if(soc_getId(returnAux) == id)
            {
                return returnAux;
            }
        }
    }
    return NULL;
}


int soc_resetData (Socio* pElement, char* data1, char* data2, char* data3)
{
    int retorno = -1;

    if(pElement != NULL)
    {
        strcpy ((pElement)->nombre,   data1);
        strcpy ((pElement)->apellido, data2);
        strcpy ((pElement)->dni,      data3);
        retorno = 0;
    }
    return retorno;
}

