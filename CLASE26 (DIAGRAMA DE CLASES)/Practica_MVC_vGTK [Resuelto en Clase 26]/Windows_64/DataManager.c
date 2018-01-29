#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "DataManager.h"

#include "Socio.h"
#include "Servicios.h"
#include "Inscripciones.h"


////////////////////////////////////////////////////////////
// GENERAR ARCHIVOS                                       //
////////////////////////////////////////////////////////////
int dm_saveAllSocios (ArrayList* listaSocios)
{
    int i, retorno = -1;
    void* pSocio = NULL;

    FILE* sociosBin = fopen (ARCHIVO_SOCIOS, "wb");


    if( sociosBin != NULL )
    {
        for(i=0; i<al_len (listaSocios); i++)
        {
            pSocio = al_get (listaSocios, i);

            fwrite (pSocio, sizeof (Socio), 1, sociosBin);

            retorno = 0;
        }
    }
    fclose (sociosBin);
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
int dm_saveAllLinkages (ArrayList* listaInscripciones)
{
    int i, retorno = -1;
    void* pVinculo = NULL;

    FILE* linkagesBin = fopen (ARCHIVO_INSCRIPCIONES, "wb");


    if( linkagesBin != NULL )
    {
        for(i=0; i<al_len (listaInscripciones); i++)
        {
            pVinculo = al_get (listaInscripciones, i);

            fwrite (pVinculo, sizeof(Linkage), 1, linkagesBin);

            retorno = 0;
        }
    }
    fclose (linkagesBin);
    return retorno;
}




////////////////////////////////////////////////////////////
// LEER ARCHIVOS                                          //
////////////////////////////////////////////////////////////
int dm_readAllSocios (ArrayList* listaSocios)
{
    int retorno = -1;
    int maxId = 0;

    Socio auxSocio;
    Socio* pSocio = NULL;

    FILE* sociosBin = fopen (ARCHIVO_SOCIOS, "rb");

    if( sociosBin != NULL )
    {
        do
        {
            if( fread (&auxSocio, sizeof(Socio), 1, sociosBin) == 1)
            {
                pSocio = soc_new (auxSocio.nombre, auxSocio.apellido,auxSocio.dni, auxSocio.id, auxSocio.estado);

                al_add (listaSocios, pSocio);

                if( auxSocio.id > maxId )
                {
                    maxId = auxSocio.id;
                }
                retorno = maxId;
            }

        }
        while( !feof(sociosBin) );

        fclose (sociosBin);
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
                pServicio = svcs_new (auxServicio.titulo, auxServicio.descripcion, auxServicio.id, auxServicio.estado);

                al_add (listaServicios, pServicio);
                if(auxServicio.id > maxId)
                {
                    maxId = auxServicio.id;
                }
                retorno = maxId;
            }
        }
        while( !feof (sociosBin) );
        fclose (sociosBin);
    }
    return retorno;
}
int dm_readAllLinkages (ArrayList* listaInscripciones)
{
    int retorno = -1;
    int maxId = 0;

    Linkage auxiliar;
    Linkage* pVinculo = NULL;

    FILE* linkagesBin = fopen (ARCHIVO_INSCRIPCIONES, "rb");

    if( linkagesBin != NULL )
    {
        do
        {
            if( fread (&auxiliar, sizeof(Linkage), 1, linkagesBin) == 1)
            {
                pVinculo = link_new (auxiliar.serviceID, auxiliar.memberID, auxiliar.subscrpitionID, auxiliar.status);

                al_add (listaInscripciones, pVinculo);

                if( auxiliar.subscrpitionID > maxId )
                {
                    maxId = auxiliar.subscrpitionID;
                }
                retorno = maxId;
            }

        }
        while( !feof(linkagesBin) );

        fclose (linkagesBin);
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
