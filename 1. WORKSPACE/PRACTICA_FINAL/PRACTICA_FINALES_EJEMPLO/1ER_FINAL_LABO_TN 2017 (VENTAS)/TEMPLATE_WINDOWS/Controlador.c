#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Controlador.h"
#include "Vista.h"

#include "Cliente.h"

////////////////////////////////////////
static ArrayList* listaX;
static int proximoIdX=0;
static int getNewIdX();
static int setNewIdX(int id);

static ArrayList* listaCliente;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);


void cont_init()
{
    listaX = al_newArrayList();
    setNewIdX(dm_readAllX(listaX) + 1);

    listaCliente = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(listaCliente) + 1);





    vista_mostrarMenu();
}



////////////////////////////////////////
// para cada entidad                  //
////////////////////////////////////////
static int getNewIdX()
{
    return proximoIdX++;
}
static int setNewIdX(int id)
{
    proximoIdX = id;
    return 0;
}

int cont_altaX (char* a,char* b,int c)
{
    return 0;
}
int cont_bajaX (int id)
{
    return 0;
}
int cont_modificarX (int id, char* a,char* b,int c)
{
    return 0;
}


int cont_listarX ()
{
    //vista_mostrarX(nominaX);
    return 0;
}
int cont_ordenarX ()
{
    return 0;
}
////////////////////////////////////////

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
        if(cliente_getClientStatus(auxiliar) != CLIENTE_ESTADO_ALTA && cliente_getClientStatus(auxiliar) != CLIENTE_ESTADO_COMPRA)
        {
            cliente_setClientStatus(auxiliar,CLIENTE_ESTADO_BAJA);
        }
        else if (cliente_getClientStatus(auxiliar) == CLIENTE_ESTADO_BAJA)
        {
            printf("el cliente ya fue dado de baja!!!\n");
        }else{printf("el cliente posee una compra");}
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
        if(cliente_getClientStatus(auxiliar)==CLIENTE_ESTADO_ALTA)
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

////////////////////////////////////////////////////////////////////////////////
