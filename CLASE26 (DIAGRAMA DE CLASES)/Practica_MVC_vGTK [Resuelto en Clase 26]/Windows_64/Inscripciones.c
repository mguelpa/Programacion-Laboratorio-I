#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Inscripciones.h"


////////////////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO                    //
////////////////////////////////////////////////////////////
Linkage* link_new (int serviceID, int memberID, int subscrpitionID, int subscrpitionStatus)
{
    Linkage* newLinkage = malloc ( sizeof(Linkage) );

    link_setStatus (newLinkage, subscrpitionStatus);
    link_setID(newLinkage, subscrpitionID);
    link_setServiceID (newLinkage, serviceID);
    link_setMemberID (newLinkage, memberID);

    return newLinkage;
}
Linkage* link_findById (ArrayList* linkage, int subscrpitionID)
{
    void*  retorno = NULL;
    Linkage* auxiliar;
    int i;

    for(i=0; i<al_len (linkage); i++)
    {
        auxiliar = al_get (linkage, i);

        if(auxiliar->subscrpitionID == subscrpitionID)
        {
            retorno = auxiliar;
        }
    }
    return retorno;
}
int link_delete(Linkage* this)
{
    free(this);
    return 0;
}





//////////////////////////////////////////////////////////////////////
// SETERS                                                           //
//////////////////////////////////////////////////////////////////////
int link_setStatus (Linkage* this, int status)
{
    this->status = status;
    return 0;
}
int link_setID (Linkage* this, int subscrpitionID)
{
    this->subscrpitionID = subscrpitionID;
    return 0;
}
int link_setServiceID (Linkage* this, int serviceID)
{
    this->serviceID = serviceID;
    return 0;
}
int link_setMemberID (Linkage* this, int memberID)
{
    this->memberID = memberID;
    return 0;
}





//////////////////////////////////////////////////////////////////////
// GETERS                                                           //
//////////////////////////////////////////////////////////////////////
int link_getStatus (Linkage* this)
{
    return this->status;
}
int link_getID (Linkage* this)
{
    return this->subscrpitionID;
}
int link_getServiceID (Linkage* this)
{
    return this->serviceID;
}
int link_getMemberID (Linkage* this)
{
    return this->memberID;
}

