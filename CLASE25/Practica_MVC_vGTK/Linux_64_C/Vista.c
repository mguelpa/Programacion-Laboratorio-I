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
        auxSocio = al_get(pListaSocios, i);

        printf("status:   %d\n", soc_getEstado(auxSocio));
        printf("id:       %d\n", soc_getId(auxSocio));

        printf("nombre:   %s\n", soc_getNombre(auxSocio));
        printf("apellido: %s\n", soc_getApellido(auxSocio));
        printf("dni:      %s\n", soc_getDni(auxSocio));
        printf("________________________________\n\n");
        //printf("NOMBRE: %s- ID: %d\n",soc_getNombre(auxSocio),soc_getId(auxSocio));
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
    char auxId[18];
    int id;
    val_getInt(auxId,"ingrese el id del socio: ", "sarasa", 2, 18);
    id = atoi(auxId);
    cont_bajaSocio(id);

}

static void opcionModificacion()
{

}

static void opcionListado()
{
    cont_listarSocios();
}
