#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Servicio.h"
#include "Vista.h"
#include "DataManager.h"
#include "inputs.h"
#include "cliente.h"



static ArrayList* nominaClientes;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

static ArrayList* listaServicios;
static int proximoIdServicios=0;
static int getNewIdServicios();
static int setNewIdServicios(int id);

void cont_init(void)
{
    // Creacion del modelo de datos
    nominaClientes = al_newArrayList();
    setNewId(dm_readAllClientes(nominaClientes) + 1);

    listaServicios = al_newArrayList();
    setNewIdServicios(dm_readAllServicios(listaServicios) + 1);

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


static int getNewIdServicios()
{
    return proximoIdServicios++;
}

static int setNewIdServicios(int id)
{
    proximoIdServicios = id;
    return 0;
}

int cont_importarClientes()
{
    FILE *pFile;
	Cliente* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50];

    pFile = fopen("clientes.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3) >0)
			{
				if(valid_verifyString(var1) != -1 &&
                   valid_verifyString(var2) != -1 &&
                   valid_verifyStrNumbr(var3) != -1)
				{
					auxiliar = cliente_new(var1, var2, var3, proximoIdSocio+1, CLIENTE_ESTADO_ACTIVO);

					al_add(nominaClientes, auxiliar);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}

int cont_existeCliente (int id)
{
    Cliente *auxiliar;
    int retorno = 0;
    auxiliar = cliente_findById(nominaClientes,id);
    if(auxiliar != NULL)
    {
        if(cliente_getEstado(auxiliar)==CLIENTE_ESTADO_ACTIVO)
            retorno = 1;
    }

    return retorno;
}

int cont_altaServicio(int idCliente,char* idProducto,float costoReparacion, char* fecha)
{
    Servicio* auxiliar;

    auxiliar = servicio_new(getNewIdServicios(), SERVICIO_ACTIVO,idCliente,idProducto,costoReparacion, fecha);

    al_add (listaServicios, auxiliar);
    dm_saveAllServicios(listaServicios);

    return 0;
}

int cont_exportarServiciosTecnicos(char* fecha)
{
    dm_exportarServiciosTecnicos(nominaClientes, listaServicios, fecha);
    return 0;
}
