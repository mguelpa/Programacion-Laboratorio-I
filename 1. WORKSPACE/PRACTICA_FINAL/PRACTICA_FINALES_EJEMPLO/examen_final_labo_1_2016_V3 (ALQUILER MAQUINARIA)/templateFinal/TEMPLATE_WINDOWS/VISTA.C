#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"
#include "inputs.h"

#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

#include "Cliente.h"
#include "Alquiler.h"

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();

static void opcionNuevoAlquiler();
static void opcionFinDelAlquiler();

static void opcionInformar();


static void opcionAltaX();
static void opcionBajaX();
static void opcionModificacionX();
static void opcionListadoX();
static void opcionOrdenarX();

int vista_mostrarMenu()
{
    int option=0;

    while(option != 10)
    {
        input_getInt(MENU_PPAL_ES, MENU_PPAL_ERROR_ES, 3, 1, 8, &option);
        switch(option)
        {
            case 1:
                opcionListadoCliente();
                break;
            case 2:
                opcionAltaCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionModificacionCliente();
                break;
            case 5:
                opcionOrdenarCliente();
                break;
///////////////////////////////////////////
            case 6:
                opcionNuevoAlquiler();
                break;
            case 7:
                opcionFinDelAlquiler();
                break;
            case 8:
                opcionInformar();
                break;
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
void vista_mostrarX(ArrayList* pListaSocios)
{
    printf("\nIMPRIMO LISTA DE ENTIDAD X\n");
}
void mostrarError(char* mensaje)
{
    printf("\nIMPRIMO ERROR\n");
}


///////////////////////////////////////////////////////
static void opcionAltaCliente()
{
    char a[50];
    char b[50];
    char c[50];
    if(val_getString(a, "NOMBRE? ", "Error",2,50) == 0 &&
       val_getString(b, "APELLIDO? ", "Error",2,50) == 0 &&
       val_getInt(c, "DNI? ", "Error",2,50) == 0)
    {
        cont_altaCliente(a,b,c);
    }
}
static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }
}
static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "NOMBRE? ", "Error",2,50) == 0 &&
           val_getString(b, "APELLIDO? ", "Error",2,50) == 0 &&
           val_getInt(c, "DNI? ", "Error",2,50) == 0)
        {
            cont_modificarCliente(id,a,b,c);
        }
    }
}
static void opcionListadoCliente()
{
    cont_listarCliente();
}
static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}
void vista_mostrarCliente(ArrayList* listaClientes)
{
    al_map(listaClientes,cliente_imprimir);
}


////////////////////////////////////////////////////
static void opcionNuevoAlquiler()
{
	int idCliente;
	int idEquipo;
	int tiempoEstimado;


    //ingrese el id del clinete

    if(input_getInt("ingrese el id de cliente: ", "numero fuera de rango", 3, 0, 999, &idCliente) == 0)
    {
        if(cont_existeCliente(idCliente) == 1)
        {
            if (input_getInt("ingrese el ID del equipo:\n\n"
                                    "1. taladro neumatico\n"
                                    "2. soldador MIG/TIG\n"
                                    "3. martillo neumatico\n"
                                    "4. cierra de banco\n",
                                    "equipo inexistente", 3, 1, 4, &idEquipo) == 0)
            {
                if(input_getInt("ingrese el tiempo estimado de alquiler (dias): ", "error", 3, 1, 365, &tiempoEstimado) == 0)
                {
                    cont_altaAlquiler(idCliente, idEquipo, tiempoEstimado);
                }

            }
        }else{printf("no existe cliente!!!\n");}
    }
}
static void opcionFinDelAlquiler()
{
	int idCliente;
	int idAlquiler;
	int tiempoReal;


    //ingrese el id del clinete

    if(input_getInt("ingrese el id de cliente: ", "numero fuera de rango", 3, 0, 999, &idCliente) == 0)
    {
        if(cont_existeCliente(idCliente) == 1)
        {
            vista_mostrarAlquileres(idCliente);
            if (input_getInt("ingrese el ID del alquiler a finalizar: ", "alquiler inexistente", 3, 0, 999, &idAlquiler) == 0)
            {
                if(cont_existeAlquiler(idAlquiler, idCliente) == 1)
                {
                    if(input_getInt("ingrese el tiempo real de alquiler (dias): ", "error", 3, 1, 365, &tiempoReal) == 0)
                    {
                        cont_bajaAlquiler(idAlquiler, tiempoReal);
                    }
                }else{printf("el alquiler no existe!!\n\n");}
            }
        }else{printf("el cliente no existe!!\n\n");}
    }
}
void vista_mostrarAlquileres(int idClinete)
{
    cont_imprimirCamposAlquiler(idClinete);
}
static void opcionInformar()
{
    cont_asociadoConMasAlquileres();
    cont_equipoMasAlquilado();
    cont_tiempoPromedioDeAlquilerXEquipo();
}




