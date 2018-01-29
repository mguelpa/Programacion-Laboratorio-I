#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Inscripciones.h"


////////////////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO                    //
////////////////////////////////////////////////////////////
Inscripciones* insc_new (int serviceID, int memberID, int subscrpitionID, int subscrpitionStatus)
{
    Inscripciones* newInscripcion = malloc ( sizeof(Inscripciones) );

    insc_setStatus (newInscripcion, subscrpitionStatus);
    insc_setID(newInscripcion, subscrpitionID);
    insc_setServiceID (newInscripcion, serviceID);
    insc_setMemberID (newInscripcion, memberID);

    return newInscripcion;
}
Inscripciones* insc_findById (ArrayList* lista, int subscrpitionID)
{
    void*  retorno = NULL;
    Inscripciones* auxiliar;
    int i;

    for(i=0; i<al_len (lista); i++)
    {
        auxiliar = al_get (lista, i);

        if(auxiliar->subscrpitionID == subscrpitionID)
        {
            retorno = auxiliar;
        }
    }
    return retorno;
}
int insc_delete(Inscripciones* this)
{
    free(this);
    return 0;
}





//////////////////////////////////////////////////////////////////////
// SETERS                                                           //
//////////////////////////////////////////////////////////////////////
int insc_setStatus (Inscripciones* this, int status)
{
    this->status = status;
    return 0;
}
int insc_setID (Inscripciones* this, int subscrpitionID)
{
    this->subscrpitionID = subscrpitionID;
    return 0;
}
int insc_setServiceID (Inscripciones* this, int serviceID)
{
    this->serviceID = serviceID;
    return 0;
}
int insc_setMemberID (Inscripciones* this, int memberID)
{
    this->memberID = memberID;
    return 0;
}





//////////////////////////////////////////////////////////////////////
// GETERS                                                           //
//////////////////////////////////////////////////////////////////////
int insc_getStatus (Inscripciones* this)
{
    return this->status;
}
int insc_getID (Inscripciones* this)
{
    return this->subscrpitionID;
}
int insc_getServiceID (Inscripciones* this)
{
    return this->serviceID;
}
int insc_getMemberID (Inscripciones* this)
{
    return this->memberID;
}

