#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include "commands.h"

#define MAX_CANTIDAD_PANTALLAS 5
#define MAX_CANTIDAD_CONTRATACIONES 10

int main()
{
    //Se crea el array de abonados y se inicializa
    sScreen arrayPantallas[MAX_CANTIDAD_PANTALLAS];
        scr_arrayInit(arrayPantallas, MAX_CANTIDAD_PANTALLAS);

    //Se crea el array de Llamadas y se inicializa
    //sContratacion arrayContrataciones[MAX_CANTIDAD_INCIDENTES];
        //rental_arrayInit(arrayContrataciones, MAX_CANTIDAD_CONTRATACIONES);

    //Carga datos de test
    //command_rageAgainstTheMachine (adheridos, MAX_CANTIDAD_ADHERENTES, incidentes, MAX_CANTIDAD_INCIDENTES);


    int opcion;

    do
    {
        opcion = 0;
        //system("cls");
        printf("\t*************************************************************************************\n");
        printf("\t*                            EMERGENCIAS MEDICAS                                    *\n");
        printf("\t*************************************************************************************\n");
        printf("\t* 1- ALTA PANTALLA\t\t");          printf("4- CONTRATAR PUBLICIDAD\t\t");printf("6- INFORMES         *\n");
        printf("\t* 2- MODIFICAR DATOS PANTALLA\t"); printf("5- MODIFICAR CONDICIONES\t"); printf("7- LISTAR LLAMADAS  *\n");
        printf("\t* 3- BAJA DE PANTALLA\t\t\t\t\t\t");                                     printf("8- LISTAR ASOCIADOS *\n");
        printf("\t* 9- Salir                                                                          *\n");
        printf("\t*************************************************************************************\n");
        interface_getInt("\tIngrese una opcion: ", "ha ingresado caracteres invalidos.\n", "fuera de rango.\n", MAX_INTENTOS_REINGRESOS, 1, 9, &opcion);

        switch(opcion)
        {

            case 1: //ALTA PANTALLA
                command_upScreen (arrayPantallas, MAX_CANTIDAD_PANTALLAS);
                break;

            case 2: //MODIFICAR DATOS ASOCIADO
                //command_modifyScreen (arrayPantallas, MAX_CANTIDAD_PANTALLAS);
                break;

            case 3: //BAJA DE ASCIADO
                //command_downScreen (arrayPantallas, MAX_CANTIDAD_PANTALLAS);
                break;

            // case 4: //REGISTRAR LLAMADA
            //     command_newRental (adheridos, MAX_CANTIDAD_ADHERENTES, incidentes, MAX_CANTIDAD_INCIDENTES);
            //     break;

            // case 5: //FINALIZAR LLAMADA
            //     command_endCall (incidentes, MAX_CANTIDAD_INCIDENTES);
            //     break;

            // case 6: //INFORME
            //     command_asocMasIncidentes (adheridos, MAX_CANTIDAD_ADHERENTES, incidentes, MAX_CANTIDAD_INCIDENTES);
            //     command_incidenteQueMasTardaEnResolverse (incidentes, MAX_CANTIDAD_INCIDENTES);

            //     break;

            // case 7: //LISTAR LLAMADAS
            //     command_listCalls (incidentes, MAX_CANTIDAD_INCIDENTES);
            //     system("pause");
            //     break;

            case 8: //LISTAR ASOCIADOS
                //command_listScreens (arrayPantallas, MAX_CANTIDAD_PANTALLAS);
                system("pause");
                break;

            case 9: //SALIR
                break;

            default:
                printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                system("pause");
                break;
        }

    }while(opcion != 9);

    return 0;
}
