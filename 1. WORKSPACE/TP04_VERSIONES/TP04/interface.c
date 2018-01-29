#include <stdio.h>
#include <stdlib.h>

#include "inputs.h"
#include "controller.h"

void intr_menu (void)
{
    int  opcion, i;
    char menu[14][100] = {
    "**********************************************************",
    "**         CLIENT MANAGER:  Lomas Social Club           **",
    "**********************************************************",
    "*|     AGENDA CLIENTES    |    |    GESTOR COMERCIAL    |*",
    "*|                                                      |*",
    "*|  1. Nuevo Socio.                                     |*",
    "*|                                                      |*",
    "*|  2. Modificacion                                     |*",
    "*|     Datos Asociados.                                 |*",
    "*|                                                      |*",
    "*|  3. Baja de Asociados.                               |*",
    "*|                                                      |*",
    "*|                                           4. Salir.  |*",
    "**********************************************************",
    };


    do
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<14; i++)
        printf("   %s\n", menu[i]);
        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 4. **\n", 3, 1, 4, &opcion);

        switch(opcion)
        {
            //ALTA DE ASOCIADO
            case 1:
                ctrl_newAffiliate();
                break;

            //MODIFICACION DE DATOS
            case 2:
                //ctrl_modifyScreen (pantallas, STOCK_PANTALLAS);
                break;

            //BAJA DE ASOCIADO
            case 3:
                //ctrl_downScreen (pantallas, STOCK_PANTALLAS);
                break;

            //SALIR
            case 4:
                system("pause");
                break;

            default:
                opcion = 11;
                break;
        }

    }while(opcion != 11);
}


