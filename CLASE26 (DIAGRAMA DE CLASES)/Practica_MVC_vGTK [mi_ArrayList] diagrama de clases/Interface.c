#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"
#include "ArrayList.h"
#include "Inputs.h"

#include "Controller.h"
#include "Interface.h"

#include "Socios.h"
#include "Servicios.h"
#include "Inscripciones.h"

static int idiomaInterface = VISTA_IDIOMA_ES;
//////////////////////////////////////////////
static void opcionAlta();
static void opcionAltaServicio();
static void opcionAltaInscripcion();

static void opcionModificar();
static void opcionModificarServicio();
static void opcionModificarInscripcion();

static void opcionBaja();
static void opcionBajaServicio();
static void opcionBajaInscripcion();

static void opcionListado();
//static void mostrarSociosPorServicio():
//////////////////////////////////////////////

int intr_init (int idioma)
{
    idiomaInterface = idioma;
    return 0;
}
int intr_mostrarMenu()
{
    char buffer[10];
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
    "*|  7. Inscripciones.      |    |  10. cant socios en cada |*",
    "*|                         |    |      servicio.           |*",
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


    while(opcion != 13)
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<26; i++)
        printf("   %s\n", menu[i]);
        val_getInt(buffer, "   Ingrese una opcion: ", MENU_PPAL_ERROR_ES, 2, 14);
        opcion = atoi(buffer);

        switch(opcion)
        {
            //////////////////////////////
            case 1:
                opcionAlta();
                break;
            case 2:
                opcionModificar();
                break;
            case 3:
                opcionBaja();
                break;
            //////////////////////////////
            case 4:
                opcionAltaServicio();
                break;
            case 5:
                opcionBajaServicio();
                break;
            case 6:
                opcionModificarServicio();
                break;
            //////////////////////////////
            case 7:
                opcionAltaInscripcion();
                break;
            case 8:
                opcionModificarInscripcion();
                break;
            case 9:
                opcionBajaInscripcion();
                break;
            //////////////////////////////
            case 10:
                //MostraraSociosPorServicio();
                break;
            case 11:
                //MostraraInscripcionesDeSocio();
                break;
            case 12:
                //MostraraSociosPorServicio();
                break;
            case 13:
                opcionListado();
                break;
            case 14:
                opcion = 14;
                break;
        }
    }
    return 0;
}
////////////////////////////////////////////////////////////
// MOSTRAR POR PANTALLA                                   //
////////////////////////////////////////////////////////////
static void opcionListado()
{
    ctrlr_listarServicios();
    ctrlr_listarSocios();
    ctrlr_listarInscripciones();
}
void intr_mostrarSocios(ArrayList* lista)
{
    int i;
    Socio* auxiliar;

    printf("   ________________________________________________________\n");
    printf("   listado de socios                                       \n");
    printf("   ID \t NOMBRE \t APELLIDO \t DNI \t     ESTADO\t  \n");
    for(i=0; i<al_len(lista); i++)
    {
        auxiliar = al_get(lista, i);

        if(auxiliar->estado == SOCIO_ACTIVO)
        {
            auxiliar = al_get(lista, i);

            printf("   %d\t", soc_getId (auxiliar));
            printf(" %s \t\t", soc_getNombre (auxiliar));
            printf(" %s \t\t", soc_getApellido (auxiliar));
            printf(" %s\t", soc_getDni (auxiliar));
            printf("%d\n", soc_getEstado(auxiliar));

        }
    }
    printf("   --------------------------------------------------------\n");
}
void intr_mostrarServicios(ArrayList* list)
{
    int i;
    Servicios* auxiliar;

    printf("   ____________________________________________\n");
    printf("   listado de servicios                        \n");
    printf("   ID \t NOMBRE \tDESCRIPCION \t ESTADO\t  \n");
    for(i=0; i<al_len(list); i++)
    {
        auxiliar = al_get (list, i);
        if(auxiliar->estado == SERVICIO_ACTIVO)
        {
            auxiliar = al_get(list, i);

            printf("   %d\t", svcs_getId(auxiliar));
            printf(" %s \t\t", svcs_getTitulo(auxiliar));
            printf(" %s \t\t", svcs_getDescripcion(auxiliar));
            printf("%d\n", svcs_getEstado(auxiliar));
        }
    }
    printf("   --------------------------------------------\n");
}
void intr_mostrarInscripciones (ArrayList* lista)
{
    int i;
    Inscripciones* auxiliar;

    printf("   ____________________________________________________________\n");
    printf("   listado de Inscripciones                                    \n");
    printf("   ID_INSCRIP\t ID_SOCIO\t ID_SERVICIO\t ESTADO\t\n");
    for(i=0; i<al_len(lista); i++)
    {
        auxiliar = al_get(lista, i);
        if(auxiliar->status == INSCRIPCION_ACTIVA)
        {
            auxiliar = al_get(lista, i);

            printf("   %d\t\t", insc_getID(auxiliar));
            printf(" %d\t\t", insc_getMemberID(auxiliar));
            printf(" %d\t\t", insc_getServiceID(auxiliar));
            printf(" %d\n", insc_getStatus(auxiliar));

        }
    }
    printf("   ------------------------------------------------------------\n");
}
/////////////////////////////////////////////////////////////









////////////////////////////////////////////////////////////
// ALTAS                                                  //
////////////////////////////////////////////////////////////
static void opcionAlta()
{
    char auxNombre [MAX_CHARS_NOMBRES +1];
    char auxApellido [MAX_CHARS_NOMBRES +1];
    char auxDni [MAX_CHARS_DNI +1];

    /* solicito nombre de pantalla */
    if (input_getString ("NOMBRE: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_NOMBRES, auxData2) == 0)
    {
        /* solicito nombre de pantalla */
        if (input_getString ("APELLIDO: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DESCRIPCIONES, auxData3) == 0)
        {
            /*solicito locacion de pantalla */
            if (input_getNumericStr ("DNI: ", "\t** el dni debe estar compuesto de 3 a 20 caracteres. **\n\n", MAX_REINGRESOS, 2, MAX_CHARS_DIRECCIONES, auxData4) == 0)
            {
                ctrlr_altaSocio (auxNombre, auxApellido, auxDni);
            }
        }
    }    
    return retorno;
}
static void opcionAltaServicio()
{
    char titulo [MAX_CHAR_TITULOS];
    char descripcion [MAX_CHAR_DESCRIPCIONES];

    if(val_getString(titulo, "titulo? ", "Error",2,50) == 0)
    {
        if(val_getString(descripcion, "descripcion? ", "Error",2,50) == 0)
        {
            ctrlr_altaServicio (titulo, descripcion);
        }
    }
    else
    {
        printf("error");
    }
}
static void opcionAltaInscripcion()
{
    char memberID[256];
    char serviceID[256];

    if(val_getInt(memberID, "id de socio?", "Error", 2, 50) == 0)
    {
        if( ctrlr_checkSocio(atoi(memberID)) == 0)
        {
            ctrlr_listarServicios();
            if(val_getInt(serviceID, "codigo de actividad? ", "Error", 2, 50) == 0)
            {
                if( ctrlr_checkServicio(atoi(serviceID)) == 0)
                {
                    ctrlr_altaInscripcion (atoi(serviceID), atoi(memberID));

                }else{printf("codigo de servicio inexistente o inactivo\n\n");}
            }

        }else{printf("socio inexistente o inactivo\n\n");}

    }else{printf("error");}
}

////////////////////////////////////////////////////////////
// MODIFICACIONES                                         //
////////////////////////////////////////////////////////////
static void opcionModificar()
{
    char auxId[256];
    int id;
    int estado;
    char auxNombre[256];
    char auxApellido[256];
    char auxDni[256];
    char auxEstado[256];

    if((val_getUnsignedInt(auxId,"Id a modificar", "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                    {
                        estado=atoi(auxEstado);
                        if(estado == 0 || estado == 1)
                        {
                            ctrlr_modificarSocio(auxNombre,auxApellido,auxDni,id,estado);
                        }
                    }
                }
            }
        }
    }
}
static void opcionModificarServicio()
{
    char id[256];
    char titulo[256];
    char descripcion[256];
    char estado[256];

    if((val_getUnsignedInt (id,"Id a modificar", "Error",2,10)==0))
    {
        if(val_getString (descripcion, "titulo? ", "Error",2,50)==0)
        {
            if(val_getString (descripcion, "Descripcion? ", "Error",2,50)==0)
            {
                if(val_getUnsignedInt (estado,"Estado?\nACTIVO= 0\nINACTIVO = 1", "Error",2,5)==0)
                {
                    if(atoi(estado) == 0 || atoi(estado) == 1)
                    {
                        ctrlr_modificarServicio(titulo, descripcion, atoi(id), atoi(estado));
                    }
                }
            }
        }
    }
}
static void opcionModificarInscripcion()
{
    char id[256];
    char code[256];
    char status[256];


    if((val_getInt (id,"id Socio?", "Error",2,10)==0))
    {
        if( ctrlr_checkSocio (atoi(id)) == 0)
        {
            ctrlr_listarInscripciones();
            if(val_getInt (code, "codigo inscripcion? ", "Error", 2, 50) == 0)
            {
                if(val_getInt (status, "estado? ", "Error", 2, 50) == 0)
                {
                    if(val_getUnsignedInt(status, "Estado?\nACTIVO = 0\nINACTIVO = 1", "Error", 2, 5) == 0)
                    {
                        if(atoi(status) == 0 || atoi(status) == 1)
                        {
                            ctrlr_modificarInscripcion( atoi(id), atoi(status));
                        }
                    }
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////
// BAJAS                                                  //
////////////////////////////////////////////////////////////
static void opcionBaja()
{
    char auxId[256];
    int id;

    if( (val_getUnsignedInt (auxId, "Id a dar de baja", "Error", 2, 10) == 0) )
    {
        id = atoi(auxId);
        ctrlr_bajaSocio(id);
    }
}
static void opcionBajaServicio()
{
    char auxId[256];
    int id;

    if((val_getUnsignedInt(auxId, "Id a dar de baja", "Error",2,10)==0))
    {
        id = atoi(auxId);
        ctrlr_bajaServicio(id);
    }
}
static void opcionBajaInscripcion()
{
    char auxId[256];
    int id;

    if( (val_getUnsignedInt(auxId,"Id a dar de baja", "Error", 2, 10) == 0) )
    {
        id = atoi(auxId);
        ctrlr_bajaServicio(id);
    }
}
////////////////////////////////////////////////////////////



//static void mostrarSociosPorServicio ()
//{
//    char serviceID[256];
//
//    //intr_mostrarServicios();
//    val_getString(serviceID, "seleccione la actividad a la cual desea conocer los inscriptos: ", "Error", 2, 50);
//    if(ctrlr_checkServicio(atoi(serviceID)) == 0)
//    {
//        //intr_mostrarInscriptos(atoi(serviceID));
//    }
//    else
//    {
//        printf("el codigo ingresado no corresponde a ningun servicio activo");
//    }
//}
//
//int intr_mostrarInscriptos(ArrayList* lista1, ArrayList* lista2, int serviceID)
//{
//    int i;
//    Inscripciones* auxiliar1;
//    Socio* auxiliar2;
//
//    printf("   ________________________________________________________\n");
//    printf("   listado de socios inscriptos en actividad: \t\n");
//    printf("   ID \t NOMBRE \t APELLIDO \t DNI \t     ESTADO\t  \n");
//    for(i=0; i<al_len(lista1); i++)
//    {
//        auxiliar1 = al_get(lista1, i);
//
//        if(auxiliar1->status == INSCRIPCION_ACTIVA && auxiliar1->serviceID == serviceID)
//        {
//            auxiliar2 = al_get(lista2, auxiliar1->memberID);
//
//            printf("   %d\t", soc_getId (auxiliar2));
//            printf(" %s \t\t", soc_getNombre (auxiliar2));
//            printf(" %s \t\t", soc_getApellido (auxiliar2));
//            printf(" %s\t", soc_getDni (auxiliar2));
//            printf("%d\n", soc_getEstado(auxiliar2));
//
//        }
//    }
//    printf("   --------------------------------------------------------\n");
//}








void mostrarError(char*);



