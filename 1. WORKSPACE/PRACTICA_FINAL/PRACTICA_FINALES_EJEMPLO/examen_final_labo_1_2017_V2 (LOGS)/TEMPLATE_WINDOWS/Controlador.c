#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

#include "LogEntry.h"
#include "Service.h"

////////////////////////////////////////
//static ArrayList* listaX;
//static int proximoIdX=0;
//static int getNewIdX();
//static int setNewIdX(int id);

static ArrayList* listaLogEntrys;
static ArrayList* listaServices;

void cont_init()
{
//    listaX = al_newArrayList();
//    setNewIdX(dm_readAllX(listaX) + 1);

    listaLogEntrys = al_newArrayList();
    listaServices = al_newArrayList();
    vista_mostrarMenu();
}



////////////////////////////////////////
// para cada entidad                  //
////////////////////////////////////////
//static int getNewIdX()
//{
//    return proximoIdX++;
//}
//static int setNewIdX(int id)
//{
//    proximoIdX = id;
//    return 0;
//}
//
//int cont_altaX (char* a,char* b,int c)
//{
//    return 0;
//}
//int cont_bajaX (int id)
//{
//    return 0;
//}
//int cont_modificarX (int id, char* a,char* b,int c)
//{
//    return 0;
//}
//
//
//int cont_listarX ()
//{
//    //vista_mostrarX(nominaX);
//    return 0;
//}
//int cont_ordenarX ()
//{
//    return 0;
//}
////////////////////////////////////////


////////////////////////////////////////
// ENTIDAD LOGENTRYS                  //
////////////////////////////////////////
int cont_altaLogEntry ()
{
    dm_readAllLogEntry(listaLogEntrys);
    int i;
    LogEntry* aux;
    for(i=0; i<al_len(listaLogEntrys); i++)
    {
        aux = al_get(listaLogEntrys, i);
        printf("date: %s\n", logEntry_getDate(aux));
    }

    return 0;
}
////////////////////////////////////////
// ENTIDAD SERVICES                   //
////////////////////////////////////////
int cont_altaService ()
{
    dm_readAllService(listaServices);
    int i;
    Service* aux;
    for(i=0; i<al_len(listaServices); i++)
    {
        aux = al_get(listaServices, i);
        printf("serviceID: %d\n", service_getId(aux));
    }
    return 0;
}
////////////////////////////////////////


int cont_procesarInformacion()
{
    int i, j;
    LogEntry* auxiliar;
    Service* auxiliar2;


    for(i=0; i<al_len(listaLogEntrys); i++)
    {
        auxiliar = al_get(listaLogEntrys, i);
        if(auxiliar!=NULL && logEntry_getGravedad(auxiliar) == 3 && logEntry_getServiceID(auxiliar) != 45)
        {
            for(j=0; j<al_len(listaServices); j++)
            {
                auxiliar2 = al_get(listaServices, j);
                if(auxiliar2!=NULL && service_getId(auxiliar2) == logEntry_getServiceID(auxiliar))
                {
                    dm_saveWarnings(auxiliar, auxiliar2);
                }
            }
        }
        if(logEntry_getGravedad(auxiliar) > 3 && logEntry_getGravedad(auxiliar) < 8)
        {
            for(j=0; j<al_len(listaServices); j++)
            {
                auxiliar2 = al_get(listaServices, j);
                if(auxiliar2!=NULL && service_getId(auxiliar2) == logEntry_getServiceID(auxiliar))
                {
                    printf("fecha: %s\n", logEntry_getDate(auxiliar));
                    printf("hora: %s\n", logEntry_getTime(auxiliar));
                    printf("nombre de servicio: %s\n", service_getName(auxiliar2));
                    printf("mensaje de error: %s\n", logEntry_getMsg(auxiliar));
                    printf("gravedad: %d\n", logEntry_getGravedad(auxiliar));
                    printf("---------------------------------------------------\n\n");
                }
            }
        }
        if(logEntry_getGravedad(auxiliar) > 7)
        {
            for(j=0; j<al_len(listaServices); j++)
            {
                auxiliar2 = al_get(listaServices, j);
                if(auxiliar2!=NULL && service_getId(auxiliar2) == logEntry_getServiceID(auxiliar))
                {
                    dm_saveErrorMsg(auxiliar, auxiliar2);
                }
            }
        }
    }
    return 0;
}
int cont_servicioConMasFallos()
{
    int i, j, k= 0;
    int flag = 0;

    LogEntry* auxLogEntry;

    int contadorFallos[al_len(listaLogEntrys)];
    int idsDeFallos[al_len(listaLogEntrys)];

    for(i=0; i<al_len(listaLogEntrys); i++)
    {
        contadorFallos[i] = 0;
        idsDeFallos[i] = 0;
    }

    for(i=0; i<al_len(listaLogEntrys); i++)
    {
        flag = 0;
        auxLogEntry = al_get(listaLogEntrys, i);
        for(j= 0; j<al_len(listaLogEntrys); j++)
        {
            if(idsDeFallos[j] == logEntry_getServiceID(auxLogEntry))
            {
                contadorFallos[j]++;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            idsDeFallos[k] = logEntry_getServiceID(auxLogEntry);
            contadorFallos[k]++;
            k++;
        }
    }

    for(i=0; i<al_len(listaLogEntrys); i++)
    {
        if(contadorFallos[i] > 0)
        {
            printf("service ID : %d - fallos: %d\n", idsDeFallos[i], contadorFallos[i]);
        }
    }
    return 0;
}
