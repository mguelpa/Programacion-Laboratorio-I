#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Venta.h"

Venta* venta_new(int ventaID,int ventaStatus,int clientID,int productID,int cantidad)
{
    Venta* this = malloc(sizeof(Venta));

    if(this != NULL)
    {

        venta_setVentaID(this,ventaID);
        venta_setVentaStatus(this,ventaStatus);
        venta_setClientID(this,clientID);
        venta_setProductID(this,productID);
        venta_setCantidad(this,cantidad);
    }
    return this;
}

void venta_delete(Venta* this)
{
    free(this);
}

int venta_setVentaID(Venta* this,int ventaID)
{
    this->ventaID = ventaID;
    return 0;
}

int venta_setVentaStatus(Venta* this,int ventaStatus)
{
    this->ventaStatus = ventaStatus;
    return 0;
}

int venta_setClientID(Venta* this,int clientID)
{
    this->clientID = clientID;
    return 0;
}

int venta_setProductID(Venta* this,int productID)
{
    this->productID = productID;
    return 0;
}

int venta_setCantidad(Venta* this,int cantidad)
{
    this->cantidad = cantidad;
    return 0;
}

int venta_getVentaID(Venta* this)
{
    return this->ventaID;
}

int venta_getVentaStatus(Venta* this)
{
    return this->ventaStatus;
}

int venta_getClientID(Venta* this)
{
    return this->clientID;
}

int venta_getProductID(Venta* this)
{
    return this->productID;
}

int venta_getCantidad(Venta* this)
{
    return this->cantidad;
}

Venta* venta_findByVentaID(ArrayList* pArray,int ventaID)
{

    int i;
    Venta* aux;
    Venta* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(ventaID == venta_getVentaID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Venta* venta_findByVentaStatus(ArrayList* pArray,int ventaStatus)
{

    int i;
    Venta* aux;
    Venta* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(ventaStatus == venta_getVentaStatus(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Venta* venta_findByClientID(ArrayList* pArray,int clientID)
{

    int i;
    Venta* aux;
    Venta* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(clientID == venta_getClientID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Venta* venta_findByProductID(ArrayList* pArray,int productID)
{

    int i;
    Venta* aux;
    Venta* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(productID == venta_getProductID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Venta* venta_findByCantidad(ArrayList* pArray,int cantidad)
{

    int i;
    Venta* aux;
    Venta* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(cantidad == venta_getCantidad(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int venta_compareByVentaID(void* pA,void* pB)
{

    int retorno = 0;

    if(venta_getVentaID(pA) > venta_getVentaID(pB))
        retorno = 1;
    else if(venta_getVentaID(pA) < venta_getVentaID(pB))
        retorno = -1;

    return retorno;
}

int venta_compareByVentaStatus(void* pA,void* pB)
{

    int retorno = 0;

    if(venta_getVentaStatus(pA) > venta_getVentaStatus(pB))
        retorno = 1;
    else if(venta_getVentaStatus(pA) < venta_getVentaStatus(pB))
        retorno = -1;

    return retorno;
}

int venta_compareByClientID(void* pA,void* pB)
{

    int retorno = 0;

    if(venta_getClientID(pA) > venta_getClientID(pB))
        retorno = 1;
    else if(venta_getClientID(pA) < venta_getClientID(pB))
        retorno = -1;

    return retorno;
}

int venta_compareByProductID(void* pA,void* pB)
{

    int retorno = 0;

    if(venta_getProductID(pA) > venta_getProductID(pB))
        retorno = 1;
    else if(venta_getProductID(pA) < venta_getProductID(pB))
        retorno = -1;

    return retorno;
}

int venta_compareByCantidad(void* pA,void* pB)
{

    int retorno = 0;

    if(venta_getCantidad(pA) > venta_getCantidad(pB))
        retorno = 1;
    else if(venta_getCantidad(pA) < venta_getCantidad(pB))
        retorno = -1;

    return retorno;
}
