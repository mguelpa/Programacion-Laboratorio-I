#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"

Cliente* cliente_new(int clientID,int clientStatus,char* nombre,char* apellido,char* dni)
{
    Cliente* this = malloc(sizeof(Cliente));

    if(this != NULL)
    {

        cliente_setClientID(this,clientID);
        cliente_setClientStatus(this,clientStatus);
        cliente_setNombre(this,nombre);
        cliente_setApellido(this,apellido);
        cliente_setDni(this,dni);
    }
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setClientID(Cliente* this,int clientID)
{
    this->clientID = clientID;
    return 0;
}

int cliente_setClientStatus(Cliente* this,int clientStatus)
{
    this->clientStatus = clientStatus;
    return 0;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}

int cliente_setApellido(Cliente* this,char* apellido)
{
    strcpy(this->apellido,apellido);
    return 0;
}

int cliente_setDni(Cliente* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}

int cliente_getClientID(Cliente* this)
{
    return this->clientID;
}

int cliente_getClientStatus(Cliente* this)
{
    return this->clientStatus;
}

char* cliente_getNombre(Cliente* this)
{
    return this->nombre;
}

char* cliente_getApellido(Cliente* this)
{
    return this->apellido;
}

char* cliente_getDni(Cliente* this)
{
    return this->dni;
}

Cliente* cliente_findByClientID(ArrayList* pArray,int clientID)
{

    int i;
    Cliente* aux;
    Cliente* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(clientID == cliente_getClientID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Cliente* cliente_findByClientStatus(ArrayList* pArray,int clientStatus)
{

    int i;
    Cliente* aux;
    Cliente* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(clientStatus == cliente_getClientStatus(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre)
{

    int i;
    Cliente* aux;
    Cliente* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(nombre,cliente_getNombre(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido)
{

    int i;
    Cliente* aux;
    Cliente* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(apellido,cliente_getApellido(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Cliente* cliente_findByDni(ArrayList* pArray,char* dni)
{

    int i;
    Cliente* aux;
    Cliente* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(dni,cliente_getDni(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int cliente_compareByClientID(void* pA,void* pB)
{

    int retorno = 0;

    if(cliente_getClientID(pA) > cliente_getClientID(pB))
        retorno = 1;
    else if(cliente_getClientID(pA) < cliente_getClientID(pB))
        retorno = -1;

    return retorno;
}

int cliente_compareByClientStatus(void* pA,void* pB)
{

    int retorno = 0;

    if(cliente_getClientStatus(pA) > cliente_getClientStatus(pB))
        retorno = 1;
    else if(cliente_getClientStatus(pA) < cliente_getClientStatus(pB))
        retorno = -1;

    return retorno;
}

int cliente_compareByNombre(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(cliente_getNombre(pA),cliente_getNombre(pB));

    return retorno;
}

int cliente_compareByApellido(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(cliente_getApellido(pA),cliente_getApellido(pB));

    return retorno;
}

int cliente_compareByDni(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(cliente_getDni(pA),cliente_getDni(pB));

    return retorno;
}



void cliente_imprimir(void* pCliente)
{

    if(cliente_getClientStatus(pCliente) == CLIENTE_ESTADO_ALTA)
        printf("ID: %d - NOMBRE: %s\n", cliente_getClientID(pCliente),cliente_getNombre(pCliente));

}
