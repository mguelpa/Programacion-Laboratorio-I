#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "contrataciones.h"



//static int rent_searchEmptySlot (sRental* nombre_array, int length);
//static int rent_generateID (sRental* Nombre_array, int length);
////______________________________________________________________________________
//
//
//////////////////////////////////////////////////////////////////////////////////
//static int rent_searchEmptySlot (sRental* nombre_array, int length)
//{
//    int retorno = -1;
//    int index;
//
//    if(nombre_array != NULL && length > 0){
//
//        for(index = 0; index < length; index++)
//        {
//            if(nombre_array[index].rent_slot == CALL_EMPTY){
//                retorno =  index;
//                break;
//            }
//        }
//    }
//    return retorno;
//}
/////////////////////////////////////////////////////////////////////////////////
//static int rent_generateID (sRental* nombre_array, int length)
//{
//    int nextID = 1;
//    int i;
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(i=0; i<length; i++)
//        {
//            if(nombre_array[i].rent_slot == CALL_TAKEN)
//            {
//                if(nombre_array[i].call_ID >= nextID){
//                   nextID = nombre_array[i].call_ID + 1;
//                }
//            }
//        }
//    }
//    return nextID;
//}
//////////////////////////////////////////////////////////////////////////////////
//int rent_arrayInit (sRental* nombre_array, int length)
//{
//    int retorno = -1;
//    int i;
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(i=0; i<length; i++)
//        {
//            nombre_array[i].rent_slot = CALL_EMPTY;
//            nombre_array[i].rent_ID   = CALL_EMPTY;
//            nombre_array[i].asoc_ID   = CALL_EMPTY;
//
//            nombre_array[i].incident_status = CALL_EMPTY;
//            nombre_array[i].incident_cause  = CALL_EMPTY;
//
//            nombre_array[i].incident_startLapse = CALL_EMPTY;
//            nombre_array[i].incident_finalLapse = CALL_EMPTY;
//            retorno = 0;
//        }
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//int call_searchIndexById (sRental* nombre_array, int length, int id)
//{
//    int retorno = -1;
//    int index;
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(index = 0; index < length; index++)
//        {
//            if(nombre_array[index].call_slot == CALL_TAKEN)
//            {
//                if(id == nombre_array[index].call_ID)
//                {
//                    retorno = index;
//                    break;
//                }
//            }
//        }
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
////             ----> CARGA, MODIFICACION Y BAJA DE DATOS    <-----            //
//////////////////////////////////////////////////////////////////////////////////
//int call_loadCall (sRental* nombre_array, int length, int asoc_ID, int data1, int data2)
//{
//    int retorno = -1;
//
//    int call_ID;
//    int index;
//
//    if(nombre_array != NULL && length > 0)
//    {
//
//        index = call_searchEmptySlot(nombre_array, length);
//        if(index != -1)
//        {
//            call_ID = call_generateID(nombre_array, length);
//            if(call_ID != 0)
//            {
//                nombre_array[index].call_slot            = CALL_TAKEN;
//                nombre_array[index].incident_status      = INCIDENT_INCOURSE;
//                nombre_array[index].call_ID              = call_ID;
//
//                nombre_array[index].asoc_ID              = asoc_ID;
//                nombre_array[index].incident_cause       = data1;
//                nombre_array[index].incident_startLapse  = data2;
//
//                retorno = 0;
//            }
//        }
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//int call_downCall (sRental* nombre_array, int index, int data1, int data2)
//{
//    int retorno = -1;
//
//    if(nombre_array != NULL && index >= 0)
//    {
//        nombre_array[index].call_slot           = CALL_ENDED;
//        nombre_array[index].incident_status     = data1;
//
//
//        nombre_array[index].incident_finalLapse = data2;
//
//        retorno = 0;
//    }
//    return retorno;
//}
/////////////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////////////
////        ---->  GRAFICOS, CALCULOS E IMPRESION DE RESULTADOS  <-----         //
//////////////////////////////////////////////////////////////////////////////////
//static char estadoLlamada[3][20]   = {"CALL_EMPTY", "CALL_TAKEN", "CALL_ENDED"};
//static char estadoIncidente[4][20] = {"INCIDENT_EMPTY", "INCIDENT_INCOURSE", "INCIDENT_SOLVED", "INCIDENT_UNSOLVED"};
//static char motivoIncidente[3][20] = {"CAUSE_ACV", "CAUSE_INFARTO", "CAUSE_GRIPE"};
//int call_printData (sLLamados* nombre_array, int index)
//{
//    int retorno;
//    printf("\n -------------------------------------------\n");
//	printf("// ID LLamada:   %d\t",     nombre_array[index].call_ID);
//	printf("Estado LLamada:  %s//\n\n", estadoLlamada[nombre_array[index].call_slot] );
//
//    printf("   ID Asociado:      %d\n\n", nombre_array[index].asoc_ID);
//
//	printf("   Estado incidente: %s\n",   estadoIncidente[nombre_array[index].incident_status] );
//    printf("   Motivo incidente: %s\n\n", motivoIncidente[nombre_array[index].incident_cause] );
//
//	printf("   hora inicial:     %d\n",   nombre_array[index].incident_startLapse);
//	printf("   hora final:       %d\n",   nombre_array[index].incident_finalLapse);
//	printf("\n");
//	retorno = 0;
//	return retorno;
//}
/////////////////////////////////////////////////////////////////////////////////
