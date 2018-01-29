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
}Cliente;
#endif // SOCIO_H_INCLUDED

#define CLIENTE_ESTADO_ACTIVO 0
#define CLIENTE_ESTADO_INACTIVO 1

Cliente* cliente_new(char* nombre, char* apellido, char* dni, int id, int estado);
int cliente_delete(Cliente*);
int cliente_setNombre(Cliente*,char* nombre);
char* cliente_getNombre(Cliente*);
int cliente_setApellido(Cliente* this,char* apellido);
char* cliente_getApellido(Cliente* this);
int cliente_setDni(Cliente* this,char* dni);
char* cliente_getDni(Cliente* this);
int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this);
int cliente_setEstado(Cliente* this,int estado);
int cliente_getEstado(Cliente* this);




Cliente* cliente_findById(ArrayList*, int);




