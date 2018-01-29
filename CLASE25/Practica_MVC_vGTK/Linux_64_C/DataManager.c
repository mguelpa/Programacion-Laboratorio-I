#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "DataManager.h"

int dm_saveAll(ArrayList* listaSocios)
{
    int retorno = -1;
    int i;
    Socio* pSocio;
    FILE* pFile;
    pFile = fopen(ARCHIVO_SOCIOS, "wb");
    if(pFile != NULL)
    {
        //escribo datos
        for (i = 0; i< al_len(listaSocios); i++)
        {
            pSocio = al_get(listaSocios, i);
            fwrite(sizeof(pSocio), 1, pFile);
        }
        fclose(sFile)
        retorno = 0;
    }
    return retorno;
}

