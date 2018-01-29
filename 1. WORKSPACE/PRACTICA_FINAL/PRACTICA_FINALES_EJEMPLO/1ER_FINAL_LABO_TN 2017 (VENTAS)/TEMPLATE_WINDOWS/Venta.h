#include "ArrayList.h"

#ifndef _VENTA_H
#define _VENTA_H
typedef struct
{
    int ventaID;
    int ventaStatus;
    int clientID;
    int productID;
    int cantidad;
} Venta;
#endif// _VENTA_H

Venta* venta_new(int ventaID,int ventaStatus,int clientID,int productID,int cantidad);
void venta_delete(Venta* this);
int venta_setVentaID(Venta* this,int ventaID);
int venta_setVentaStatus(Venta* this,int ventaStatus);
int venta_setClientID(Venta* this,int clientID);
int venta_setProductID(Venta* this,int productID);
int venta_setCantidad(Venta* this,int cantidad);
int venta_getVentaID(Venta* this);
int venta_getVentaStatus(Venta* this);
int venta_getClientID(Venta* this);
int venta_getProductID(Venta* this);
int venta_getCantidad(Venta* this);
Venta* venta_findByVentaID(ArrayList* pArray,int ventaID);
Venta* venta_findByVentaStatus(ArrayList* pArray,int ventaStatus);
Venta* venta_findByClientID(ArrayList* pArray,int clientID);
Venta* venta_findByProductID(ArrayList* pArray,int productID);
Venta* venta_findByCantidad(ArrayList* pArray,int cantidad);
int venta_compareByVentaID(void* pA,void* pB);
int venta_compareByVentaStatus(void* pA,void* pB);
int venta_compareByClientID(void* pA,void* pB);
int venta_compareByProductID(void* pA,void* pB);
int venta_compareByCantidad(void* pA,void* pB);

