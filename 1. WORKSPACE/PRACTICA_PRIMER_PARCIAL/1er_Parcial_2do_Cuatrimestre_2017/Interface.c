#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Inputs.h"

#include "Controller.h"
#include "Interface.h"

#include "Products.h"
#include "Subjects.h"

//#include "Servicios.h"
//#include "Inscripciones.h"


// FUNCIONES PRIVADAS
static void initProduct();
static void editProduct();
static void deleteProduct();

static void initSubject();
static void editSubject();
static void deleteSubject();

static void debugShowAll();

//_________________________


int intr_showMenu()
{
    int  opcion, i;
    char menu[26][100] = {
    "*************************************************************",
    "**  CLIENT MANAGER:  Lomas Social Club                     **",
    "*************************************************************",
    "*|     AGENDA CLIENTES     |    |     GESTOR COMERCIAL     |*",
    "*|                         |    |                          |*",
    "*|  1. Nuevo Asociado.     |    |   4. Nuevo servicio.     |*",
    "*|                         |    |                          |*",
    "*|  2. Modificacion        |    |   5. Editar servicio.    |*",
    "*|     Datos Asociados.    |    |                          |*",
    "*|                         |    |                          |*",
    "*|  3. Baja de Asociados.  |    |   6. Baja de Servicios.  |*",
    "*|-------------------------|    |--------------------------|*",
    "*|                         |    |                          |*",
    "*|  7. Inscripciones.      |    |  10. Parse Subjects      |*",
    "*|                         |    |                          |*",
    "*|                         |    |                          |*",
    "*|  8. Editar              |    |  11. cant de servicios   |*",
    "*|     inscripciones.      |    |      por cada socio.     |*",
    "*|                         |    |                          |*",
    "*|  9. Baja inscripciones. |    |  12. servicio con mas    |*",
    "*|                         |    |      socios.             |*",
    "*|                         |    |                          |*",
    "*|                         |    |  12. Listar todo.        |*",
    "*|                         |    |                          |*",
    "*|                         |    |  14. Salir.              |*",
    "*************************************************************",
    };
    while(opcion != 14)
    {
        opcion = 0;

        for(i=0; i<26; i++)
        printf("   %s\n", menu[i]);
        input_getInt("   Seleccione una opcion: ", "\t** numero invalido **", 3, 1, 14, &opcion);

        switch(opcion)
        {
            /* ADMINISTRADOR DE PANTALLAS */
            case 1:
                initProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            /* ADMINISTRADOR DE CLIENTES */
            case 4:
                initAd();
                break;
            case 5:
                editAd();
                break;
            case 6:
                deleteAd();
                break;
            //////////////////////////////
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            //////////////////////////////
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                debugShowAll();
                break;
            case 14:
                opcion = 14;
                break;
        }
    }
    return 0;
}

/*Alta de pantalla: Se solicitan al usuario los datos de la pantalla, para que el sistema
pueda funcionar se deberá generar un ID único para cada pantalla.*/
static void initProduct()
{
    //Buffers para validar datos obtenidos
    int   auxData1;                          //int   type;
    char  auxData2[MAX_CHAR_TITLES +1];      //char  title;
    char  auxData3[MAX_CHAR_DESCRIPTION +1]; //char  review;
    char  auxData4[MAX_CHAR_ADRESS +1];      //char  address;
    float auxData5;                          //float price;

    if (input_getInt ("seleccione el tipo de pantalla:\n1. LCD.\n2. LED.\n", "\t** opciones 1 o 2. **\n\n", MAX_REINGRESOS, 1, 2, &auxData1) == 0)
    {
        if (input_getAnumericStr ("modelo de pantalla: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_TITLES, auxData2) == 0)
        {
            if (input_getAnumericStr ("descripcion de pantalla (50 caracteres max): ", "\t** la descripcion debe estar compuesta de 5 a 50 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_DESCRIPTION, auxData3) == 0)
            {
                if (input_getAnumericStr ("ubicacion / direccion de la pantalla: ", "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_ADRESS, auxData4) == 0)
                {
                    if (input_getFloat ("costo de publicacion: ", "\t** el valor de la pantalla debe estar comprendido entre usd 1,00 y usd 1.000.000,00 **\n\n", MAX_REINGRESOS, 1, 999999, &auxData5) == 0)
                    {
                        ctrl_loadProduct (auxData1, auxData2, auxData3, auxData4, auxData5);
                    }
                }
            }
        }
    }
}
static void editProduct()
{
    //Buffers para validar datos obtenidos
    int   id;
    int   auxData1;       //int   type;
    char  auxData2[1024]; //char  name;
    char  auxData3[1024]; //char  review;
    char  auxData4[1024]; //char  address;
    float auxData5;       //float price;


    if (input_getInt ("ingrese el id de la pantalla: ", "\t** el id de la pantalla debe ser mayor a 0 **\n\n", MAX_REINGRESOS, 0, 1000000, &id) == 0)
    {
        if (ctrl_checkProduct(id) == 0)
        {
            if (input_getInt ("seleccione el tipo de pantalla:\n1. LCD.\n2. LED.\n", "\t** opciones 1 o 2. **\n\n", 3, 1, 2, &auxData1) == 0)
            {
                if (input_getAnumericStr ("modelo de pantalla: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_TITLES, auxData2) == 0)
                {
                    if (input_getAnumericStr ("descripcion de pantalla (50 caracteres max): ", "\t** la descripcion debe estar compuesta de 5 a 50 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_DESCRIPTION, auxData3) == 0)
                    {
                        if (input_getAnumericStr ("ubicacion / direccion de la pantalla: ", "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_ADRESS, auxData4) == 0)
                        {
                            if (input_getFloat ("costo de publicacion: ", "\t** el valor de la pantalla debe estar comprendido entre usd 1,00 y usd 1.000.000,00 **\n\n", MAX_REINGRESOS, 1, 999999, &auxData5) == 0)
                            {
                                ctrl_modifyProduct (id, auxData1, auxData2, auxData3, auxData4, auxData5);
                            }
                        }
                    }
                }
            }
        }
    }
}
static void deleteProduct()
{
    int id = 0;

    if(input_getInt("Ingrese el id de la pantalla: ", "\t** el id debe ser mayor a 0 **\n", MAX_REINGRESOS, 1, 99999, &id) == 0)
    {
        if(ctrl_checkProduct(id) == 0)
        {
            ctrl_deleteProduct(id);
        }
        else
        {
            printf("El ID ingresado no corresponde a ningun asociado\n");
        }
    }
}


static void initAd()
{
    //Buffers para validar datos obtenidos
    char auxData1[MAX_CHARS_CUIT+1];     //char cuit;
    int  auxData2;                       //int  scr_code;
    int  auxData3;                       //int  adv_lapse;
    char auxData4[MAX_CHARS_ARCHIVOS+1]; //char adv_archve;

        /* solicito codigo de pantalla */
        retorno = input_getInt("ingrese el codigo de la pantalla donde quiere publicar: ", "el codigo debe ser mayor a 0", MAX_REINGRESOS, 1, 999, &auxData2);

        if (ctrl_checkProduct() == 0){
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
}
static void editAd()
{
    //Buffers para validar datos obtenidos
    int id;
    char auxData1[MAX_CHAR_NAMES +1];        //name
    char auxData2[MAX_CHAR_NAMES +1];        //surname
    //int auxData3[MAX_CHAR_DESCRIPTION +1]; //age
    //char auxData4[MAX_CHAR_ADRESS +1];     //dni
    //float auxData5;                        //salary


    if (input_getInt ("ingrese el id de cliente: ", "\t** el id del cliente debe ser mayor a 0 **\n\n", MAX_REINGRESOS, 0, 1000000, &id) == 0)
    {
        if (ctrl_checkSubject(id) == 0)
        {
            if (input_getString ("nombre: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 3, MAX_CHAR_NAMES, auxData1) == 0)
            {
                if (input_getString ("apellido: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHAR_NAMES, auxData2) == 0)
                {
                    ctrl_modifySubject (id, auxData1, auxData2);
                }
            }
        }
    }
}
static void deleteAd()
{
    int id = 0;

    if(input_getInt("Ingrese el id cliente: ", "\t** el id debe ser mayor a 0 **\n", MAX_REINGRESOS, 1, 99999, &id) == 0)
    {
        if(ctrl_checkProduct(id) == 0)
        {
            ctrl_deleteSubject(id);
        }
        else
        {
            printf("El ID ingresado no corresponde a ningun asociado\n");
        }
    }
}


static void debugShowAll()
{
    ctrl_debugShowAll();
}
