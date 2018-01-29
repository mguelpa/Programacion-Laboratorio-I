#include "ArrayList.h"

#ifndef _ALQUILER_H
#define _ALQUILER_H
typedef struct
{
	int idCliente;
	int idEquipo;
	int tiempoReal;
	int tiempoEstimado;
	int idAlquiler;
	int estado;
}Alquiler;
#endif// _ALQUILER_H

Alquiler* alquiler_new(int idCliente,int idEquipo,int tiempoReal,int tiempoEstimado,int idAlquiler,int estado);
void alquiler_delete(Alquiler* this);
int alquiler_setIdCliente(Alquiler* this,int idCliente);
int alquiler_setIdEquipo(Alquiler* this,int idEquipo);
int alquiler_setTiempoReal(Alquiler* this,int tiempoReal);
int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado);
int alquiler_setIdAlquiler(Alquiler* this,int idAlquiler);
int alquiler_setEstado(Alquiler* this,int estado);
int alquiler_getIdCliente(Alquiler* this);
int alquiler_getIdEquipo(Alquiler* this);
int alquiler_getTiempoReal(Alquiler* this);
int alquiler_getTiempoEstimado(Alquiler* this);
int alquiler_getIdAlquiler(Alquiler* this);
int alquiler_getEstado(Alquiler* this);
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente);
Alquiler* alquiler_findByIdEquipo(ArrayList* pArray,int idEquipo);
Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal);
Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado);
Alquiler* alquiler_findByIdAlquiler(ArrayList* pArray,int idAlquiler);
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado);
int alquiler_compareByIdCliente(void* pA ,void* pB);
int alquiler_compareByIdEquipo(void* pA ,void* pB);
int alquiler_compareByTiempoReal(void* pA ,void* pB);
int alquiler_compareByTiempoEstimado(void* pA ,void* pB);
int alquiler_compareByIdAlquiler(void* pA ,void* pB);
int alquiler_compareByEstado(void* pA ,void* pB);

