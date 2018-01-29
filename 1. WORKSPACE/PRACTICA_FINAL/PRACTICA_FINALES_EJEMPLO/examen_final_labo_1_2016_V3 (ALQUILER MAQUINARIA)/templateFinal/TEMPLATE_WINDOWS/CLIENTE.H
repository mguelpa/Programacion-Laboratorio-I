#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
	int idCliente;
	char nombre[50];
	char apellido[50];
	char dni[50];
	int estado;
}Cliente;
#endif// _CLIENTE_H

#define CLIENTE_ESTADO_ALTA 0
#define CLIENTE_ESTADO_BAJA 1

Cliente* cliente_new(int idCliente,char* nombre,char* apellido,char* dni,int estado);
void cliente_delete(Cliente* this);
int cliente_setIdCliente(Cliente* this,int idCliente);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setEstado(Cliente* this,int estado);
int cliente_getIdCliente(Cliente* this);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getEstado(Cliente* this);
Cliente* cliente_findByIdCliente(ArrayList* pArray,int idCliente);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findByEstado(ArrayList* pArray,int estado);
int cliente_compareByIdCliente(void* pA ,void* pB);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareByEstado(void* pA ,void* pB);

void cliente_imprimir(void* pCliente);

