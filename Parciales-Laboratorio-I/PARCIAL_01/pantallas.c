#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pantallas.h"



static int scr_searchEmptySlot (sScreen* nombre_array, int length);
static int scr_generateID (sScreen* Nombre_array, int length);
//______________________________________________________________________________


////////////////////////////////////////////////////////////////////////////////
static int scr_searchEmptySlot (sScreen* nombre_array, int length)
{
    int retorno = -1;
    int index;

    if(nombre_array != NULL && length > 0){

        for(index = 0; index < length; index++)
        {
            if(nombre_array[index].scr_slot == SCR_EMPTY){
                retorno =  index;
                break;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
static int scr_generateID (sScreen* nombre_array, int length)
{
    int nextID = -1;
    int i;

    if(nombre_array != NULL && length > 0){
    	nextID = 1;

        for(i=0; i<length; i++)
        {
            if(nombre_array[i].scr_slot == SCR_TAKEN)
            {
                if(nombre_array[i].scr_ID >= nextID){
                   nextID = nombre_array[i].scr_ID + 1;
                }
            }
        }
    }
    return nextID;
}
////////////////////////////////////////////////////////////////////////////////
int scr_arrayInit (sScreen* nombre_array, int length)
{
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0){
        for(i=0; i<length; i++)
        {
            nombre_array[i].scr_slot = SCR_EMPTY;
            nombre_array[i].scr_ID   = SCR_EMPTY;
            nombre_array[i].scr_type = 0;
            strcpy (nombre_array[i].name, "000000");
            strcpy (nombre_array[i].adress, "000000");
            nombre_array[i].price = 0;
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int scr_searchIndexById (sScreen* nombre_array, int length, int id)
{
    int retorno = -1;
    int index;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if(nombre_array[index].scr_slot == SCR_TAKEN)
            {
                if(id == nombre_array[index].scr_ID)
                {
                    retorno = index;
                    break;
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
//             ----> CARGA, MODIFICACION Y BAJA DE DATOS    <-----            //
////////////////////////////////////////////////////////////////////////////////
int scr_loadData (sScreen* nombre_array, int length, int data1, char* data2, char* data3, float data4)
{
    int retorno = -1;
    int scr_ID;
    int index = 0;

    if(nombre_array != NULL && length > 0)
    {
        index = scr_searchEmptySlot(nombre_array, length);
        if(index != -1)
        {
            scr_ID = scr_generateID(nombre_array, length);
            if(scr_ID != 0)
            {
                nombre_array[index].scr_slot = SCR_TAKEN;
                nombre_array[index].scr_ID   = scr_ID;

                nombre_array[index].scr_type = data1;
                strncpy(nombre_array[index].name, data2, MAX_CHARS_NOMBRES);
                strncpy(nombre_array[index].adress, data3, MAX_CHARS_DIRECCIONES);
                        nombre_array[index].price = data4;

                retorno = 0;
            }
        }
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////
int scr_modifyData (sScreen* nombre_array, int length, int id, int data1, char* data2, char* data3, float data4)
{
    int retorno = -1;
    int index;

    if(nombre_array != NULL && length > 0)
    {
        index = asoc_searchIndexById(nombre_array, length, id);
        if(index != -1)
        {
            strncpy(nombre_array[index].nombre, data1, MAX_CHARS_NOMBRES);   //strncpy((nombre_array +index)->nombre, auxData1, MAX_CHARS_NOMBRES);
            strncpy(nombre_array[index].apellido, data2, MAX_CHARS_NOMBRES); //strncpy((nombre_array +index)->apellido, auxData1, MAX_CHARS_NOMBRES);
            nombre_array[index].edad = data4;                                //strncpy((nombre_array +index)->edad = auxData1;
            strncpy(nombre_array[index].dni, data3, MAX_CHARS_DNI);          //strncpy((nombre_array +index)->dni, auxData1, MAX_CHARS_DNI);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
//int asoc_downData (sScreen* nombre_array, int index)
//{
//    int retorno = -1;
//
//    if(nombre_array != NULL && index >= 0)
//    {
//        nombre_array[index].asoc_slot = ASOC_DOWN;
//        retorno = 0;
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////////
////        ---->  GRAFICOS, CALCULOS E IMPRESION DE RESULTADOS  <-----         //
//////////////////////////////////////////////////////////////////////////////////
//static char slot[3][20] = {"ASOC_EMPTY", "ASOC_TAKEN", "ASOC_DOWN"};
//int asoc_printData (sScreen* nombre_array, int index)
//{
//    int retorno;
//	printf("\n --------------------------------------------\n");
//	printf("// ID Asociado: %d\t", nombre_array[index].asoc_ID);
//	printf("Estado:  %s//\n\n", slot[ nombre_array[index].asoc_slot ]);
//
//	printf("   Nombre:   %s\n", nombre_array[index].nombre);
//    printf("   Apellido: %s\n", nombre_array[index].apellido);
//	printf("   Edad:     %d\n", nombre_array[index].edad);
//	printf("   DNI:      %s\n", nombre_array[index].dni);
//    printf(" -------------------------------------------");
//
//
//	printf("\n");
//	retorno = 0;
//	return retorno;
//}
/////////////////////////////////////////////////////////////////////////////////
