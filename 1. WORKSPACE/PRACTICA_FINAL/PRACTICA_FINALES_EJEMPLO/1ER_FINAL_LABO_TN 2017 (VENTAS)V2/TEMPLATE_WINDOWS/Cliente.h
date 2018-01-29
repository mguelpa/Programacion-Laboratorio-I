#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
    int clientID;
    int clientStatus;
    char nombre[50];
    char apellido[50];
    char dni[50];
} Cliente;
#endif// _CLIENTE_H
#define CLIENTE_ESTADO_ALTA 1
#define CLIENTE_ESTADO_BAJA -1
#define CLIENTE_ESTADO_COMPRA 0

Cliente* cliente_new(int clientID,int clientStatus,char* nombre,char* apellido,char* dni);
void cliente_delete(Cliente* this);
int cliente_setClientID(Cliente* this,int clientID);
int cliente_setClientStatus(Cliente* this,int clientStatus);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_getClientID(Cliente* this);
int cliente_getClientStatus(Cliente* this);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
Cliente* cliente_findByClientID(ArrayList* pArray,int clientID);
Cliente* cliente_findByClientStatus(ArrayList* pArray,int clientStatus);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
int cliente_compareByClientID(void* pA,void* pB);
int cliente_compareByClientStatus(void* pA,void* pB);
int cliente_compareByNombre(void* pA,void* pB);
int cliente_compareByApellido(void* pA,void* pB);
int cliente_compareByDni(void* pA,void* pB);

void cliente_imprimir(void* pCliente);

