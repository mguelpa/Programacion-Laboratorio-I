#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Service.h"

Service* service_new(int id,char* name,char* email)
{
    Service* this = malloc(sizeof(Service));

    if(this != NULL)
    {

        service_setId(this,id);
        service_setName(this,name);
        service_setEmail(this,email);
    }
    return this;
}

void service_delete(Service* this)
{
    free(this);
}

int service_setId(Service* this,int id)
{
    this->id = id;
    return 0;
}

int service_setName(Service* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}

int service_setEmail(Service* this,char* email)
{
    strcpy(this->email,email);
    return 0;
}

int service_getId(Service* this)
{
    return this->id;
}

char* service_getName(Service* this)
{
    return this->name;
}

char* service_getEmail(Service* this)
{
    return this->email;
}

Service* service_findById(ArrayList* pArray,int id)
{

    int i;
    Service* aux;
    Service* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(id == service_getId(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Service* service_findByName(ArrayList* pArray,char* name)
{

    int i;
    Service* aux;
    Service* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(name,service_getName(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

Service* service_findByEmail(ArrayList* pArray,char* email)
{

    int i;
    Service* aux;
    Service* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(email,service_getEmail(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int service_compareById(void* pA,void* pB)
{

    int retorno = 0;

    if(service_getId(pA) > service_getId(pB))
        retorno = 1;
    else if(service_getId(pA) < service_getId(pB))
        retorno = -1;

    return retorno;
}

int service_compareByName(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(service_getName(pA),service_getName(pB));

    return retorno;
}

int service_compareByEmail(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(service_getEmail(pA),service_getEmail(pB));

    return retorno;
}




