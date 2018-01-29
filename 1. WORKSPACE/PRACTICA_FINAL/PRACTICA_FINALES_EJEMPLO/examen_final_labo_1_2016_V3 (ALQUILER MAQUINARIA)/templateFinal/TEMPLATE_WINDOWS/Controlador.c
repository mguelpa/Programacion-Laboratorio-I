#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

#include "Cliente.h"
#include "Alquiler.h"

static ArrayList* listaClientes;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static ArrayList* listaAlquileres;
static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int id);

//////////////////////////////////////
static ArrayList* nominaX;
static int proximoIdX=0;
static int getNewIdX();
static int setNewIdX(int id);
////////////////////////////////////////
//void cont_init()
//{
//    nominaX = al_newArrayList();
//    setNewIdX(dm_readAllX(nominaX) + 1);
//    vista_mostrarMenu();
//}
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
static int getNewIdX()
{
    return proximoIdX++;
}
static int setNewIdX(int id)
{
    proximoIdX = id;
    return 0;
}

/////////////////////////////////////////////
void cont_init()
{
    listaClientes = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(listaClientes) + 1);

    listaAlquileres = al_newArrayList();
    setNewIdAlquiler(dm_readAllAlquileres(listaAlquileres) + 1);

    vista_mostrarMenu();
}
/////////////////////////////////////////////
static int getNewIdCliente()
{
    return proximoIdCliente++;
}
static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}
int cont_altaCliente (char* a,char* b,char* c)
{
    Cliente* auxiliar;

    auxiliar = cliente_new (getNewIdCliente(), a, b, c, CLIENTE_ESTADO_ALTA);

    al_add (listaClientes, auxiliar);
    dm_saveAllClientes (listaClientes);
    return 0;
}
int cont_bajaCliente (int id)
{
    Cliente *auxiliar;
    auxiliar = cliente_findByIdCliente(listaClientes,id);
    if(auxiliar != NULL)
    {
        if(cliente_getEstado(auxiliar)==CLIENTE_ESTADO_ALTA)
            cliente_setEstado(auxiliar,CLIENTE_ESTADO_BAJA);
        else
            mostrarError("el cliente ya fue dado de baja!!!\n");
    }
    else
    {
        mostrarError("el cliente no existe!!!\n");
    }
    return 0;
}
int cont_modificarCliente (int id, char* a,char* b,char* c)
{
    Cliente *auxiliar;
    auxiliar = cliente_findByIdCliente(listaClientes,id);
    if(auxiliar != NULL)
    {
        if(cliente_getEstado(auxiliar)==CLIENTE_ESTADO_ALTA)
        {
            cliente_setNombre(auxiliar,a);
            cliente_setApellido(auxiliar,b);
            cliente_setDni(auxiliar,c);
            dm_saveAllClientes(listaClientes);
        }
    }
    return 0;
}
int cont_existeCliente (int id)
{
    Cliente *auxiliar;
    int retorno = 0;
    auxiliar = cliente_findByIdCliente(listaClientes,id);
    if(auxiliar != NULL)
    {
        if(cliente_getEstado(auxiliar)==CLIENTE_ESTADO_ALTA)
            retorno = 1;
    }

    return retorno;
}
int cont_listarCliente ()
{
    vista_mostrarCliente(listaClientes);
    return 0;
}
int cont_ordenarCliente()
{
    al_sort(listaClientes,cliente_compareByNombre,0);
    return 0;
}
/////////////////////////////////////////////////////////
static int getNewIdAlquiler ()
{
    return proximoIdAlquiler++;
}
static int setNewIdAlquiler (int id)
{
    proximoIdAlquiler = id;
    return 0;
}
int cont_altaAlquiler (int idCliente, int idEquipo, int tiempoEstimado)
{
    Alquiler* auxiliar;

    auxiliar = alquiler_new (idCliente, idEquipo, 0, tiempoEstimado, getNewIdAlquiler(), ALQUILER_ESTADO_ALTA);
    al_add (listaAlquileres, auxiliar);
    dm_saveAllAlquileres (listaAlquileres);
    return 0;
}
int cont_bajaAlquiler (int id, int tiempoReal)
{
    Alquiler *auxiliar;
    auxiliar = alquiler_findByIdAlquiler(listaAlquileres,id);

    printf("%d", alquiler_getIdAlquiler(auxiliar));
    if(auxiliar != NULL)
    {
        if(alquiler_getEstado(auxiliar)==ALQUILER_ESTADO_ALTA)
        {
            alquiler_setTiempoReal(auxiliar,tiempoReal);
            alquiler_setEstado(auxiliar, ALQUILER_ESTADO_BAJA);
            dm_saveAllAlquileres (listaAlquileres);

        }
    }
    return 0;
}
int cont_existeAlquiler (int idAlquiler, int idCliente)
{
    Alquiler *auxiliar;
    int retorno = 0;
    auxiliar = alquiler_findByIdAlquiler(listaAlquileres, idAlquiler);
    if(auxiliar != NULL)
    {
        if(alquiler_getEstado(auxiliar)==ALQUILER_ESTADO_ALTA &&
           alquiler_getIdCliente(auxiliar) == idCliente)
            retorno = 1;
    }
    return retorno;
}
int cont_listarAlquiler()
{
    //vista_mostrarX(nominaX);
    return 0;
}
/////////////////////////////////////////////////////////
int cont_asociadoConMasAlquileres ()
{
    int i;
    int j;

    Cliente* auxCliente;
    Alquiler* auxAlquler;

    int contadorAlquileres[al_len(listaClientes)];

    for(i=0; i<al_len(listaClientes); i++)
        contadorAlquileres[i] = 0;

    for(i=0; i<al_len(listaClientes); i++)
    {
        auxCliente = al_get(listaClientes, i);
        for(j=0; j<al_len(listaAlquileres); j++)
        {
            auxAlquler = al_get(listaAlquileres, j);
            if(alquiler_getIdCliente(auxAlquler) == cliente_getIdCliente(auxCliente) &&
               cliente_getEstado(auxCliente) == CLIENTE_ESTADO_ALTA &&
               alquiler_getEstado(auxAlquler) == ALQUILER_ESTADO_ALTA)
            {
                contadorAlquileres[i]++;
            }
        }
    }

    for(i=0; i<al_len(listaClientes); i++)
    {
        printf("id socio: %d - alquileres: %d\n", i, contadorAlquileres[i]);
    }
    return 0;
}

int cont_equipoMasAlquilado()
{
    int i;

    Alquiler* auxAlquler;

    int contadorAlquileres[5];

    for(i=0; i<5; i++)
        contadorAlquileres[i] = 0;

    for(i=0; i<al_len(listaAlquileres); i++)
    {
        auxAlquler = al_get(listaAlquileres, i);
        contadorAlquileres[alquiler_getIdEquipo(auxAlquler)]++;
    }

    for(i=0; i<5; i++)
    {
        printf("id maquina: %d - alquileres: %d\n", i, contadorAlquileres[i]);
    }
    return 0;
}

int cont_tiempoPromedioDeAlquilerXEquipo()
{
    int i;

    Alquiler* auxAlquler;

    int contadorAlquileres[5];
    int contadorTiempoReal[5];
    float promedioAlquileres[5];


    for(i=0; i<5; i++)
    {
        contadorAlquileres[i] = 0;
        contadorTiempoReal[i] = 0;
        promedioAlquileres[i] = 0;
    }

    for(i=0; i<al_len(listaAlquileres); i++)
    {
        auxAlquler = al_get(listaAlquileres, i);
        contadorAlquileres[alquiler_getIdEquipo(auxAlquler)]++;
        contadorTiempoReal[alquiler_getIdEquipo(auxAlquler)] += alquiler_getTiempoReal(auxAlquler);
    }
    for(i=0; i<5; i++)
    {
        promedioAlquileres[i] = contadorTiempoReal[i] / contadorAlquileres[i];
    }

    for(i=0; i<5; i++)
    printf("id maquina: %d - alquieres: %d - promedio: %.2f\n", i, contadorAlquileres[i], promedioAlquileres[i]);
    return 0;
}

int cont_imprimirCamposAlquiler(int idCliente)
{
    Alquiler* auxiliar;
    int i;

    for(i=0; i<al_len(listaAlquileres); i++)
    {
        auxiliar = al_get(listaAlquileres, i);
        if(alquiler_getIdCliente(auxiliar) == idCliente)
        alquiler_imprimir(auxiliar);
    }
    return 0;
}
