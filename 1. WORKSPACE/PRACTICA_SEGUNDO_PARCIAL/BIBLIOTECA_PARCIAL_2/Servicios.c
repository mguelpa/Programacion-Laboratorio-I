#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"

#include "Subjects.h"
#include "Servicios.h"

////////////////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO                    //
////////////////////////////////////////////////////////////
Servicios* svcs_new (char* titulo, char* descripcion, int id, int estado)
{
    Servicios* nuevoServicio = malloc ( sizeof(Servicios) );

    svcs_setTitulo (nuevoServicio, titulo);
    svcs_setDescripcion (nuevoServicio, descripcion);
    svcs_setId (nuevoServicio, id);
    svcs_setEstado (nuevoServicio, estado);

    return nuevoServicio;
}
Servicios* svcs_findById (ArrayList* SvcsList, int id)
{
    void* retorno = NULL;

    Servicios* thisSubjet;
    int i;

    for(i=0; i<al_len(SvcsList); i++)
    {
        thisSubjet = al_get(SvcsList, i);


        if( thisSubjet->serviceID == id )
        {
            retorno = thisSubjet;
        }
    }
    return retorno;
}
int svcs_delete (Servicios* this)
{
    free (this);
    return 0;
}
////////////////////////////////////////////////////////////
//SETERS                                                  //
////////////////////////////////////////////////////////////
int svcs_setTitulo (Servicios* this, char* titulo)
{
    strcpy (this->title, titulo);
    return 0;
}
int svcs_setDescripcion (Servicios* this, char* descripcion)
{
    strcpy (this->description, descripcion);
    return 0;
}
int svcs_setId (Servicios* this,int id)
{
    this->serviceID = id;
    return 0;
}
int svcs_setEstado (Servicios* this, int estado)
{
    this->serStatus = estado;
    return 0;
}
////////////////////////////////////////////////////////////
//GETERS                                                  //
////////////////////////////////////////////////////////////
int svcs_getId (Servicios* this)
{
    return this-> serviceID;
}
int svcs_getEstado (Servicios* this)
{
    return this-> serStatus;
}
char* svcs_getDescripcion (Servicios* this)
{
    return this-> description;
}
char* svcs_getTitulo (Servicios* this)
{
    return this-> title;
}

