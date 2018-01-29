#include "ArrayList.h"

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
	typedef struct
	{
	    int id;
	    char nombre[51];
	    char apellido[51];
	    char dni[51];
	    int estado;
	}Socio;

#endif // SOCIO_H_INCLUDED

#define SOCIO_ESTADO_ACTIVO 0
#define SOCIO_ESTADO_INACTIVO 1

Socio* soc_new (char* nombre, char* apellido, char* dni, int id, int estado);
Socio* soc_findById (ArrayList* this, int id);

int soc_delete (Socio* this);

int soc_setNombre (Socio* this, char* nombre);
int soc_setApellido (Socio* this, char* apellido);
int soc_setDni (Socio* this, char* dni);
int soc_setId (Socio* this, int id);
int soc_setEstado (Socio* this, int estado);

char* soc_getNombre (Socio* this);
char* soc_getApellido (Socio* this);
char* soc_getDni (Socio* this);
int soc_getId (Socio* this);
int soc_getEstado (Socio* this);
