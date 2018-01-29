#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
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

        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
    {
        auxSocio = al_get(pListaSocios,i);
        printf("NOMBRE: %s- ID: %d - ESTADO: %d\n",soc_getNombre(auxSocio),soc_getId(auxSocio),soc_getEstado(auxSocio));
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
    cont_altaSocio(auxNombre,auxApellido,auxDni);

}

static void opcionBaja()
{
    char auxId[10];
    int id;
    val_getInt(auxId, "Id a borrar: \n", "Error\n", 2,10);
    id = atoi(auxId);
    cont_bajaSocio(id);
}

static void opcionModificacion()
{
    char auxId[10];
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[20];

    int id;

    val_getInt(auxId, "Id a modificar: \n", "Error\n", 2,10);
    val_getString(auxNombre, "Nombre?", "Error", 2, 50);
    val_getString(auxApellido, "Apellido?", "Error", 2, 50);
    val_getInt(auxDni, "Dni?", "Error\n", 2, 20);
    id = atoi(auxId);

    cont_modificarSocio(auxNombre, auxApellido, auxDni, id, SOCIO_ESTADO_ACTIVO);
}

static void opcionListado()
{
    cont_listarSocios();
}
