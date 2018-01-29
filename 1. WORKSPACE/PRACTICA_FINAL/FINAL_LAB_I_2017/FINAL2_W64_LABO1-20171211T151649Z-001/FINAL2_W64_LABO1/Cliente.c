#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"


Cliente* cliente_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Cliente* nuevoSocio = malloc(sizeof(Cliente));
    cliente_setNombre(nuevoSocio,nombre);
    cliente_setApellido(nuevoSocio,apellido);
    cliente_setDni(nuevoSocio,dni);
    cliente_setId(nuevoSocio,id);
    cliente_setEstado(nuevoSocio,estado);

    return nuevoSocio;
}


int cliente_delete(Cliente* this)
{
    free(this);
    return 0;
}


int cliente_setNombre(Cliente* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}


char* cliente_getNombre(Cliente* this)
{
    return this->nombre;
}


int cliente_setApellido(Cliente* this,char* apellido)
{
    strcpy(this->apellido,apellido);
    return 0;
}


char* cliente_getApellido(Cliente* this)
{
    return this->apellido;
}


int cliente_setDni(Cliente* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}


char* cliente_getDni(Cliente* this)
{
    return this->dni;
}


int cliente_setId(Cliente* this,int id)
{

    this->id = id;
    return 0;
}

int cliente_getId(Cliente* this)
{
    return this->id;
}

int cliente_setEstado(Cliente* this,int estado)
{

    this->estado = estado;
    return 0;
}

int cliente_getEstado(Cliente* this)
{
    return this->estado;
}


Cliente* cliente_findById(ArrayList* pArraySocio, int id)
{
    int i;
    Cliente *auxSocio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArraySocio);i++)
    {
        auxSocio = al_get(pArraySocio,i);
        if(id == auxSocio->id)
        {
            retorno = auxSocio;
        }
    }

    return retorno;
}




