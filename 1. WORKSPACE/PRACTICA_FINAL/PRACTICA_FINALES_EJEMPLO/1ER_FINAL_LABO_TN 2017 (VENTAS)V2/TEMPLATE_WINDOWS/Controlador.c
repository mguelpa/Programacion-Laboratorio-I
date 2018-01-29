#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Controlador.h"
#include "Vista.h"

#include "Cliente.h"
#include "Venta.h"


static ArrayList* listaCliente;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static ArrayList* listaVenta;
static int proximoIdVenta=0;
static int getNewIdVenta();
static int setNewIdVenta(int id);


void cont_init()
{
    listaCliente = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(listaCliente) + 1);

    listaVenta = al_newArrayList();
    setNewIdVenta(dm_readAllVentas(listaVenta) + 1);

    vista_mostrarMenu();
}
////////////////////////////////////////
// ENTIDAD CLIENTE                    //
////////////////////////////////////////
static int getNewIdCliente()
{
    return proximoIdCliente++;
}
static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_altaCliente(char* nombre,char* apellido,char* dni)
{
    Cliente* auxiliar;

    auxiliar = cliente_new (getNewIdCliente(), CLIENTE_ESTADO_ALTA, nombre, apellido, dni);

    al_add (listaCliente, auxiliar);
    dm_saveAllClientes (listaCliente);
    return 0;
}
int cont_bajaCliente(int id)
{
    Cliente *auxiliar;
    auxiliar = cliente_findByClientID(listaCliente,id);
    if(auxiliar != NULL)
    {
        if(cliente_getClientStatus(auxiliar) == CLIENTE_ESTADO_ALTA)
        {
            cliente_setClientStatus(auxiliar,CLIENTE_ESTADO_BAJA);
            dm_saveAllClientes(listaCliente);
        }
        else if (cliente_getClientStatus(auxiliar) == CLIENTE_ESTADO_BAJA)
        {
            printf("el cliente ya fue dado de baja!!!\n");
        }else{printf("el cliente posee compras activas, no se podra dar de baja hasta que se finalizen las compras.\n");}
    }else{printf("el cliente no existe!!!\n");}
    return 0;
}
int cont_modificarCliente(int id, char* a,char* b,char* c)
{
    Cliente *auxiliar;
    auxiliar = cliente_findByClientID(listaCliente,id);
    if(auxiliar != NULL)
    {
        if(cliente_getClientStatus(auxiliar)==CLIENTE_ESTADO_ALTA)
        {
            cliente_setNombre(auxiliar,a);
            cliente_setApellido(auxiliar,b);
            cliente_setDni(auxiliar,c);
            dm_saveAllClientes(listaCliente);
        }
    }
    return 0;
}

int cont_existeCliente(int id)
{
    Cliente *auxiliar;
    int retorno = 0;
    auxiliar = cliente_findByClientID(listaCliente,id);
    if(auxiliar != NULL)
    {
        if(cliente_getClientStatus(auxiliar)==CLIENTE_ESTADO_ALTA || cliente_getClientStatus(auxiliar)==CLIENTE_ESTADO_COMPRA)
            retorno = 1;
    }

    return retorno;
}
int cont_listarCliente()
{
    cont_ordenarCliente(listaCliente);
    vista_mostrarCliente(listaCliente);
    return 0;
}
int cont_ordenarCliente()
{
    al_sort(listaCliente,cliente_compareByNombre,1);
    return 0;
}
////////////////////////////////////////



////////////////////////////////////////
// ENTIDAD VENTAS                     //
////////////////////////////////////////
static int getNewIdVenta()
{
    return proximoIdVenta++;
}
static int setNewIdVenta(int id)
{
    proximoIdVenta = id;
    return 0;
}

int cont_altaVenta(int idCliente, int idProducto, int cantidad)
{
    Venta* auxiliar;

    auxiliar = venta_new (getNewIdVenta(), VENTA_ACTIVA, idCliente, idProducto, cantidad);
    cliente_setClientStatus(cliente_findByClientID(listaCliente, idCliente), CLIENTE_ESTADO_COMPRA);

    al_add (listaVenta, auxiliar);
    dm_saveAllVentas (listaVenta);
    dm_saveAllClientes(listaCliente);
    return 0;
}
int cont_bajaVenta(int id)
{
    Venta *auxiliar;
    auxiliar = venta_findByVentaID(listaVenta, id);
    if(auxiliar != NULL)
    {
        if(venta_getVentaStatus(auxiliar) != VENTA_FINALIZADA)
        {
            venta_setVentaStatus(auxiliar,VENTA_FINALIZADA);
        }
    }else{printf("el cliente no existe!!!\n");}
    return 0;
}


int cont_existeVenta(int id)
{
    Venta *auxiliar;
    int retorno = 0;
    auxiliar = venta_findByVentaID(listaVenta,id);
    if(auxiliar != NULL)
    {
        if(venta_getVentaStatus(auxiliar)==VENTA_ACTIVA)
            retorno = 1;
    }
    return retorno;
}

int cont_imprimirCamposVentaPorIdCliente(int idCliente)
{
    Venta* auxiliar;
    int i;

    for(i=0; i<al_len(listaVenta); i++)
    {
        auxiliar = al_get(listaVenta, i);
        if(venta_getClientID(auxiliar) == idCliente)
        venta_imprimir(auxiliar);
    }
    return 0;
}

int cont_imprimirCamposVentaPorIdProducto(int idProducto)
{
    Venta* auxiliar;
    int i;

    for(i=0; i<al_len(listaVenta); i++)
    {
        auxiliar = al_get(listaVenta, i);
        if(venta_getProductID(auxiliar) == idProducto)
        {
            venta_imprimir(auxiliar);
            venta_setVentaStatus(auxiliar, VENTA_MOSTRADA);
        }
    }
    return 0;
}
int cont_mostrarVentasPorCliente()
{
    int i;
    Cliente* auxiliar;

    for(i=0; i<al_len(listaCliente); i++)
    {
        auxiliar = al_get(listaCliente, i);

        if(auxiliar!=NULL && cliente_getClientStatus(auxiliar) == CLIENTE_ESTADO_COMPRA)
        {
            printf("ventas para el cliente: %s, %s\n", cliente_getApellido(auxiliar), cliente_getNombre(auxiliar));
            printf("-------------------------------------------\n");
            cont_imprimirCamposVentaPorIdCliente(cliente_getClientID(auxiliar));
            printf("-------------------------------------------\n\n");
            cont_sumarComprasPorIdCliente(cliente_getClientID(auxiliar));
        }

    }
    return 0;
}

int cont_mostrarVentasPorProducto()
{
    char herramientas[5][50] = {"empty", "Taladro Neumatico", "Soldador MIG/TIG", "Martillo Neumatico", "Cierra de banco"};

    int i;
    Venta* auxiliar;

    for(i=0; i<al_len(listaVenta); i++)
    {
        auxiliar = al_get(listaVenta, i);
        if(auxiliar!=NULL && venta_getVentaStatus(auxiliar) == VENTA_ACTIVA)
        {
            printf("ventas para el producto: %s\n", herramientas[venta_getProductID(auxiliar)]);
            printf("-------------------------------------------\n");
            cont_imprimirCamposVentaPorIdProducto(venta_getProductID(auxiliar));
            printf("-------------------------------------------\n\n");

        }
    }

    for(i=0; i<al_len(listaVenta); i++)
    {
        auxiliar = al_get(listaVenta, i);
        if(auxiliar!=NULL && venta_getVentaStatus(auxiliar) == VENTA_MOSTRADA)
        {
            venta_setVentaStatus(auxiliar, VENTA_ACTIVA);
        }
    }

    return 0;
}

int cont_genrarArchivoInforme()
{
    dm_genrarArchivoInforme(listaVenta, listaCliente);
    return 0;
}

int cont_sumarComprasPorIdCliente(idCliente)
{
    float acumuladorDeVentas = 0;
    Venta* auxiliar;
    int i;

    for(i=0; i<al_len(listaVenta); i++)
    {
        auxiliar = al_get(listaVenta, i);
        if(venta_getClientID(auxiliar) == idCliente)
        {
            switch(venta_getProductID(auxiliar))
            {
                case 1000:
                    acumuladorDeVentas = acumuladorDeVentas + (venta_getCantidad(auxiliar) * 8999.99);
                    break;
                case 1001:
                    acumuladorDeVentas = acumuladorDeVentas + (venta_getCantidad(auxiliar) * 12999.99);
                    break;
                case 1002:
                    acumuladorDeVentas = acumuladorDeVentas + (venta_getCantidad(auxiliar) * 19480.99);
                    break;
            }
        }
        printf("el total a bonar es: $%.2f", acumuladorDeVentas);
    }
    return 0;
}
////////////////////////////////////////

