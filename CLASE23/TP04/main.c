#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "interface.h"


int main()
{
    int  opcion, i;
    char menu[12][100] = {
    "******************************",
    "* REGISTRO DE ASOCIADOS GYM  *",
    "******************************",
    "* 1. NUEVO ASOCIADO.         *",
    "*                            *",
    "* 2. BAJA ASOCIADO.          *",
    "*                            *",
    "* 3. MODIFICACION            *",
    "*    DATOS ASOCIDO.          *",
    "*                            *",
    "* 4. LISTAR ASOCIADOS.       *",
    "******************************",
    };

    do
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<12; i++)
        printf("   %s\n", menu[i]);
        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 11. **\n", 3, 1, 12, &opcion);

        switch(opcion)
        {
            //ALTA DE ASOCIADO
            case 1:
                //cmd_newMember (asociados);
                break;

            //MODIFICAR ASOCIADO
            case 2:
                //cmd_modifyMember (asociados);
                break;

            //BAJA DE ASOCIADO
            case 3:
                //cmd_downMember (asociados);
                break;










            //CONTRATAR PUBLICIDAD
            case 4:
                //cmd_newAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se listaran todas las pantallas y se le pedirá
                al usuario que elija la pantalla donde se quiere
                publicar, ingresando su ID. Luego se pedirán los
                datos asociados a la publicidad: cuit del cliente,
                cantidad de días que dura la publicación y nombre​
                ​del​ ​archivo​ ​de​ ​video​ ​(p.ej.​ ​Video1.avi).*/
                break;

            //MODIFICAR CONDICIONES DE PUBLICACION
            case 5:
                //cmd_modifyAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se pedirá que se ingrese el cuit del cliente y se
                listaran todas las pantallas de video que el cliente
                tiene contratadas mostrando todos sus campos.
                Luego de ingresar el ID de la pantalla, se permitirá
                modificar la cantidad de días contratados​ ​para​ ​la​ ​misma.*/
                break;

            //CANCELAR CONTRATACION
            case 6:
               // cmd_deleteAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Sepedirá que se ingrese el cuit del cliente y se
                listaran todas las pantallas de video que el cliente
                tiene contratadas mostrando todos sus campos. Luego
                ingresar​ ​el​ ​ID​ ​de​ ​la​ ​pantalla​ ​de​ ​la​ ​cual​ ​se​ ​quiere​ ​
                cancelar​ ​la​ ​contratación.*/
                break;

            //CONSULTAR FACTURACION
            case 7:
                //cmd_billing (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se deberá ingresar el cuit del cliente y se deberá
                listar el importe a​ ​pagar​ ​por​ ​cada​ ​contratación.*/
                break;

            //LISTAR CONTRATACIONES
            case 8:
                //cmd_listAds (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se deberán listar las contrataciones indicando
                nombre de la pantalla,​ ​nombre​ ​de​ ​video,​ ​cantidad​
                de​ ​días​ ​y​ ​cuit​ ​de​ ​cliente. */
                break;

            //LISTAR PANTALLAS
            case 9:
                //scr_listScreens (pantallas, STOCK_PANTALLAS);
                /*
                Se​ ​deberán​ ​listar​ ​las​ ​pantallas​ ​existentes​ ​
                indicando​ ​todos​ ​sus​ ​campos.*/
                break;

            //INFORMES
            case 10:
                //cmd_listClientsAds (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                1. Lista de cada cliente con cantidad de
                   contrataciones e importe a pagar por
                   cada una. */
                /*
                2. Cliente con importe más alto a facturar
                   (si hay más de uno indicar el primero) */
                break;

            //SALIR
            case 11:
                system("pause");
                break;

            //HISTORIAL (opcion oculta)
            case 12:
                //scr_arrayRecords(pantallas, STOCK_PANTALLAS);
                //adv_arrayRecords(publicaciones, MAX_CANT_PUBLICACIONES);
                break;

            default:
                opcion = 11;
                break;
        }

    }while(opcion != 11);

    return 0;
}
