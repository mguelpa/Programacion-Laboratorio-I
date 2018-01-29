#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "Inscripciones.h"

#include "Vista.h"
#include "DataManager.h"

static ArrayList* listaSocios;
static ArrayList* listaServicios;
static ArrayList* listaInscripciones;

static int proximoIdSocio = 0;
static int proximoIdServicios = 0;
static int proximoIdInscripciones = 0;


static int getNewIdSocios ();
static int setNewIdSocios (int id);

static int getNewIdServicios ();
static int setNewIdServicios (int id);

static int getNewIdInscripciones ();
static int setNewIdInscripciones (int id);

/////////////////////////////////////////////////////////////
static int getNewIdSocios()
{
    return proximoIdSocio++;
}
static int getNewIdServicios()
{
    return proximoIdServicios++;
}
static int getNewIdInscripciones()
{
    return proximoIdInscripciones++;
}
/////////////////////////////////////////////////////////////
static int setNewIdSocios(int id)
{
    proximoIdSocio = id;
    return 0;
}
static int setNewIdServicios(int id)
{
    proximoIdServicios = id;
    return 0;
}
static int setNewIdInscripciones(int id)
{
    proximoIdInscripciones = id;
    return 0;
}




////////////////////////////////////////////////////////////
void ctrlr_init()
{
    listaSocios = al_newArrayList();
    listaServicios = al_newArrayList();
    listaInscripciones = al_newArrayList();

    setNewIdSocios ( dm_readAllSocios(listaSocios) + 1 );
    setNewIdServicios ( dm_readAllServicios(listaServicios) + 1 );
    setNewIdInscripciones ( dm_readAllInscripciones(listaInscripciones) + 1 );

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}




////////////////////////////////////////////////////////////
// ALTAS                                                  //
////////////////////////////////////////////////////////////
int ctrlr_altaSocio (char* nombre, char* apellido, char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre, apellido, dni, getNewIdSocios(), SOCIO_ESTADO_ACTIVO);
    al_add (listaSocios, auxSocio);

    dm_saveAllSocios(listaSocios);
    return 0;
}
int ctrlr_altaServicio (char* titulo, char* descripcion)
{
    Servicios* auxServicio;
    auxServicio = svcs_new(titulo, descripcion, getNewIdServicios(), SERVICIO_ACTIVO);
    al_add (listaServicios, auxServicio);
    dm_saveAllServicios(listaServicios);
    return 0;
}
int ctrlr_altaInscripcion (int serviceID, int memberID)
{
    Inscripciones* auxiliar;
    auxiliar = insc_new(serviceID, memberID, getNewIdInscripciones(), INSCRIPCION_ACTIVA);
    al_add (listaInscripciones, auxiliar);
    dm_saveAllInscripciones (listaInscripciones);
    return 0;
}


////////////////////////////////////////////////////////////
// MODIFICACIONES                                         //
////////////////////////////////////////////////////////////
int ctrlr_modificarSocio (char* nombre, char* apellido, char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById (listaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio, nombre);
        soc_setApellido(auxSocio, apellido);
        soc_setDni(auxSocio, dni);
        soc_setEstado(auxSocio, estado);
        dm_saveAllSocios(listaSocios);
    }
    return 0;
}
int ctrlr_modificarServicio (char* titulo, char* descripcion, int id, int estado)
{
    Servicios* auxServicio;

    auxServicio = svcs_findById (listaServicios, id);

    if(auxServicio!=NULL)
    {
        svcs_setTitulo (auxServicio, titulo);
        svcs_setDescripcion (auxServicio, titulo);
        svcs_setEstado (auxServicio, estado);
        dm_saveAllServicios (listaServicios);
    }
    return 0;
}
int ctrlr_modificarInscripcion (int id, int status)
{
    Inscripciones* auxiliar;

    auxiliar = insc_findById (listaInscripciones, id);

    if(auxiliar!=NULL)
    {
        insc_setStatus (auxiliar, status);
        dm_saveAllInscripciones (listaInscripciones);
    }
    return 0;
}


////////////////////////////////////////////////////////////
// BAJAS                                                  //
////////////////////////////////////////////////////////////
int ctrlr_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio = soc_findById (listaSocios, id);

    if(auxSocio != NULL)
    {
        soc_setEstado (auxSocio, SOCIO_ESTADO_INACTIVO);
        dm_saveAllSocios (listaSocios);
    }
    return 0;
}
int ctrlr_bajaServicio (int id)
{
    Servicios* auxServicio;
    auxServicio = svcs_findById (listaServicios, id);
    if(auxServicio != NULL)
    {
        svcs_setEstado (auxServicio, SERVICIO_INACTIVO);
        dm_saveAllServicios (listaServicios);
    }
    return 0;
}
int ctrlr_bajaInscripcion (int id)
{
    Inscripciones* auxiliar;
    auxiliar = insc_findById (listaServicios, id);
    if(auxiliar != NULL)
    {
        insc_setStatus (auxiliar, INSCRIPCION_INACTIVA);
        dm_saveAllInscripciones (listaServicios);
    }
    return 0;
}





/////////////////////////////////////////////////////////////
int ctrlr_checkSocio(int id)
{
    int retorno = -1;
    Socio* auxiliar;
    auxiliar = soc_findById (listaSocios, id);

    if(auxiliar != NULL && soc_getEstado(auxiliar) == SOCIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}
int ctrlr_checkServicio(int id)
{
    int retorno = -1;
    Servicios* auxiliar;
    auxiliar = svcs_findById (listaServicios, id);

    if(auxiliar != NULL && svcs_getEstado(auxiliar) == SERVICIO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////
int ctrlr_listarSocios ()
{
    vista_mostrarSocios (listaSocios);
    return 0;
}
int ctrlr_listarServicios()
{
    vista_mostrarServicios (listaServicios);
    return 0;
}
int ctrlr_listarInscripciones ()
{
    vista_mostrarInscripciones (listaInscripciones);
    return 0;
}
/////////////////////////////////////////////////////////////
