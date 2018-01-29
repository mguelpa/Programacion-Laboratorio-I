#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Alquiler.h"

Alquiler* alquiler_new(int idCliente,int idEquipo,int tiempoReal,int tiempoEstimado,int idAlquiler,int estado)
{
	Alquiler* this = malloc(sizeof(Alquiler));

	if(this != NULL)
	{

		alquiler_setIdCliente(this,idCliente);
		alquiler_setIdEquipo(this,idEquipo);
		alquiler_setTiempoReal(this,tiempoReal);
		alquiler_setTiempoEstimado(this,tiempoEstimado);
		alquiler_setIdAlquiler(this,idAlquiler);
		alquiler_setEstado(this,estado);
	}
	return this;
}
void alquiler_delete(Alquiler* this)
{
	free(this);
}
int alquiler_setIdCliente(Alquiler* this,int idCliente)
{
	this->idCliente = idCliente;
	return 0;
}
int alquiler_setIdEquipo(Alquiler* this,int idEquipo)
{
	this->idEquipo = idEquipo;
	return 0;
}
int alquiler_setTiempoReal(Alquiler* this,int tiempoReal)
{
	this->tiempoReal = tiempoReal;
	return 0;
}
int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado)
{
	this->tiempoEstimado = tiempoEstimado;
	return 0;
}
int alquiler_setIdAlquiler(Alquiler* this,int idAlquiler)
{
	this->idAlquiler = idAlquiler;
	return 0;
}
int alquiler_setEstado(Alquiler* this,int estado)
{
	this->estado = estado;
	return 0;
}
int alquiler_getIdCliente(Alquiler* this)
{
	return this->idCliente;
}
int alquiler_getIdEquipo(Alquiler* this)
{
	return this->idEquipo;
}
int alquiler_getTiempoReal(Alquiler* this)
{
	return this->tiempoReal;
}
int alquiler_getTiempoEstimado(Alquiler* this)
{
	return this->tiempoEstimado;
}
int alquiler_getIdAlquiler(Alquiler* this)
{
	return this->idAlquiler;
}
int alquiler_getEstado(Alquiler* this)
{
	return this->estado;
}
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(idCliente == alquiler_getIdCliente(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
Alquiler* alquiler_findByIdEquipo(ArrayList* pArray,int idEquipo)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(idEquipo == alquiler_getIdEquipo(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(tiempoReal == alquiler_getTiempoReal(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(tiempoEstimado == alquiler_getTiempoEstimado(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
Alquiler* alquiler_findByIdAlquiler(ArrayList* pArray,int idAlquiler)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(idAlquiler == alquiler_getIdAlquiler(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado)
{

	int i;
	Alquiler* aux;
	Alquiler* retorno=NULL;
	for(i=0;i<al_len(pArray);i++)
	{
		aux = al_get(pArray,i);
		if(estado == alquiler_getEstado(aux))
		{
			retorno = aux;
			break;
		}
	}
	return retorno;
}
int alquiler_compareByIdCliente(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getIdCliente(pA) > alquiler_getIdCliente(pB))
		retorno = 1;
	else if(alquiler_getIdCliente(pA) < alquiler_getIdCliente(pB))
		retorno = -1;

	return retorno;
}
int alquiler_compareByIdEquipo(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getIdEquipo(pA) > alquiler_getIdEquipo(pB))
		retorno = 1;
	else if(alquiler_getIdEquipo(pA) < alquiler_getIdEquipo(pB))
		retorno = -1;

	return retorno;
}
int alquiler_compareByTiempoReal(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getTiempoReal(pA) > alquiler_getTiempoReal(pB))
		retorno = 1;
	else if(alquiler_getTiempoReal(pA) < alquiler_getTiempoReal(pB))
		retorno = -1;

	return retorno;
}
int alquiler_compareByTiempoEstimado(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getTiempoEstimado(pA) > alquiler_getTiempoEstimado(pB))
		retorno = 1;
	else if(alquiler_getTiempoEstimado(pA) < alquiler_getTiempoEstimado(pB))
		retorno = -1;

	return retorno;
}
int alquiler_compareByIdAlquiler(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getIdAlquiler(pA) > alquiler_getIdAlquiler(pB))
		retorno = 1;
	else if(alquiler_getIdAlquiler(pA) < alquiler_getIdAlquiler(pB))
		retorno = -1;

	return retorno;
}
int alquiler_compareByEstado(void* pA ,void* pB)
{

	int retorno = 0;

	if(alquiler_getEstado(pA) > alquiler_getEstado(pB))
		retorno = 1;
	else if(alquiler_getEstado(pA) < alquiler_getEstado(pB))
		retorno = -1;

	return retorno;
}

void alquiler_imprimir (void* pAlquiler)
{
    char herramientas[5][50] = {"empty", "Taladro Neumatico", "Soldador MIG/TIG", "Martillo Neumatico", "Cierra de banco"};
    char estados[2][50] = {"ALQUILER_ESTADO_ALTA", "ALQUILER_ESTADO_BAJA"};

    if(alquiler_getEstado(pAlquiler) == ALQUILER_ESTADO_ALTA)
    {
        printf("ID alquiler: %d - ", alquiler_getIdAlquiler(pAlquiler));
        printf("ESTADO: %s\n\n", estados[alquiler_getEstado(pAlquiler)]);

        printf("ID Cliente: %d\n", alquiler_getIdCliente(pAlquiler));
        printf("Equipo %s\n", herramientas[alquiler_getIdEquipo(pAlquiler)]);
        printf("Tiempo Real: %d\n", alquiler_getTiempoReal(pAlquiler));
        printf("Tiempo Estimado: %d\n\n", alquiler_getTiempoEstimado(pAlquiler));
    }
}

