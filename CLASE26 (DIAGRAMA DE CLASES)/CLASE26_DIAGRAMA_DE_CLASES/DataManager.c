#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Socio.h"
#include "DataManager.h"

//////////////////////////////////////////////////////////////////////
int dm_saveAll (ArrayList* listaSocios)
{
    int retorno = -1;
    int i;
    int cantidad = 0;

    FILE* pFile;
    Socio* pSocio;

    pFile = fopen (ARCHIVO_SOCIOS, "ab+");
    if(pFile==NULL)
    {
        printf("Error opening file");
        return 0;
    }

    if(pFile != NULL)
    {
        for(i=0; i<al_len(listaSocios); i++)
        {
            pSocio = al_get (listaSocios, i);
            printf("%s", pSocio->nombre);
            printf("%s", pSocio->apellido);
            fflush(stdin);
            cantidad = fwrite (pSocio, sizeof(Socio), 1, pFile);
            printf("datos escritos: %d", cantidad);
        }
        fclose (pFile);
        retorno = 0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////
int dm_readAll(ArrayList* listaSocios)
{
    Socio auxSocio;
    Socio* pSocio;
    FILE* pFile;
    int maximo  = 0;

    pFile = fopen(ARCHIVO_SOCIOS, "rb");

    if(listaSocios != NULL)
    {
        do
        {
            if(fread (&auxSocio, sizeof(Socio), 1, pFile) == 1)
            {
                pSocio = soc_new(auxSocio.nombre, auxSocio.apellido, auxSocio.dni, auxSocio.id, auxSocio.estado);
                al_add (listaSocios, pSocio);
            }
            if(auxSocio.id > maximo)
            {
                auxSocio.id = maximo;
            }

        }while( !feof(pFile) );
    }
    return maximo;
}
//////////////////////////////////////////////////////////////////////
