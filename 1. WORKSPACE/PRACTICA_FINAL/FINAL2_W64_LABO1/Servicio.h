#include "ArrayList.h"

#ifndef _SERVICIO_H
#define _SERVICIO_H
typedef struct
{
    int serviceID;
    int serviceStatus;
    int idCliente;
    char idProducto[50];
    float costoReparacion;
    char fecha[50];
} Servicio;
#endif// _SERVICIO_H

#define SERVICIO_ACTIVO 0
#define SERVICIO_INACTIVO 1

Servicio* servicio_new(int serviceID,int serviceStatus,int idCliente,char* idProducto,float costoReparacion,char* fecha);
void servicio_delete(Servicio* this);
int servicio_setServiceID(Servicio* this,int serviceID);
int servicio_setServiceStatus(Servicio* this,int serviceStatus);
int servicio_setIdCliente(Servicio* this,int idCliente);
int servicio_setIdProducto(Servicio* this,char* idProducto);
int servicio_setCostoReparacion(Servicio* this,float costoReparacion);
int servicio_setFecha(Servicio* this,char* fecha);
int servicio_getServiceID(Servicio* this);
int servicio_getServiceStatus(Servicio* this);
int servicio_getIdCliente(Servicio* this);
char* servicio_getIdProducto(Servicio* this);
float servicio_getCostoReparacion(Servicio* this);
char* servicio_getFecha(Servicio* this);
Servicio* servicio_findByServiceID(ArrayList* pArray,int serviceID);
Servicio* servicio_findByServiceStatus(ArrayList* pArray,int serviceStatus);
Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente);
Servicio* servicio_findByIdProducto(ArrayList* pArray,char* idProducto);
Servicio* servicio_findByCostoReparacion(ArrayList* pArray,float costoReparacion);
Servicio* servicio_findByFecha(ArrayList* pArray,char* fecha);
int servicio_compareByServiceID(void* pA,void* pB);
int servicio_compareByServiceStatus(void* pA,void* pB);
int servicio_compareByIdCliente(void* pA,void* pB);
int servicio_compareByIdProducto(void* pA,void* pB);
int servicio_compareByCostoReparacion(void* pA,void* pB);
int servicio_compareByFecha(void* pA,void* pB);
