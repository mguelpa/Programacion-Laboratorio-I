#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicio.h"

Servicio* servicio_new(int serviceID,int serviceStatus,int idCliente,char* idProducto,float costoReparacion,char* fecha)
{
    Servicio* this = malloc(sizeof(Servicio));

    if(this != NULL)
    {

        servicio_setServiceID(this,serviceID);
        servicio_setServiceStatus(this,serviceStatus);
        servicio_setIdCliente(this,idCliente);
        servicio_setIdProducto(this,idProducto);
        servicio_setCostoReparacion(this,costoReparacion);
        servicio_setFecha(this,fecha);
    }
    return this;
}

void servicio_delete(Servicio* this)
{
    free(this);
}

int servicio_setServiceID(Servicio* this,int serviceID)
{
    this->serviceID = serviceID;
    return 0;
}

int servicio_setServiceStatus(Servicio* this,int serviceStatus)
{
    this->serviceStatus = serviceStatus;
    return 0;
}

int servicio_setIdCliente(Servicio* this,int idCliente)
{
    this->idCliente = idCliente;
    return 0;
}

int servicio_setIdProducto(Servicio* this,char* idProducto)
{
    strcpy(this->idProducto,idProducto);
    return 0;
}

int servicio_setCostoReparacion(Servicio* this,float costoReparacion)
{
    this->costoReparacion = costoReparacion;
    return 0;
}

int servicio_setFecha(Servicio* this,char* fecha)
{
    strcpy(this->fecha,fecha);
    return 0;
}

int servicio_getServiceID(Servicio* this)
{
    return this->serviceID;
}

int servicio_getServiceStatus(Servicio* this)
{
    return this->serviceStatus;
}

int servicio_getIdCliente(Servicio* this)
{
    return this->idCliente;
}

char* servicio_getIdProducto(Servicio* this)
{
    return this->idProducto;
}

float servicio_getCostoReparacion(Servicio* this)
{
    return this->costoReparacion;
}

char* servicio_getFecha(Servicio* this)
{
    return this->fecha;
}

Servicio* servicio_findByServiceID(ArrayList* pArray,int serviceID)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(serviceID == servicio_getServiceID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Servicio* servicio_findByServiceStatus(ArrayList* pArray,int serviceStatus)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(serviceStatus == servicio_getServiceStatus(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(idCliente == servicio_getIdCliente(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Servicio* servicio_findByIdProducto(ArrayList* pArray,char* idProducto)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(idProducto,servicio_getIdProducto(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Servicio* servicio_findByCostoReparacion(ArrayList* pArray,float costoReparacion)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(costoReparacion == servicio_getCostoReparacion(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Servicio* servicio_findByFecha(ArrayList* pArray,char* fecha)
{

    int i;
    Servicio* aux;
    Servicio* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(fecha,servicio_getFecha(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int servicio_compareByServiceID(void* pA,void* pB)
{

    int retorno = 0;

    if(servicio_getServiceID(pA) > servicio_getServiceID(pB))
        retorno = 1;
    else if(servicio_getServiceID(pA) < servicio_getServiceID(pB))
        retorno = -1;

    return retorno;
}

int servicio_compareByServiceStatus(void* pA,void* pB)
{

    int retorno = 0;

    if(servicio_getServiceStatus(pA) > servicio_getServiceStatus(pB))
        retorno = 1;
    else if(servicio_getServiceStatus(pA) < servicio_getServiceStatus(pB))
        retorno = -1;

    return retorno;
}

int servicio_compareByIdCliente(void* pA,void* pB)
{

    int retorno = 0;

    if(servicio_getIdCliente(pA) > servicio_getIdCliente(pB))
        retorno = 1;
    else if(servicio_getIdCliente(pA) < servicio_getIdCliente(pB))
        retorno = -1;

    return retorno;
}

int servicio_compareByIdProducto(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(servicio_getIdProducto(pA),servicio_getIdProducto(pB));

    return retorno;
}

int servicio_compareByCostoReparacion(void* pA,void* pB)
{

    int retorno = 0;

    if(servicio_getCostoReparacion(pA) > servicio_getCostoReparacion(pB))
        retorno = 1;
    else if(servicio_getCostoReparacion(pA) < servicio_getCostoReparacion(pB))
        retorno = -1;

    return retorno;
}

int servicio_compareByFecha(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(servicio_getFecha(pA),servicio_getFecha(pB));

    return retorno;
}
