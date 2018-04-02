#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "interface.h"

#include "pantallas.h"
#include "contrataciones.h"


 ////////////////////////////////////////////////////////////////////////////////
 int command_upScreen (sScreen* nombre_array, int length)
 {
     int retorno = -1;
     char respuesta = 'n';
     int i = 0;

     int auxData1;                          // scr_type
     char auxData2[MAX_CHARS_NOMBRES];      // name
     char auxData3[MAX_CHARS_DIRECCIONES];  // adress
     float auxData4 = 0;                    // price
   //sNombre_struct nombre_datostruct;


     if(nombre_array != NULL && length > 0)
     {
         do
         {
             system("cls");
             printf("  ------------------------\n");
             printf(" //   ALTA DE PANTALLA  //\n");
             printf(" ------------------------\n\n");


            if(interface_getInt ("\tIngrese el tipo de pantalla: \n1. LCD\n2. LED", "ha ingresado caracteres invalidos.\n", "opciones 1 o 2.\n", MAX_INTENTOS_REINGRESOS, 1, 2, &auxData1) == 0)
            {
                if(interface_getAlfaNumericNames ("\tIngrese el nombre de la pantalla: ", "Ha ingresado caracteres no validos, intente nuevamente.\n", "el nombre no puede poseer mas de 20 caracteres.\n", 3, 1, 50, auxData2) == 0)
                {
                    if(interface_getAlfaNumericNames ("\tIngrese direccion de la ubicacion de la pantalla pantalla: ", "Ha ingresado caracteres no validos, intente nuevamente.\n", "el apellido no puede poseer mas de 20 caracteres.\n", MAX_INTENTOS_REINGRESOS, 1, MAX_CHARS_NOMBRES, auxData3) == 0)
                    {
                         if(interface_getFloat("ingrese el preciode la pantalla", "caracteres invalidos", "el precio minimo de la publicacion es 500", 3, 500, 10000, &auxData4) == 0)
                         {
                             scr_loadData(nombre_array, length, auxData1, auxData2, auxData3, auxData4);
                             retorno = 0;
                         }//printf("ErrorMsg: supero cantidad de intentos DNI\n");
                     }//printf("ErrorMsg: supero cantidad de intentos edad\n");
                 }//printf("ErrorMsg: supero cantidad de intentos apellido\n");
             }//printf("ErrorMsg: supero cantidad de intentos nombre\n");
             if(retorno == -1){
                 printf("\n     Error al completar los campos.\n ---> no se han guardado los datos <---\n\n\a");
             }
             interface_continuar("\n\tdesea agregar otro asociado? S/N: ", "Ha ingresado una opcion no valida. \nintente nuevamente: ", 3, &respuesta);
             i++;
         } while (respuesta != 'n' && i < length);
     }
     return retorno;
 }
 //////////////////////////////////////////////////////////////////////////////
 int command_modifyAsoc (sScreen* nombre_array, int length)
 {
     int retorno = -1;

     int  id;
     int  index;

     int auxData1;                          // scr_type
     char auxData2[MAX_CHARS_NOMBRES];      // name
     char auxData3[MAX_CHARS_DIRECCIONES];  // adress
     float auxData4 = 0;                    // price
   //sNombre_struct nombre_datostruct;

     if(nombre_array != NULL && length > 0)
     {
         if(interface_getInt("Ingrese el ID de la pantalla: ", "ha ingresado caracteres invalidos.\n", "fuera de rango.\n", MAX_INTENTOS_REINGRESOS, 1, 99999, &id) == 0)
         {
             index = scr_searchIndexById(nombre_array, length, id);
             if(index != -1)
             {
                if(interface_getInt ("\tIngrese el tipo de pantalla: \n1. LCD\n2. LED", "ha ingresado caracteres invalidos.\n", "opciones 1 o 2.\n", MAX_INTENTOS_REINGRESOS, 1, 2, &auxData1) == 0)
                {
                    if(interface_getAlfaNumericNames ("\tIngrese el nombre de la pantalla: ", "Ha ingresado caracteres no validos, intente nuevamente.\n", "el nombre no puede poseer mas de 20 caracteres.\n", 3, 1, 50, auxData2) == 0)
                    {
                        if(interface_getAlfaNumericNames ("\tIngrese direccion de la ubicacion de la pantalla pantalla: ", "Ha ingresado caracteres no validos, intente nuevamente.\n", "el apellido no puede poseer mas de 20 caracteres.\n", MAX_INTENTOS_REINGRESOS, 1, MAX_CHARS_NOMBRES, auxData3) == 0)
                        {
                             if(interface_getFloat("ingrese el preciode la pantalla", "caracteres invalidos", "el precio minimo de la publicacion es 500", 3, 500, 10000, &auxData4) == 0)
                             {
                                 scr_modifyData(nombre_array, length, id, auxData1, auxData2, auxData3, auxData4);
                             }
                         }
                     }
                 }
             }else{printf("El ID ingresado no corresponde a ningun asociado\n");}
         }
     }
     return retorno;
 }
 ////////////////////////////////////////////////////////////////////////////////
// int command_downAsoc (sAsociados* nombre_array, int length)
// {
//     int retorno = -1;
//     int index = -1;
//     int id = 0;

//     if(nombre_array != NULL && length > 0)
//     {
//         if(interface_getInt("Ingrese el ID del asociado: ", "ha ingresado caracteres invalidos.\n", "fuera de rango.\n", MAX_INTENTOS_REINGRESOS, 1, 99999, &id) == 0)
//         {
//             index = asoc_searchIndexById(nombre_array, length, id);
//             if(index != -1)
//             {
//                 asoc_downData(nombre_array, index);
//             }
//             else{
//                 printf("El ID ingresado no corresponde a ningun asociado\n");
//             }
//         }
//     }
//     return retorno;
// }
//////////////////////////////////////////////////////////////////////////////////
//int command_newCall (sAsociados* nombre_array1, int length1, sLLamados* nombre_array2, int length2)
//{
//    int retorno = -1;
//
//    int asoc_ID, index;
//    int auxData1; // cause;
//    int auxData2; // startLapse;
//  //sNombre_struct nombre_datostruct;
//
//    system("cls");
//    printf("  ---------------------------\n");
//    printf(" //  REGISTRO DE LLAMADAS  //\n");
//    printf(" ---------------------------\n\n");
//
//    if(interface_getInt("\tIngrese el ID del asociado: ", "ha ingresado caracteres invalidos.\n", "ID fuera de rango.\n", MAX_INTENTOS_REINGRESOS, 1, 9999, &asoc_ID) == 0)
//    {
//        index = asoc_searchIndexById(nombre_array1, length1, asoc_ID);
//        if(index != -1)
//        {
//            if(interface_getInt("\n\tSeleccone un motivo: \n\t1. ACV. \t 2. Infarto. \t3. Gripe.\n\topcion: ", "ha ingresado caracteres invalidos.\n", "opciones 1, 2 o 3.\n", MAX_INTENTOS_REINGRESOS, 1, 3, &auxData1) == 0)
//            {
//                if(interface_getInt("\n\tHora de llamada (minutos): ", "ha ingresado caracteres invalidos.\n", "opciones 1, 2 o 3.\n", MAX_INTENTOS_REINGRESOS, 1, 120, &auxData2) == 0)
//                {
//                    call_loadCall(nombre_array2, length2, asoc_ID, auxData1, auxData2);
//                    retorno = 0;
//                }
//            }
//        }
//        else{
//            printf("El ID ingresado no corresponde a ningun asociado\n");
//        }
//
//        if(retorno == -1){
//            printf("\n     Error al completar los campos.\n ---> no se han guardado los datos <---\n\n\a");
//        }
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//int command_endCall (sLLamados* nombre_array, int length)
//{
//    int retorno = -1;
//
//    int call_ID;
//    int index;
//
//    int auxData1;// incident_Status;
//    int auxData2;// time;
//
//    if(interface_getInt("Ingrese el ID de la llamada: ", "ha ingresado caracteres invalidos.\n", "ID fuera de rango.\n", MAX_INTENTOS_REINGRESOS, 1, 9999, &call_ID) == 0)
//    {
//        index = call_searchIndexById(nombre_array, length, call_ID);
//        if(index != -1)
//        {
//            if(nombre_array[index].incident_status == INCIDENT_INCOURSE)
//            {
//                if(interface_getInt("Estado de Cierre:\n  Resuelto [1]\n  No Resuelto [2]\n\n Opcion:  ", "ha ingresado caracteres invalidos.\n", "opciones 1, 2 o 3.\n", MAX_INTENTOS_REINGRESOS, 1, 2, &auxData1) == 0)
//                {
//                    if(interface_getInt("Tiempo insumido (minutos): ", "ha ingresado caracteres invalidos.\n", "opciones 1, 2 o 3.\n", MAX_INTENTOS_REINGRESOS, 1, 120, &auxData2) == 0)
//                    {
//                        call_downCall(nombre_array, index, auxData1, auxData2);
//                        retorno = 0;
//                    }//printf("ErrorMsg: supero cantidad de intentos DNI\n");
//                }
//
//            }else{printf("Aun no hay llamadas pedintes.\n");}
//
//        }else{printf("El ID ingresado no corresponde a ninguna llamada.\n");}
//
//        if(retorno == -1){
//            printf("\n     Error al completar los campos.\n ---> no se han guardado los datos <---\n\n\a");
//        }
//    }
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//int command_listCalls (sLLamados* nombre_array, int length)
//{
//    int index;
//    int retorno = -1;
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(index = 0; index<length; index++)
//        {
//            if(nombre_array[index].call_slot == CALL_TAKEN)
//            {
//                call_printData (nombre_array, index);
//            }
//        }
//    }else{retorno = -2;}
//
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//int command_listAsocs (sAsociados* nombre_array, int length)
//{
//    int index;
//    int retorno = -1;
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(index = 0; index<length; index++)
//        {
//            if(nombre_array[index].asoc_slot == ASOC_TAKEN)
//            {
//                asoc_printData (nombre_array, index);
//            }
//        }
//    }else{retorno = -2;}
//
//    return retorno;
//}
//////////////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////////////
////        ---->  GRAFICOS, CALCULOS E IMPRESION DE RESULTADOS  <-----         //
//////////////////////////////////////////////////////////////////////////////////
//int command_asocMasIncidentes (sAsociados* nombre_array1, int length1, sLLamados* nombre_array2, int length2)
//{
//    int retorno = -1;
//
//    int asoc = length1 +1;
//    int contadorLLamados[asoc];
//    int asociadoConMasLLamados = 1;
//    int asocID, j;
//
//
//    if(nombre_array1 != NULL && length1 > 0 && nombre_array2 != NULL && length2 > 0)
//    {
//        //inicializo contador de llamados
//        for(asocID = 1; asocID<asoc; asocID++)
//        {
//            contadorLLamados[asocID] = 0;
//            printf("\tcontadorLLamados[%02d] = %d\n", asocID, contadorLLamados[asocID]);
//
//        }printf("\n");
//
//
//        //busco en erray de llamados las llamadas tomadas y elevo en el contados de llamados indice que corresponde al id de asoc
//        for(asocID = 1; asocID<asoc; asocID++)
//        {
//            for(j = 0; j<length2; j++)
//            {
//                if(nombre_array2[j].call_slot == CALL_TAKEN && nombre_array2[j].asoc_ID == asocID)
//                {
//                    contadorLLamados[ nombre_array2[j].asoc_ID ]++;
//                }
//            }printf("\tcontadorLLamados[%02d] = %d\n", asocID, contadorLLamados[asocID]);
//        }printf("\n");
//
//
//        //busco en erray de llamados indice con mas llamadas que corresponde al id de asoc
//        for(asocID = 1; asocID<asoc; asocID++)
//        {
//            if(contadorLLamados[asocID] > contadorLLamados[asociadoConMasLLamados])
//            {
//                asociadoConMasLLamados = asocID;
//            }
//        }printf("\tasociadoConMasLLamados = %d\n", asociadoConMasLLamados);
//
//
//        //busco en erray de llamados indice con mas llamadas que corresponde al id de asoc
//        printf("\n\t*************************************************************\n");
//        printf("\t*                ASOCIADO CON MAS INCIDENTES                *\n");
//        printf("\t*************************************************************\n");
//        for(asocID = 1; asocID<asoc; asocID++)
//        {
//            if(contadorLLamados[asocID] == contadorLLamados[asociadoConMasLLamados])
//            {
//                asoc_printData(nombre_array1, asoc_searchIndexById(nombre_array1, length1, asocID));
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
/////////////////////////////////////////////////////////////////////////////////
//static char motivoLlamada[3][20] = {"CAUSE_ACV", "CAUSE_INFARTO", "CAUSE_GRIPE"};
////static char estadoLlamada[4][20] = {"INCIDENT_EMPTY", "INCIDENT_INCOURSE", "INCIDENT_SOLVED", "INCIDENT_UNSOLVED"};
//
//int command_incidenteQueMasTardaEnResolverse (sLLamados* nombre_array, int length)
//{
//    int retorno = -1;
//    int i;
//
//    int incidenteMasFrecuente = 0;
//    int incidenteQueMasTardaEnResolverse = 0;
//
//    int   acum_motivos   [3];
//    int   acum_tiempos   [3];
//    float acum_promedios [3];
//
//    for(i=0; i<3; i++)
//    {
//        acum_motivos   [i] = 0;
//        acum_tiempos   [i] = 0;
//        acum_promedios [i] = 0;
//    }
//
//    if(nombre_array != NULL && length > 0)
//    {
//        for(i=0; i<length; i++)
//        {
//            if( (nombre_array[i].call_slot == CALL_ENDED) && (nombre_array[i].incident_status == INCIDENT_SOLVED) )
//            {
//                acum_motivos[ nombre_array[i].incident_cause ]++;
//                acum_tiempos[ nombre_array[i].incident_cause ] = acum_tiempos[ nombre_array[i].incident_cause ] + nombre_array[i].incident_finalLapse;
//            }
//        }
//
//
//        printf("\t*************************************************************\n");
//        printf("\t**************** SOLO INCIDENTES FINALIZADOS ****************\n");
//        printf("\t*************************************************************\n");
//        printf("\t%15s - %8s - %8s- %11s\n", "Tipo incidente", "Cantidad", "Tiempo", "Promedio");
//
//        for(i=0; i<3; i++)
//        {
//            acum_promedios[i] = (float)acum_tiempos[i] / (float)acum_motivos[i];
//
//
//
//            if(acum_motivos[i] >= acum_motivos [ incidenteMasFrecuente ]){
//                incidenteMasFrecuente = i;
//            }
//
//            if(acum_promedios[i] >= acum_promedios[ incidenteQueMasTardaEnResolverse ] && acum_motivos[i] >= acum_motivos [ incidenteMasFrecuente ]){
//                incidenteQueMasTardaEnResolverse = i;
//            }
//
//            printf("\t%15s - %8d - %8d - %8.2f\n", motivoLlamada[i], acum_motivos[i], acum_tiempos[i], acum_promedios[i]);
//        }
//
//
//        printf("\tReclamo con mayor ocurrencia: %s\n", motivoLlamada[ incidenteMasFrecuente ]);
//        printf("\tReclamo que mas demora en ser atendido: %s\n", motivoLlamada[ incidenteQueMasTardaEnResolverse ]);
//
//        retorno = 0;
//    }
//    return retorno;
//
//}
//////////////////////////////////////////////////////////////////////////////////
//void command_rageAgainstTheMachine (sAsociados* nombre_array1, int length1, sLLamados* nombre_array2, int length2)
//{
/////////////////////////////////////////////////////////////////////
////                     /* ASOCIADO 1 */                          //
/////////////////////////////////////////////////////////////////////
//        nombre_array1[0].asoc_slot = ASOC_TAKEN;
//        nombre_array1[0].asoc_ID   = 1;
//
//strcpy (nombre_array1[0].nombre,    "Max");
//strcpy (nombre_array1[0].apellido,  "Max");
//strcpy (nombre_array1[0].dni,       "35340965");
//        nombre_array1[0].edad      = 27;
//
//
//            /* LLAMADA 1 */
//            nombre_array2[0].call_slot = CALL_TAKEN;
//            nombre_array2[0].call_ID = 1;
//            nombre_array2[0].asoc_ID = 1;
//            nombre_array2[0].incident_status = INCIDENT_INCOURSE;
//            nombre_array2[0].incident_cause = CAUSE_ACV;
//            nombre_array2[0].incident_startLapse = 00;
//            nombre_array2[0].incident_finalLapse = 20;
//            /* LLAMADA 2 */
//            nombre_array2[1].call_slot = CALL_ENDED;
//            nombre_array2[1].call_ID = 2;
//            nombre_array2[1].asoc_ID = 1;
//            nombre_array2[1].incident_status = INCIDENT_SOLVED;
//            nombre_array2[1].incident_cause = CAUSE_GRIPE;
//            nombre_array2[1].incident_startLapse = 00;
//            nombre_array2[1].incident_finalLapse = 30;
//            /* LLAMADA 3 */
//            nombre_array2[2].call_slot = CALL_TAKEN;
//            nombre_array2[2].call_ID = 3;
//            nombre_array2[2].asoc_ID = 1;
//            nombre_array2[2].incident_status = INCIDENT_UNSOLVED;
//            nombre_array2[2].incident_cause = CAUSE_ACV;
//            nombre_array2[2].incident_startLapse = 00;
//            nombre_array2[2].incident_finalLapse = 20;
///////////////////////////////////////////////////////////////////
//                     /* ASOCIADO 2 */                          //
///////////////////////////////////////////////////////////////////
//        nombre_array1[1].asoc_slot = ASOC_TAKEN;
//        nombre_array1[1].asoc_ID   = 2;
//
//strcpy (nombre_array1[1].nombre,    "ale");
//strcpy (nombre_array1[1].apellido,  "ale");
//strcpy (nombre_array1[1].dni,       "35340965");
//        nombre_array1[1].edad      = 27;
//
//
//            /* LLAMADA 1 */
//            nombre_array2[3].call_slot = CALL_TAKEN;
//            nombre_array2[3].call_ID = 4;
//            nombre_array2[3].asoc_ID = 2;
//            nombre_array2[3].incident_status = INCIDENT_INCOURSE;
//            nombre_array2[3].incident_cause = CAUSE_ACV;
//            nombre_array2[3].incident_startLapse = 00;
//            nombre_array2[3].incident_finalLapse = 45;
//            /* LLAMADA 2 */
//            nombre_array2[4].call_slot = CALL_ENDED;
//            nombre_array2[4].call_ID = 5;
//            nombre_array2[4].asoc_ID = 2;
//            nombre_array2[4].incident_status = INCIDENT_SOLVED;
//            nombre_array2[4].incident_cause = CAUSE_GRIPE;
//            nombre_array2[4].incident_startLapse = 0;
//            nombre_array2[4].incident_finalLapse = 50;
//            /* LLAMADA 3 */
//            nombre_array2[5].call_slot = CALL_TAKEN;
//            nombre_array2[5].call_ID = 6;
//            nombre_array2[5].asoc_ID = 2;
//            nombre_array2[5].incident_status = INCIDENT_INCOURSE;
//            nombre_array2[5].incident_cause = CAUSE_GRIPE;
//            nombre_array2[5].incident_startLapse = 00;
//            nombre_array2[5].incident_finalLapse = 10;
///////////////////////////////////////////////////////////////////
//                     /* ASOCIADO 3 */                          //
///////////////////////////////////////////////////////////////////
//        nombre_array1[2].asoc_slot = ASOC_TAKEN;
//        nombre_array1[2].asoc_ID   = 3;
//
//strcpy (nombre_array1[2].nombre,    "osc");
//strcpy (nombre_array1[2].apellido,  "osc");
//strcpy (nombre_array1[2].dni,       "35340965");
//        nombre_array1[2].edad      = 27;
//
//
//            /* LLAMADA 1 */
//            nombre_array2[6].call_slot = CALL_ENDED;
//            nombre_array2[6].call_ID = 7;
//            nombre_array2[6].asoc_ID = 3;
//            nombre_array2[6].incident_status = INCIDENT_SOLVED;
//            nombre_array2[6].incident_cause = CAUSE_GRIPE;
//            nombre_array2[6].incident_startLapse = 00;
//            nombre_array2[6].incident_finalLapse = 50;
//            /* LLAMADA 2 */
//            nombre_array2[7].call_slot = CALL_TAKEN;
//            nombre_array2[7].call_ID = 8;
//            nombre_array2[7].asoc_ID = 3;
//            nombre_array2[7].incident_status = INCIDENT_SOLVED;
//            nombre_array2[7].incident_cause = CAUSE_INFARTO;
//            nombre_array2[7].incident_startLapse = 00;
//            nombre_array2[7].incident_finalLapse = 50;
//            /* LLAMADA 3 */
//            nombre_array2[8].call_slot = CALL_TAKEN;
//            nombre_array2[8].call_ID = 9;
//            nombre_array2[8].asoc_ID = 3;
//            nombre_array2[8].incident_status = INCIDENT_UNSOLVED;
//            nombre_array2[8].incident_cause = CAUSE_GRIPE;
//            nombre_array2[8].incident_startLapse = 00;
//            nombre_array2[8].incident_finalLapse = 60;
//}
/////////////////////////////////////////////////////////////////////////////////
