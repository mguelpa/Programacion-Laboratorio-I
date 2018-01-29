#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

//static void opcionAltaX();
//static void opcionBajaX();
//static void opcionModificacionX();
//
//static void opcionListadoX();
//static void opcionOrdenarX();
//////////////////////////////////////////////////

static void opcionleerLog();
static void opcionProcesarInformacion();
static void opcionMostrarEstadisticas();


int vista_mostrarMenu()
{
    int option=0;

    while(option != 5)
    {
        input_getInt(MENU_PPAL_ES, MENU_PPAL_ERROR_ES, 3, 1, 5, &option);
        switch(option)
        {
            case 1:
                // LEER LOG
                opcionleerLog();
                break;
            case 2:
                // PROCESAR INFO
                opcionProcesarInformacion();
                break;
            case 3:
                // MOSTRAR ESTADISTICAS
                opcionMostrarEstadisticas();
                break;
            case 4:
                option = 5;
                break;
        }
    }
    return 0;
}
//////////////////////////////////////////////////
//static void opcionAltaX()
//{
//    char a[50];
//    char b[50];
//    char c[50];
//
//    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//       val_getString(b, "B? ", "Error",2,50) == 0 &&
//       val_getInt(c, "C? ", "Error",2,50) == 0)
//    {
//        cont_altaX(a,b,atoi(c));
//    }
//}
//static void opcionBajaX()
//{
//    char auxId[10];
//    int id;
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        cont_bajaX(id);
//    }
//}
//static void opcionModificacionX()
//{
//    char auxId[10];
//    int id;
//    char a[50];
//    char b[50];
//    char c[50];
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//           val_getString(b, "B? ", "Error",2,50) == 0 &&
//           val_getInt(c, "C? ", "Error",2,50) == 0)
//        {
//            cont_modificarX(id,a,b,atoi(c));
//        }
//    }
//}
//static void opcionListadoX()
//{
//    cont_listarX();
//}
//static void opcionOrdenarX()
//{
//    cont_ordenarX();
//}
//void vista_mostrarX(ArrayList* pListaX)
//{
//    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");
//}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
static void opcionleerLog()
{
    cont_altaLogEntry();
    cont_altaService();
}
static void opcionProcesarInformacion()
{
    cont_procesarInformacion();
}
static void opcionMostrarEstadisticas()
{
    cont_servicioConMasFallos();
}
//////////////////////////////////////////////////


