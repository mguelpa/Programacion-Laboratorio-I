#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Ads.h"

Ads* ads_new(int advertID,int adStatus,int clientID,int productID,int duration,char* files)
{
    Ads* this = malloc(sizeof(Ads));

    if(this != NULL)
    {

        ads_setAdvertID(this,advertID);
        ads_setAdStatus(this,adStatus);
        ads_setClientID(this,clientID);
        ads_setProductID(this,productID);
        ads_setDuration(this,duration);
        ads_setFiles(this,files);
    }
    return this;
}

void ads_delete(Ads* this)
{
    free(this);
}

int ads_setAdvertID(Ads* this,int advertID)
{
    this->advertID = advertID;
    return 0;
}

int ads_setAdStatus(Ads* this,int adStatus)
{
    this->adStatus = adStatus;
    return 0;
}

int ads_setClientID(Ads* this,int clientID)
{
    this->clientID = clientID;
    return 0;
}

int ads_setProductID(Ads* this,int productID)
{
    this->productID = productID;
    return 0;
}

int ads_setDuration(Ads* this,int duration)
{
    this->duration = duration;
    return 0;
}

int ads_setFiles(Ads* this,char* files)
{
    strcpy(this->files,files);
    return 0;
}

int ads_getAdvertID(Ads* this)
{
    return this->advertID;
}

int ads_getAdStatus(Ads* this)
{
    return this->adStatus;
}

int ads_getClientID(Ads* this)
{
    return this->clientID;
}

int ads_getProductID(Ads* this)
{
    return this->productID;
}

int ads_getDuration(Ads* this)
{
    return this->duration;
}

char* ads_getFiles(Ads* this)
{
    return this->files;
}

Ads* ads_findByAdvertID(ArrayList* pArray,int advertID)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(advertID == ads_getAdvertID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Ads* ads_findByAdStatus(ArrayList* pArray,int adStatus)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(adStatus == ads_getAdStatus(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Ads* ads_findByClientID(ArrayList* pArray,int clientID)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(clientID == ads_getClientID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Ads* ads_findByProductID(ArrayList* pArray,int productID)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(productID == ads_getProductID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Ads* ads_findByDuration(ArrayList* pArray,int duration)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(duration == ads_getDuration(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Ads* ads_findByFiles(ArrayList* pArray,char* files)
{

    int i;
    Ads* aux;
    Ads* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(files,ads_getFiles(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}



