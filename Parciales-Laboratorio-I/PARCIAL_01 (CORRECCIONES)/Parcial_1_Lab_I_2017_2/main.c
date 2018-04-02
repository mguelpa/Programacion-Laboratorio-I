#include <stdio.h>
#include <stdlib.h>

#include "controlador.h"
#include "interface.h"

#define STOCK_PANTALLAS 15
#define MAX_CANT_PUBLICACIONES 15

int main()
{
    int  opcion, i;
    char menu[12][100] = {
    "**********************************************************************************",
    "*                            PUBLICACIONES PANTALLAS                             *",
    "**********************************************************************************",
    "* 1. Alta de pantalla.    4. Contratar publicidad.     7. Consulta facturacion.  *",
    "*                                                                                *",
    "* 2. Modificar datos      5. Modificar publicacion.    8. Listar contrataciones. *",
    "*    de pantalla.                                                                *",
    "*                                                                                *",
    "* 3. Baja de pantalla.    6. Cancelar contratacion.    9. Listar pantallas.      *",
    "*                                                                                *",
    "* 10. Informes.           11. Salir.                                             *",
    "**********************************************************************************",
    };

    //DECLARO EL ARRAY Y LO INICIALIZO.
    sScreen pantallas[STOCK_PANTALLAS];
        scr_arrayInit(pantallas, STOCK_PANTALLAS);

    //DECLARO EL ARRAY Y LO INICIALIZO.
    sAdvertisement publicaciones[MAX_CANT_PUBLICACIONES];
        adv_arrayInit(publicaciones, MAX_CANT_PUBLICACIONES);

    cont_cheater (pantallas, publicaciones);


    do
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<12; i++)
        printf("   %s\n", menu[i]);
        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 11. **\n", MAX_REINGRESOS, 1, 12, &opcion);

        switch(opcion)
        {
            //ALTA DE PANTALLA
            case 1:
                cont_loadScreen (pantallas, STOCK_PANTALLAS);
                break;

            //MODIFICAR PANTALLA
            case 2:
                cont_modifyScreen (pantallas, STOCK_PANTALLAS);
                break;

            //BAJA DE PANTALLA
            case 3:
                cont_downScreen (pantallas, STOCK_PANTALLAS);
                break;

            //CONTRATAR PUBLICIDAD
            case 4:
                cont_newAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
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
                cont_modifyAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se pedirá que se ingrese el cuit del cliente y se
                listaran todas las pantallas de video que el cliente
                tiene contratadas mostrando todos sus campos.
                Luego de ingresar el ID de la pantalla, se permitirá
                modificar la cantidad de días contratados​ ​para​ ​la​ ​misma.*/
                break;

            //CANCELAR CONTRATACION
            case 6:
                cont_deleteAd (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Sepedirá que se ingrese el cuit del cliente y se
                listaran todas las pantallas de video que el cliente
                tiene contratadas mostrando todos sus campos. Luego
                ingresar​ ​el​ ​ID​ ​de​ ​la​ ​pantalla​ ​de​ ​la​ ​cual​ ​se​ ​quiere​ ​
                cancelar​ ​la​ ​contratación.*/
                break;

            //CONSULTAR FACTURACION
            case 7:
                cont_billing (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se deberá ingresar el cuit del cliente y se deberá
                listar el importe a​ ​pagar​ ​por​ ​cada​ ​contratación.*/
                break;

            //LISTAR CONTRATACIONES
            case 8:
                cont_listAds (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
                /*
                Se deberán listar las contrataciones indicando
                nombre de la pantalla,​ ​nombre​ ​de​ ​video,​ ​cantidad​
                de​ ​días​ ​y​ ​cuit​ ​de​ ​cliente. */
                break;

            //LISTAR PANTALLAS
            case 9:
                scr_listScreens (pantallas, STOCK_PANTALLAS);
                /*
                Se​ ​deberán​ ​listar​ ​las​ ​pantallas​ ​existentes​ ​
                indicando​ ​todos​ ​sus​ ​campos.*/
                break;

            //INFORMES
            case 10:
                cont_listClientsAds (pantallas, STOCK_PANTALLAS, publicaciones, MAX_CANT_PUBLICACIONES);
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
                scr_arrayRecords(pantallas, STOCK_PANTALLAS);
                adv_arrayRecords(publicaciones, MAX_CANT_PUBLICACIONES);
                break;

            default:
                opcion = 11;
                break;
        }

    }while(opcion != 11);

    return 0;
}
