#include "ArrayList.h"

#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

    #define MAX_CHAR_TITULOS 50
    #define MAX_CHAR_DESCRIPCIONES 50
    typedef struct
    {
        int serviceID;
        int serStatus;
        char title [MAX_CHAR_TITULOS+1];
        char description [MAX_CHAR_DESCRIPCIONES+1];

    }Servicios;

#endif // SERVICIOS_H_INCLUDED

#define SERVICIO_ACTIVO 0
#define SERVICIO_INACTIVO 1

Servicios* svcs_new (char* titulo, char* descripcion, int id, int estado);
Servicios* svcs_findById (ArrayList* SvcsList, int id);
int svcs_delete (Servicios* this);

int svcs_setTitulo (Servicios* this, char* titulo);
int svcs_setDescripcion (Servicios*, char* descripcion);
int svcs_setId (Servicios* this, int id);
int svcs_setEstado (Servicios* this, int estado);

char* svcs_getTitulo (Servicios* this);
char* svcs_getDescripcion (Servicios* this);
int svcs_getId (Servicios* this);
int svcs_getEstado (Servicios* this);


