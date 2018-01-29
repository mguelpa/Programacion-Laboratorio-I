#include "ArrayList.h"

#ifndef INSCRIPCIONES_H_INCLUDED
#define INSCRIPCIONES_H_INCLUDED

    typedef struct
    {
        int status;
        int subscrpitionID;

        int serviceID;
        int memberID;
	}Linkage;

#endif // INSCRIPCIONES_H_INCLUDED

#define VINCULO_ACTIVO 0
#define VINCULO_INACTIVO 1

Linkage* link_new (int serviceID, int memberID, int subscrpitionID, int subscrpitionStatus);

Linkage* link_findById (ArrayList* linkage, int subscrpitionID);

int link_delete(Linkage* this);


int link_setStatus (Linkage* this, int status);
int link_setID (Linkage* this, int subscrpitionID);
int link_setServiceID (Linkage* this, int serviceID);
int link_setMemberID (Linkage* this, int memberID);


int link_getStatus (Linkage* this);
int link_getID (Linkage* this);
int link_getServiceID (Linkage* this);
int link_getMemberID (Linkage* this);







