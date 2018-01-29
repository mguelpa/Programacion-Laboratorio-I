#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "affiliate.h"
#include "ArrayList.h"

/** FUNCIONES Y VARIABLES PRIVADAS **/
static int affi_idGen (int* prevID);
static int idCounter = 0;

//////////////////////////////////
static int affi_idGen(int* prevID)
{
    *prevID += 1;
    return *prevID;
}
//////////////////////////////////
/**________________________________**/


////////////////////////////////////////////////////////////////////////////////
sAsociado* affi_newElement (void)
{
    return malloc( sizeof(sAsociado) );
}
////////////////////////////////////////////////////////////////////////////////
sAsociado* affi_getElementById (ArrayList* list, unsigned int id)
{
    sAsociado* returnAux = NULL;
    int i;

    if(list != NULL)
    {
        for(i=0; i<list->size; i++)
        {
            returnAux = *(list->pElements+i);
            if( returnAux->id == id)
            {
                return returnAux;
            }
        }
        returnAux = NULL;
    }
    return returnAux;
}
////////////////////////////////////////////////////////////////////////////////
int affi_searchIndexById (sAsociado* list, int length, int id)
{
    int index = -1;

    if(list != NULL)
    {
        for(index = 0; index < length; index++)
        {
            if(list->status == SLT_LOAD)
            {
                if( (list->id+index) == id)
                {
                    return index;
                }
            }
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////////
int affi_resetData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4)
{
    int retorno = -1;

    if(pElement != NULL)
    {
        strcpy ((pElement)->nombre,   data1);
        strcpy ((pElement)->apellido, data2);
                (pElement)->edad   = *data3;
        strcpy ((pElement)->dni,      data4);
        retorno = 0;
    }
    return retorno;
}

////////////////////////////////////////////////////////////////////////////////
int affi_setData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4)
{
    int retorno = -1;

    if(pElement != NULL)
    {
        retorno = affi_idGen(&idCounter);
        if(retorno > 0)
        {
            (pElement)->status = SLT_LOAD;
            (pElement)->id     = retorno;

            strcpy ((pElement)->nombre,   data1);
            strcpy ((pElement)->apellido, data2);
                    (pElement)->edad   = *data3;
            strcpy ((pElement)->dni,      data4);
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////


