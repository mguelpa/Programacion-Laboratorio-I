#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "LogEntry.h"

LogEntry* logEntry_new(char* date,char* time,int serviceID,int gravedad,char* msg)
{
    LogEntry* this = malloc(sizeof(LogEntry));

    if(this != NULL)
    {
        logEntry_setDate(this,date);
        logEntry_setTime(this,time);
        logEntry_setServiceID(this,serviceID);
        logEntry_setGravedad(this,gravedad);
        logEntry_setMsg(this,msg);
    }
    return this;
}

void logEntry_delete(LogEntry* this)
{
    free(this);
}

int logEntry_setDate(LogEntry* this,char* date)
{
    strcpy(this->date,date);
    return 0;
}

int logEntry_setTime(LogEntry* this,char* time)
{
    strcpy(this->time,time);
    return 0;
}

int logEntry_setServiceID(LogEntry* this,int serviceID)
{
    this->serviceID = serviceID;
    return 0;
}

int logEntry_setGravedad(LogEntry* this,int gravedad)
{
    this->gravedad = gravedad;
    return 0;
}

int logEntry_setMsg(LogEntry* this,char* msg)
{
    strcpy(this->msg,msg);
    return 0;
}

char* logEntry_getDate(LogEntry* this)
{
    return this->date;
}

char* logEntry_getTime(LogEntry* this)
{
    return this->time;
}

int logEntry_getServiceID(LogEntry* this)
{
    return this->serviceID;
}

int logEntry_getGravedad(LogEntry* this)
{
    return this->gravedad;
}

char* logEntry_getMsg(LogEntry* this)
{
    return this->msg;
}

LogEntry* logEntry_findByDate(ArrayList* pArray,char* date)
{

    int i;
    LogEntry* aux;
    LogEntry* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(date,logEntry_getDate(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

LogEntry* logEntry_findByTime(ArrayList* pArray,char* time)
{

    int i;
    LogEntry* aux;
    LogEntry* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(time,logEntry_getTime(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

LogEntry* logEntry_findByServiceID(ArrayList* pArray,int serviceID)
{

    int i;
    LogEntry* aux;
    LogEntry* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(serviceID == logEntry_getServiceID(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

LogEntry* logEntry_findByGravedad(ArrayList* pArray,int gravedad)
{

    int i;
    LogEntry* aux;
    LogEntry* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(gravedad == logEntry_getGravedad(aux))
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

LogEntry* logEntry_findByMsg(ArrayList* pArray,char* msg)
{

    int i;
    LogEntry* aux;
    LogEntry* retorno=NULL;
    for(i=0; i<al_len(pArray); i++)
    {
        aux = al_get(pArray,i);
        if(strcmp(msg,logEntry_getMsg(aux))==0)
        {
            retorno = aux;
            break;
        }
    }
    return retorno;
}

int logEntry_compareByDate(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(logEntry_getDate(pA),logEntry_getDate(pB));

    return retorno;
}

int logEntry_compareByTime(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(logEntry_getTime(pA),logEntry_getTime(pB));

    return retorno;
}

int logEntry_compareByServiceID(void* pA,void* pB)
{

    int retorno = 0;

    if(logEntry_getServiceID(pA) > logEntry_getServiceID(pB))
        retorno = 1;
    else if(logEntry_getServiceID(pA) < logEntry_getServiceID(pB))
        retorno = -1;

    return retorno;
}

int logEntry_compareByGravedad(void* pA,void* pB)
{

    int retorno = 0;

    if(logEntry_getGravedad(pA) > logEntry_getGravedad(pB))
        retorno = 1;
    else if(logEntry_getGravedad(pA) < logEntry_getGravedad(pB))
        retorno = -1;

    return retorno;
}

int logEntry_compareByMsg(void* pA,void* pB)
{

    int retorno;

    retorno = strcmp(logEntry_getMsg(pA),logEntry_getMsg(pB));

    return retorno;
}
