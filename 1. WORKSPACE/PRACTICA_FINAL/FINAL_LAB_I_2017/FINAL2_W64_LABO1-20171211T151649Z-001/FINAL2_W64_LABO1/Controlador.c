#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Servicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaClientes;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

void cont_init(void)
{
    // Creacion del modelo de datos
    nominaClientes = al_newArrayList();
    setNewId(dm_readAllClientes(nominaClientes) + 1);
    //______________________________

    vista_init();

    vista_mostrarMenu(); // bloqueante, nunca sale de esta funcion. no poner nada debajo de esta linea
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxSocio;
    auxSocio = cliente_new(nombre,apellido,dni,getNewId(),CLIENTE_ESTADO_ACTIVO);
    if(auxSocio!=NULL)
    {
        al_add(nominaClientes,auxSocio);
        dm_saveAllClientes(nominaClientes);
        return 0;
    }
    return -1;
}

int cont_bajaCliente (int id)
{
    Cliente* auxSocio;
    auxSocio=cliente_findById(nominaClientes,id);
    if(auxSocio!=NULL)
    {
        cliente_setEstado(auxSocio,CLIENTE_ESTADO_INACTIVO);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}


int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id)
{
    Cliente* auxSocio;

    auxSocio=cliente_findById(nominaClientes,id);

    if(auxSocio!=NULL)
    {
        cliente_setNombre(auxSocio,nombre);
        cliente_setApellido(auxSocio,apellido);
        cliente_setDni(auxSocio,dni);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}

int cont_listarClientes (void)
{
    vista_mostrarSocios(nominaClientes);
    return 0;
}


static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}
