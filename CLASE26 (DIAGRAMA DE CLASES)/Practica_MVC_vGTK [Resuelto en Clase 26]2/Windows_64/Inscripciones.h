#include "ArrayList.h"

#ifndef INSCRIPCIONES_H_INCLUDED
#define INSCRIPCIONES_H_INCLUDED

    typedef struct
    {
        int subscrpitionID;
        int status;

        int serviceID;
        int memberID;
	}Inscripciones;

#endif // INSCRIPCIONES_H_INCLUDED

#define INSCRIPCION_ACTIVA 0
#define INSCRIPCION_INACTIVA 1

Inscripciones* insc_new (int serviceID, int memberID, int subscrpitionID, int subscrpitionStatus);

Inscripciones* insc_findById (ArrayList* Inscripciones, int subscrpitionID);

int insc_delete (Inscripciones* this);


int insc_setStatus (Inscripciones* this, int status);
int insc_setID (Inscripciones* this, int subscrpitionID);
int insc_setServiceID (Inscripciones* this, int serviceID);
int insc_setMemberID (Inscripciones* this, int memberID);


int insc_getStatus (Inscripciones* this);
int insc_getID (Inscripciones* this);
int insc_getServiceID (Inscripciones* this);
int insc_getMemberID (Inscripciones* this);







