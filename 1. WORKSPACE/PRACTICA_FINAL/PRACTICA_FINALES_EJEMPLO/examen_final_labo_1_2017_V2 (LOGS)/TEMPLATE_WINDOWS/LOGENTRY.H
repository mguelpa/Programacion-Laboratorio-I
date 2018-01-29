#include "ArrayList.h"

#ifndef _LOGENTRY_H
#define _LOGENTRY_H
typedef struct
{
    char date[11];
    char time[6];
    int serviceID;
    int gravedad;
    char msg[65];
} LogEntry;
#endif// _LOGENTRY_H

LogEntry* logEntry_new(char* date,char* time,int serviceID,int gravedad,char* msg);
void logEntry_delete(LogEntry* this);
int logEntry_setDate(LogEntry* this,char* date);
int logEntry_setTime(LogEntry* this,char* time);
int logEntry_setServiceID(LogEntry* this,int serviceID);
int logEntry_setGravedad(LogEntry* this,int gravedad);
int logEntry_setMsg(LogEntry* this,char* msg);
char* logEntry_getDate(LogEntry* this);
char* logEntry_getTime(LogEntry* this);
int logEntry_getServiceID(LogEntry* this);
int logEntry_getGravedad(LogEntry* this);
char* logEntry_getMsg(LogEntry* this);
LogEntry* logEntry_findByDate(ArrayList* pArray,char* date);
LogEntry* logEntry_findByTime(ArrayList* pArray,char* time);
LogEntry* logEntry_findByServiceID(ArrayList* pArray,int serviceID);
LogEntry* logEntry_findByGravedad(ArrayList* pArray,int gravedad);
LogEntry* logEntry_findByMsg(ArrayList* pArray,char* msg);
int logEntry_compareByDate(void* pA,void* pB);
int logEntry_compareByTime(void* pA,void* pB);
int logEntry_compareByServiceID(void* pA,void* pB);
int logEntry_compareByGravedad(void* pA,void* pB);
int logEntry_compareByMsg(void* pA,void* pB);
