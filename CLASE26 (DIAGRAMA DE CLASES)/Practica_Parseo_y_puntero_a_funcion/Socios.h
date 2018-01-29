#include "ArrayList.h"

#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

	#define	MAX_CHARS_NOMBRES 50
	#define	MAX_CHARS_DNI 50

	typedef struct
	{
	    int id;
   	    int status;

	    char nombre[MAX_CHARS_NOMBRES +1];
	    float salario;
	}Socio;

#endif // SOCIO_H_INCLUDED

#define SOCIO_ACTIVO 0
#define SOCIO_INACTIVO 1

Socio* soc_new (char* nombre, char* apellido, char* dni, int id, int estado, float salario);
Socio* soc_findById (ArrayList* this, int id);

int soc_delete (Socio* this);

int soc_setId (Socio* this, int id);
int soc_setEstado (Socio* this, int estado);
int soc_setNombre (Socio* this, char* nombre);
void soc_setSalario(Socio* this, float salario);

int soc_getId (Socio* this);
int soc_getEstado (Socio* this);
char* soc_getNombre (Socio* this);
float soc_getSalario (Socio* this);


