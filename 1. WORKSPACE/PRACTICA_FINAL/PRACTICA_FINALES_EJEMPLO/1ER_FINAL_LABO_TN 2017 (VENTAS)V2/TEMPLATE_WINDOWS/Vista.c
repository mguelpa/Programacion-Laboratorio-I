#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

#include "Cliente.h"

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();

static void opcionListadoCliente();
static void opcionOrdenarCliente();

static void opcionNuevaVenta();
static void opcionAnularVenta();

static void opcionInformarVentas();
static void opcionInformarVentasPorProducto();
static void opcionGenerarInformeDeVentas();
static void opcionInformarCantidadDeVentasPorClientes();

int vista_mostrarMenu()
{
    int option=0;

    while(option != 10)
    {
        input_getInt(MENU_PPAL_ES, MENU_PPAL_ERROR_ES, 3, 1, 10, &option);
        system("cls");
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
                opcionNuevaVenta();
                break;
            case 6:
                opcionAnularVenta();
                break;
///////////////////////////////////////////
            case 7:
                opcionInformarVentas();
                break;
            case 8:
                opcionInformarVentasPorProducto();
                break;
            case 9:
                opcionGenerarInformeDeVentas();
                break;
            case 10:
                opcionInformarCantidadDeVentasPorClientes();
                break;
        }
    }

    return 0;
}

//////////////////////////////////////////////
static void opcionAltaCliente()
{
    char nombre[50];
    char apellido[50];
    char dni[50];
    if(input_getString("nombre: ", "\t** el nombre debe estar compuesto de 3 a 20 caracteres. **\n\n", 3, 2, 50, nombre) == 0 &&
       input_getString("apellido: ", "\t** el apellido debe estar compuesto de 3 a 20 caracteres. **\n\n", 3, 2, 50, apellido) == 0 &&
       input_getNumericStr("dni: ", "error", 3, 3500000, 50500000, dni) == 0)
    {
        cont_altaCliente(nombre,apellido,dni);
    }
}
static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja: " , "Error",2,10)==0))
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

    if((val_getUnsignedInt(auxId,"Id a modificar: " , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(cont_existeCliente(id) == 1)
        {
            if(val_getString(a, "nombre: ", "Error",2,50) == 0 &&
               val_getString(b, "apellido: ", "Error",2,50) == 0 &&
               val_getInt(c, "dni: ", "Error",2,50) == 0)
            {
                cont_modificarCliente(id,a,b,c);
            }
        }else{printf("el cliente no existe!!\n\n");}
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

//////////////////////////////////////////////
static void opcionNuevaVenta()
{
	int idCliente;
	int idProducto;
	int cantidad;


    //ingrese el id del clinete

    if(input_getInt("ingrese el id de cliente: ", "numero fuera de rango", 3, 0, 999, &idCliente) == 0)
    {
        if(cont_existeCliente(idCliente) == 1)
        {
            if (input_getInt("ingrese el ID del producto:\n\n"
                                    "TV_LG_32: cod. 1000\n"
                                    "PS4: cod. 1001\n"
                                    "IPHONE7: cod. 1002\n",
                                    "producto inexistente\n", 3, 1, 4, &idProducto) == 0)
            {
                if(input_getInt("ingrese la cantidad de productos: ", "error", 3, 1, 365, &cantidad) == 0)
                {
                    cont_altaVenta(idCliente, idProducto, cantidad);
                }
            }
        }else{printf("no existe cliente!!!\n");}
    }
}
static void opcionAnularVenta()
{
    char auxIdCliente[10];
    char auxIdVenta[10];


    if((val_getUnsignedInt(auxIdCliente,"Id del cliente: " , "Error",2,10)==0))
    {
        if(cont_existeCliente(atoi(auxIdCliente)) == 1)
        {
            cont_imprimirCamposVentaPorIdCliente(atoi(auxIdCliente));
            if((val_getUnsignedInt(auxIdVenta,"Id de la venta a finalizar: " , "Error",2,10)==0))
            {
                if(cont_existeVenta(atoi(auxIdVenta)) == 1)
                {
                    cont_bajaVenta(atoi(auxIdVenta));

                }else{printf("el ID ingresado no corresponde a ninguna venta\n");}
            }
        }else{printf("el ID ingresado no corresponde a ningun cliente\n");}
    }
}


void vista_mostrarVentas(int idClinete)
{
    cont_imprimirCamposVentaPorIdCliente(idClinete);
}



static void opcionInformarVentas()
{
    cont_mostrarVentasPorCliente();
}
static void opcionInformarVentasPorProducto()
{
    cont_mostrarVentasPorProducto();
}
static void opcionGenerarInformeDeVentas()
{
    cont_genrarArchivoInforme();
}
static void opcionInformarCantidadDeVentasPorClientes()
{
    cont_mostrarVentasPorCliente();
}



