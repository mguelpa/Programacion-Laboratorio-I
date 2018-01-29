#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pantallas.h"
#include "publicaciones.h"
#include "interface.h"



////////////////////////////////////////////////////////////////////////////////
int cmd_loadScreen (sScreen* nombre_array, int length)
{
    int retorno = -1;

    //Buffers para validar datos obtenidos
    int   auxData1;                          //int   type;
    char  auxData2[MAX_CHARS_NOMBRES +1];       //char  name;
    char  auxData3[MAX_CHARS_DESCRIPCIONES +1]; //char  review;
    char  auxData4[MAX_CHARS_DIRECCIONES +1];   //char  address;
    float auxData5;                          //float price;


    if (nombre_array != NULL && length > 0)
    {
        /* solicito tipo de pantalla */
        if (input_getInt ("seleccione el tipo de pantalla:\n1. LCD.\n2. LED.\n",
                          "\t** opciones 1 o 2. **\n\n", MAX_REINGRESOS, 1, 2, &auxData1) == 0){
            /* solicito nombre de pantalla */
            if (input_getAnumericStr ("modelo de pantalla: ",
                                      "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_NOMBRES, auxData2) == 0){
                /* solicito nombre de pantalla */
                if (input_getAnumericStr ("descripcion de pantalla (50 caracteres max): ",
                                          "\t** la descripcion debe estar compuesta de 5 a 50 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DESCRIPCIONES, auxData3) == 0){
                    /*solicito locacion de pantalla */
                    if (input_getAnumericStr ("ubicacion / direccion de la pantalla: ",
                                              "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData4) == 0){
                        /*solicito el precio de la pantalla */
                        if (input_getFloat ("costo de publicacion: ",
                                            "\t** el valor de la pantalla debe estar comprendido entre usd 1,00 y usd 1.000.000,00 **\n\n", MAX_REINGRESOS, 1, 999999, &auxData5) == 0)
                        {
                            scr_loadData (nombre_array, length, &auxData1, auxData2, auxData3, auxData4, &auxData5);
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_modifyScreen (sScreen* nombre_array, int length)
{
    int retorno = -1;

    //Buffers para validar datos obtenidos
    int   idBox;
    int   indexBox;

    int   auxData1;       //int   type;
    char  auxData2[1024]; //char  name;
    char  auxData3[1024]; //char  review;
    char  auxData4[1024]; //char  address;
    float auxData5;       //float price;


    if (nombre_array != NULL && length > 0)
    {   /* solicito id*/
        if (input_getInt ("ingrese el id de la pantalla: ",
                          "\t** el id de la pantalla debe ser mayor a 0 **\n\n", MAX_REINGRESOS, 0, 1000000, &idBox) == 0){
            /* busco id */
            indexBox = scr_searchIndexById(nombre_array, length, idBox);
            if (indexBox > -1){
                /* solicito tipo de pantalla */
                if (input_getInt ("seleccione el tipo de pantalla:\n1. LCD.\n2. LED.\n",
                                  "\t** opciones 1 o 2. **\n\n", 3, 1, 2, &auxData1) == 0){
                    /* solicito nombre de pantalla */
                    if (input_getAnumericStr ("modelo de pantalla: ",
                                              "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_NOMBRES, auxData2) == 0){
                        /* solicito nombre de pantalla */
                        if (input_getAnumericStr ("descripcion de pantalla (50 caracteres max): ",
                                                  "\t** la descripcion debe estar compuesta de 5 a 50 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DESCRIPCIONES, auxData3) == 0){
                            /*solicito locacion de pantalla */
                            if (input_getAnumericStr ("ubicacion / direccion de la pantalla: ",
                                                      "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData4) == 0){
                                /*solicito el precio de la pantalla */
                                if (input_getFloat ("costo de publicacion: ",
                                                    "\t** el valor de la pantalla debe estar comprendido entre usd 1,00 y usd 1.000.000,00 **\n\n", MAX_REINGRESOS, 1, 999999, &auxData5) == 0)
                                {
                                    scr_modifyData (nombre_array, indexBox, auxData1, auxData2, auxData3, auxData4, auxData5);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_downScreen (sScreen* nombre_array, int length)
{
    int retorno;
    int index;
    int id = 0;

    if(nombre_array != NULL && length > 0)
    {
        retorno = input_getInt("Ingrese el id de la pantalla: ",
                               "\t** el id debe ser mayor a 0 **\n", MAX_REINGRESOS, 1, 99999, &id);
        if(retorno == 0)
        {
            index = scr_searchIndexById(nombre_array, length, id);
            if(index > -1)
            {
                scr_downData(nombre_array, index);
            }
            else
            {
                printf("El ID ingresado no corresponde a ningun asociado\n");
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_newAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    int i;

    char panel[3][100] = {
    "**********************************************************************************",
    "*                         DISPONIBILIDAD DE PANTALLAS                            *",
    "**********************************************************************************",
    };

    //Buffers para validar datos obtenidos
    char auxData1[MAX_CHARS_CUIT+1];     //char cuit;
    int  auxData2;                       //int  scr_code;
    int  auxData3;                       //int  adv_lapse;
    char auxData4[MAX_CHARS_ARCHIVOS+1]; //char adv_archve;

    int scr_indexBox;




    if((nombre_array1 != NULL && length1 > 0) && (nombre_array2 != NULL && length2 > 0))
    {
        for(i=0; i<3; i++)
            printf("   %s\n", panel[i]);
        for (i=0; i<length1; i++)
        {
            if(nombre_array1[i].scr_slot == SCR_TAKEN && nombre_array1[i].scr_availability == SCR_FREE)
            scr_printData(nombre_array1, i);
        }

        /* solicito codigo de pantalla */
        retorno = input_getInt("ingrese el codigo de la pantalla donde quiere publicar: ",
                               "el codigo debe ser mayor a 0", MAX_REINGRESOS, 1, 999, &auxData2);
        if (retorno == 0){
            scr_indexBox = scr_searchIndexById (nombre_array1, length1, auxData2);

            if (scr_indexBox > -1){
                /* solicito cuit de cliente */
                retorno = input_getAnumericStr("ingrese su numero de CUIT: ",
                                               "\t** la cantidad de caracteres ingresados es invalida. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData1);
                if (retorno == 0){
                    /* solicito duracion de la publicacion */
                    retorno = input_getInt("duracion de la publicacion (cant. dias): ",
                                           "\t** . **\n\n", MAX_REINGRESOS, 2, 1460, &auxData3);
                    if (retorno == 0){
                        /* solicito nombre de archivo */
                        retorno = input_getAnumericStr ("nombre de archivo a publicar: ",
                                                        "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData4);
                        if (retorno == 0){

                            adv_loadData (nombre_array2, length2, auxData1, &auxData2, &auxData3, auxData4);
                            (nombre_array1+scr_indexBox)->scr_availability = SCR_TAKEN;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_modifyAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    int i;

    char panel[3][100] = {
    "**********************************************************************************",
    "*                          MODIFICACION DE CONTRATO                              *",
    "**********************************************************************************",
    };

    //Buffers para validar datos obtenidos
    int  adv_indexBox;
    int  scr_indexBox;
    char auxData1[MAX_CHARS_CUIT+1];     //char cuit;
    int  auxData2;                       //int  scr_code;
    int  auxData3;                       //int  adv_lapse;



    if((nombre_array1 != NULL && length1 > 0) && (nombre_array2 != NULL && length2 > 0))
    {
        for(i=0; i<3; i++)
            printf("   %s\n", panel[i]);

        /* solicito cuit de cliente */
        retorno = input_getAnumericStr("ingrese su numero de CUIT: ",
                                       "\t** la cantidad de caracteres ingresados es invalida. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData1);
        if (retorno == 0)
        {
            /* busco el numero de cuit en array publicaciones */
            adv_indexBox = adv_searchIndexById (nombre_array2, length2, auxData1);
            if (adv_indexBox > -1)
            {
                /* solicito tipo de pantalla */
                for (i=0; i<length1; i++)
                {
                    if(strncmp(auxData1, (nombre_array2+i)->clientID, MAX_CHARS_CUIT+1) == 0)
                    {
                        //printf("auxData1: %s\n", auxData1);
                        //printf("clientID: %s\n", (nombre_array2+i)->clientID);
                        scr_indexBox = scr_searchIndexById(nombre_array1, length1, (nombre_array2+i)->scr_code);
                            scr_printData(nombre_array1, scr_indexBox);
                    }
                }

                /* solicito codigo de pantalla */
                retorno = input_getInt("ingrese el codigo de la pantalla que desea modificar: ",
                                       "el codigo debe ser mayor a 0", MAX_REINGRESOS, 1, 999, &auxData2);
                if (retorno == 0)
                {
                    scr_indexBox = scr_searchIndexById(nombre_array1, length1, auxData2);
                    if (scr_indexBox > -1)
                    {
                        /* solicito duracion de la publicacion */
                        retorno = input_getInt("duracion de la publicacion (cant. dias): ",
                                                       "\t** . **\n\n", MAX_REINGRESOS, 2, 1460, &auxData3);
                        if (retorno == 0){

                            for (i=0; i<length2; i++)
                            {
                                if(auxData2 == (nombre_array2+i)->scr_code)
                                {
                                    adv_modifyData (nombre_array2, i, &auxData3);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_deleteAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    int i;

    char panel[3][100] = {
    "**********************************************************************************",
    "*                               BAJA DE CONTRATO                                 *",
    "**********************************************************************************",
    };

    //Buffers para validar datos obtenidos
    int  adv_indexBox;
    int  scr_indexBox;
    char auxData1[MAX_CHARS_CUIT+1];     //char cuit;
    int  auxData2;                       //int  scr_code;


    if((nombre_array1 != NULL && length1 > 0) && (nombre_array2 != NULL && length2 > 0))
    {
        for(i=0; i<3; i++)
            printf("   %s\n", panel[i]);

        /* solicito cuit de cliente */
        retorno = input_getAnumericStr("ingrese su numero de CUIT: ",
                                       "\t** la cantidad de caracteres ingresados es invalida. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData1);
        if (retorno == 0)
        {
            /* busco el numero de cuit en array publicaciones */
            adv_indexBox = adv_searchIndexById (nombre_array2, length2, auxData1);
            if (adv_indexBox > -1)
            {
                /* solicito tipo de pantalla */
                for (i=0; i<length1; i++)
                {
                    if(strncmp(auxData1, (nombre_array2+i)->clientID, MAX_CHARS_CUIT+1) == 0)
                    {
                        //printf("auxData1: %s\n", auxData1);
                        //printf("clientID: %s\n", (nombre_array2+i)->clientID);
                        scr_indexBox = scr_searchIndexById(nombre_array1, length1, (nombre_array2+i)->scr_code);
                            scr_printData(nombre_array1, scr_indexBox);
                    }
                }

                /* solicito codigo de pantalla */
                retorno = input_getInt("ingrese el codigo de la pantalla que desea modificar: ",
                                       "el codigo debe ser mayor a 0", MAX_REINGRESOS, 1, 999, &auxData2);
                if (retorno == 0)
                {
                    scr_indexBox = scr_searchIndexById(nombre_array1, length1, auxData2);
                    if (scr_indexBox > -1)
                    {
                        for (i=0; i<length2; i++)
                        {
                            if(auxData2 == (nombre_array2+i)->scr_code)
                            {
                                adv_downData(nombre_array2, i);
                                (nombre_array1+scr_indexBox)->scr_availability = SCR_FREE;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_billing (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    int i;
    char scr_types[3][12] = {"EMPTY", "LCD screen", "LED screen"};
    char panel[3][100] = {
    "**********************************************************************************",
    "*                          FACTURACION DEL CLIENTE                               *",
    "**********************************************************************************",
    };

    int adv_indexBox;
    char auxData1[MAX_CHARS_CUIT+1];

    sAdvertisement aux1;
    sScreen aux2;


    if((nombre_array1 != NULL && length1 > 0) && (nombre_array2 != NULL && length2 > 0))
    {
        for(i=0; i<3; i++){
            printf("   %s\n", panel[i]);
        }

        /* solicito cuit de cliente */
        retorno = input_getAnumericStr("ingrese su numero de CUIT: ",
                                       "\t** la cantidad de caracteres ingresados es invalida. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData1);
        if (retorno == 0)
        {
            /* busco el numero de cuit en array publicaciones */
            adv_indexBox = adv_searchIndexById (nombre_array2, length2, auxData1);
            if (adv_indexBox > -1)
            {
                printf("   CONTRATACIONES DEL CLIENTE: %s\n", auxData1);
                for(i = 0; i< length2; i++)
                {
                    if (strcmp (auxData1, (nombre_array2+i)->clientID ) == 0)
                    {
                        retorno = adv_getData(nombre_array2, i, &aux1);
                        retorno = scr_getData(nombre_array1, scr_searchIndexById(nombre_array1, length1, aux1.scr_code), &aux2);

                        printf("\n");
                        printf("   PANTALLA: %s \t //\tTIPO: %s\n\n",  aux2.name, scr_types[aux2.scr_type]);
                        printf("   ARCHIVO:     \t %s\n",              aux1.adv_archive);
                        printf("   CONTRATACION:\t %d dias\n",         aux1.adv_lapse);
                        printf("   IMPORTE PUBLICACION:  USD %.2f\n",  aux1.adv_lapse*aux2.price);
                        printf("   -------------------------------------------------------\n\n");
                    }
                }
                printf("\n\n");

            }

        }

    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_listAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    char scr_types[3][12] = {"EMPTY", "LCD screen", "LED screen"};
    int i;

    char panel[3][100] = {
    "**********************************************************************************",
    "*                      LISTADO DE PUBLICACIONES POR CLIENTE                      *",
    "**********************************************************************************",
    };

    char auxData1 [MAX_CHARS_CUIT+1]; // cuit cliente
    sAdvertisement aux1;
    sScreen aux2;

    for(i=0; i<3; i++){
        printf("   %s\n", panel[i]);
    }

    if (input_getAnumericStr("ingrese su numero de CUIT: ", "\t** la cantidad de caracteres ingresados es invalida. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData1) == 0)
    {
        for(i= 0; i< length2; i++)
        {
            if ( ( strcmp((nombre_array2+i)->clientID, auxData1) == 0 ))
            {
                retorno = adv_getData(nombre_array2, i, &aux1);
                retorno = scr_getData(nombre_array1, scr_searchIndexById(nombre_array1, length1, (nombre_array2+i)->scr_code), &aux2);

                printf("\n");
                printf("   PANTALLA: %s \t //\tTIPO: %s\n\n", aux2.name, scr_types[aux1.adv_code]);
                printf("   ARCHIVO:     \t %s\n",              aux1.adv_archive);
                printf("   CONTRATACION:\t %d dias\n",         aux1.adv_lapse);
                printf("   CUIT CLIENTE:\t %s\n\n",            aux1.clientID);
                printf("   -------------------------------------------------------\n\n");
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int cmd_listClientsAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2)
{
    int retorno = -1;
    char scr_types[3][12] = {"EMPTY", "LCD screen", "LED screen"};
    int i,j;
    int flag = 0;

    char panel[3][100] = {
    "**********************************************************************************",
    "*                      LISTADO DE PUBLICACIONES POR CLIENTE                      *",
    "**********************************************************************************",
    };

    char panel2[3][100] = {
    "**********************************************************************************",
    "*                     CLIENTE CON IMPORTE MAS ALTO A FACTURAR                    *",
    "**********************************************************************************",
    };

    char  arrayClientes [length2][MAX_CHARS_CUIT+1];
    int   nroContrataciones [length2];
    int   screenCodes [length2][length2];
    int   advCodes [length2][length2];
    float importeXpantalla [length2]/*[length2]*/;
    float suma = 0;
    float mayorImporte = 0;
    int   clienteImporteMasAlto = 0;

    sAdvertisement aux1;
    sScreen aux2;

    // INICIALIZACION DE VARIABLES
    for (i=0; i< length2; i++)
    {
        strncpy (arrayClientes[i], "0000000000000", 21);
        nroContrataciones[i] = 0;
        for (j=0; j< length2; j++)
        {
            screenCodes[i][j] = 0;
            advCodes[i][j] = 0;
            importeXpantalla[i]/*[j]*/ = 0;
        }
    }
//                                                                                                    //VERIFICACION INICIALIZACION DE ARRAY
//                                                                                                    for (i=0; i<length2; i++)
//                                                                                                    {
//                                                                                                        printf(" i\tid\t\t screen codes\t\tadv codes\t\timporte por pantalla\tnrocontrataciones\n");
//                                                                                                        printf(" %d\t%s    ", i, arrayClientes[i]);
//                                                                                                        for (j = 0; j<length2; j++)
//                                                                                                            printf("%d ", screenCodes[i][j]);
//                                                                                                            printf("\t");
//                                                                                                        for (j = 0; j<length2; j++)
//                                                                                                            printf("%d ", advCodes[i][j]);
//                                                                                                            printf("\t");
//                                                                                                            printf("%.2f\t\t\t", importeXpantalla[i]);
//                                                                                                            printf("%d\n\n", nroContrataciones[i]);
//                                                                                                    }
    // IMPRESION DE PANEL
    for(i=0; i<3; i++){
        printf("   %s\n", panel[i]);
    }

    // BUSQUEDA Y CRGA DE DATOS EN MATRIZ
    for(i= 0; i< length2; i++)
    {
        flag = 0;
        for (j=0; j<length2; j++)
        {
            if (strcmp (arrayClientes[j], (nombre_array2+i)->clientID ) == 0)
            {
                  nroContrataciones[j]++;
                  screenCodes[j][i] = (nombre_array2+i)->scr_code;
                  advCodes[j][i] = (nombre_array2+i)->adv_code;
                importeXpantalla[j] = importeXpantalla[j] + ((nombre_array1+scr_searchIndexById(nombre_array1, length1, screenCodes[j][i]))->price * (nombre_array2+i)->adv_lapse);
                flag = 1;
            }
        }
        if (flag == 0 && (strcmp ("0", (nombre_array2+i)->clientID) != 0))
        {
            for (j= 0; j<length2; j++)
            {
                if (strcmp (arrayClientes[j], "0000000000000") == 0)
                {
                    strcpy (arrayClientes[j], (nombre_array2+i)->clientID);
                    nroContrataciones[j]++;
                    screenCodes[j][i] = (nombre_array2+i)->scr_code;
                    advCodes[j][i] = (nombre_array2+i)->adv_code;
                    importeXpantalla[j] = importeXpantalla[j] + ((nombre_array1+scr_searchIndexById(nombre_array1, length1, screenCodes[j][i]))->price * (nombre_array2+i)->adv_lapse);
                    break;
                }
            }
        }
    }
//                                                                                                            //VERIFICACION DE DATOS GUARDADOS EN ARRAYS
//                                                                                                            for (i=0; i<length2; i++)
//                                                                                                            {
//                                                                                                                printf(" i\tid\t\t screen codes\t\tadv codes\t\timporte por pantalla\tnrocontrataciones\n");
//                                                                                                                printf(" %d\t%s    ", i, arrayClientes[i]);
//                                                                                                                for (j = 0; j<length2; j++)
//                                                                                                                    printf("%d ", screenCodes[i][j]);
//                                                                                                                    printf("\t");
//                                                                                                                for (j = 0; j<length2; j++)
//                                                                                                                    printf("%d ", advCodes[i][j]);
//                                                                                                                    printf("\t");
//                                                                                                                    printf("%.2f\t\t\t", importeXpantalla[i]);
//                                                                                                                    printf("%d\n\n", nroContrataciones[i]);
//                                                                                                            }
    // CLIENTE IMPORTE MAS ALTO - NRO DE CONTRATACIONES - IMPORTE TOTAL A ABONAR
    for(i=0; i< length2; i++)
    {
        if(arrayClientes[i] != 0 && nroContrataciones[i] != 0)
        {
            printf("   CUIT CLIENTE: %s\n", arrayClientes[i]);
            printf("   TOTAL DE CONTRATACIONES: %d\n", nroContrataciones[i]);
            for (j=0; j< length2; j++)
            {
                if(screenCodes[i][j] != 0 && importeXpantalla[i] != 0)
                {
                    retorno = adv_getData(nombre_array2, adv_searchIndexById2(nombre_array2, length2, advCodes[i][j]), &aux1);
                    retorno = scr_getData(nombre_array1, scr_searchIndexById(nombre_array1, length1, screenCodes[i][j]), &aux2);

                    printf("\n");
                    printf("   PANTALLA: %s \t //\tTIPO: %s\n\n",  aux2.name, scr_types[aux2.scr_type]);
                    printf("   ARCHIVO:     \t %s\n",              aux1.adv_archive);
                    printf("   CONTRATACION:\t %d dias\n",         aux1.adv_lapse);
                    printf("   IMPORTE PUBLICACION:  USD %.2f\n",  aux1.adv_lapse*aux2.price);
                    printf("   -------------------------------------------------------\n\n");
                }
            }
            printf("\n\n");
        }
    }

    // CLIENTE IMPORTE MAS ALTO - NRO DE CONTRATACIONES - IMPORTE TOTAL A ABONAR
    for(i=0; i<3; i++){
    printf("   %s\n", panel2[i]);
    }

    for(i=0; i< length2; i++)
    {
        suma = 0;
        for (j= 0; j< length2; j++)
        {
            suma += importeXpantalla[i+1]/*[j]*/;
        }

        if(suma > mayorImporte)
        {
            mayorImporte = suma;
            clienteImporteMasAlto = i;
        }
    }
    printf("   CUIT CLIENTE: %s\n", arrayClientes[clienteImporteMasAlto]);
    printf("   TOTAL DE CONTRATACIONES: %d\n", nroContrataciones[clienteImporteMasAlto]);
    printf("   IMPORTE A ABONAR: USD %.2f\n", mayorImporte);
    printf("\n\n");

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////
void cmd_cheater (sScreen* nombre_array1, sAdvertisement* nombre_array2)
{
    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 1 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+0)->scr_slot = SLT_LOADED;
            (nombre_array1+0)->scr_id   = 1;
            (nombre_array1+0)->scr_type = TYPE_LED;
            (nombre_array1+0)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+0)->name,"Panasonic VT20");
    strcpy ((nombre_array1+0)->review,"PANTALLA 60\" PULGADAS Hotel Corrientes");
    strcpy ((nombre_array1+0)->address,"Av. Corrientes 767, Microcentro");
            (nombre_array1+0)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 2 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+1)->scr_slot = SLT_LOADED;
            (nombre_array1+1)->scr_id   = 2;
            (nombre_array1+1)->scr_type = TYPE_LCD;
            (nombre_array1+1)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+1)->name,"Sony HX903");
    strcpy ((nombre_array1+1)->review,"PANTALLA 77\" PULGADAS Hamburgueseria Dean & Dennys");
    strcpy ((nombre_array1+1)->address,"Malabia 1591, Palermo");
            (nombre_array1+1)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 3 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+2)->scr_slot = SLT_LOADED;
            (nombre_array1+2)->scr_id   = 3;
            (nombre_array1+2)->scr_type = TYPE_LED;
            (nombre_array1+2)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+2)->name,"Samsung C9000");
    strcpy ((nombre_array1+2)->review,"PANTALLA 92\" PULGADAS Estadio Luna Park");
    strcpy ((nombre_array1+2)->address,"Av. Eduardo Madero 470, Puerto Madero");
            (nombre_array1+2)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 4 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+3)->scr_slot = SLT_LOADED;
            (nombre_array1+3)->scr_id   = 4;
            (nombre_array1+3)->scr_type = TYPE_LED;
            (nombre_array1+3)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+3)->name,"Philips Aurea");
    strcpy ((nombre_array1+3)->review,"PANTALLA 55\" PULGADAS Abasto Shopping");
    strcpy ((nombre_array1+3)->address,"Av. Corrientes 3247, Balvanera");
            (nombre_array1+3)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 5 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+4)->scr_slot = SLT_LOADED;
            (nombre_array1+4)->scr_id   = 5;
            (nombre_array1+4)->scr_type = TYPE_LCD;
            (nombre_array1+4)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+4)->name,"Sony LX903");
    strcpy ((nombre_array1+4)->review,"PANTALLA 80\" PULGADAS Alto Palermo Shopping");
    strcpy ((nombre_array1+4)->address,"Av. Santa Fe 3253, Palermo");
            (nombre_array1+4)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 6 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+5)->scr_slot = SLT_LOADED;
            (nombre_array1+5)->scr_id   = 6;
            (nombre_array1+5)->scr_type = TYPE_LCD;
            (nombre_array1+5)->scr_availability = SCR_TAKEN;

    strcpy ((nombre_array1+5)->name,"Samsung C7000");
    strcpy ((nombre_array1+5)->review,"PANTALLA 55\" PULGADAS McDonalds");
    strcpy ((nombre_array1+5)->address,"Av. A. Moreau 1150, Puerto madero");
            (nombre_array1+5)->price = 5600;


    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 7 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+13)->scr_slot = SLT_LOADED;
            (nombre_array1+13)->scr_id   = 14;
            (nombre_array1+13)->scr_type = TYPE_LED;
            (nombre_array1+13)->scr_availability = SCR_FREE;

    strcpy ((nombre_array1+13)->name,"Sony XBR-65X900E");
    strcpy ((nombre_array1+13)->review,"PANTALLA 55\" PULGADAS Galerias Pacifico");
    strcpy ((nombre_array1+13)->address,"Av. Cordoba 550, Retiro");
            (nombre_array1+13)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 8 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+9)->scr_slot = SLT_LOADED;
            (nombre_array1+9)->scr_id   = 10;
            (nombre_array1+9)->scr_type = TYPE_LCD;
            (nombre_array1+9)->scr_availability = SCR_FREE;

    strcpy ((nombre_array1+9)->name,"Samsung UN65MU8");
    strcpy ((nombre_array1+9)->review,"PANTALLA 60\" PULGADAS Patio Bullrich");
    strcpy ((nombre_array1+9)->address,"Posadas 1245, Retiro");
            (nombre_array1+9)->price = 5600;

    ////////////////////////////////////////////////////////////
    //                    /* PANTALLA 9 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+7)->scr_slot = SLT_LOADED;
            (nombre_array1+7)->scr_id   = 8;
            (nombre_array1+7)->scr_type = TYPE_LED;
            (nombre_array1+7)->scr_availability = SCR_FREE;

    strcpy ((nombre_array1+7)->name,"Lg OLED65C7P");
    strcpy ((nombre_array1+7)->review,"PANTALLA 55\" PULGADAS Burger King");
    strcpy ((nombre_array1+7)->address,"Av. Corrientes 602, San Nicolas");
            (nombre_array1+7)->price = 5600;


    ////////////////////////////////////////////////////////////
    //                     /* CLIENTE 1 */                    //
    ////////////////////////////////////////////////////////////
                /* AD 1 */
                nombre_array2[0].adv_slot = ADV_TAKEN;
                (nombre_array2+0)->adv_code = 1;

        strcpy ((nombre_array2+0)->clientID, "20-11111111-5");
                (nombre_array2+0)->scr_code = 1;
                (nombre_array2+0)->adv_lapse = 1;
        strcpy ((nombre_array2+0)->adv_archive, "publicidad1.avi");

                /* AD 2 */
                (nombre_array2+1)->adv_slot = ADV_TAKEN;
                (nombre_array2+1)->adv_code = 2;

        strcpy ((nombre_array2+1)->clientID, "20-11111111-5");
                (nombre_array2+1)->scr_code = 2;
                (nombre_array2+1)->adv_lapse = 7;
        strcpy ((nombre_array2+1)->adv_archive, "publicidad2.avi");
    ////////////////////////////////////////////////////////////
    //                     /* CLIENTE 2 */                    //
    ////////////////////////////////////////////////////////////
                /* AD 3 */
                (nombre_array2+2)->adv_slot = ADV_TAKEN;
                (nombre_array2+2)->adv_code = 3;

        strcpy ((nombre_array2+2)->clientID, "20-22222222-5");
                (nombre_array2+2)->scr_code = 3;
                (nombre_array2+2)->adv_lapse = 1;
        strcpy ((nombre_array2+2)->adv_archive, "publicidad3.avi");

                /* AD 4 */
                (nombre_array2+3)->adv_slot = ADV_TAKEN;
                (nombre_array2+3)->adv_code = 4;

        strcpy ((nombre_array2+3)->clientID, "20-22222222-5");
                (nombre_array2+3)->scr_code = 4;
                (nombre_array2+3)->adv_lapse = 2;
        strcpy ((nombre_array2+3)->adv_archive, "publicidad4.avi");

                /* AD 5 */
                (nombre_array2+4)->adv_slot = ADV_TAKEN;
                (nombre_array2+4)->adv_code = 5;

        strcpy ((nombre_array2+4)->clientID, "20-22222222-5");
                (nombre_array2+4)->scr_code = 5;
                (nombre_array2+4)->adv_lapse = 6;
        strcpy ((nombre_array2+4)->adv_archive, "publicidad5.avi");
    ////////////////////////////////////////////////////////////
    //                     /* CLIENTE 3 */                    //
    ////////////////////////////////////////////////////////////
                /* AD 6 */
                (nombre_array2+5)->adv_slot = ADV_TAKEN;
                (nombre_array2+5)->adv_code = 6;

        strcpy ((nombre_array2+5)->clientID, "20-33333333-5");
                (nombre_array2+5)->scr_code = 6;
                (nombre_array2+5)->adv_lapse = 4;
        strcpy ((nombre_array2+5)->adv_archive, "publicida6.avi");

///////////////////////////////////////////////////////////////////////////////
}



















