#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "DataManager.h"

#include "Subjects.h"
#include "Servicios.h"
#include "Inscripciones.h"


////////////////////////////////////////////////////////////
// GENERAR ARCHIVOS                                       //
////////////////////////////////////////////////////////////
int dm_saveAllSubjects (ArrayList* listaSubjects)
{
    int i, retorno = -1;
    void* pSubject = NULL;

    FILE* subjectsBin = fopen (ARCHIVO_SUBJECTS, "wb");


    if( subjectsBin != NULL )
    {
        for(i=0; i<al_len (listaSubjects); i++)
        {
            pSubject = al_get (listaSubjects, i);

            fwrite (pSubject, sizeof (Subject), 1, subjectsBin);

            retorno = 0;
        }
    }
    fclose (subjectsBin);
    return retorno;
}
int dm_saveAllServicios (ArrayList* listaServicios)
{
    int i, retorno = -1;
    void* pServicio = NULL;

    FILE* serviciosBin = fopen (ARCHIVO_SERVICIOS, "wb");


    if( serviciosBin != NULL )
    {
        for(i=0; i<al_len (listaServicios); i++)
        {
            pServicio = al_get (listaServicios, i);

            fwrite (pServicio, sizeof(Servicios), 1, serviciosBin);

            retorno = 0;
        }
    }
    fclose (serviciosBin);
    return retorno;
}
int dm_saveAllInscripciones (ArrayList* listaInscripciones)
{
    int i, retorno = -1;
    void* pVinculo = NULL;

    FILE* InscripcionesBin = fopen (ARCHIVO_INSCRIPCIONES, "wb");


    if( InscripcionesBin != NULL )
    {
        for(i=0; i<al_len (listaInscripciones); i++)
        {
            pVinculo = al_get (listaInscripciones, i);

            fwrite (pVinculo, sizeof(Inscripciones), 1, InscripcionesBin);

            retorno = 0;
        }
    }
    fclose (InscripcionesBin);
    return retorno;
}




////////////////////////////////////////////////////////////
// LEER ARCHIVOS                                          //
////////////////////////////////////////////////////////////
int dm_readAllSubjects (ArrayList* listaSubjects)
{
    int retorno = -1;
    int maxId = 0;

    Subject auxiliar;
    Subject* pSubject = NULL;

    FILE* subjectsBin = fopen (ARCHIVO_SUBJECTS, "rb");

    if( subjectsBin != NULL )
    {
        do
        {
            if( fread (&auxiliar, sizeof(Subject), 1, subjectsBin) == 1)
            {
                pSubject = sub_new (auxiliar.subjectID, auxiliar.subStatus, auxiliar.name, auxiliar.surname/*, auxiliar.age, auxiliar.dni, auxiliar.salary*/);

                al_add (listaSubjects, pSubject);

                if( auxiliar.subjectID > maxId )
                {
                    maxId = auxiliar.subjectID;
                }
                retorno = maxId;
            }

        }
        while( !feof(subjectsBin) );

        fclose (subjectsBin);
    }
    return retorno;
}
int dm_readAllServicios (ArrayList* listaServicios)
{
    int retorno = -1;
    int maxId = 0;

    Servicios auxServicio;
    Servicios* pServicio = NULL;

    FILE* sociosBin = fopen (ARCHIVO_SERVICIOS, "rb");

    if( sociosBin != NULL )
    {
        do
        {
            if( fread (&auxServicio, sizeof(Servicios), 1, sociosBin) == 1 )
            {
                pServicio = svcs_new (auxServicio.title, auxServicio.description, auxServicio.serviceID, auxServicio.serStatus);

                al_add (listaServicios, pServicio);
                if(auxServicio.serviceID > maxId)
                {
                    maxId = auxServicio.serviceID;
                }
                retorno = maxId;
            }
        }
        while( !feof (sociosBin) );
        fclose (sociosBin);
    }
    return retorno;
}
int dm_readAllInscripciones (ArrayList* listaInscripciones)
{
    int retorno = -1;
    int maxId = 0;

    Inscripciones auxiliar;
    Inscripciones* pInscripcion = NULL;

    FILE* InscripcionesBin = fopen (ARCHIVO_INSCRIPCIONES, "rb");

    if( InscripcionesBin != NULL )
    {
        do
        {
            if( fread (&auxiliar, sizeof(Inscripciones), 1, InscripcionesBin) == 1)
            {
                pInscripcion = insc_new (auxiliar.serviceID, auxiliar.memberID, auxiliar.subscrpitionID, auxiliar.status);

                al_add (listaInscripciones, pInscripcion);

                if( auxiliar.subscrpitionID > maxId )
                {
                    maxId = auxiliar.subscrpitionID;
                }
                retorno = maxId;
            }

        }
        while( !feof(InscripcionesBin) );

        fclose (InscripcionesBin);
    }
    return retorno;
}

































































/*
int dm_saveAll (ArrayList* list, void* thisObject, char* fileName)
{
    int retorno = -1;
    int i;

    FILE* pArchivo = fopen (fileName, "wb");

    thisObject = NULL;

    if( pArchivo != NULL )
    {
        for(i=0; i<al_len(list); i++)
        {
            thisObject = al_get(list, i);

            fwrite(thisObject, sizeof(thisObject), 1, pArchivo);
            retorno = 0;
        }
    }
    fclose(pArchivo);
    return retorno;
}

int dm_readAll(ArrayList* list, void* thisObject, void* buffer, char* fileName)
{
    int retorno = -1;
    Socio auxSocio;
    int maxId = 0;
    thisObject = NULL;
    FILE* pArchivo = fopen(fileName,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if( fread(buffer, sizeof(thisObject), 1, pArchivo) == 1 )
            {
                al_add (pArray, thisObject);

                if(buffer.id > maxId)
                {
                    maxId = buffer.id;
                }
                retorno = maxId;
            }
        }while(!feof(pArchivo));
        fclose(pArchivo);
    }
    return retorno;
}
*/