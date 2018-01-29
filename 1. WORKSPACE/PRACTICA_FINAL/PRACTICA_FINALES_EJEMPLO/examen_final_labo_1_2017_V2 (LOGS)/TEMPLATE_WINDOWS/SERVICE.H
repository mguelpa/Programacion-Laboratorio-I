#include "ArrayList.h"

#ifndef _SERVICE_H
#define _SERVICE_H
typedef struct
{
    int id;
    char name[33];
    char email[65];
} Service;
#endif// _SERVICE_H

Service* service_new(int id,char* name,char* email);
void service_delete(Service* this);
int service_setId(Service* this,int id);
int service_setName(Service* this,char* name);
int service_setEmail(Service* this,char* email);
int service_getId(Service* this);
char* service_getName(Service* this);
char* service_getEmail(Service* this);
Service* service_findById(ArrayList* pArray,int id);
Service* service_findByName(ArrayList* pArray,char* name);
Service* service_findByEmail(ArrayList* pArray,char* email);
int service_compareById(void* pA,void* pB);
int service_compareByName(void* pA,void* pB);
int service_compareByEmail(void* pA,void* pB);
