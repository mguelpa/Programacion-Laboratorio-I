#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "inputs.h"

#include "Cliente.h"
#include "Servicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"


static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

static void opcionImportarClientes();
static void opcionIngresoServicioTecnico();
static void opcionExportarServiciosTenicosDeFecha();




int vista_init (void)
{
    return 0;
}

int vista_mostrarMenu(void)
{
    char buffer[10];
    int option=0;

    while(option != 10)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
                opcionAlta();
                break;
            case 3:
                opcionBaja();
                break;
            case 4:
                opcionModificacion();
                break;
            // HACER
            case 5:
            {
                opcionImportarClientes();
                break;
            }
            case 6:
            {
                opcionIngresoServicioTecnico();
                break;
            }
            case 7:
            {
                opcionExportarServiciosTenicosDeFecha();
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            //_______
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Cliente* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==CLIENTE_ESTADO_ACTIVO)
            {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",cliente_getNombre(auxSocio),
                            cliente_getApellido(auxSocio),cliente_getId(auxSocio),cliente_getDni(auxSocio));
            }
        }

}


void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaCliente(auxNombre,auxApellido,auxDni);

}

static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    cont_modificarCliente(auxNombre,auxApellido,auxDni,id);
                }
            }
        }
    }
}

static void opcionListado()
{
    cont_listarClientes();
}

static void opcionImportarClientes()
{
    cont_importarClientes();
}

static void opcionIngresoServicioTecnico()
{
    int idCliente;
    char idProducto[50];
    float costoReparacion;
    char fecha[50];


    //ingrese el id del clinete

    if(input_getInt("ingrese el id de cliente: ", "numero fuera de rango", 3, 0, 999, &idCliente) == 0)
    {
        if(cont_existeCliente(idCliente) == 1)
        {
            if (input_getAnumericStr("ingrese el ID del producto:\n\n"
                                     "\nTV_LG_32: cod. A123"
                                     "\nPS4: cod. B456"
                                     "\nIPHONE7: cod. C789\n","error!!\n", 3, 4, 4, idProducto) == 0)
            {
                if(strcmp(idProducto, "A123") == 0 || strcmp(idProducto, "B456") == 0 || strcmp(idProducto, "C789") == 0)
                {
                    if(input_getFloat("ingrese el costo de la reparacion: ", "error\n", 3, 1, 900000, &costoReparacion) == 0)
                    {
                        if(val_getString("ingrese la fecha de la reparacion: ", "error", 3, 1, 20, fecha) == 0)
                        {
                           // printf("")
                            //fgets(fecha,50, stdin);
                            cont_altaServicio(idCliente, idProducto, costoReparacion, fecha);
                        }
                    }
                }
            }
        }
        else
        {
            printf("no existe cliente!!!\n");
        }
    }
}


static void opcionExportarServiciosTenicosDeFecha()
{
    char fecha[50];
    if(input_getString("ingrese la fecha: ", "error", 3, 8, 8, fecha) == 0)
    cont_exportarServiciosTecnicos(fecha);
}

