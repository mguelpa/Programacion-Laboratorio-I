#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pantallas.h"

/***************************** FUNCIONES PRIVADAS **********************************/
static int scr_searchEmptySlot (sScreen* nombre_array, int length, int* indexTarget);
static int scr_idGen (sScreen* nombre_array, int length, int* idTarget);
static char availability[2][12] = {"DISPONIBLE", "ALQUILADO"};
static char scr_type[3][12] = {"EMPTY","LCD screen","LED screen"};
static char scr_slot[3][12] = {"SCR_EMPTY","SCR_TAKEN","SCR_DOWN"};



////////////////////////////////////////////////////////////////////////////////
static int scr_searchEmptySlot (sScreen* nombre_array, int length, int* indexTarget)
{
    int index;
    if(nombre_array != NULL && length > 0)
    {
        for(index=0; index < length; index++)
        {
            if((nombre_array+index)->scr_slot == SLT_EMPTY)
            {
                *indexTarget = index;
                return 0;
            }
        }
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////
static int scr_idGen (sScreen* nombre_array, int length, int* idTarget)
{
    int id = -1;
    int i;
    if(nombre_array != NULL && length > 0)
    {
        id = 0;
        for (i=0; i<length; i++)
        {
            if((nombre_array+i)->scr_id > id){
            id=(nombre_array+i)->scr_id;
            }
        }
        *idTarget = id+1;
    }
    return id;
}
////////////////////////////////////////////////////////////////////////////////



/*************************** FUNCIONES PUBLICAS *******************************/
////////////////////////////////////////////////////////////////////////////////
int scr_arrayInit (sScreen* nombre_array, int length)
{
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            (nombre_array+i)-> scr_slot = SLT_EMPTY;
            (nombre_array+i)-> scr_id   = SLT_EMPTY;
            (nombre_array+i)-> scr_type = SLT_EMPTY;
            (nombre_array+i)-> scr_availability = SCR_FREE;


            strcpy((nombre_array+i)-> name,    "0");
            strcpy((nombre_array+i)-> review,  "0");
            strcpy((nombre_array+i)-> address, "0");
                   (nombre_array+i)-> price   = 0;
        }
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int scr_searchIndexById (sScreen* nombre_array, int length, int id)
{
    int index = -1;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if(nombre_array[index].scr_slot == SCR_TAKEN)
            {
                if(id == nombre_array[index].scr_id){
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
int scr_loadData (sScreen* nombre_array, int length, int* data1, char* data2, char* data3, char* data4, float* data5)
{
    int retorno = -1;

    int index = -1;
    int idBox;

    if(nombre_array != NULL && length > 0)
    {
        retorno = scr_searchEmptySlot(nombre_array, length, &index);
        if(retorno != -1)
        {
            retorno = scr_idGen(nombre_array, length, &idBox);
            if(retorno != -1)
            {
                (nombre_array+index)->scr_slot = SCR_TAKEN;
                (nombre_array+index)->scr_id   = idBox;
                (nombre_array+index)->scr_type = *data1;

                strcpy ((nombre_array+index)->name,     data2);
                strcpy ((nombre_array+index)->review,   data3);
                strcpy ((nombre_array+index)->address,  data4);
                        (nombre_array+index)->price  = *data5;
                retorno = 0;
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int scr_modifyData (sScreen* nombre_array, int index, int data1, char* data2, char* data3, char* data4, float data5)
{
    int retorno = -1;

    if(nombre_array != NULL && index > -1)
    {
        strcpy ((nombre_array+index)->name,    data2);
        strcpy ((nombre_array+index)->review,  data3);
        strcpy ((nombre_array+index)->address, data4);
                (nombre_array+index)->price  = data5;
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int scr_downData (sScreen* nombre_array, int index)
{
    int retorno = -1;

    if(nombre_array != NULL && index >= 0)
    {
        (nombre_array+index)->scr_slot = SLT_DOWN;
         retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
//                        ----> PASAR DATOS <-----                            //
////////////////////////////////////////////////////////////////////////////////
int scr_getData (sScreen* nombre_array, int index, sScreen* dataTarget)
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
int scr_listScreens (sScreen* nombre_array, int length)
{
    int retorno = -1;

    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            if ((nombre_array+i)->scr_slot != SLT_EMPTY)
            {
                printf("   *********************************************************\n");
                printf("   SCREEN SLOT: %s\n\n",         scr_slot[(nombre_array+i)-> scr_slot]);
                printf("   PANTALLA:\t%s\t",               (nombre_array+i)-> name);
                printf("// TIPO:\t%s \n\n",         scr_type[(nombre_array+i)-> scr_type]);

                printf("   DESCRIPCION:\t\t%s\n",            (nombre_array+i)-> review);
                printf("   UBICACION:\t\t%s\n",              (nombre_array+i)-> address);
                printf("   COSTO PUBLICAION:\tUSD %.2f\n\n", (nombre_array+i)-> price);
                printf("   CODIGO DE PANTALLA:\t%d\t",       (nombre_array+i)-> scr_id);
                printf("// ESTADO:\t%s\n",      availability[(nombre_array+i)-> scr_availability]);
                //printf("   -------------------------------------------------------\n\n");
                printf("   *********************************************************\n\n");
            }
        }
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int scr_printData (sScreen* nombre_array, int index)
{
    int retorno = -1;

    if(nombre_array != NULL && index > -1)
    {
        if ((nombre_array+index)->scr_slot == SCR_TAKEN)
        {

            printf("\n   PANTALLA:\t%s\t",               (nombre_array+index)-> name);
            printf("// TIPO:\t%s \n\n",      scr_type[ (nombre_array+index)-> scr_type ]);

            printf("   DESCRIPCION:\t\t%s\n",            (nombre_array+index)-> review);
            printf("   UBICACION:\t\t%s\n",              (nombre_array+index)-> address);
            printf("   COSTO PUBLICAION:\tUSD %.2f\n\n", (nombre_array+index)-> price);
            printf("   CODIGO DE PANTALLA:\t%d\t",       (nombre_array+index)-> scr_id);
            printf("// ESTADO:\t%s\n",      availability[(nombre_array+index)-> scr_availability]);
            printf("   -------------------------------------------------------\n\n");

        }
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////




























///////////////////////////////////////////////////////////////////////////////
int scr_arrayRecords (sScreen* nombre_array, int length)
{
    int retorno = -1;

    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            printf("***************\n\n");

            printf("scr_slot = %d\n",   (nombre_array+i)-> scr_slot);
            printf("scr_id   = %d\n",   (nombre_array+i)-> scr_id);
            printf("scr_type = %d\n",   (nombre_array+i)-> scr_type);
            printf("scr_disp = %s\n\n",  availability[(nombre_array+i)-> scr_availability]);


            printf("name     = %s\n",   (nombre_array+i)-> name);
            printf("review   = %s\n",   (nombre_array+i)-> review);
            printf("adress   = %s\n",   (nombre_array+i)-> address);
            printf("price    = %.2f\n", (nombre_array+i)-> price);

            printf("***************\n\n");
        }
        retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
