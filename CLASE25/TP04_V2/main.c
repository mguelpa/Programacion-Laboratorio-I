#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "controller.h"
#include "inputs.h"


int main()
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

    //DECLARO EL ARRAY Y LO INICIALIZO.
    ArrayList* listaAsociados;
        listaAsociados = al_newArrayList();

    do
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<14; i++)
        printf("   %s\n", menu[i]);

        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 4. **\n", 3, 1, 5, &opcion);
        switch(opcion)
        {
            //ALTA DE ASOCIADO
            case 1:
                ctrl_newAffiliate(listaAsociados);
                system("pause");
                system("cls");
                break;

            //MODIFICACION DE DATOS
            case 2:
                ctrl_modifyAffiliate(listaAsociados);
                system("pause");
                system("cls");
                break;

            //BAJA DE ASOCIADO
            case 3:
                ctrl_downAffiliate (listaAsociados);
                system("pause");
                system("cls");
                break;

            //SALIR
            case 4:
                opcion = 11;
                break;

            //SALIR
            case 5:
                al_debugShow(listaAsociados);
                printf("________________________________\n\n");
                for(i=0; i<listaAsociados->size; i++)
                {
                    ctrl_debugShow(*(listaAsociados->pElements+i));
                }
                break;

            default:
                opcion = 11;
                break;
        }

    }while(opcion != 11);

    return 0;
}
