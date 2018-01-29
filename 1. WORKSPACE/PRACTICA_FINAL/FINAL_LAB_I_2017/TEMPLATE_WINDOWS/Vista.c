#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static void opcionAltaX();
static void opcionBajaX();
static void opcionModificacionX();

static void opcionListadoX();
static void opcionOrdenarX();

int vista_mostrarMenu()
{
    int option=0;

    while(option != 6)
    {
        input_getInt(MENU_PPAL_ES, MENU_PPAL_ERROR_ES, 3, 1, 5, &option);
        switch(option)
        {
            case 1:
                opcionListadoX();
                break;
            case 2:
                opcionAltaX();
                break;
            case 3:
                opcionBajaX();
                break;
            case 4:
                opcionModificacionX();
                break;
            case 5:
                opcionOrdenarX();
                break;
///////////////////////////////////////////
//            case 6:
//                opcionListadoX();
//                break;
//            case 7:
//                opcionAltaX();
//                break;
//            case 8:
//                opcionBajaX();
//                break;
//            case 9:
//                opcionModificacionX();
//                break;
//            case 10:
//                opcionOrdenarX();
//                break;
        }
    }

    return 0;
}

static void opcionAltaX()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
       val_getString(b, "B? ", "Error",2,50) == 0 &&
       val_getInt(c, "C? ", "Error",2,50) == 0)
    {
        cont_altaX(a,b,atoi(c));
    }
}
static void opcionBajaX()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaX(id);
    }
}
static void opcionModificacionX()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarX(id,a,b,atoi(c));
        }
    }
}


static void opcionListadoX()
{
    cont_listarX();
}
static void opcionOrdenarX()
{
    cont_ordenarX();
}
void vista_mostrarX(ArrayList* pListaX)
{
    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");
}




