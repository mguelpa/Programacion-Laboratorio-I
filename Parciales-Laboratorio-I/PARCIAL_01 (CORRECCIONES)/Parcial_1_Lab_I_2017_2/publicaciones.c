#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "publicaciones.h"

/***************************** FUNCIONES PRIVADAS **********************************/
static int adv_searchEmptySlot (sAdvertisement* nombre_array, int length, int* indexTarget);
static int adv_idGen (sAdvertisement* nombre_array, int length, int* idTarget);

////////////////////////////////////////////////////////////////////////////////
static int adv_searchEmptySlot (sAdvertisement* nombre_array, int length, int* indexTarget)
{
    int index;
    if(nombre_array != NULL && length > 0)
    {
        for(index=0; index < length; index++)
        {
            if(nombre_array[index].adv_slot == 0)
            {
                *indexTarget = index;
                return 0;
            }
        }
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////
static int adv_idGen (sAdvertisement* nombre_array, int length, int* idTarget)
{
    int id = -1;
    int i;
    if(nombre_array != NULL && length > 0)
    {
        id = 0;
        for (i=0; i<length; i++)
        {
            if((nombre_array+i)->adv_code > id){
            id=(nombre_array+i)->adv_code;
            }
        }
        *idTarget = id+1;
    }
    return id;
}
////////////////////////////////////////////////////////////////////////////////


/*************************** FUNCIONES PUBLICAS ******************************/
////////////////////////////////////////////////////////////////////////////////
int adv_arrayInit (sAdvertisement* nombre_array, int length)
{
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            (nombre_array+i)-> adv_slot = 0;
            (nombre_array+i)-> adv_code = 0;

            strcpy((nombre_array+i)-> clientID,    "0");
                   (nombre_array+i)-> scr_code   =  0;
                   (nombre_array+i)-> adv_lapse  =  0;
            strcpy((nombre_array+i)-> adv_archive, "0");

        }
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int adv_arrayRecords (sAdvertisement* nombre_array, int length)
{
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            printf("***************\n\n");

            printf("adv_slot = %d\n",    (nombre_array+i)-> adv_slot);
            printf("adv_code = %d\n\n",  (nombre_array+i)-> adv_code);

            printf("clientID    = %s\n", (nombre_array+i)-> clientID);
            printf("scr_code    = %d\n", (nombre_array+i)-> scr_code);
            printf("adv_lapse   = %d\n", (nombre_array+i)-> adv_lapse);
            printf("adv_archive = %s\n", (nombre_array+i)-> adv_archive);

            printf("***************\n\n");
        }
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int adv_searchIndexById (sAdvertisement* nombre_array, int length, char* id)
{
    int index = -1;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if(nombre_array[index].adv_slot == ADV_TAKEN)
            {
                if(strncmp (id, (nombre_array+index)->clientID, MAX_CHARS_CUIT+1) == 0){
                    return index;
                }
            }
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////////
int adv_searchIndexById2 (sAdvertisement* nombre_array, int length, int id)
{
    int index = -1;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if(nombre_array[index].adv_slot == ADV_TAKEN)
            {
                if(id == nombre_array[index].adv_code){
                    return index;
                }
            }
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////////
//             ----> CARGA, MODIFICACION Y BAJA DE DATOS    <-----            //
////////////////////////////////////////////////////////////////////////////////
int adv_loadData (sAdvertisement* nombre_array, int length, char* data1, int* data2, int* data3, char* data4)
{
    int retorno = -1;

    int index = -1;
    int idBox;

    if(nombre_array != NULL && length > 0)
    {
        retorno = adv_searchEmptySlot(nombre_array, length, &index);
        if(retorno != -1)
        {
            retorno = adv_idGen(nombre_array, length, &idBox);
            if(retorno != -1)
            {
                (nombre_array+index)->adv_slot = ADV_TAKEN;
                (nombre_array+index)->adv_code = idBox;

                strcpy ((nombre_array+index)->clientID,    data1);
                        (nombre_array+index)->scr_code  = *data2;
                        (nombre_array+index)->adv_lapse = *data3;
                strcpy ((nombre_array+index)->adv_archive, data4);
                retorno = 0;
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int adv_modifyData (sAdvertisement* nombre_array, int index, int* data3)
{
    int retorno = -1;

    if(nombre_array != NULL && index > -1)
    {
        (nombre_array+index)->adv_lapse  = *data3;
         retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int adv_downData (sAdvertisement* nombre_array, int index)
{
    int retorno = -1;

    if(nombre_array != NULL && index >= 0)
    {
        (nombre_array+index)->adv_slot = ADV_DOWN;
         retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                        ----> PASAR DATOS <-----                            //
////////////////////////////////////////////////////////////////////////////////
int adv_getData (sAdvertisement* nombre_array, int index, sAdvertisement* dataTarget)
{
    int retorno = -1;

    if(nombre_array != NULL && index >= 0)
    {
        *dataTarget = *(nombre_array+index);
         retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
