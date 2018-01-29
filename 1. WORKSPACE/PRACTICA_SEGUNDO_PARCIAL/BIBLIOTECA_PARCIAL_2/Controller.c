#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"

#include "DataManager.h"
#include "Interface.h"

#include "Subjects.h"
#include "Servicios.h"
#include "Inscripciones.h"

static void ctrlr_parsear ();

//////////////////////////////////////////////////
// FUNCIONES LISTA SUBJECTS                     //
//////////////////////////////////////////////////
static ArrayList* listaSubjects;
static int SubjectNextID = 0;

static int getSubjectNewID ();
static int setSubjectNewID (int id);

static int getSubjectNewID ()
{
    return SubjectNextID++;
}
static int setSubjectNewID (int id)
{
    SubjectNextID = id;
    return 0;
}
//////////////////////////////////////////////////
// FUNCIONES LISTA SUBJECTS2                    //
//////////////////////////////////////////////////
static ArrayList* listaServicios;
static int servicesNextID = 0;

static int getServicesNewID ();
static int setServicesNewID (int id);

static int getServicesNewID ()
{
    return servicesNextID++;
}
static int setServicesNewID (int id)
{
    servicesNextID = id;
    return 0;
}
//////////////////////////////////////////////////
// FUNCIONES LISTA RELACION                     //
//////////////////////////////////////////////////
static ArrayList* listaInscripciones;
static int InscripcionesID = 0;

static int getInscripcionesNewID ();
static int setInscripcionesNewID (int id);

static int getInscripcionesNewID ()
{
    return InscripcionesID++;
}
static int setInscripcionesNewID (int id)
{
    InscripcionesID = id;
    return 0;
}
//////////////////////////////////////////////////
// INICIALIZACION DE LISTAS Y MENU              //
//////////////////////////////////////////////////
void ctrlr_init()
{
    listaSubjects = al_newArrayList();
    listaServicios = al_newArrayList();
    listaInscripciones = al_newArrayList();

    setSubjectNewID ( dm_readAllSubjects (listaSubjects) + 1 );
    setServicesNewID ( dm_readAllServicios(listaServicios) + 1 );
    setInscripcionesNewID ( dm_readAllInscripciones(listaInscripciones) + 1 );

    intr_mostrarMenu();
}

//////////////////////////////////////////////////
// ALTAS                                        //
//////////////////////////////////////////////////
int ctrlr_altaSubject (char* name, char* surname/*,int age,char* dni,float salary*/)
{
    Subject* auxiliar;

    auxiliar = sub_new (getSubjectNewID(), SUB_ACTIVE, name, surname/*, age, dni, salary*/);

    al_add (listaSubjects, auxiliar);
    dm_saveAllSubjects (listaSubjects);
    return 0;
}
int ctrlr_altaServicio (char* title, char* description/*,int age,char* dni,float salary*/)
{
    Servicios* auxiliar;
    auxiliar = svcs_new (title, description/*, age, dni, salary*/, getServicesNewID(), SERVICIO_ACTIVO);

    al_add (listaServicios, auxiliar);
    dm_saveAllServicios (listaServicios);
    return 0;
}
int ctrlr_altaInscripcion (int serviceID, int memberID)
{
    Inscripciones* auxiliar;

    auxiliar = insc_new (getInscripcionesNewID(), INSCRIPCION_ACTIVA, serviceID, memberID);

    al_add (listaInscripciones, auxiliar);
    dm_saveAllInscripciones (listaInscripciones);
    return 0;
}


////////////////////////////////////////////////////////////
// MODIFICACIONES                                         //
////////////////////////////////////////////////////////////
int ctrlr_modificarSubject (int id, int status, char* name, char* surname/*,int age,char* dni,float salary*/)
{
    int retorno = -1;
    Subject* auxiliar;

    auxiliar = sub_findById (listaSubjects, id);

    if(auxiliar != NULL)
    {
        sub_setName(auxiliar, name);
        sub_setSurname(auxiliar, surname);

        //sub_setAge(auxiliar, age);
        //sub_setDni(auxiliar, dni);
        //sub_setSalary(auxiliar, salary);

        dm_saveAllSubjects (listaSubjects);
    }
    return retorno;
}
int ctrlr_modificarServicio (int id, int status, char* title, char* description/*,int age,char* dni,float salary*/)
{
    int retorno = -1;
    Servicios* auxiliar;

    auxiliar = svcs_findById (listaServicios, id);

    if(auxiliar != NULL)
    {
        svcs_setTitulo (auxiliar, title);
        svcs_setDescripcion (auxiliar, description);

        dm_saveAllServicios (listaServicios);
        retorno = 0;
    }
    return retorno;
}
int ctrlr_modificarInscripcion (int id, int status)
{
    int retorno = -1;
    Inscripciones* auxiliar;

    auxiliar = insc_findById (listaInscripciones, id);

    if(auxiliar != NULL)
    {
        insc_setStatus (auxiliar, status);
        dm_saveAllInscripciones (listaInscripciones);
    }
    return retorno;
}


////////////////////////////////////////////////////////////
// BAJAS                                                  //
////////////////////////////////////////////////////////////
int ctrlr_bajaSubject (int id)
{
    int retorno = -1;
    Subject* auxiliar = sub_findById (listaSubjects, id);

    if(auxiliar != NULL)
    {
        sub_setStatus (auxiliar, SUB_ACTIVE);
        dm_saveAllSubjects (listaSubjects);
    }
    return retorno;
}
int ctrlr_bajaServicio (int id)
{
    int retorno = -1;
    Servicios* auxiliar  = svcs_findById (listaServicios, id);

    if(auxiliar != NULL)
    {
        svcs_setEstado (auxiliar, SERVICIO_INACTIVO);
        dm_saveAllServicios (listaServicios);
    }
    return retorno;
}
int ctrlr_bajaInscripcion (int id)
{
    int retorno = -1;
    Inscripciones* auxiliar = insc_findById (listaServicios, id);

    if(auxiliar != NULL)
    {
        insc_setStatus (auxiliar, INSCRIPCION_INACTIVA);
        dm_saveAllInscripciones (listaServicios);
    }
    return retorno;
}


////////////////////////////////////////////////////////////
// check data                                             //
////////////////////////////////////////////////////////////
int ctrlr_checkSubject (int id)
{
    int retorno = -1;
    Subject* auxiliar;

    auxiliar = sub_findById (listaSubjects, id);

    if(auxiliar != NULL && sub_getStatus(auxiliar) == SUB_ACTIVE)
    {
        retorno = 0;
    }
    return retorno;
}
int ctrlr_checkServicio (int id)
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


////////////////////////////////////////////////////////////
// mostrar                                                //
////////////////////////////////////////////////////////////
int ctrlr_listarSubjects()
{
    intr_mostrarSubjects (listaSubjects);
    return 0;
}
int ctrlr_listarServicios()
{
    intr_mostrarServicios (listaServicios);
    return 0;
}
int ctrlr_listarInscripciones ()
{
    intr_mostrarInscripciones (listaInscripciones);
    return 0;
}

static void ctrlr_parsear ()
{
    sub_parseSubject (listaSubjects);
}

