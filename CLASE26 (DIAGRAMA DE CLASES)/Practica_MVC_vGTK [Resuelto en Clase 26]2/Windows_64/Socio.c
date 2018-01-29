#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Socio.h"

////////////////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO                    //
////////////////////////////////////////////////////////////
Socio* soc_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Socio* nuevoSocio = malloc ( sizeof(Socio) );

    soc_setNombre (nuevoSocio, nombre);
    soc_setApellido (nuevoSocio, apellido);
    soc_setDni (nuevoSocio, dni);
    soc_setId (nuevoSocio, id);
    soc_setEstado (nuevoSocio, estado);

    return nuevoSocio;
}
Socio* soc_findById (ArrayList* pArraySocio, int id)
{
    void*  retorno = NULL;
    Socio* auxSocio;

    int i;
    for(i = 0; i<al_len (pArraySocio); i++)
    {
        auxSocio = al_get (pArraySocio, i);

        if(id == auxSocio->id)
        {
            retorno = auxSocio;
        }
    }
    return retorno;
}
int soc_delete(Socio* this)
{
    free(this);
    return 0;
}
//////////////////////////////////////////////////////////////////////
// SETERS                                                           //
//////////////////////////////////////////////////////////////////////
int soc_setNombre (Socio* this, char* nombre)
{
    strcpy (this->nombre, nombre);
    return 0;
}
int soc_setApellido (Socio* this, char* apellido)
{
    strcpy(this->apellido, apellido);
    return 0;
}
int soc_setDni (Socio* this, char* dni)
{
    strcpy (this->dni,dni);
    return 0;
}
int soc_setId (Socio* this, int id)
{
    this->id = id;
    return 0;
}
int soc_setEstado (Socio* this, int estado)
{

    this->estado = estado;
    return 0;
}
//////////////////////////////////////////////////////////////////////
// GETERS                                                           //
//////////////////////////////////////////////////////////////////////
char* soc_getNombre (Socio* this)
{
    return this->nombre;
}
char* soc_getApellido (Socio* this)
{
    return this->apellido;
}
char* soc_getDni (Socio* this)
{
    return this->dni;
}
int soc_getId (Socio* this)
{
    return this->id;
}
int soc_getEstado (Socio* this)
{
    return this->estado;
}

