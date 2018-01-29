#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "inputs.h"


static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    setNewId(0);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios, auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio = soc_findById(nominaSocios, id);
    if(auxSocio != NULL)
    {
        soc_setEstado(auxSocio, SOCIO_ESTADO_INACTIVO);
    }
    return 0;
}


int cont_modificarSocio (char* nombre, char* apellido, char* dni, int id, int estado)
{
    int retorno = -1;
    int idBox = 0;
    Socio* aux = NULL;

        if (input_getInt ("   ingrese el id del cliente: ", "\t** el id de la pantalla debe ser mayor a 0 **\n\n", 3, 0, 1000000, &idBox) == 0)
        {
            /* busco id */
            aux = soc_findById(nominaSocios, idBox);
            if (aux != NULL)
            {
                if( soc_resetData(aux, nombre, apellido, dni) == 0 )
                {
                    printf("   ** los datos han sido modificados con exito **\n\n");
                    retorno = 0;
                }
                else
                {
                    printf("   ** no se gaurdaron los datos ingresados **\n\n");
                    retorno = -1;
                }
            }
        }

    return retorno;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
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
